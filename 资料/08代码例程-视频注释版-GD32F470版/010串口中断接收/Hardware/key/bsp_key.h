#ifndef _BSP_KEY_H
#define _BSP_KEY_H

#include "gd32f4xx.h"
#include "systick.h"

#define BSP_KEY_RCU   RCU_GPIOA      // 按键端口时钟
#define BSP_KEY_PORT  GPIOA          // 按键端口
#define BSP_KEY_PIN   GPIO_PIN_0     // 按键引脚


#define BSP_KEY_EXTI_IRQN			 		EXTI0_IRQn          // 外部中断0
#define BSP_KEY_EXTI_PORT_SOURCE 	EXTI_SOURCE_GPIOA   // 外部中断端口资源
#define BSP_KEY_EXTI_PIN_SOURCE  	EXTI_SOURCE_PIN0    // 外部中断引脚资源
#define BSP_KEY_EXTI_LINE 				EXTI_0              // 外部中断
#define BSP_KEY_EXTI_IRQHANDLER   EXTI0_IRQHandler    // 外部中断函数名


void key_gpio_config(void); // key gpio引脚配置
void key_scan(void); // 按键扫描

#endif