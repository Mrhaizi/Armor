/*
 * @Author: myq 2127800097@qq.com
 * @Date: 2024-04-04 14:36:46
 * @LastEditors: myq 2127800097@qq.com
 * @LastEditTime: 2024-04-05 08:45:59
 * @FilePath: /detect_armor2/detect_lights/src/main1.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved.
 */
#include <QCoreApplication>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <VCOMCOMM.h>
#include <adjustcamera.h>
#include <detect_armors.h>     
#include <adjustcamera.h>
#define SOUREC_PATH "/home/mayuqi/桌面/1.mp4"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  VCOMCOMM port("STMicroelectronics");
  static OpenvinoInference infer("/home/mayuqi/桌面/Armor/auto_aiming/detect_armor_model/opt-0527-001.onnx", "CPU");
  Camera cam;
  // cam.OpenCamera(0);
  cv::Mat read_img;
  cv::VideoCapture cap(SOUREC_PATH);
  Vcomcomm_Data angle_data = {0, 0};

  AllInformation all_information;
  all_information.color = BLUE;
  all_information.color_image_thresold = 100; // 单彩色通道图像的二值化阈值
  all_information.gray_image_thresold = 60; // 灰度图的二值化阈值
  all_information.min_area_light = 6000;      // 最大的灯条面积
  all_information.max_angle_light = 10;     // 最大的灯条角度
  all_information.max_angelediff = 3;       // 最大的左右灯条角度差
  all_information.max_tangent = 10; // 左右灯条中心线与水平的最大tan
  all_information.max_boxlenthdivwidth = 0.8;  // 最大的装甲板长宽比
  all_information.min_boxlenthdivwidth = 0.3; // 最小的装甲板长宽比

  ArmorDetect armor_detect(all_information, infer);
  while (1) {
    cap.read(read_img);
    // cam.GetPic(&read_img);
    if (read_img.empty()) {
      fmt::print("{}读取失败", SOUREC_PATH);
    }
    armor_detect.Run(read_img);
    if (!armor_detect.end_armor.empty()) {
        angle_data.p_angle = armor_detect.information.y_angle;
        angle_data.y_angle = armor_detect.information.p_angle;
        const int angle_data_size = sizeof(angle_data.p_angle) * 3;
        QByteArray data_angle(angle_data_size, '/0');
        memcpy(data_angle.data(), &angle_data, sizeof(angle_data));
        emit port.CrossThreadTransmitSignal(0, 1, data_angle);
      } else {
        // std::cout << "armor is emptye" << std::endl;
      }
  }
  return a.exec();
}