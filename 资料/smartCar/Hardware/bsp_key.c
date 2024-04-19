/*
 * @Author       : Shannon
 * @Date         : 2023-02-13 21:10:40
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-21 13:47:21
 * @FilePath     : \0000smartCar\Hardware\bsp_key.c
 * @Description  : driver for the keys
 * Copyright (c) 2023 by Shannon, All Rights Reserved. 
 */
#include "bsp_key.h"

/**
 * @description: KEY_S and KEY_M initialization
 * @return {*}
 */
void key_init(void)
{
    // KEY_S 初始化
    // 使能时钟
    rcu_periph_clock_enable(RCU_KEY_S);
    // 输入模式 上拉
    gpio_mode_set(PORT_KEY_S, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, PIN_KEY_S);

    // KEY_M 初始化
    // 使能时钟
    rcu_periph_clock_enable(RCU_KEY_M);
    // 输入模式 上拉
    gpio_mode_set(PORT_KEY_M, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, PIN_KEY_M);
    
}

/**
 * @description: San the keys' states with indicator leds 
 * @return {*}
 */
void scan_key(void)
{
    // 扫描按键Key_S
    if(gpio_input_bit_get(PORT_KEY_S, PIN_KEY_S) == RESET) 
    {
        delay_1ms(20); // 延时消抖
        if(gpio_input_bit_get(PORT_KEY_S, PIN_KEY_S) == RESET)
        {
            gpio_bit_toggle(PORT_LED_S, PIN_LED_S);
            while(gpio_input_bit_get(PORT_KEY_S, PIN_KEY_S) == SET);
        }

    }
    // 扫描按键Key_M
    if(gpio_input_bit_get(PORT_KEY_M, PIN_KEY_M) == RESET) 
    {
        delay_1ms(20);  // 延时消抖
        if(gpio_input_bit_get(PORT_KEY_M, PIN_KEY_M) == RESET)
        {
            gpio_bit_toggle(PORT_LED_M, PIN_LED_M);
            while(gpio_input_bit_get(PORT_KEY_M, PIN_KEY_M) == SET);
        }

    }
}



