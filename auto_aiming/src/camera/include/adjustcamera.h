#ifndef ADJUSTCAMERA_H_INCLUDED
#define ADJUSTCAMERA_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "MvCameraControl.h"
#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/video/video.hpp>
class Camera {
public:
    Camera();
    void PrintDeviceInfo();
    void CloseCamera();
    void OpenCamera(const float &exposurenumber);
    void GetPic(cv::Mat*  srcimg);
private:
    void* m_handle; // 相机句柄
    bool m_if_exit; //是否退出的标志
    int m_return_data; // 返回值
    unsigned int m_image_data_size; // 图像数据大小
    unsigned char *m_image_cache; // 图像数据缓存区
    MV_CC_DEVICE_INFO* m_device_info; // 设备信息指针
    MV_CC_DEVICE_INFO_LIST m_device_list; // 设备列表
    MVCC_INTVALUE m_param; // 参数;
    MV_FRAME_OUT m_out_frame; // 输出帧
    MV_CC_PIXEL_CONVERT_PARAM m_cvt_param; // 像素转换参数
};
#endif