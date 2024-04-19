/*** 
 * @Author       : Shannon
 * @Date         : 2023-02-13 21:10:46
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-14 10:01:49
 * @FilePath     : \0000smartCar\Hardware\bsp_key.h
 * @Description  : definitions of the keys
 * @Copyright (c) 2023 by Shannon, All Rights Reserved. 
 */
#ifndef __BSP_KEY_H
#define __BSP_KEY_H

#include "gd32f4xx.h"
#include "systick.h"
#include "bsp_led.h"

// KEY_S
#define RCU_KEY_S   RCU_GPIOE
#define PORT_KEY_S  GPIOE
#define PIN_KEY_S   GPIO_PIN_5

// KEY_M
#define RCU_KEY_M   RCU_GPIOB
#define PORT_KEY_M  GPIOB
#define PIN_KEY_M   GPIO_PIN_5



// 按键初始化
void key_init(void);
// 按键扫描
void scan_key(void);

#endif // !__BSP_KEY_H
