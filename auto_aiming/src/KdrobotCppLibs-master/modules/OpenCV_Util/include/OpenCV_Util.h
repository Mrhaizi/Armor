/**
 * @file OpenCV_Util.h
 * @author yao
 * @date 2021年1月13日
 * @brief OpenCV常用算法整理
 */

#ifndef KDROBOTCPPLIBS_OPENCV_UTIL_H
#define KDROBOTCPPLIBS_OPENCV_UTIL_H

#include <opencv2/opencv.hpp>
#include <spdlog/fmt/ostr.h>

/**
 * 点到点距离
 * @tparam T 点数据类型
 * @param a 点A
 * @param b 点B
 * @return 两点间距离
 */
template<typename T>
inline T distenceP2P(const cv::Point_<T> &a, const cv::Point_<T> &b = {0, 0}) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

/**
 * 点到线距离
 * @tparam T 点数据类型
 * @param p 点
 * @param a 线端点A
 * @param b 线端点B
 * @return 点到线距离
 */
template<typename T>
inline T distenceP2L(const cv::Point_<T> &p, const cv::Point_<T> &a, const cv::Point_<T> &b) {
    T l = (b.y - a.y) / (b.x - a.x);
    return fabs(l * p.x - p.y + a.y - l * a.x) / sqrt(l * l + 1);
}

/**
 * 三维点到点距离
 * @tparam T 点数据类型
 * @param a 点A
 * @param b 点B
 * @return 两点间距离
 */
template<typename T>
inline T distence3P2P(const cv::Point3_<T> &a, const cv::Point3_<T> &b = {0, 0, 0}) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2) + std::pow(a.z - b.z, 2));
}

/**
 * 线角度
 * @tparam T 点数据类型
 * @param a 线端点A
 * @param b 线端点B
 * @return 线角度
 */
template<typename T>
inline float lineAngle(const cv::Point_<T> &a, const cv::Point_<T> &b = {0, 0}) {
    cv::Point_<T> l = b - a;
    return std::atan2(l.y, l.x) * 360 / CV_2PI;
}

/**
 * 画旋转矩形
 * @param Img 图像
 * @param rect 旋转矩形
 * @param color 颜色
 * @param thickness 线粗
 * @param lineType 线类型
 * @param shift 坐标点的小数点位数
 */
void drawRotatedRect(cv::InputOutputArray Img, cv::RotatedRect rect, const cv::Scalar &color,
                     int thickness = 1, int lineType = cv::LINE_8, int shift = 0);

/**
 * 基于旋转矩阵的三维空间旋转，绕X轴
 * @see https://zh.wikipedia.org/wiki/%E6%97%8B%E8%BD%AC%E7%9F%A9%E9%98%B5
 * @param point 三维点
 * @param x 弧度表示的绕X轴旋转角度
 * @return 旋转后三维点
 */
cv::Point3f Rotation3D_X(const cv::Point3f &point, float x);

/**
 * 基于旋转矩阵的三维空间旋转，绕Y轴
 * @see https://zh.wikipedia.org/wiki/%E6%97%8B%E8%BD%AC%E7%9F%A9%E9%98%B5
 * @param point 三维点
 * @param y 弧度表示的绕Y轴旋转角度
 * @return 旋转后三维点
 */
cv::Point3f Rotation3D_Y(const cv::Point3f &point, float y);

/**
 * 基于旋转矩阵的三维空间旋转，绕Z轴
 * @see https://zh.wikipedia.org/wiki/%E6%97%8B%E8%BD%AC%E7%9F%A9%E9%98%B5
 * @param point 三维点
 * @param z 弧度表示的绕Z轴旋转角度
 * @return 旋转后三维点
 */
cv::Point3f Rotation3D_Z(const cv::Point3f &point, float z);

/**
 * 基于旋转矩阵的三维空间旋转
 * @see https://zh.wikipedia.org/wiki/%E6%97%8B%E8%BD%AC%E7%9F%A9%E9%98%B5
 * @see Rotation3D_X Rotation3D_Y Rotation3D_Z
 * @param point 三维点
 * @param order 字符串表示的旋转顺序
 *              "XYZ" 表示XYZ顺序旋转
 *              "XY" 表示XY顺序，Z不旋转
 * @param v1 第一个角度
 * @param v2 第二个角度
 * @param v3 第三个角度
 * @return 旋转后三维点
 */
cv::Point3f Rotation3D(const cv::Point3f &point, const char *order, float v1, float v2 = 0, float v3 = 0);

/**
 * 通道一带有偏置的InRange，带有OpenMP多线程加速
 * @note 针对解决HSV颜色空间中红色在0附近不好判断的问题，HSV的H通道范围[0-180)
 * @param Input 输入图像
 * @param offset 通道一偏置
 * @param lowerb 下限
 * @param upperb 上线
 * @param dst 输出图像
 */
void HChannleOffsetInRange(const cv::Mat &Input, int offset, const cv::Scalar &lowerb,
                           const cv::Scalar &upperb, cv::Mat &dst);

template<class _Traits, class T>
inline std::basic_ostream<char, _Traits> &
operator<<(std::basic_ostream<char, _Traits> &os, const cv::Point_<T> &c) {
    return os << "[" << c.x << ", " << c.y << ']';
}

template<class _Traits, class T>
inline std::basic_ostream<char, _Traits> &
operator<<(std::basic_ostream<char, _Traits> &os, const cv::Point3_<T> &c) {
    return os << "[" << c.x << ", " << c.y << ", " << c.z << ']';
}

#endif
