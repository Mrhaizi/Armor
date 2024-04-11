/**
 * @file Realsense.cpp
 * @author yao
 * @date 2021年2月2日
 */

#include <opencv2/opencv.hpp>
#include <librealsense2/rsutil.h>
#include "Realsense.h"

void Realsense::run() {
    logger.info("Realseson Thread Started");

    /* 搜索Realsense摄像头 */
    rs2::context ctx;
    rs2::device_list devices = ctx.query_devices();
    rs2::device selected_device;
    if (devices.size() == 0) {
        logger.error("No device connected, please connect a RealSense device");
        throw std::runtime_error("No device connected, please connect a RealSense device");
    }

    /* 搜索传感器并读取配置文件配置传感器 */
    logger.info("Found the following devices:");
    int index = 0;
    for (rs2::device device : devices) {
        logger.info("\t{} name:'{}'", index++, get_device_name(device));
        for (auto &sensor : device.query_sensors()) {
            QString sensorName = "RealSense/Options/" + QString::fromStdString(get_sensor_name(sensor));
            logger.info("\t\tfind sensor:'{}' supported options:", get_sensor_name(sensor));
            for (const rs2_option &option : sensor.get_supported_options()) {
                double optionCfg = config.findObject(sensorName + '/' + rs2_option_to_string(option)).toDouble(-1);
                if (optionCfg != -1 && sensor.supports(option)) {
                    logger.critical("\t\t\t{:2}: '{}', set the value to '{}' from the configuration file", option,
                                    rs2_option_to_string(option), optionCfg);
                    try {
                        sensor.set_option(option, optionCfg);
                    } catch (rs2::invalid_value_error e) {
                        logger.error("option error: '{}', {}", rs2_option_to_string(option), e.what());
                        throw e;
                    }
                } else {
                    try {
                        logger.info("\t\t\t{:2}: '{}', default value = '{}'", option, rs2_option_to_string(option),
                                    sensor.get_option(option));
                    } catch (rs2::invalid_value_error e) {
                        logger.info("\t\t\t{:2}: '{}', {}", option, rs2_option_to_string(option), e.what());
                    }
                }
            }
        }
    }

    int StreamWidth = config.findInt("RealSense/Width", -1, [](int a) { return a > 0; });
    int StreamHeight = config.findInt("RealSense/Height", -1, [](int a) { return a > 0; });
    int StreamDepthFPS = config.findInt("RealSense/DepthFPS", -1, [](int a) { return a > 0; });
    int StreamColorFPS = config.findInt("RealSense/ColorFPS", -1, [](int a) { return a > 0; });
    bool alignEnable = config.findObject("RealSense/align").toBool();

    /* 创建管道并写入管道配置 */
    rs2::pipeline p;
    rs2::config cfg;
    cfg.disable_all_streams();
    cfg.enable_stream(RS2_STREAM_DEPTH, StreamWidth, StreamHeight, RS2_FORMAT_Z16, StreamDepthFPS);
    cfg.enable_stream(RS2_STREAM_COLOR, StreamWidth, StreamHeight, RS2_FORMAT_BGR8, StreamColorFPS);

    /* 启动管道 */
    rs2::pipeline_profile selection = p.start(cfg);
    auto depth_stream = selection.get_stream(RS2_STREAM_DEPTH).as<rs2::video_stream_profile>();
    auto color_stream = selection.get_stream(RS2_STREAM_COLOR).as<rs2::video_stream_profile>();
    depth_intrinsics = depth_stream.get_intrinsics();
    color_intrinsics = color_stream.get_intrinsics();
    /* 初始化调整滤波器 */
    rs2::align align(RS2_STREAM_COLOR);
    rs2::frameset frames;
    /* 获取并校准图像 */

    while (running) {
        try {
            if (alignEnable) frames = align.process(p.wait_for_frames());
            else frames = p.wait_for_frames();
        } catch (rs2::error e) {
            logger.error("in function '{}', {}", e.get_failed_function(), e.what());
            throw e;
        }
        if (frames.size() == 0) {
            logger.error("frames.size == 0");
            throw std::runtime_error("Realsense: frames.size == 0");
        }
        QMutexLocker lk(&mut);
        buffer = RealsenseFrame(frames);
        (void) ready.try_lock();
        ready.unlock();
    }
}

bool Realsense::waitReady(int time_out) {
    return ready.tryLock(time_out);
}

const RealsenseFrame &Realsense::getFrame() {
    /* Mat缓冲区就绪锁，从缓冲区读取图像之后上锁，新图像到达时解锁 */
    ready.lock();
    /* 缓冲区变量锁 */
    QMutexLocker lk(&mut);
    return buffer;
}

/**
 * Given pixel coordinates and depth in an image with no distortion or inverse distortion
 * coefficients, compute the corresponding point in 3D space relative to the same camera
 * @param intrin 相机参数
 * @param pixel 像素坐标
 * @param depth 深度
 * @return 三维坐标
 */
cv::Point3f Realsense::deproject_pixel_to_point(const rs2_intrinsics &intrin, const cv::Point2f &pixel, float depth) {
    float p3d[3], p2d[2] = {pixel.x, pixel.y};
    rs2_deproject_pixel_to_point(p3d, &intrin, p2d, depth);
    return {p3d[0], p3d[1], p3d[2]};
}

std::string Realsense::get_device_name(const rs2::device &dev) {
    // Each device provides some information on itself, such as name:
    std::string name = "Unknown Device";
    if (dev.supports(RS2_CAMERA_INFO_NAME))
        name = dev.get_info(RS2_CAMERA_INFO_NAME);

    // and the serial number of the device:
    std::string sn = "########";
    if (dev.supports(RS2_CAMERA_INFO_SERIAL_NUMBER))
        sn = std::string("#") + dev.get_info(RS2_CAMERA_INFO_SERIAL_NUMBER);

    return name + " " + sn;
}

std::string Realsense::get_sensor_name(const rs2::sensor &sensor) {
    // Sensors support additional information, such as a human readable name
    if (sensor.supports(RS2_CAMERA_INFO_NAME))
        return sensor.get_info(RS2_CAMERA_INFO_NAME);
    else
        return "Unknown Sensor";
}

Realsense::~Realsense() {
    running = false;
    this->quit();
    this->wait();
    this->exit();
    mut.try_lock();
    ready.try_lock();
    mut.unlock();
    ready.unlock();
}
