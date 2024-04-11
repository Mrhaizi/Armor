/*
 * @Author: myq 2127800097@qq.com
 * @Date: 2024-03-30 13:37:20
 * @LastEditors: myq 2127800097@qq.com
 * @LastEditTime: 2024-04-01 21:12:50
 * @FilePath: /eigen_other/src/detect/src/Kit.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include <kit.h>

float Kit::ComputeDistance(const cv::Point2f &pt1, const cv::Point2f &pt2) {
    float x = pt1.x - pt2.x;
    float y = pt1.y - pt2.y;
    float distance = std::sqrt(x * x + y * y); 
    return distance;
}
cv::RotatedRect Kit::SelectRoatedRect(const cv::Mat &image) {
    cv::Rect rect = cv::selectROI(image);
    std::vector<cv::Point> vers;
    cv::Point tl = rect.tl(); // 左上角顶点
    cv::Point br = rect.br(); // 右下角顶点
    cv::Point tr(rect.x + rect.width, rect.y); // 右上角顶点
    cv::Point bl(rect.x, rect.y + rect.height);
    vers.push_back(tl);
    vers.push_back(tr);
    vers.push_back(br);
    vers.push_back(bl);
    cv::RotatedRect rotatedrect = cv::minAreaRect(vers);
    return rotatedrect;
}
float Kit::ComputeIou(const cv::RotatedRect &rect_one, const cv::RotatedRect &rect_two) {
    // 计算交集部分
    float x1 = std::max(rect_one.center.x, rect_two.center.x);
    float y1 = std::max(rect_one.center.y, rect_two.center.y);
    float x2 = std::min(rect_one.center.x + rect_one.size.width, rect_two.center.x + rect_two.size.width);
    float y2 = std::min(rect_one.center.y + rect_one.size.height, rect_two.center.y + rect_two.size.height);

    // 检查交集是否为空，即检查 x 和 y 方向是否存在交集
    if (x2 < x1 || y2 < y1) {
        return 0.0f; // 交集为空，IoU 为 0
    }

    // 计算交集和并集的面积
    float intersection_area = (x2 - x1) * (y2 - y1);
    float box1_area = rect_one.size.width * rect_one.size.height;
    float box2_area = rect_two.size.width * rect_two.size.height;
    float union_area = box1_area + box2_area - intersection_area;

    // 避免除以零
    if (union_area == 0) {
        return 0.0f; // 并集面积为 0，IoU 无定义，返回 0
    }

    // 计算 IOU 值
    float iou = intersection_area / union_area;
    return iou;
}



float Kit::CIou(const cv::RotatedRect &rect_one, const cv::RotatedRect &rect_two) {
    // 计算两个矩形的中心点距离
    float dist_center = cv::norm(rect_one.center - rect_two.center);

    // 计算两个矩形的交集部分
    cv::Rect intersect_rect = rect_one.boundingRect() & rect_two.boundingRect();
    float intersection_area = intersect_rect.area();

    // 计算两个矩形的并集部分
    float box1_area = rect_one.size.width * rect_one.size.height;
    float box2_area = rect_two.size.width * rect_two.size.height;
    float union_area = box1_area + box2_area - intersection_area;

    // 计算两个矩形的外接矩形
    cv::Rect enclosing_rect = rect_one.boundingRect() | rect_two.boundingRect();
    float enclose_area = enclosing_rect.area();

    // 计算 IoU
    float iou = intersection_area / union_area;

    // 计算 CIoU
    float cious = iou - pow((dist_center / enclose_area), 2);

    return cious;
}

