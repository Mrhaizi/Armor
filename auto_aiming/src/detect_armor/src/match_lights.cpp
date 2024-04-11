#include <detect_armors.h>
#include <vector>
#define LINE_COLOR cv::Scalar(0,255,0)
ImageTrackle::ImageTrackle(const LightColor color,
                            const int thresold_gray,
                            const int thresold_color) {
    color_image_thresold = thresold_color;
    gray_image_thresold = thresold_gray;
    enemy_color = color;
}
cv::Mat ImageTrackle::TrackleImageSubtract(const cv::Mat &image) {
    cv::Mat img_color,img_subtract,kernel_a,kernel_b,img_gray;
    image.copyTo(img_color);// 要进行相减操作的彩色图像的拷贝
    image.copyTo(img_gray);// 要进行取交集操作的灰度图像的拷贝
    std::vector<cv::Mat> split_img;
    cv::split(img_color,split_img);
    if (enemy_color == BLUE) {
        img_subtract = split_img[0]-split_img[2];

    } else {
        img_subtract = split_img[2]-split_img[0];
    }
    cv::cvtColor(img_gray,img_gray,10);
    cv::threshold(img_gray,img_gray,gray_image_thresold,255,0);
    cv::threshold(img_subtract,img_subtract,color_image_thresold,255,0);
    cv::bitwise_and(img_gray,img_subtract,img_subtract);
    kernel_b = cv::getStructuringElement(2,cv::Size(3,3));
    cv::morphologyEx(img_subtract,img_subtract,1,kernel_b,cv::Point(-1,-1),3);
    cv::imshow("灰度图",img_subtract);
    return img_subtract;
}
LightDetect::LightDetect(const float min_area,const float max_angle) {
    min_area_light = min_area;
    max_angle_light = max_angle;
}
void LightDetect::DetectEnemyLight(const cv::Mat &image) {
    cv::Mat img_contours;
    image.copyTo(img_contours);
    std::vector<std::vector<cv::Point>> contours; // 存放临时轮廓的vector向量
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(img_contours,contours,hierarchy,0,2);
    cv::RotatedRect rotated_rect;// 拟合由灯条轮廓匹配的椭圆得来的旋转矩形
    LightBar light;
    for (const auto &contour : contours) {
        if (contour.size() < 6) {
            continue;
        }
        if (cv::contourArea(contour) > min_area_light) {
            continue;
        }
        rotated_rect = cv::fitEllipse(contour);// 用匹配的椭圆拟合旋转矩形

        light = LightBar(rotated_rect);
        if (abs(light.light_angle) > max_angle_light) {
            continue;;
        }
        lights.push_back(light);
        }
        if (lights.size()>1) {
        for (int i = 0; i < lights.size(); i++) {
            for (int j = i+1; j < lights.size(); j++) {
                LightBar temporay_light;
                if (lights[i].lingt_center.x > lights[j].lingt_center.x) {
                    temporay_light = lights[j];
                    lights[j] = lights[i];
                    lights[i] = temporay_light;
                }
            }
        }
        }
}
void LightDetect::MatchPreArmor() {
    if (lights.size()>1) {
        for (int i = 0; i < lights.size(); i++) {
            for (int j = i+1; j < lights.size(); j++) {
                pre_armor.push_back(Armor(lights[i],lights[j]));
                }
            }
        }
    }



  