/*
 *  pid.hpp
 *
 *  Created on: 2023/10/16
 *  Author: Haruto Tanaka
 */

#pragma once

class PID {
public:
    // コンストラクタ：PIDゲインを初期化
    PID(float kp, float ki, float kd);
    
    // PIDコントローラの状態をリセット
    void reset();

    // PID制御出力を計算
    float control(float value);

private:
    // PIDゲイン
    float kp;
    float ki;
    float kd;

    // 内部変数
    float integral;
    float prev_value;
};
