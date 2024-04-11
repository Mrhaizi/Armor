/*
 * @Author: myq 2127800097@qq.com
 * @Date: 2024-04-04 18:40:21
 * @LastEditors: myq 2127800097@qq.com
 * @LastEditTime: 2024-04-04 18:54:15
 * @FilePath: /camera_calibration/main.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved.
 */
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// 定义棋盘格的尺寸  是交点
int CHECKERBOARD[2] = {8, 11};

int main()
{
    // 创建矢量以存储每个棋盘图像的三维点矢量
    std::vector<std::vector<cv::Point3f>> objpoints;

    // 创建矢量以存储每个棋盘图像的二维点矢量
    std::vector<std::vector<cv::Point2f>> imgpoints;

    // 为三维点定义世界坐标系
    std::vector<cv::Point3f> objp;
    for (int i = 0; i < CHECKERBOARD[1]; i++)
    {
        for (int j = 0; j < CHECKERBOARD[0]; j++)
        {
            objp.push_back(cv::Point3f(j, i, 0));
        }
    }

    // 提取存储在给定目录中的单个图像的路径
    std::vector<cv::String> images;

    // 包含棋盘图像的文件夹的路径
    std::string path = "/home/mayuqi/图片/demo/*.bmp";

    // 使用glob函数读取所有图像的路径
    cv::glob(path, images);

    cv::Mat frame, gray;
    // 存储检测到的棋盘转角像素坐标的矢量
    std::vector<cv::Point2f> corner_pts;
    bool success;

    // 循环读取图像
    for (int i{0}; i < images.size(); i++)
    {
        frame = cv::imread(images[i]);
        if (frame.empty())
        {
            continue;
        }
        if (i == 40)
        {
            int b = 1;
        }
        cout << "the current image is " << i << "th" << endl;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

        // 寻找角点
        success = cv::findChessboardCorners(gray, cv::Size(CHECKERBOARD[0], CHECKERBOARD[1]), corner_pts, CALIB_CB_ADAPTIVE_THRESH | CALIB_CB_FAST_CHECK | CALIB_CB_NORMALIZE_IMAGE);

        // 如果检测到所需数量的角点，我们将细化像素坐标并将其显示在棋盘图像上
        if (success)
        {

            cv::TermCriteria criteria(TermCriteria::EPS | TermCriteria::Type::MAX_ITER, 30, 0.001);

            // 为给定的二维点细化像素坐标
            cv::cornerSubPix(gray, corner_pts, cv::Size(11, 11), cv::Size(-1, -1), criteria);

            // 在棋盘上显示检测到的角点
            cv::drawChessboardCorners(frame, cv::Size(CHECKERBOARD[0], CHECKERBOARD[1]), corner_pts, success);

            objpoints.push_back(objp);
            imgpoints.push_back(corner_pts);
        }
    }

    cv::destroyAllWindows();

    cv::Mat cameraMatrix, distCoeffs, R, T;

    // 通过传递已知3D点（objpoints）的值和检测到的角点（imgpoints）的相应像素坐标来执行相机校准
    cv::calibrateCamera(objpoints, imgpoints, cv::Size(gray.rows, gray.cols), cameraMatrix, distCoeffs, R, T);

    // 内参矩阵
    std::cout << "cameraMatrix : " << cameraMatrix << std::endl;
    // 透镜畸变系数
    std::cout << "distCoeffs : " << distCoeffs << std::endl;
    // rvecs
    std::cout << "Rotation vector : " << R << std::endl;
    // tvecs
    std::cout << "Translation vector : " << T << std::endl;

    return 0;
}
