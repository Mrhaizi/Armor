/**
 * @file RealsenseFrame.h
 * @author yao
 * @date 2021年2月2日
 * @brief Realsense帧对象
 */

#ifndef KDROBOTCPPLIBS_REALSENSEFRAME_H
#define KDROBOTCPPLIBS_REALSENSEFRAME_H

#include <opencv2/opencv.hpp>
#include <librealsense2/rs.hpp>

class RealsenseFrame {
    friend class Realsense;

    cv::Size ColorImageSize, DepthImageSize;
    cv::Mat ColorImage, DepthImage;
    uint64_t frame_number;
    double timestamp; //!<@brief 毫秒单位的时间戳

    RealsenseFrame(const rs2::frameset &frameset);

public:
    RealsenseFrame() = default;

    RealsenseFrame(const RealsenseFrame &c);

    RealsenseFrame(RealsenseFrame &&m);

    RealsenseFrame operator=(const RealsenseFrame &c);

    inline const cv::Mat &getColorImage() const {
        return ColorImage;
    }

    inline const cv::Mat &getDepthImage() const {
        return DepthImage;
    }

    inline uint64_t getFrameNumber() const {
        return frame_number;
    }

    inline double getTimestamp() const {
        return timestamp;
    }

    inline const cv::Size &getColorImageSize() const {
        return ColorImageSize;
    }

    inline const cv::Size &getDepthImageSize() const {
        return DepthImageSize;
    }
};


#endif //KDROBOTCPPLIBS_REALSENSEFRAME_H
