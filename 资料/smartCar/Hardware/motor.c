/*
 * @Author       : Shannon
 * @Date         : 2023-02-14 14:10:29
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-21 23:10:32
 * @FilePath     : \0000smartCar\Hardware\motor.c
 * @Description  : Drivers for the motors
 * Copyright (c) 2023 by Shannon, All Rights Reserved. 
 */
#include "motor.h"

/**
 * @description: Motor GPIOs initialization
 * @return {*}
 */
void motor_init(void)
{
    // 左前轮
    // 开启时钟
    rcu_periph_clock_enable(RCU_MOTOR_LF_F);
    // 输出模式 浮空
    gpio_mode_set(PORT_MOTOR_LF_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LF_F);
    // 推挽输出 最快输出频率50MHZ
    gpio_output_options_set(PORT_MOTOR_LF_F, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_MOTOR_LF_F);
    // 引脚置0
    gpio_bit_reset(PORT_MOTOR_LF_F, PIN_MOTOR_LF_F);
    // 开启复用功能
    gpio_af_set(PORT_MOTOR_LF_F, TIMER2, PIN_MOTOR_LF_F);
    // 开启时钟
    rcu_periph_clock_enable(RCU_MOTOR_LF_B);
    // 输出模式 浮空
    gpio_mode_set(PORT_MOTOR_LF_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LF_B);
    // 推挽输出 最快输出频率50MHZ
    gpio_output_options_set(PORT_MOTOR_LF_B, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_MOTOR_LF_B);
    // 引脚置0
    gpio_bit_reset(PORT_MOTOR_LF_B, PIN_MOTOR_LF_B);
    // 开启复用功能
    gpio_af_set(PORT_MOTOR_LF_B, TIMER2, PIN_MOTOR_LF_B);

    // 右前轮
    // 开启时钟
    rcu_periph_clock_enable(RCU_MOTOR_RF_F);
    // 输出模式 浮空
    gpio_mode_set(PORT_MOTOR_RF_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RF_F);
    // 推挽输出 最快输出频率50MHZ
    gpio_output_options_set(PORT_MOTOR_RF_F, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_MOTOR_RF_F);
    // 引脚置0
    gpio_bit_reset(PORT_MOTOR_RF_F, PIN_MOTOR_RF_F);
    // 开启复用功能
    gpio_af_set(PORT_MOTOR_RF_F, TIMER1, PIN_MOTOR_RF_F);
    // 开启时钟
    rcu_periph_clock_enable(RCU_MOTOR_RF_B);
    // 输出模式 浮空
    gpio_mode_set(PORT_MOTOR_RF_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RF_B);
    // 推挽输出 最快输出频率50MHZ
    gpio_output_options_set(PORT_MOTOR_RF_B, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_MOTOR_RF_B);
    // 引脚置0
    gpio_bit_reset(PORT_MOTOR_RF_B, PIN_MOTOR_RF_B);
    // 开启复用功能
    gpio_af_set(PORT_MOTOR_RF_B, TIMER1, PIN_MOTOR_RF_B);

    // 左后轮
    // 开启时钟
    rcu_periph_clock_enable(RCU_MOTOR_LB_F);
    // 输出模式 浮空
    gpio_mode_set(PORT_MOTOR_LB_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LB_F);
    // 推挽输出 最快输出频率50MHZ
    gpio_output_options_set(PORT_MOTOR_LB_F, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_MOTOR_LB_F);
    // 引脚置0
    gpio_bit_reset(PORT_MOTOR_LB_F, PIN_MOTOR_LB_F);
    // 开启复用功能
    gpio_af_set(PORT_MOTOR_LB_F, TIMER2, PIN_MOTOR_LB_F);
    // 开启时钟
    rcu_periph_clock_enable(RCU_MOTOR_LB_B);
    // 输出模式 浮空
    gpio_mode_set(PORT_MOTOR_LB_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LB_B);
    // 推挽输出 最快输出频率50MHZ
    gpio_output_options_set(PORT_MOTOR_LB_B, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_MOTOR_LB_B);
    // 引脚置0
    gpio_bit_reset(PORT_MOTOR_LB_B, PIN_MOTOR_LB_B);
    // 开启复用功能
    gpio_af_set(PORT_MOTOR_LB_B, TIMER2, PIN_MOTOR_LB_B);

    // 右前轮
    // 开启时钟
    rcu_periph_clock_enable(RCU_MOTOR_RB_F);
    // 输出模式 浮空
    gpio_mode_set(PORT_MOTOR_RB_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RB_F);
    // 推挽输出 最快输出频率50MHZ
    gpio_output_options_set(PORT_MOTOR_RB_F, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_MOTOR_RB_F);
    // 引脚置0
    gpio_bit_reset(PORT_MOTOR_RB_F, PIN_MOTOR_RB_F);
    // 开启复用功能
    gpio_af_set(PORT_MOTOR_RB_F, TIMER1, PIN_MOTOR_RB_F);
    // 开启时钟
    rcu_periph_clock_enable(RCU_MOTOR_RB_B);
    // 输出模式 浮空
    gpio_mode_set(PORT_MOTOR_RB_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RB_B);
    // 推挽输出 最快输出频率50MHZ
    gpio_output_options_set(PORT_MOTOR_RB_B, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_MOTOR_RB_B);
    // 引脚置0
    gpio_bit_reset(PORT_MOTOR_RB_B, PIN_MOTOR_RB_B);
    // 开启复用功能
    gpio_af_set(PORT_MOTOR_RB_B, TIMER1, PIN_MOTOR_RB_B);
}

/**
 * @description: Go forward
 * @return {*}
 */
void motor_front(void)
{
    // 左前
    LF_F = 1; // 1-0表示前进
    LF_B = 0;
    // 右前
    RF_F = 1;
    RF_B = 0;
    // 左后
    LB_F = 1;
    LB_B = 0;
    // 右后
    RB_F = 1;
    RB_B = 0;
}

/**
 * @description: Go back
 * @return {*}
 */
void motor_back(void)
{
    // 左前
    LF_F = 0; // 0-1表示后退
    LF_B = 1;
    // 右前
    RF_F = 0;
    RF_B = 1;
    // 左后
    LB_F = 0;
    LB_B = 1;
    // 右后
    RB_F = 0;
    RB_B = 1;
}

/**
 * @description: Turn left
 * @return {*}
 */
void motor_left(void)
{
    // 左边的轮子后退，右边的轮子前进，就可以左转
    // 左前
    LF_F = 0;
    LF_B = 1;
    // 右前
    RF_F = 1;
    RF_B = 0;
    // 左后
    LB_F = 0;
    LB_B = 1;
    // 右后
    RB_F = 1;
    RB_B = 0;
}

/**
 * @description: Turn right
 * @return {*}
 */
void motor_right(void)
{
    // 右边的轮子后退，左边的轮子前进，就可以右转
    // 左前
    LF_F = 1;
    LF_B = 0;
    // 右前
    RF_F = 0;
    RF_B = 1;
    // 左后
    LB_F = 1;
    LB_B = 0;
    // 右后
    RB_F = 0;
    RB_B = 1;
}

/**
 * @description: Stop
 * @return {*}
 */
void motor_stop(void)
{
    // 左前
    LF_F = 1; // 1-1:刹车停止    0-0:熄火停止
    LF_B = 1;
    // 右前
    RF_F = 1;
    RF_B = 1;
    // 左后
    LB_F = 1;
    LB_B = 1;
    // 右后
    RB_F = 1;
    RB_B = 1;
}


/* 左前轮 */
/**
 * @description: 左前轮PWM前进
 * @param {uint16_t} speed: 0~9999
 * @return {*}
 */
void motor_lf_forward(uint16_t speed)
{
    // 前进引脚 设置为PWM输出
    gpio_mode_set(PORT_MOTOR_LF_F, GPIO_MODE_AF, GPIO_PUPD_NONE, PIN_MOTOR_LF_F);
    timer_channel_output_pulse_value_config(TIMER_MOTOR_LF_F, CH_MOTOR_LF_F, speed);

    // 后退引脚 置0
    gpio_mode_set(PORT_MOTOR_LF_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LF_B);
    LF_B = 0;
}
/**
 * @description: 左前轮PWM后退
 * @param {uint16_t} speed: 0~9999
 * @return {*}
 */
void motor_lf_backward(uint16_t speed)
{
    // 前进引脚 置0
    gpio_mode_set(PORT_MOTOR_LF_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LF_F);
    LF_F = 0;
    // 后退引脚 设置为PWM输出
    gpio_mode_set(PORT_MOTOR_LF_B, GPIO_MODE_AF, GPIO_PUPD_NONE, PIN_MOTOR_LF_B);
    timer_channel_output_pulse_value_config(TIMER_MOTOR_LF_B, CH_MOTOR_LF_B, speed);
}
/**
 * @description: 左前轮停止
 * @param {uint8_t} mode: 停止方式，0熄火 1刹车
 * @return {*}
 */
void motor_lf_stop(uint8_t mode)
{
    if(mode)
    {
        gpio_mode_set(PORT_MOTOR_LF_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LF_F);
        LF_F = 1;
        gpio_mode_set(PORT_MOTOR_LF_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LF_B);
        LF_B = 1;
    }
    else
    {
        gpio_mode_set(PORT_MOTOR_LF_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LF_F);
        LF_F = 0;
        gpio_mode_set(PORT_MOTOR_LF_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LF_B);
        LF_B = 0;
    }
}


/* 左后轮 */
/**
 * @description: 左后轮PWM前进
 * @param {uint16_t} speed: 0~9999
 * @return {*}
 */
void motor_lb_forward(uint16_t speed)
{
    // 前进引脚 设置为PWM输出
    gpio_mode_set(PORT_MOTOR_LB_F, GPIO_MODE_AF, GPIO_PUPD_NONE, PIN_MOTOR_LB_F);
    timer_channel_output_pulse_value_config(TIMER_MOTOR_LB_F, CH_MOTOR_LB_F, speed);
    // 后退引脚 置0
    gpio_mode_set(PORT_MOTOR_LB_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LB_B);
    LF_B = 0;
}
/**
 * @description: 左后轮PWM后退
 * @param {uint16_t} speed: 0~9999
 * @return {*}
 */
void motor_lb_backward(uint16_t speed)
{
    // 前进引脚 置0
    gpio_mode_set(PORT_MOTOR_LB_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LB_F);
    LF_F = 0;
    // 后退引脚 设置为PWM输出
    gpio_mode_set(PORT_MOTOR_LB_B, GPIO_MODE_AF, GPIO_PUPD_NONE, PIN_MOTOR_LB_B);
    timer_channel_output_pulse_value_config(TIMER_MOTOR_LB_B, CH_MOTOR_LB_B, speed);
}
/**
 * @description: 左后轮停止
 * @param {uint8_t} mode: 停止方式，0熄火 1刹车
 * @return {*}
 */
void motor_lb_stop(uint8_t mode)
{
    if(mode)
    {
        gpio_mode_set(PORT_MOTOR_LB_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LB_F);
        LB_F = 1;
        gpio_mode_set(PORT_MOTOR_LB_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LB_B);
        LB_B = 1;
    }
    else
    {
        gpio_mode_set(PORT_MOTOR_LB_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LB_F);
        LB_F = 0;
        gpio_mode_set(PORT_MOTOR_LB_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_LB_B);
        LB_B = 0;
    }
}

/* 右前轮 */
/**
 * @description: 右前轮PWM前进
 * @param {uint16_t} speed: 0~9999
 * @return {*}
 */
void motor_rf_forward(uint16_t speed)
{
    // 前进引脚 设置为PWM输出
    gpio_mode_set(PORT_MOTOR_RF_F, GPIO_MODE_AF, GPIO_PUPD_NONE, PIN_MOTOR_RF_F);
    timer_channel_output_pulse_value_config(TIMER_MOTOR_RF_F, CH_MOTOR_RF_F, speed);
    // 后退引脚 置0
    gpio_mode_set(PORT_MOTOR_RF_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RF_B);
    LF_B = 0;
}
/**
 * @description: 右前轮PWM后退
 * @param {uint16_t} speed: 0~9999
 * @return {*}
 */
void motor_rf_backward(uint16_t speed)
{
    // 前进引脚 置0
    gpio_mode_set(PORT_MOTOR_RF_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RF_F);
    LF_F = 0;
    // 后退引脚 设置为PWM输出
    gpio_mode_set(PORT_MOTOR_RF_B, GPIO_MODE_AF, GPIO_PUPD_NONE, PIN_MOTOR_RF_B);
    timer_channel_output_pulse_value_config(TIMER_MOTOR_RF_B, CH_MOTOR_RF_B, speed);
}
/**
 * @description: 右前轮停止
 * @param {uint8_t} mode: 停止方式，0熄火 1刹车
 * @return {*}
 */
void motor_rf_stop(uint8_t mode)
{
    if(mode)
    {
        gpio_mode_set(PORT_MOTOR_RF_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RF_F);
        RF_F = 1;
        gpio_mode_set(PORT_MOTOR_RF_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RF_B);
        RF_B = 1;
    }
    else
    {
        gpio_mode_set(PORT_MOTOR_RF_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RF_F);
        RF_F = 0;
        gpio_mode_set(PORT_MOTOR_RF_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RF_B);
        RF_B = 0;
    }
}


/* 右后轮 */
/**
 * @description: 右后轮PWM前进
 * @param {uint16_t} speed: 0~9999
 * @return {*}
 */
void motor_rb_forward(uint16_t speed)
{
    // 前进引脚 设置为PWM输出
    gpio_mode_set(PORT_MOTOR_RB_F, GPIO_MODE_AF, GPIO_PUPD_NONE, PIN_MOTOR_RB_F);
    timer_channel_output_pulse_value_config(TIMER_MOTOR_RB_F, CH_MOTOR_RB_F, speed);
    // 后退引脚 置0
    gpio_mode_set(PORT_MOTOR_RB_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RB_B);
    LF_B = 0;
}
/**
 * @description: 右后轮PWM后退
 * @param {uint16_t} speed: 0~9999
 * @return {*}
 */
void motor_rb_backward(uint16_t speed)
{
    // 前进引脚 置0
    gpio_mode_set(PORT_MOTOR_RB_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RB_F);
    LF_F = 0;
    // 后退引脚 设置为PWM输出
    gpio_mode_set(PORT_MOTOR_RB_B, GPIO_MODE_AF, GPIO_PUPD_NONE, PIN_MOTOR_RB_B);
    timer_channel_output_pulse_value_config(TIMER_MOTOR_RB_B, CH_MOTOR_RB_B, speed);
}
/**
 * @description: 右后轮停止
 * @param {uint8_t} mode: 停止方式，0熄火 1刹车
 * @return {*}
 */
void motor_rb_stop(uint8_t mode)
{
    if(mode)
    {
        gpio_mode_set(PORT_MOTOR_RB_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RB_F);
        RB_F = 1;
        gpio_mode_set(PORT_MOTOR_RB_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RB_B);
        RB_B = 1;
    }
    else
    {
        gpio_mode_set(PORT_MOTOR_RB_F, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RB_F);
        RB_F = 0;
        gpio_mode_set(PORT_MOTOR_RB_B, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_MOTOR_RB_B);
        RB_B = 0;
    }
}


