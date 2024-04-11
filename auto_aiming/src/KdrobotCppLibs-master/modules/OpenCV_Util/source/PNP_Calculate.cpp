/**
 * @file PNP_Calculate.cpp
 * @author yao
 * @date 2021年2月2日
 */

#include "PNP_Calculate.h"

PNP_Calculate::PNP_Calculate(const PNP_Calculate &Copy) {
    cameraMatrix = Copy.cameraMatrix;
    distortion = Copy.distortion;
    PATH = Copy.PATH;
    TargetHeight = Copy.TargetHeight;
    TargetWidth = Copy.TargetWidth;

    if (PATH.length())
        Init(PATH);

    if (TargetHeight != 0 && TargetWidth != 0)
        SetTargetSize(TargetHeight, TargetWidth);
}

PNP_Calculate::PNP_Calculate(const std::string XML_PATH) {
    cameraMatrix = cv::Mat::eye(3, 3, CV_64FC1);
    distortion = cv::Mat::zeros(5, 1, CV_64FC1);
    PATH = XML_PATH;
    Init(PATH);
}

PNP_Calculate::PNP_Calculate() {
    cameraMatrix = cv::Mat::eye(3, 3, CV_64FC1);
    distortion = cv::Mat::zeros(5, 1, CV_64FC1);
}

bool PNP_Calculate::Init(const std::string XML_PATH) {
    cv::FileStorage params;
    params.open(XML_PATH, cv::FileStorage::READ);
    if (params.isOpened()) {
        params["camera-matrix"] >> cameraMatrix;
        params["distortion"] >> distortion;
        params.release();
        return true;
    }

    throw std::runtime_error("can't open" + XML_PATH);
}

void PNP_Calculate::SetTargetSize(double height, double width) {
    //按照cv::solvePnP使用方法处理目标大小
    TargetHeight = height;
    TargetWidth = width;

    double half_x = TargetWidth / 2.0;
    double half_y = TargetHeight / 2.0;

    Points3D.clear();

    Points3D.push_back(cv::Point3f((float) -half_x, (float) -half_y, 0.0f));
    Points3D.push_back(cv::Point3f((float) half_x, (float) -half_y, 0.0f));
    Points3D.push_back(cv::Point3f((float) half_x, (float) half_y, 0.0f));
    Points3D.push_back(cv::Point3f((float) -half_x, (float) half_y, 0.0f));
}

bool PNP_Calculate::GetSpatialLocation(SpatialLocation &Output, std::vector<cv::Point2f> Points2D,
                                       const cv::Point2f &offset) {
    if (Points2D.size() < 4)
        return false;

    cv::Point2f lt, ld, rt, rd;

    //对点集按x排序
    auto it = Points2D.begin();
    std::sort(it, it + 4, [](const cv::Point2f &p1, const cv::Point2f &p2) { return p1.x < p2.x; });

    //对点集按y排序
    if (Points2D[0].y < Points2D[1].y) {
        lt = Points2D[0];
        ld = Points2D[1];
    } else {
        lt = Points2D[1];
        ld = Points2D[0];
    }
    if (Points2D[2].y < Points2D[3].y) {
        rt = Points2D[2];
        rd = Points2D[3];
    } else {
        rt = Points2D[3];
        rd = Points2D[2];
    }

    std::vector<cv::Point2f> target2d;

    //加偏置，压入向量
    target2d.push_back(lt + offset); //0
    target2d.push_back(rt + offset); //1
    target2d.push_back(rd + offset); //2
    target2d.push_back(ld + offset); //3

    //PnP解算
    cv::Mat r, trans;
    bool res = cv::solvePnP(Points3D, target2d, cameraMatrix, distortion, r, trans);
    if (res) {
        //对输出进行单位换算，分类
        spatial_location.Pitch = atan(r.at<double>(0, 0)) / CV_2PI * 360;
        spatial_location.Yaw = atan(r.at<double>(0, 1)) / CV_2PI * 360;
        spatial_location.Roll = atan(r.at<double>(0, 2)) / CV_2PI * 360;
        spatial_location.x = trans.at<double>(0, 0);
        spatial_location.y = trans.at<double>(1, 0);
        spatial_location.z = trans.at<double>(2, 0);
        Output = spatial_location;
    }
    return res;
}

SpatialLocation PNP_Calculate::GetSpatialLocation(void) {
    return spatial_location;
}