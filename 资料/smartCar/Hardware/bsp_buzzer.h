/*** 
 * @Author       : Shannon
 * @Date         : 2023-02-13 21:10:46
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-14 10:03:44
 * @FilePath     : \0000smartCar\Hardware\bsp_buzzer.h
 * @Description  : definitions of the buzzer
 * @Copyright (c) 2023 by Shannon, All Rights Reserved. 
 */
#ifndef __BSP_BUZZER_H
#define __BSP_BUZZER_H

#include "gd32f4xx.h"
#include "systick.h"
#include "bsp_led.h"

// 蜂鸣器
#define RCU_BUZZER   RCU_GPIOF
#define PORT_BUZZER  GPIOF
#define PIN_BUZZER   GPIO_PIN_8

// 蜂鸣器叫
#define BUZZER_ON   gpio_bit_reset(PORT_BUZZER, PIN_BUZZER);
// 蜂鸣器停
#define BUZZER_OFF  gpio_bit_set(PORT_BUZZER, PIN_BUZZER);


// 蜂鸣器初始化
void buzzer_init(void);
// 蜂鸣器叫伴随着LED闪烁
void buzzer_on_with_led(void);

#endif // !__BSP_BUZZER_H
