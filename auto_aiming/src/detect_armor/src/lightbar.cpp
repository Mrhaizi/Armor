/*
 * @Author: myq 2127800097@qq.com
 * @Date: 2024-04-04 18:18:39
 * @LastEditors: myq 2127800097@qq.com
 * @LastEditTime: 2024-04-04 19:20:35
 * @FilePath: /detect_armor2/detect_lights/src/detect_lights/src/lightbar.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include <detect_armors.h>
LightBar::LightBar() {
    light_rect = cv::RotatedRect();
    light_angle = 0;
    light_lenth = 0;
    lingt_center = cv::Point2f();
}
LightBar::LightBar(const cv::RotatedRect rotated_rect) {
    light_rect = rotated_rect;
    light_lenth = std::max(rotated_rect.size.height,rotated_rect.size.width);
    lingt_center = rotated_rect.center;
    if (rotated_rect.angle>90) {
        light_angle=rotated_rect.angle-180;
    }else {
        light_angle = rotated_rect.angle;
    }
}

