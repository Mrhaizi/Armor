/**
 * @file coordinate.h
 * @author yao
 * @date 2021年2月2日
 * @brief 坐标系定义
 */

#ifndef KDROBOTCPPLIBS_COORDINATE_H
#define KDROBOTCPPLIBS_COORDINATE_H

#include "opencv2/opencv.hpp"
#include <iostream>
#include "spdlog/fmt/ostr.h"

#define Deg2Ran(_Deg_) ((_Deg_) * CV_2PI / 360)  //!<@brief 角度转弧度
#define Ran2Deg(_Ran_) ((_Ran_) / CV_2PI * 360)  //!<@brief 弧度转角度

class EulerAngle;
class Rect_COORD;

/**
 * 球坐标系类
 * 面同镜头方向，上为z轴正方向，前为x轴正方向，左为y轴正方向
 */
class Sphe_COORD : public cv::Point3f {
public:
    float &r = x;      //!<@brief 径向距离别名
    float &theta = y;  //!<@brief 仰角、极角别名
    float &phi = z;    //!<@brief 方位角别名

    using cv::Point3f::Point3f;

    /**
    * @brief  重载构造函数
    * @param  初始化r
    * @param  初始化theta
    * @param  初始化phi
    */
    Sphe_COORD(float _r, float _theta, float _phi);

    Sphe_COORD operator=(const Rect_COORD &R2S);

    /**
     * @brief 重载输出流运算符模板
     */
    template<class _Traits>
    friend inline std::basic_ostream<char, _Traits> &operator<<(std::basic_ostream<char, _Traits> &os, const Sphe_COORD &out) {
        return os << "[Sphe(tPr):" << out.theta << ',' << out.phi << ',' << out.r << ']';
    }
};

/**
 * 空间直角坐标系类
 * 以画面坐标系为准，面同镜头方向，下位y轴正方向，右为x轴正方向，前为z轴正方向
 */
class Rect_COORD : public cv::Point3f {
public:
    using cv::Point3f::Point3f;

    /**
    * @brief  求两点距离静态函数
    * @param  A点
    * @param  B点
    * @retval 距离
    */
    static float distence(const Rect_COORD &A, const Rect_COORD &B);

    float distence(const Rect_COORD &A);

    /**
    * @brief  重载运算符= 坐标系换算，球坐标系到空间直角坐标系
    * @param  球坐标系
    * @retval 本身
    */
    Rect_COORD operator=(const Sphe_COORD &S2T);

    /**
     * @brief 重载输出流运算符模板
     */
    template<class _Traits>
    friend inline std::basic_ostream<char, _Traits> &operator<<(std::basic_ostream<char, _Traits> &os, const Rect_COORD &out) {
        return os << "[Rect(XYZ):" << out.x << ',' << out.y << ',' << out.z << ']';
    }
};

/**
 * 欧拉角类
 */
class EulerAngle {
public:
    float Pitch;
    float Yaw;
    float Roll;

    /**
    * @brief  默认构造函数
    */
    EulerAngle() { Pitch = Yaw = Roll = 0; }

    /**
    * @brief  重载构造函数
    * @param  初始化Pitch
    * @param  初始化Yaw
    * @param  初始化Roll
    */
    EulerAngle(float _Pitch, float _Yaw, float _Roll);

    /**
    * @brief  拷贝构造函数
    */
    EulerAngle(const EulerAngle &Copy);

    /**
    * @brief  重载运算符+ 两欧拉角相加
    * @param  加数
    * @retval 本身
    */
    EulerAngle operator+(const EulerAngle &add);

    /**
    * @brief  重载运算符- 两欧拉角相减
    * @param  减数
    * @retval 本身
    */
    EulerAngle operator-(const EulerAngle &sub);

    /**
    * @brief  重载运算符=
    * @param
    * @retval 本身
    */
    const EulerAngle &operator=(const EulerAngle &equ);

    /**
     * @brief 重载输出流运算符模板
     */
    template<class _Traits>
    friend inline std::basic_ostream<char, _Traits> &operator<<(std::basic_ostream<char, _Traits> &os, const EulerAngle &out) {
        return os << "[Eural(YPR):" << out.Yaw << ',' << out.Pitch << ',' << out.Roll << ']';
    }
};

/**
 * 6维空间坐标系类(继承EulerAngle,Rect_COORD)
 */
class SpatialLocation : public EulerAngle, public Rect_COORD {
public:
    SpatialLocation() = default;

    SpatialLocation(const SpatialLocation &Copy) = default;

    /**
    * @brief  使用继承的重载构造函数
    */
    SpatialLocation(float _x, float _y, float _z, float _Pitch, float _Yaw, float _Roll) :
            EulerAngle(_Pitch, _Yaw, _Roll), Rect_COORD(_x, _y, _z) {}

    /**
    * @brief  重载运算符=
    * @param
    * @retval 本身
    */
    const SpatialLocation &operator=(const SpatialLocation &equ) {
        this->Pitch = equ.Pitch;
        this->Roll = equ.Roll;
        this->Yaw = equ.Yaw;
        this->x = equ.x;
        this->y = equ.y;
        this->z = equ.z;
        return *this;
    }

    /**
     * @brief 重载输出流运算符模板
     */
    template<class _Traits>
    friend inline std::basic_ostream<char, _Traits> &operator<<(std::basic_ostream<char, _Traits> &os, const SpatialLocation &location) {
        os << '[' << static_cast<const EulerAngle &>(location) << ' '
           << static_cast<const Rect_COORD &>(location) << ']';
        return os;
    }
};

#endif //KDROBOTCPPLIBS_COORDINATE_H
