/**
 * @file PNP_Calculate.h
 * @author yao
 * @date 2021年2月2日
 * @brief PNP解算
 */

#ifndef KDROBOTCPPLIBS_PNP_CALCULATE_H
#define KDROBOTCPPLIBS_PNP_CALCULATE_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "coordinate.h"

class PNP_Calculate {
public:

    /**
    * @brief  单目测距类拷贝构造函数
    */
    PNP_Calculate(const PNP_Calculate &Copy);

    /**
    * @brief  单目测距类重载构造函数
    * @param  相机标定XML文件路径字符串
    */
    PNP_Calculate(const std::string XML_PATH);

    /**
    * @brief  单目测距类默认构造函数
    */
    PNP_Calculate();

    /**
    * @brief  初始化单目测距
    * @param  相机标定XML文件路径字符串
    * @retval status
    */
    bool Init(const std::string XML_PATH);

    /**
    * @brief  设置目标大小，单位由标定时设置决定
    * @param  目标高度
    * @param  目标宽度
    */
    void SetTargetSize(double height, double width);

    /**
    * @brief  得到目标空间位置
    * @param  目标空间位置输出引用
    * @param  目标在画面中的四边形2D点集
    * @param  如果设置ROI,ROI的偏移量
    * @retval status
    */
    bool GetSpatialLocation(SpatialLocation &Output, std::vector<cv::Point2f> Points2D,
                            const cv::Point2f &offset = cv::Point2f(0, 0));

    /**
    * @brief  得到目标空间位置重载
    * @retval 目标空间位置
    */
    inline bool GetSpatialLocation(SpatialLocation &Output, const cv::RotatedRect &rect,
                                   const cv::Point &offset = cv::Point(0, 0)) {
        std::vector<cv::Point2f> Points2D(4);
        rect.points(Points2D.data());
        return GetSpatialLocation(Output, Points2D, cv::Point2f(offset));
    }

    /**
    * @brief  得到目标空间位置重载
    * @retval 目标空间位置
    */
    SpatialLocation GetSpatialLocation(void);

private:
    std::string PATH;                   //相机标定XML文件路径

    cv::Mat cameraMatrix;               //相机内参矩阵
    cv::Mat distortion;                 //相机矢量失真系数矩阵

    double TargetHeight;                //目标高度
    double TargetWidth;                 //目标宽度

    std::vector<cv::Point3f> Points3D;  //转化的目标3D点集

    SpatialLocation spatial_location;   //目标空间位置
};


#endif //KDROBOTCPPLIBS_PNP_CALCULATE_H
