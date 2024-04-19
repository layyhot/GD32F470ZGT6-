#ifndef _BSP_LED_H
#define _BSP_LED_H


#include "gd32f4xx.h"
#include "systick.h"

#define BSP_RCU_BASE 		(unsigned int)0x40023800U                   // RCU寄存器的基地址
#define BSP_RCU_AHB1EN 	*(unsigned int*)(BSP_RCU_BASE + 0x30U)			// AHB1使能寄存器地址

#define BSP_GPIOD_BASE 	(unsigned int)0x40020C00U    								// GPIOD的基地址
#define BSP_GPIOD_CTL 	*(unsigned int*)(BSP_GPIOD_BASE + 0x00U)    // GPIOD控制寄存器的地址
#define BSP_GPIOD_PUD 	*(unsigned int*)(BSP_GPIOD_BASE + 0x0CU)    // GPIOD的上下拉寄存器的地址
#define BSP_GPIOD_OMODE *(unsigned int*)(BSP_GPIOD_BASE + 0x04U)    // GPIOD的输出模式寄存器的地址
#define BSP_GPIOD_OSPD 	*(unsigned int*)(BSP_GPIOD_BASE + 0x08U)    // GPIOD的速度寄存器的地址
#define BSP_GPIOD_OCTL 	*(unsigned int*)(BSP_GPIOD_BASE + 0x14U)    // GPIOD的输出控制寄存器的地址
#define BSP_GPIOD_BOP 	*(unsigned int*)(BSP_GPIOD_BASE + 0x18U)    // GPIOD的位操作寄存器的地址
	
void led_gpio_config(void); // led gpio引脚配置
 
#endif  /* BSP_LED_H */