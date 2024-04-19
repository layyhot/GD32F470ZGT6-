
#ifndef __TRACK_H
#define __TRACK_H

#include "gd32f4xx.h"
#include "systick.h"
#include "bsp_led.h"

// 第一路循迹
#define RCU_XJ_01   RCU_GPIOA
#define PORT_XJ_01  GPIOA
#define PIN_XJ_01   GPIO_PIN_15

// 第二路循迹
#define RCU_XJ_02   RCU_GPIOC
#define PORT_XJ_02  GPIOC
#define PIN_XJ_02   GPIO_PIN_10

// 第三路循迹
#define RCU_XJ_03   RCU_GPIOC
#define PORT_XJ_03  GPIOC
#define PIN_XJ_03   GPIO_PIN_12

// 第四路循迹
#define RCU_XJ_04   RCU_GPIOB
#define PORT_XJ_04  GPIOB
#define PIN_XJ_04   GPIO_PIN_13

// 第五路循迹
#define RCU_XJ_05   RCU_GPIOB
#define PORT_XJ_05  GPIOB
#define PIN_XJ_05   GPIO_PIN_15




// 按键初始化
void track_init(void);
// 黑线检测函数
void black_detection(void);

#endif // !__TRACK_H
