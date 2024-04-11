/**
 * @file coordinate.cpp
 * @author yao
 * @date 2021年2月2日
 */

#include "coordinate.h"
#include <math.h>

Sphe_COORD::Sphe_COORD(float _r, float _theta, float _phi) {
    r = _r;
    theta = _theta;
    phi = _phi;
}

Sphe_COORD Sphe_COORD::operator=(const Rect_COORD &R2S) {
    Rect_COORD Temp(R2S.z, -R2S.x, -R2S.y);
    this->r = sqrt(pow(Temp.x, 2) + pow(Temp.y, 2) + pow(Temp.z, 2));
    this->theta = atan(sqrt(pow(Temp.x, 2) + pow(Temp.y, 2)) / Temp.z);
    float atan_xy = atan(Temp.y / Temp.x);
    if (Temp.x < 0)
        atan_xy += CV_PI;
    this->phi = atan_xy;
    return *this;
}

float Rect_COORD::distence(const Rect_COORD &A, const Rect_COORD &B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2) + pow(A.z - B.z, 2));
}

Rect_COORD Rect_COORD::operator=(const Sphe_COORD &S2R) {
    Rect_COORD Temp;
    Temp.x = S2R.r * sin(S2R.theta) * cos(S2R.phi);
    Temp.y = S2R.r * sin(S2R.theta) * sin(S2R.phi);
    Temp.z = S2R.r * cos(S2R.theta);

    //坐标系转换有方向问题，在下半画面的时候符号相反
    if (Temp.x < 0) {
        this->x = Temp.y;
        this->y = Temp.z;
        this->z = -Temp.x;
        return *this;
    }
    this->x = -Temp.y;
    this->y = -Temp.z;
    this->z = Temp.x;
    return *this;
}

float Rect_COORD::distence(const Rect_COORD &A) {
    return distence(*this, A);
}

EulerAngle::EulerAngle(float _Pitch, float _Yaw, float _Roll) {
    Pitch = _Pitch;
    Yaw = _Yaw;
    Roll = _Roll;
}

EulerAngle::EulerAngle(const EulerAngle &Copy) {
    Pitch = Copy.Pitch;
    Yaw = Copy.Yaw;
    Roll = Copy.Roll;
}

EulerAngle EulerAngle::operator+(const EulerAngle &add) {
    EulerAngle Temp;
    Temp.Pitch = this->Pitch + add.Pitch;
    Temp.Yaw = this->Yaw + add.Yaw;
    Temp.Roll = this->Roll + add.Roll;
    return Temp;
}

EulerAngle EulerAngle::operator-(const EulerAngle &sub) {
    EulerAngle Temp;
    Temp.Pitch = this->Pitch - sub.Pitch;
    Temp.Yaw = this->Yaw - sub.Yaw;
    Temp.Roll = this->Roll - sub.Roll;
    return Temp;
}

const EulerAngle &EulerAngle::operator=(const EulerAngle &equ) {
    this->Pitch = equ.Pitch;
    this->Roll = equ.Roll;
    this->Yaw = equ.Yaw;
    return *this;
}
