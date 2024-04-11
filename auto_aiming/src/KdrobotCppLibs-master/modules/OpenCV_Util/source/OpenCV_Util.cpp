/**
 * @file OpenCV_Util.cpp
 * @author yao
 * @date 2021年1月13日
 */

#include "OpenCV_Util.h"
#include "omp.h"

void drawRotatedRect(cv::InputOutputArray Img, cv::RotatedRect rect,
                     const cv::Scalar &color, int thickness, int lineType, int shift) {
    cv::Point2f points[4];
    rect.points(points);
    for (int k = 0; k < 4; ++k)
        cv::line(Img, points[k], points[(k + 1) % 4], color, thickness, lineType, shift);
}

cv::Point3f Rotation3D_X(const cv::Point3f &point, float x) {
    float sin_x = sin(x), cos_x = cos(x);
    return {point.x,
            point.y * cos_x + point.z * sin_x,
            point.y * -sin_x + point.z * cos_x};
}

cv::Point3f Rotation3D_Y(const cv::Point3f &point, float y) {
    float sin_y = sin(y), cos_y = cos(y);
    return {point.x * cos_y + point.z * -sin_y,
            point.y,
            point.x * sin_y + point.z * cos_y};
}

cv::Point3f Rotation3D_Z(const cv::Point3f &point, float z) {
    float sin_z = sin(z), cos_z = cos(z);
    return {point.x * cos_z + point.y * sin_z,
            point.x * -sin_z + point.y * cos_z,
            point.z};
}

void HChannleOffsetInRange(const cv::Mat &Input, int offset, const cv::Scalar &lowerb,
                           const cv::Scalar &upperb, cv::Mat &dst) {
    int nr = Input.rows;
    // 将3通道转换为1通道
    int chs = Input.channels();
    int nl = Input.cols * chs;
    dst.create(Input.rows, Input.cols, CV_8U);

    int16_t H_Upper = (int16_t) upperb[0] + offset, H_Lower = (int16_t) lowerb[0] + offset;
    int16_t S_Upper = (int16_t) upperb[1], S_Lower = (int16_t) lowerb[1];
    int16_t V_Upper = (int16_t) upperb[2], V_Lower = (int16_t) lowerb[2];
#pragma omp parallel for
    for (int k = 0; k < nr; k++) {
        // 每一行图像的指针
        const uchar *inData = Input.ptr<uchar>(k);
        uchar *outData = dst.ptr<uchar>(k);
#pragma omp parallel for
        for (int i = 0; i < nl; i += 3) {
            int16_t H = ((int16_t) inData[i] + offset) % 180;
            uint8_t S = inData[i + 1];
            uint8_t V = inData[i + 2];
            outData[i / 3] = (H_Lower <= H && H <= H_Upper &&
                              S_Lower <= S && S <= S_Upper &&
                              V_Lower <= V && V <= V_Upper) ? 0xff : 0x00;
        }
    }
}

cv::Point3f Rotation3D(const cv::Point3f &point, const char *order, float v1, float v2, float v3) {
    cv::Point3f p = point;
    float a[] = {v1, v2, v3};
    for (int i = 0; i < 3 && order[i] != 0; i++) {
        switch (order[i]) {
            case 'x':
            case 'X':
                p = Rotation3D_X(p, a[i]);
                break;
            case 'y':
            case 'Y':
                p = Rotation3D_Y(p, a[i]);
                break;
            case 'z':
            case 'Z':
                p = Rotation3D_Z(p, a[i]);
                break;
            default:
                throw std::invalid_argument("顺序字符串错误");
        }
    }
    return p;
}
