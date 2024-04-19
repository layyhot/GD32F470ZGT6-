/*** 
 * @Author       : Shannon
 * @Date         : 2023-02-25 20:31:42
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-25 21:56:31
 * @FilePath     : \0000smartCar\Hardware\hcsr04.h
 * @Description  : definitions of the HCSR04 ultrasound module 
 * @Copyright (c) 2023 by Shannon, All Rights Reserved. 
 */
#ifndef __HCSR04_H
#define __HCSR04_H

#include "gd32f4xx.h"
#include "systick.h"
#include "sys.h"

// 超声波模块
#define RCU_HCSR04          RCU_GPIOB
#define PORT_HCSR04         GPIOB
#define PIN_HCSR04_TRIG     GPIO_PIN_12
#define PIN_HCSR04_ECHO     GPIO_PIN_10


// 超声波模块初始化函数
void hcsr04_init(void);
// 超声波模块测距函数
int32_t hcsr04_distance(void);

// Trig和Echo引脚的位带操作
#define HCSR04_TRIG PBout(12)
#define HCSR04_ECHO PBin(10)


#endif // !__HCSR04_H
