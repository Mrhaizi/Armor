#include <openvino.h>
using namespace InferenceEngine;
OpenvinoInference::OpenvinoInference(const std::string &model_path, const std::string &inferplace, const std::string &label_path) {
    // 初始化Inference Engin
    Core ie;
    ov::Core core;
    m_network = ie.ReadNetwork(model_path);
    // auto a = core.get_available_devices();
    
    // ie.get_available_devices();

    // 加载网络
    m_network_ov = core.compile_model(model_path, "AUTO");
    auto model = core.read_model(model_path);
   
   
    
    // 设置输入配置
    auto inputs = model->inputs();
    auto outputs = model->inputs();
    for (auto input : outputs) {
        std::cout << input << std::endl;
        std::cout << std::endl;
    }
    
    m_input_info = m_network.getInputsInfo().begin()->second; // 获取输入数据的一系列数据
    m_input_name = m_network.getInputsInfo().begin()->first; // 获取输入数据的名称
    m_input_info->setLayout(Layout::NCHW); // 将输入数据的图像数据改为 nhwc
    m_input_info->setPrecision(Precision::FP32); // 方法将该输入数据的精度设置为无符号8位整数（U8）。这种数据类型通常用于图像数据，因为它能够有效地表示像素值（0-255范围内）。

    // 设置输出配置
    m_output_info = m_network.getOutputsInfo().begin()->second; // 获取输出的数据
    m_output_name = m_network.getOutputsInfo().begin()->first; // 获取输出数据的名字
    m_output_info->setPrecision(Precision::FP32);


    // 加载模型到设备
    m_executableNetwork = ie.LoadNetwork(m_network, inferplace); //在cpu加载神经网络模型，也可以用gpu等等
    InferenceEngine::InputsDataMap inputInfo(m_network.getInputsInfo());
    InferenceEngine::OutputsDataMap outputInfo(m_network.getOutputsInfo());
            std::cout << "Model Inputs:" << std::endl;
        for (auto&& input : inputInfo) {
            std::string input_name = input.first;
            SizeVector input_shape = input.second->getTensorDesc().getDims();
            std::cout << "Name: " << input_name << ", Shape: ";
            for (size_t i = 0; i < input_shape.size(); ++i) {
                std::cout << input_shape[i] << " ";
            }
            std::cout << std::endl;
        }

        // 打印模型输出信息
        std::cout << "\nModel Outputs:" << std::endl;
        for (auto&& output : outputInfo) {
            std::string output_name = output.first;
            SizeVector output_shape = output.second->getTensorDesc().getDims();
            std::cout << "Name: " << output_name << ", Shape: ";
            for (size_t i = 0; i < output_shape.size(); ++i) {
                std::cout << output_shape[i] << " ";
            }
            std::cout << std::endl;
        }
    
}

void OpenvinoInference::quicksort(std::vector<InferenceResult>& inference_armors, const int& left, const int& right) {
    if (inference_armors.empty() || left >= right)
    return;

    float probability = inference_armors[(left + right) / 2].probability;
    int i = left;
    int j = right;
    while (i <= j) {
        while (inference_armors[i].probability > probability)
            i++;
        while (inference_armors[j].probability < probability)
            j--;
        if (i <= j) {
            std::swap(inference_armors[i], inference_armors[j]);
            i++;
            j--;
        }
    }
    std::thread left_thread(quicksort, std::ref(inference_armors), left, j);
    std::thread right_thread(quicksort, std::ref(inference_armors), i, right);
    left_thread.join();
    right_thread.join();
}

cv::Mat OpenvinoInference::scaledResize(const cv::Mat& src) {
    auto width = static_cast<float>(src.cols);
    auto height = static_cast<float>(src.rows);
    float rate = std::min(OpenvinoInference::INPUT_WIDTH / width,
                          OpenvinoInference::INPUT_WIDTH / height);
    int updated_w = static_cast<int>(rate * width);
    int updated_h = static_cast<int>(rate * height);
    int dw = (OpenvinoInference::INPUT_WIDTH - updated_w) / 2;
    int dh = (OpenvinoInference::INPUT_HEIGHT - updated_h) / 2;

    m_transfrom_matrix << 1.0f / rate, 0.0f,        -dw / rate,
                              0.0f,        1.0f / rate, -dh / rate,
                              0.0f,        0.0f,         1.0f;
    cv::Mat resized, out;
    cv::resize(src, resized, cv::Size(updated_w, updated_h));
    cv::copyMakeBorder(resized, out, dh, dh, dw, dw, cv::BORDER_CONSTANT);
    cv::imshow("show", out);
    return out;
}

void OpenvinoInference::generateGridsAndStride(const int& target_w, const int& target_h, const std::vector<int>& strides,
                            std::vector<GridAndStride>* grid_strides) {
    for (const auto& stride: strides) {
        int num_grid_w = target_w / stride;
        int num_grid_h = target_h / stride;
        for (int g1 = 0; g1 < num_grid_h; g1++) {
            for (int g0 = 0; g0 < num_grid_w; g0++)
                grid_strides->push_back((GridAndStride) {g0, g1, stride});
        }
    }
}
void OpenvinoInference::nonMaximumSuppression(std::vector<InferenceResult> &selected_armors, std::vector<InferenceResult>&inference_armors, const float& threshold) {
    /**
     * @brief 计算交并比(iou)
     */
    auto getIou = [threshold](const InferenceResult& a, const InferenceResult& b)->float {
        float inter_area = (a.rect & b.rect).area();
        float union_area = (a.rect | b.rect).area();
        return inter_area / union_area;
    };

    quicksort(inference_armors, 0, static_cast<int>(inference_armors.size()) - 1);
    while (!inference_armors.empty()) {
        InferenceResult& selected_armor = inference_armors[0];
        selected_armors.push_back(selected_armor);
        inference_armors.erase(inference_armors.begin());
        // 移除重叠区域大的边界框(en: Remove overlapping bounding boxes with large overlapping areas)
        auto new_end = std::remove_if(inference_armors.begin(), inference_armors.end(), [&selected_armor, threshold, getIou](InferenceResult& item)->bool {
            float iou = getIou(selected_armor, item);
            if (iou > k_UseToMeanIouThreshold &&
                selected_armor.classification == item.classification &&
                selected_armor.color == item.color &&
                abs(selected_armor.probability - item.probability) < k_MergeConfidenceError) {
                for (auto & i : item.armor_apex)
                    selected_armor.points.push_back(std::move(i));
            }
            return iou > threshold;
        });
        inference_armors.erase(new_end, inference_armors.end());
//        for (int i = static_cast<int>(inference_armors.size()) - 1; i >= 0; --i) {
//            auto& item = inference_armors[i];
//            if (selected_armor.classification == item.classification &&
//                selected_armor.color == item.color &&
//                abs(selected_armor.probability - item.probability) < k_MergeConfidenceError &&
//                getIou(selected_armor, item) > threshold) {
//                    inference_armors.erase(inference_armors.begin() + i);
//            }
//        }
    }
}
void OpenvinoInference::generateYoloxProposals(const float* inference_result_ptr, const std::vector<GridAndStride>& grid_strides,
                            const Eigen::Matrix<float, 3, 3> transform_matrix, const float& probability_confidence_threshold, std::vector<InferenceResult> *result) {
    const int num_anchors = static_cast<int>(grid_strides.size());
    // Travel all the anchors
    for (int anchor_idx = 0; anchor_idx < num_anchors; anchor_idx++) {
        // 通过网格、步长、偏移获取值
        const auto grid0 = static_cast<float>(grid_strides[anchor_idx].grid_x);
        const auto grid1 = static_cast<float>(grid_strides[anchor_idx].grid_y);
        const auto stride = static_cast<float>(grid_strides[anchor_idx].stride);
        const int basic_pos = anchor_idx * (9 + k_NumberColor + k_NumberClassification);
        float x_1 = (inference_result_ptr[basic_pos + 0] + grid0) * stride;
        float y_1 = (inference_result_ptr[basic_pos + 1] + grid1) * stride;
        float x_2 = (inference_result_ptr[basic_pos + 2] + grid0) * stride;
        float y_2 = (inference_result_ptr[basic_pos + 3] + grid1) * stride;
        float x_3 = (inference_result_ptr[basic_pos + 4] + grid0) * stride;
        float y_3 = (inference_result_ptr[basic_pos + 5] + grid1) * stride;
        float x_4 = (inference_result_ptr[basic_pos + 6] + grid0) * stride;
        float y_4 = (inference_result_ptr[basic_pos + 7] + grid1) * stride;
        // 获取目标框概率
        auto argMax = [](const float* ptr, const int& len)->int {
            int max_arg = 0;
            for (int i = 1; i < len; i++) {
                if (ptr[i] > ptr[max_arg])
                    max_arg = i;
            }
            return max_arg;
        };
        int box_color = argMax(inference_result_ptr + basic_pos + 9, k_NumberColor);
        int box_class = argMax(inference_result_ptr + basic_pos + 9 + k_NumberColor, k_NumberClassification);
        float box_probability = inference_result_ptr[basic_pos + 8];
        // 筛选并生成装甲板对象
        if (box_probability >= probability_confidence_threshold) {
            InferenceResult armor;
            Eigen::Matrix<float, 3, 4> tmp_apex;  // 顶点
            Eigen::Matrix<float, 3, 4> armor_apex_destination;  // 目标顶点
            tmp_apex << x_1, x_2, x_3, x_4,
                         y_1, y_2, y_3, y_4,
                         1,   1,   1,   1;
            Eigen::Matrix<float, 3, 3> matrix_temp = transform_matrix;
            armor_apex_destination = matrix_temp * tmp_apex;
            for (int i = 0; i < 4; i++) {
                armor.armor_apex[i] = cv::Point2f(armor_apex_destination(0, i), armor_apex_destination(1, i));
                armor.points.push_back(armor.armor_apex[i]);
            }
            std::vector<cv::Point2f> tmp(armor.armor_apex, armor.armor_apex + 4);
            armor.rect = cv::boundingRect(tmp);
            armor.classification = box_class;
            armor.color = box_color;
            armor.probability = box_probability;
            result->push_back(armor);
        }

    } // point anchor loo

}

void OpenvinoInference::StartInfer(const cv::Mat &image) {
    cv::Mat out_image = scaledResize(image);
    out_image.convertTo(out_image,CV_32F);
    cv::Mat split[3];
    cv::split(out_image,split);
    m_inferrequest = m_executableNetwork.CreateInferRequest();    
    int size = out_image.cols * out_image.rows;
    Blob::Ptr input_blob = m_inferrequest.GetBlob(m_input_name);
    float* input_data = input_blob->buffer().as<float*>();
    for (int i = 0; i < 3; i++) {
        std::memcpy(input_data + i * size, split[i].data, size * sizeof(float));
    }
    m_inferrequest.SetBlob(m_input_name, input_blob);
    m_inferrequest.Infer();
    m_output_blob = m_inferrequest.GetBlob(m_output_name);
    m_outputData = m_output_blob->buffer().as<const float*>();
}

void OpenvinoInference::TrackleData(std::vector<InferenceResult> *infer_result) {

    if (m_outputData == nullptr) return;
    std::vector<InferenceResult> tmp_armors;
    std::vector<GridAndStride> grid_strides;
    std::vector<int> strides = { 8, 16, 32 };
    // 解析

    generateGridsAndStride(OpenvinoInference::INPUT_WIDTH, OpenvinoInference::INPUT_HEIGHT, strides, &grid_strides);
    generateYoloxProposals(m_outputData, grid_strides, m_transfrom_matrix, k_BoundBoxConfidenceThreshold, &tmp_armors);
   
    if (tmp_armors.size() > k_InferenceResultPollMaxVal) {
        tmp_armors.resize(k_InferenceResultPollMaxVal);
    }
    nonMaximumSuppression(*infer_result, tmp_armors, k_BoundBoxConfidenceThreshold);
    // if (infer_result->empty()) return;
    std::vector<InferenceResult> tmep = *infer_result;
    for (auto& armor: *infer_result) {
    if (armor.points.size() >= 8) {
        auto number = armor.points.size() / 4;
        cv::Point2f averaged_apex[4];  // 均值化后的装甲板四个顶点
        for (int i = 0; i < armor.points.size(); ++i)
            averaged_apex[i % 4] += armor.points[i];
        for (auto & item : averaged_apex) {
            item.x = item.x / static_cast<float>(number);
            item.y = item.y / static_cast<float>(number);
        }
        std::copy(averaged_apex, averaged_apex + sizeof(averaged_apex) / sizeof(cv::Point2f), armor.armor_apex);
    }
    // armor.area = static_cast<int>(quadrilateralArea(armor.armor_apex));  // TODO: 是否需要更改
    }
}
Blob::Ptr OpenvinoInference::WarpMatToBlob(const cv::Mat &image) {
    size_t channels = image.channels();
    size_t height = image.rows;
    size_t width = image.cols; 
    TensorDesc tensorDesc(Precision::FP32, {1,height, width,channels}, Layout::NHWC);
    Blob::Ptr blob = make_shared_blob<float>(tensorDesc);
    blob->allocate();
    auto buffer = blob->buffer().as<float*>();
    std::copy(image.data, image.data + image.total() * image.channels(), buffer);
    return blob;
}
