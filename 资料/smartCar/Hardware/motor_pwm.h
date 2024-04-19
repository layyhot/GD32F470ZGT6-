/*** 
 * @Author       : Shannon
 * @Date         : 2023-02-20 21:00:01
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-21 20:40:28
 * @FilePath     : \0000smartCar\Hardware\motor_pwm.h
 * @Description  : definitions of the motor PWM
 * @Copyright (c) 2023 by Shannon, All Rights Reserved. 
 */
#ifndef __MOTOR_PWM_H
#define __MOTOR_PWM_H

#include "gd32f4xx.h"
#include "systick.h"
// #include "motor.h"

// PWM1配置
void pwm1_config(uint16_t pre, uint16_t per);
// PWM2配置
void pwm2_config(uint16_t pre, uint16_t per);


#endif // !__MOTOR_PWM_H
