/*
 * pid.cpp
 *
 *  Created on: 2023/10/16
 *  Author: Haruto Tanaka
 */

#include "pid.hpp"

// コンストラクタ：PIDゲインを初期化し、内部変数をリセット
PID::PID(float kp, float ki, float kd) : kp(kp), ki(ki), kd(kd) {
    reset();
}

// PIDコントローラの状態をリセット
void PID::reset() {
    integral = 0;
    prev_value = 0;
}

// PID制御出力を計算
float PID::control(float value) {
    float diff;

    // 積分項を計算
    integral += value;

    // 微分項を計算
    diff = value - prev_value;
    prev_value = value;

    // PID計算式：出力 = Kp * 誤差 + Ki * 積分 + Kd * 微分
    return (value * kp + integral * ki - diff * kd);
}
