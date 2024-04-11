/*
 * @Author: myq 2127800097@qq.com
 * @Date: 2024-04-04 18:18:39
 * @LastEditors: myq 2127800097@qq.com
 * @LastEditTime: 2024-04-04 20:17:10
 * @FilePath: /detect_armor2/detect_lights/src/detect_lights/src/detect_armors.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include<detect_armors.h>
ArmorDetect::ArmorDetect(const AllInformation &information, const OpenvinoInference &infer):information(information), infer(infer) {}

void ArmorDetect::DrawArmor() {
    for(const auto &armor : end_armor) {
        cv::Rect rect(armor.left_on_point.x,armor.left_on_point.y,armor.armor_width,armor.armor_lenth);
        cv::rectangle(now_image,rect,cv::Scalar(0,255,0),2,8);
    }
    imshow("展示",now_image);
}
void ArmorDetect::ComputeAngle() {
    //相机内参
    cv::Mat cameraMatrix = (cv::Mat_<double>(3,3) << 2774.072438378028, 0, 581.6242066161772, 0, 2776.373613923545, 493.0019753768456,0, 0, 1);
        //相机畸变
    cv::Mat distCoeffs = (cv::Mat_<double>(1,5) << -0.1066840616987659, -0.1932346636433034, -0.004304864360822717, -0.008192305801843786, 2.249618125010471);
    double tan_x = (end_armor[0].armor_center.x-cameraMatrix.at<double>(0,2)) / cameraMatrix.at<double>(0, 0);
    double tan_y = (end_armor[0].armor_center.y - cameraMatrix.at<double>(1, 2)) / cameraMatrix.at<double>(1, 1);
    double angle_x = atan(tan_x) / 2 / CV_PI * 360;
    double angle_y = atan(tan_y) / 2 / CV_PI * 360;
    information.y_angle = angle_y;
    information.p_angle = angle_x;
    std::cout << "y = " <<angle_y << "p = " <<angle_x << std::endl;
}
bool ArmorDetect::MatchSlotArmor(const Armor &armor) {
    if (armor.number_image.cols == 0) {
        return 0;
    }
    // auto infer_result = std::make_shared<std::vector<InferenceResult>>(19);
    std::vector<InferenceResult> *infer_result = new std::vector<InferenceResult>;
    cv::Mat wait_trackle_image = armor.number_image.clone();
    cv::imshow("2", wait_trackle_image);
    infer.StartInfer(now_image);
    infer.TrackleData(infer_result);
    std::vector<InferenceResult> check = *infer_result;
    // if (check.empty()) delete infer_result; return 0;
    if (check.empty() ) {
        std::cout << "未识别" << std::endl;
        delete infer_result;
        infer_result = nullptr;
        return 0;
    }
    for (auto a : check) {
        cv::rectangle(now_image, a.rect, cv::Scalar(255, 0 , 0), 1, 8, 0);
        cv::imshow("deep_learn", now_image);
        float iou = Kit::ComputeIouRect(a.rect, armor.rect);
        std::cout << iou << std::endl;
        if ((a.classification == 5 || a.classification == 4) && iou > 0) {
            delete infer_result;
            infer_result = nullptr;
            return 1;
        }else {
            delete infer_result;
            infer_result = nullptr;
            return 0;
         }
    }

}

void ArmorDetect::DeleteFalseArmor(const std::vector<Armor> armor_arr) {
    std::vector<cv::Point2f> temp_arr;
    for (int i = 0; i < armor_arr.size(); i++) {
        for (int j = i + 1; j < armor_arr.size(); j++) {
            cv::Rect rect1(armor_arr[i].left_on_point.x, armor_arr[i].left_on_point.y, armor_arr[i].armor_width, armor_arr[i].armor_lenth);
            cv::Rect rect2(armor_arr[j].left_on_point.x, armor_arr[j].left_on_point.y, armor_arr[j].armor_width, armor_arr[j].armor_lenth);
            float iou = Kit::ComputeIouRect(rect1, rect2);
            if (iou > 0.1) {
                if (armor_arr[i].armor_width * armor_arr[i].armor_lenth < armor_arr[j].armor_width * armor_arr[j].armor_lenth) {
                    end_armor.push_back(armor_arr[i]);
                } else {
                    end_armor.push_back(armor_arr[j]);
                }
                temp_arr.push_back(armor_arr[i].armor_center);
                temp_arr.push_back(armor_arr[j].armor_center);
            }
        }
    }
    for (auto &armor : armor_arr) {
        int i = 0;
        for (auto &center : temp_arr) {
            if (armor.armor_center == center) {
                i++;
                break;
            }
        }
        if (i == 0) {
            end_armor.push_back(armor);
        }   
    }
}

void ArmorDetect::CreateNumberImage(const cv::Mat &src, std::vector<Armor> &armors) {
    cv::Mat wait_trackle_imgae;
    cv::copyMakeBorder(src, wait_trackle_imgae, 1000, 1000, 1000, 1000, cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255));
    for (auto &armor :armors) {
        if (armor.left_on_point.x < 0 || armor.left_on_point.y < 0) {
            continue;
        }
        cv::Rect rect(armor.left_on_point.x + 1000, armor.left_on_point.y +  1000, armor.armor_width + 200, armor.armor_lenth + 200);

        cv::Mat number_image = wait_trackle_imgae(rect);
        // cv::cvtColor(number_image, number_image, cv::COLOR_RGB2GRAY);
        // cv::threshold(number_image, number_image, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
        // cv::threshold(number_image, number_image, 30, 255, 0);
        cv::imshow("2", number_image);
        armor.number_image = number_image;
    }
}
void ArmorDetect::Run(const cv::Mat &image) {
    now_image = image;  
    ImageTrackle trackle_image(information.color,
                               information.color_image_thresold,
                               information.gray_image_thresold);
    LightDetect light_detect(information.min_area_light,
                             information.max_angle_light);
    this->trackled_image = trackle_image.TrackleImageSubtract(image);
    light_detect.DetectEnemyLight(trackled_image);
    light_detect.MatchPreArmor();
    CreateRelArmor rel_armor(light_detect.pre_armor,
                                no_trackle_image,
                                information.max_angelediff,
                                information.max_tangent,
                                information.max_boxlenthdivwidth,
                                information.min_boxlenthdivwidth);
    rel_armor.MatchRelArmor();
    CreateNumberImage(now_image, rel_armor.rel_armors);
    std::vector<Armor> wait_delete_armor;
    for (auto &armor : rel_armor.rel_armors) {
        if (MatchSlotArmor(armor)) {
            wait_delete_armor.push_back(armor);
        } else {
            // std::cout << "假装甲板" << std::endl;
        }
    }
    if (wait_delete_armor.size() == 1) {
        end_armor = wait_delete_armor;
    } else if (wait_delete_armor.size() > 1) {
        DeleteFalseArmor(wait_delete_armor);
    }
    DrawArmor();
    end_armor.clear();
    cv::waitKey(1);
    if (!end_armor.empty()) {
        ComputeAngle();
    }
}
    
