#include <adjustcamera.h>

Camera::Camera() {
    m_handle = nullptr;
    m_if_exit = true;
    m_return_data = MV_OK;
    m_image_data_size = 0;
    m_image_cache = (unsigned char*)malloc(1280 *960 * 4 + 2048);
    m_device_info = nullptr;
    m_device_list = {0};
    m_param = {0};
    memset(&m_param, 0, sizeof(MVCC_INTVALUE));
    m_out_frame = {0};
    memset(&m_out_frame, 0, sizeof(MV_FRAME_OUT));
    m_cvt_param = {0};

}
void Camera::OpenCamera(const float &exposurenumber) {
    m_device_list = {};
    m_return_data = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &m_device_list);
    if (m_return_data != MV_OK) {
        std::cout << "enum error" << std::endl;
    }
    if (m_device_list.nDeviceNum > 0) {
        for (int i = 0; i < m_device_list.nDeviceNum; i++) {
            m_device_info = m_device_list.pDeviceInfo[i];
            if (m_device_info == nullptr) {
                break;
            }
            PrintDeviceInfo();
        }
    } else {
        std::cout << "no find device" << std::endl;
    }
    unsigned int index = 0;
    m_return_data = MV_CC_CreateHandle(&m_handle, m_device_list.pDeviceInfo[index]);
    if (m_return_data != MV_OK) {
        std::cout << "fail to create handle" << std::endl;
    } else if (m_return_data == MV_OK) {
        MV_CC_OpenDevice(m_handle);
    }
    if (m_device_list.pDeviceInfo[index]->nTLayerType == MV_GIGE_DEVICE) {
        int packet_size = MV_CC_GetOptimalPacketSize(m_handle);
        if (packet_size > 0) {
            MV_CC_SetIntValue(m_handle, "GevSCPSPacketSize", packet_size);
        } else {
            std::cout << "fail get packet size" << std::endl;
        }
    }
        MVCC_ENUMVALUE scan_type = {0}; // 储存相机设备的扫描类型
        MVCC_STRINGVALUE information; // 储存相机设备信息
        MV_CC_GetStringValue(m_handle, "DeviceModelName", &information);
        std::cout<< "DeviceModelName: " << information.chCurValue << std::endl;
        MV_CC_GetStringValue(m_handle, "DeviceVersion", &information);
        std::cout<< "DeviceVersion:\t" << information.chCurValue << std::endl;
        MV_CC_GetEnumValue(m_handle, "DeviceScanType", &scan_type);
        if (scan_type.nCurValue == 0) {
            std::cout << "scantype = " << "Areascan" << std::endl;
        } else {
            std::cout << "scantype = " << "Linescan" << std::endl;
        }

        MV_CC_SetEnumValue(m_handle, "TriggerMode", 0); // 设置触发模式为 0，这可能表示禁用触发模式或设置为软件触发模式。

        MV_CC_SetEnumValue(m_handle, "PixelFormat", 0x0210001F); //设置像素格式为 0x0210001F，这个数值代表着一种特定的像素格式，具体是什么格式需要参考相机设备的文档。

        MV_CC_SetEnumValue(m_handle, "GainAuto", 1); //启用自动增益。

        MV_CC_SetFloatValue(m_handle, "Gamma", 0.8); // 设置 Gamma 值为 0.8。

        MV_CC_SetBoolValue(m_handle, "GammaEnable", 1); //启用 Gamma 校正。

        MV_CC_SetEnumValue(m_handle, "BalanceWhiteAuto", 2); // 设置白平衡模式为自动。

        MV_CC_GetIntValue(m_handle, "PayloadSize", &m_param); //获取图像数据的有效载荷大小，并将结果存储在 m_Param 变量中。

        m_image_data_size = m_param.nCurValue; // 将有效载荷大小保存在全局变量 g_nPayloadSize 中。
        if (exposurenumber == 0 ) {
            std::cout << "auto exposure" << std::endl;
            MV_CC_SetEnumValue(m_handle, "ExposureAuto", 1); // 设置曝光模式为自动。
        } else if (exposurenumber > 0) {
            std::cout << "no auto exposure" << std::endl;
            MV_CC_SetEnumValue(m_handle, "ExposureAuto", 0);
            m_return_data = MV_CC_SetFloatValue(m_handle, "ExposureTime", exposurenumber);
            if (m_return_data != MV_OK) {
                std::cout << "set error" << std::endl;
            } else {
                std::cout << "set ok" << std::endl;
            }
        }
        m_return_data = MV_CC_StartGrabbing(m_handle); // 开始图像采集，并将结果存储在 nRet 变量中。

        if (MV_OK == m_return_data) std::cout << "Start Grabbing !" << std::endl; // 如果采集操作成功，则输出 "Start Grabbing !" 到控制台
}

void Camera::PrintDeviceInfo() {
    if (nullptr == m_device_info)
    {
        std::cout << "null point" << std::endl;
    }
    if (m_device_info->nTLayerType == MV_GIGE_DEVICE)
    {
        int nIp1 = ((m_device_info->SpecialInfo.stGigEInfo.nCurrentIp & 0xff000000) >> 24);
        int nIp2 = ((m_device_info->SpecialInfo.stGigEInfo.nCurrentIp & 0x00ff0000) >> 16);
        int nIp3 = ((m_device_info->SpecialInfo.stGigEInfo.nCurrentIp & 0x0000ff00) >> 8);
        int nIp4 = (m_device_info->SpecialInfo.stGigEInfo.nCurrentIp & 0x000000ff);
        std::cout << "IP:" << nIp1 << ".camera_class.cpp" << nIp2 << "." << nIp3 << "." << nIp4 << std::endl;
    }
}

void Camera::CloseCamera() {
    int m_return_data = MV_CC_StopGrabbing(m_handle);
    if (m_return_data == MV_OK) {
        std::cout << "stop successfully" << std::endl;
    }
}

void Camera::GetPic(cv::Mat*  srcimg)
{
    // 获取图像缓冲区
    MV_CC_GetImageBuffer(m_handle, &m_out_frame, 400);

    // 设置转换参数
    m_cvt_param.enSrcPixelType = m_out_frame.stFrameInfo.enPixelType;
    m_cvt_param.enDstPixelType = PixelType_Gvsp_RGB8_Packed;
    m_cvt_param.nHeight = m_out_frame.stFrameInfo.nHeight;
    m_cvt_param.nWidth = m_out_frame.stFrameInfo.nWidth;
    m_cvt_param.nDstBufferSize = m_out_frame.stFrameInfo.nWidth * m_out_frame.stFrameInfo.nHeight * 4 + 2048;
    m_cvt_param.pSrcData = m_out_frame.pBufAddr;
    m_cvt_param.pDstBuffer = m_image_cache;
    m_cvt_param.nSrcDataLen = m_out_frame.stFrameInfo.nFrameLen;

    // 转换像素类型
    MV_CC_ConvertPixelType(m_handle, &m_cvt_param);

    // 构建图像
    *srcimg = cv::Mat(m_out_frame.stFrameInfo.nHeight, m_out_frame.stFrameInfo.nWidth, CV_8UC3, m_image_cache);

    // 转换颜色空间
    cv::cvtColor(*srcimg, *srcimg, cv::COLOR_RGB2BGR);

    // 释放图像缓冲区
    if (NULL != m_out_frame.pBufAddr)
    {
        MV_CC_FreeImageBuffer(m_handle, &m_out_frame);
    }
}
