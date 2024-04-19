#ifndef _BSP_PWM_H
#define _BSP_PWM_H


#include "gd32f4xx.h"
#include "systick.h"

#define BSP_PWM_RCU     RCU_GPIOA               // PWM端口时钟
#define BSP_PWM_PORT    GPIOA 					// PWM端口
#define BSP_PWM_PIN     GPIO_PIN_5              // PWM引脚
#define BSP_PWM_AF      GPIO_AF_1				// PWM引脚复用


#define BSP_PWM1_TIMER_RCU  			RCU_TIMER1		// 定时器时钟
#define BSP_PWM1_TIMER      			TIMER1        // 定时器
#define BSP_PWM1_CHANNEL0  				TIMER_CH_0    // 定时器通道
#define BSP_PWM1_CHANNEL1 				TIMER_CH_1    // 定时器通道
#define BSP_PWM1_CHANNEL2				TIMER_CH_2    // 定时器通道
#define BSP_PWM1_CHANNEL3 				TIMER_CH_3    // 定时器通道

#define BSP_PWM2_TIMER_RCU  			RCU_TIMER2		// 定时器时钟
#define BSP_PWM2_TIMER      			TIMER2        // 定时器
#define BSP_PWM2_CHANNEL0  				TIMER_CH_0    // 定时器通道
#define BSP_PWM2_CHANNEL1 				TIMER_CH_1    // 定时器通道
#define BSP_PWM2_CHANNEL2				TIMER_CH_2    // 定时器通道
#define BSP_PWM2_CHANNEL3 				TIMER_CH_3    // 定时器通道

void pwm1_config(uint16_t pre,uint16_t per);			// PWM1配置 
void pwm2_config(uint16_t pre,uint16_t per);			// PWM2配置

//void pwm_breathing_lamp(void);                  // 呼吸灯函数

#endif  /* BSP_PWM_H */
