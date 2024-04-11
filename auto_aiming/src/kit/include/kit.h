#ifndef KIT_H
#define KIT_H
/*
 * @Author: myq 2127800097@qq.com
 * @Date: 2024-03-30 13:35:29
 * @LastEditors: myq 2127800097@qq.com
 * @LastEditTime: 2024-03-31 17:26:41
 * @FilePath: /eigen_other/src/detect/include/kit.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include <iostream>
#include <opencv2/opencv.hpp>
namespace Kit{

    float ComputeDistance(const cv::Point2f &pt1, const cv::Point2f &pt2);
    cv::RotatedRect SelectRoatedRect(const cv::Mat &image);
    float ComputeIou(const cv::RotatedRect &rect_one, const cv::RotatedRect &rect_two);
    float CIou(const cv::RotatedRect &rect_one, const cv::RotatedRect &rect_two);
    
    template<typename T>
    float ComputeIouRect(const cv::Rect_<T> &rect_one, const cv::Rect_<T> &rect_two) {
        // 计算矩形的交集和并集
        cv::Rect_<T> intersection = rect_one & rect_two;
        cv::Rect_<T> unionRect = rect_one | rect_two;

        // 检查并集的面积是否为零，避免除以零的错误
        if (unionRect.area() == 0) {
            return 0.0f;
        }
        
        // 计算 IoU 值
        float iou = static_cast<float>(intersection.area()) / unionRect.area();
        return iou;
    }
    
} // namespace kit
#endif