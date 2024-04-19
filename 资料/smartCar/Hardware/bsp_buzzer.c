/*
 * @Author       : Shannon
 * @Date         : 2023-02-13 21:10:40
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-14 10:03:28
 * @FilePath     : \0000smartCar\Hardware\bsp_buzzer.c
 * @Description  : driver for the buzzer
 * Copyright (c) 2023 by Shannon, All Rights Reserved. 
 */
#include "bsp_buzzer.h"

/**
 * @description: Buzzer initialization
 * @return {*}
 */
void buzzer_init(void)
{
    // 使能时钟
    rcu_periph_clock_enable(RCU_BUZZER);
    // 输出模式 推挽输出
    gpio_mode_set(PORT_BUZZER, GPIO_MODE_OUTPUT, GPIO_PUPD_PULLDOWN, PIN_BUZZER);
    // 输出选项 50MHZ
    gpio_output_options_set(PORT_BUZZER, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_BUZZER);
}

/**
 * @description: Buzzer ON with LEDs flshaing
 * @return {*}
 */
void buzzer_on_with_led(void)
{
    BUZZER_ON;
    led_on();
    delay_1ms(500);
    led_off();
    delay_1ms(500);
}



