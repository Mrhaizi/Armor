#ifndef DETECTARMOR_H
#define DETECTARMOR_H
#include <opencv2/opencv.hpp>
#include <vector>
#include <fmt/core.h>
#include <kit.h>
#include <openvino.h>
enum LightColor {
    BLUE,
    RED
};

enum class ArmorType { SMALL, LARGE, INVALID };

struct AllInformation
{
    int color_image_thresold;
    int gray_image_thresold;
    float min_area_light;
	float max_angle_light;
    float  max_angelediff;
    float max_tangent;
    float max_boxlenthdivwidth;
    float min_boxlenthdivwidth;
    LightColor color;
    float y_angle;
    float p_angle;

};



class ImageTrackle
{
public:
    ImageTrackle(const LightColor color,
                const int thresold_gray,
                const int thresold_color);
    cv::Mat TrackleImageSubtract(const cv::Mat &image);// 对图像进行两色通道相减的处理。
    void TrackleImageRGB();// 对图像以RGB形式处理
    void TrackleImageHSV();// 对图像以HSV形式进行处理
public:
    cv::Mat image_trackle_subtract;
    LightColor enemy_color;
    int color_image_thresold;
    int gray_image_thresold;
};



class LightBar 
{
public:
/**
 *@brief: 灯条有参构造函数
 *@param: 椭圆拟合的旋转矩形
 */
    LightBar();
    ~LightBar() = default;
    LightBar(const cv::RotatedRect roatated_rect);
public:
    float light_lenth;
    float light_angle;
    cv::Point2f lingt_center;
    cv::RotatedRect light_rect;
};



class Armor
{
public:

/**
 *@brief: 装甲板的构造函数
 *@param: 左右灯条，构造时计算装甲板的各个数值
 */
    Armor(const LightBar &l_bar,const LightBar &r_bar);
public:
    LightBar armor_l_bar,armor_r_bar;
    cv::Point2f armor_center;
    float armor_lenth;
    float armor_width;
    cv::Point2f left_on_point;
    cv::Mat number_image;
    ArmorType type;
    cv::Point2f left_on;
    cv::Point2f left_under;
    cv::Point2f right_on;
    cv::Point2f right_under;
    cv::Rect2f rect;
};




class LightDetect
{
public:

/**
 *@brief: 检查灯条的方法类
 *@param: 最小灯条面积和最小灯条角度
 */

    LightDetect(const float min_area,const float min_angle);
    
    void DetectEnemyLight(const cv::Mat &image);

    void MatchPreArmor();
public:
    float min_area_light;
	float max_angle_light;
    std::vector<LightBar> lights;// 灯条储存
    std::vector<Armor> pre_armor;// 初拟合装甲板储存
};



class CreateRelArmor
{
public:

/**
 *@brief: 筛选出目标装甲板
 *@param: 用于筛选的四种数据和装甲板
 */

    CreateRelArmor(std::vector<Armor> armor,
                    const cv::Mat &image,
                    float  max_angelediff,
                    float max_tangent,
                    float max_boxlenthdivwidth,
                    float min_boxlenthdivwidth);
/**
 *@brief: 将预装甲板通过筛选匹配为真实的装甲板
 */
    void MatchRelArmor();

    bool ArmorIssuiable(const Armor &armor);

    float GetAnglediff(const Armor &armor);// 计算该装甲板的左右灯条的角度差

    float GetTangent(const Armor &armor);// 计算改装甲板中心线与水平线的tan

    float GetBoxLenthDivWidth(const Armor &armor);// 计算该装甲板的长宽比;

    bool MatchSlotArmor(const Armor &armor);

public:
    std::vector<Armor> rel_armors;// 判断完毕的真正装甲板
    std::vector<Armor> pre_armors;// 未判断的装甲板
    float  max_angelediff;
    float max_tangent;
    float max_boxlenthdivwidth;
    float min_boxlenthdivwidth; 
    cv::Mat now_image;
};
class ArmorDetect
{
public:
    ArmorDetect(const AllInformation &information, const OpenvinoInference &infer);
    bool MatchSlotArmor(const Armor &armor);
/**
 *@brief: 识别装甲板的集成函数
 *@param: 
 */
    void  Run(const cv::Mat &image);

    void DrawArmor();

    void ComputeAngle();
    
    void DeleteFalseArmor(const std::vector<Armor> armor_arr);

    void CreateNumberImage(const cv::Mat &src,  std::vector<Armor> &armors);
    
public:
    cv::Mat trackled_image;
    cv::Mat no_trackle_image;
    AllInformation information;
    std::vector<Armor> end_armor;
    cv::Mat now_image;
    OpenvinoInference infer;
};
#endif