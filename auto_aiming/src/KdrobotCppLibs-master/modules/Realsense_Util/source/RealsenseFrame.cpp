/**
 * @file RealsenseFrame.cpp
 * @author yao
 * @date 2021年2月2日
 */

#include "RealsenseFrame.h"
#include <memory>

RealsenseFrame::RealsenseFrame(const rs2::frameset &frameset) :
        ColorImageSize(frameset.get_color_frame().get_width(), frameset.get_color_frame().get_height()),
        DepthImageSize(frameset.get_color_frame().get_width(), frameset.get_color_frame().get_height()),
        ColorImage(ColorImageSize, CV_8UC3, (void *) frameset.get_color_frame().get_data(),
                   cv::Mat::AUTO_STEP),
        DepthImage(DepthImageSize, CV_16UC1, (void *) frameset.get_depth_frame().get_data(),
                   cv::Mat::AUTO_STEP) {
    timestamp = frameset.get_timestamp();
    frame_number = frameset.get_frame_number();
}

RealsenseFrame::RealsenseFrame(const RealsenseFrame &c) :
        ColorImage(c.ColorImage.clone()), DepthImage(c.DepthImage.clone()) {
    timestamp = c.timestamp;
    frame_number = c.frame_number;
}

RealsenseFrame::RealsenseFrame(RealsenseFrame &&m) :
        ColorImage(std::move(m.ColorImage)), DepthImage(std::move(m.DepthImage)) {
    timestamp = m.timestamp;
    frame_number = m.frame_number;
}

RealsenseFrame RealsenseFrame::operator=(const RealsenseFrame &c) {
    DepthImage = c.DepthImage;
    ColorImage = c.ColorImage;
    timestamp = c.timestamp;
    frame_number = c.frame_number;
    return *this;
}