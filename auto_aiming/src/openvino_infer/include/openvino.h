#ifndef OPENVINO_INFERENCE_H
#define OPENVINO_INFERENCE_H
#include <openvino/openvino.hpp>
#include <opencv2/opencv.hpp>
#include <inference_engine.hpp>
#include <fstream>
#include <iostream>
#include <ctime>
#include <eigen3/Eigen/Core>
#include <Eigen/Dense>
#include <thread>
#include <algorithm>

static constexpr int k_NumberClassification = 8;
static constexpr int k_NumberColor = 4;
static constexpr int k_InferenceResultPollMaxVal = 128;  // 最多保留的推理出的装甲板数量(保留概率更大的)
static constexpr float k_BoundBoxConfidenceThreshold = 0.01f;  // 推理输出的边框的概率的阈值(en: bounding box confidence threshold)
static constexpr float k_NmsThreshold = 0.35f;  // 非极大值抑制-阈值(en: Non-Maximum Suppression)
static constexpr float k_MergeConfidenceError = 0.15f;  // 重合置信度误差
static constexpr float k_UseToMeanIouThreshold = 0.9f;  // 高于该阈值的iou可以被用来均值化装甲板的四个顶点以减少误差


struct GridAndStride {
    int grid_x;
    int grid_y;
    int stride;  // 步长
};


struct InferenceResult {
    int area{};  // 装甲板四个顶点所成四边形面积
    int color{};  // Blue: 0; Red: 1; 灰色: 2
    int classification{}; // 编号
    float probability{};
    cv::Rect_<float> rect{};  // 装甲板的包围矩形
    cv::Point2f armor_apex[4];  // 装甲板的四个顶点(左上角开始逆时针)
    std::vector<cv::Point2f> points{};  // 用来均值化的装甲板角点(iou > 0.9f)
    InferenceResult() =default;
};
class OpenvinoInference {
public:
    static constexpr int INPUT_HEIGHT = 416;
    static constexpr int INPUT_WIDTH = 416;

    OpenvinoInference(const std::string &model_path, const std::string &inferplace);  

    void StartInfer(const cv::Mat &image);

    void TrackleData(std::vector<InferenceResult> *infer_request);

    InferenceEngine::Blob::Ptr WarpMatToBlob(const cv::Mat &image);

    void generateGridsAndStride(const int& target_w, const int& target_h, const std::vector<int>& strides,
                            std::vector<GridAndStride>* grid_strides);

    void generateYoloxProposals(const float* inference_result_ptr, const std::vector<GridAndStride>& grid_strides,
                            const Eigen::Matrix<float, 3, 3> ransform_matrix, const float& probability_confidence_threshold, 
                            std::vector<InferenceResult> *result);

    cv::Mat scaledResize(const cv::Mat& src);

    static void  quicksort(std::vector<InferenceResult>& inference_armors, const int& left, const int& right);

    void nonMaximumSuppression(std::vector<InferenceResult> &selected_armors, std::vector<InferenceResult>& inference_armors, const float& threshold);

private:
    InferenceEngine::InputInfo::Ptr m_input_info; //输入的一系列数据
    std::string m_input_name; //输入数据的名字
    InferenceEngine::DataPtr m_output_info; //输出的一系列数据
    std::string m_output_name; // 输出数据的名字0
    InferenceEngine::InferRequest m_inferrequest; //推理器
    InferenceEngine::Blob::Ptr m_output_blob; // 输出的blob数据
    InferenceEngine::ExecutableNetwork m_executableNetwork; 
    ov::CompiledModel m_network_ov; 
    InferenceEngine::CNNNetwork m_network;
    const float* m_outputData;
    int m_src_width;
    Eigen::Matrix<float, 3, 3> m_transfrom_matrix;
    int m_src_height;
};
#endif