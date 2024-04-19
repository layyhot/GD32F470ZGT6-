/*
 * @Author       : Shannon
 * @Date         : 2023-02-13 16:37:56
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-14 09:49:53
 * @FilePath     : \0000smartCar\Hardware\bsp_led.c
 * @Description  : driver for the LED
 * Copyright (c) 2023 by Shannon, All Rights Reserved.
 */

#include "bsp_led.h"

/**
 * @description: LEDs initialization
 * @return {*}
 */
void led_init(void)
{
    // 左车灯初始化
    // 使能时钟
    rcu_periph_clock_enable(RCU_LED_L);
    // 输出模式 推挽输出
    gpio_mode_set(PORT_LED_L, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLDOWN, PIN_LED_L);
    // 输出选项 50MHZ
    gpio_output_options_set(PORT_LED_L, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_LED_L);

    // 右车灯初始化
    // 使能时钟
    rcu_periph_clock_enable(RCU_LED_R);
    // 输出模式 推挽输出
    gpio_mode_set(PORT_LED_R, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLDOWN, PIN_LED_R);
    // 输出选项 50MHZ
    gpio_output_options_set(PORT_LED_R, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_LED_R);

    // LED_S 初始化
    // 使能时钟
    rcu_periph_clock_enable(RCU_LED_S);
    // 输出模式 推挽输出
    gpio_mode_set(PORT_LED_S, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLDOWN, PIN_LED_S);
    // 输出选项 50MHZ
    gpio_output_options_set(PORT_LED_S, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_LED_S);

    // LED_M 初始化
    // 使能时钟
    rcu_periph_clock_enable(RCU_LED_M);
    // 输出模式 推挽输出
    gpio_mode_set(PORT_LED_M, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLDOWN, PIN_LED_M);
    // 输出选项 50MHZ
    gpio_output_options_set(PORT_LED_M, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_LED_M);
}

/**
 * @description: Open the LED
 * @return {*}
 */
void led_on(void)
{
    LED_L_ON;
    LED_R_ON;
}

/**
 * @description: Close the LED
 * @return {*}
 */
void led_off(void)
{
    LED_L_OFF;
    LED_R_OFF;
}
