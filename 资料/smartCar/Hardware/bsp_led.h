/*** 
 * @Author       : Shannon
 * @Date         : 2023-02-13 16:37:48
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-14 09:15:02
 * @FilePath     : \0000smartCar\Hardware\led\bsp_led.h
 * @Description  : definitions of the LEDs
 * @Copyright (c) 2023 by Shannon, All Rights Reserved. 
 */

#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "gd32f4xx.h"
#include "systick.h"

// 左车灯 LED_L
#define RCU_LED_L   RCU_GPIOA
#define PORT_LED_L  GPIOA
#define PIN_LED_L   GPIO_PIN_12
// 右车灯 LED_R
#define RCU_LED_R   RCU_GPIOG
#define PORT_LED_R  GPIOG
#define PIN_LED_R   GPIO_PIN_7
// LED_S
#define RCU_LED_S   RCU_GPIOE
#define PORT_LED_S  GPIOE
#define PIN_LED_S   GPIO_PIN_2
// LED_M
#define RCU_LED_M   RCU_GPIOB
#define PORT_LED_M  GPIOB
#define PIN_LED_M   GPIO_PIN_3

// 打开左车灯
#define LED_L_ON    gpio_bit_set(PORT_LED_L, PIN_LED_L) 
// 打开右车灯
#define LED_R_ON    gpio_bit_set(PORT_LED_R, PIN_LED_R)

// 关闭左车灯
#define LED_L_OFF   gpio_bit_reset(PORT_LED_L, PIN_LED_L) 
// 关闭右车灯
#define LED_R_OFF   gpio_bit_reset(PORT_LED_R, PIN_LED_R)

// 打开LED S
#define LED_S_ON    gpio_bit_set(PORT_LED_S, PIN_LED_S) 
// 关闭LED S
#define LED_S_OFF   gpio_bit_reset(PORT_LED_S, PIN_LED_S) 

// 打开LED M
#define LED_M_ON    gpio_bit_set(PORT_LED_M, PIN_LED_M) 
// 关闭LED M
#define LED_M_OFF   gpio_bit_reset(PORT_LED_M, PIN_LED_M) 

// led初始化
void led_init(void);
// 打开led车灯
void led_on(void);
// 关闭led车灯
void led_off(void);

#endif // !__BSP_LED_H
