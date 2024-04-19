/*** 
 * @Author       : Shannon
 * @Date         : 2023-02-14 14:10:36
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-21 18:55:29
 * @FilePath     : \0000smartCar\Hardware\motor.h
 * @Description  : Definitions of the motors
 * @Copyright (c) 2023 by Shannon, All Rights Reserved. 
 */
#ifndef __MOTOR_H
#define __MOTOR_H

#include "gd32f4xx.h"
#include "systick.h"
#include "sys.h"

// 左前轮
// 前进引脚
#define RCU_MOTOR_LF_F      RCU_GPIOB
#define PORT_MOTOR_LF_F     GPIOB
#define PIN_MOTOR_LF_F      GPIO_PIN_4
#define PWM_AF_MOTOR_LF_F   GPIO_AF_2
#define TIMER_MOTOR_LF_F    TIMER2
#define CH_MOTOR_LF_F       TIMER_CH_0
// 后退引脚
#define RCU_MOTOR_LF_B      RCU_GPIOA
#define PORT_MOTOR_LF_B     GPIOA
#define PIN_MOTOR_LF_B      GPIO_PIN_7
#define PWM_AF_MOTOR_LF_B   GPIO_AF_2
#define TIMER_MOTOR_LF_B    TIMER2
#define CH_MOTOR_LF_B       TIMER_CH_1


// 右前轮
// 前进引脚
#define RCU_MOTOR_RF_F      RCU_GPIOA
#define PORT_MOTOR_RF_F     GPIOA
#define PIN_MOTOR_RF_F      GPIO_PIN_3
#define PWM_AF_MOTOR_RF_F   GPIO_AF_1
#define TIMER_MOTOR_RF_F    TIMER1
#define CH_MOTOR_RF_F       TIMER_CH_3
// 后退引脚
#define RCU_MOTOR_RF_B      RCU_GPIOA
#define PORT_MOTOR_RF_B     GPIOA
#define PIN_MOTOR_RF_B      GPIO_PIN_2
#define PWM_AF_MOTOR_RF_B   GPIO_AF_1
#define TIMER_MOTOR_RF_B    TIMER1
#define CH_MOTOR_RF_B       TIMER_CH_2

// 左后轮
// 前进引脚
#define RCU_MOTOR_LB_F      RCU_GPIOB
#define PORT_MOTOR_LB_F     GPIOB
#define PIN_MOTOR_LB_F      GPIO_PIN_0
#define PWM_AF_MOTOR_LB_F   GPIO_AF_2
#define TIMER_MOTOR_LB_F    TIMER2
#define CH_MOTOR_LB_F       TIMER_CH_2
// 后退引脚
#define RCU_MOTOR_LB_B      RCU_GPIOB
#define PORT_MOTOR_LB_B     GPIOB
#define PIN_MOTOR_LB_B      GPIO_PIN_1
#define PWM_AF_MOTOR_LB_B   GPIO_AF_2
#define TIMER_MOTOR_LB_B    TIMER2
#define CH_MOTOR_LB_B       TIMER_CH_3

// 右后轮
// 前进引脚
#define RCU_MOTOR_RB_F      RCU_GPIOA
#define PORT_MOTOR_RB_F     GPIOA
#define PIN_MOTOR_RB_F      GPIO_PIN_0
#define PWM_AF_MOTOR_RB_F   GPIO_AF_1
#define TIMER_MOTOR_RB_F    TIMER1
#define CH_MOTOR_RB_F       TIMER_CH_0
// 后退引脚
#define RCU_MOTOR_RB_B      RCU_GPIOA
#define PORT_MOTOR_RB_B     GPIOA
#define PIN_MOTOR_RB_B      GPIO_PIN_1
#define PWM_AF_MOTOR_RB_B   GPIO_AF_1
#define TIMER_MOTOR_RB_B    TIMER1
#define CH_MOTOR_RB_B       TIMER_CH_1


// 电机引脚位带操作
// 左前
#define LF_F    PBout(4)
#define LF_B    PAout(7)
// 右前
#define RF_F    PAout(3)
#define RF_B    PAout(2)
// 左后
#define LB_F    PBout(0)
#define LB_B    PBout(1)
// 右后
#define RB_F    PAout(0)
#define RB_B    PAout(1)




// 电机初始化
void motor_init(void);
// 小车简单前进
void motor_front(void);
// 小车简单后退
void motor_back(void);
// 小车简单左转
void motor_left(void);
// 小车简单右转
void motor_right(void);
// 小车简单停止
void motor_stop(void);



/* PWM控制电机运动*/
/* 左前轮 */
// 前进
void motor_lf_forward(uint16_t speed);
// 后退
void motor_lf_backward(uint16_t speed);
// 停止
void motor_lf_stop(uint8_t mode);

/* 左后轮 */
// 前进
void motor_lb_forward(uint16_t speed);
// 后退
void motor_lb_backward(uint16_t speed);
// 停止
void motor_lb_stop(uint8_t mode);

/* 右前轮 */
// 前进
void motor_rf_forward(uint16_t speed);
// 后退
void motor_rf_backward(uint16_t speed);
// 停止
void motor_rf_stop(uint8_t mode);

/* 右后轮 */
// 前进
void motor_rb_forward(uint16_t speed);
// 后退
void motor_rb_backward(uint16_t speed);
// 停止
void motor_rb_stop(uint8_t mode);





#endif  // !__MOTOR_H
