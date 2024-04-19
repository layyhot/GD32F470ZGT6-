/*
 * @Author       : Shannon
 * @Date         : 2023-02-13 16:18:58
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-26 22:36:13
 * @FilePath     : \0000smartCar\User\main.c
 * @Description  : 
 * Copyright (c) 2023 by Shannon, All Rights Reserved. 
 */


#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "bsp_led.h"
#include "bsp_buzzer.h"
#include "bsp_key.h"
#include "motor.h"
#include "motor_pwm.h"
#include "bsp_usart.h"
#include "string.h"
#include "hcsr04.h"
#include "adc.h"
#include "track.h"

// 串口接收的相关数据
extern uint8_t 	    g_recv_buff[USART_RECEIVE_LENGTH];	// 接收的数据存放的数组
extern uint16_t 	g_recv_length;					    // 已经接收的数据的长度
extern uint8_t		g_recv_complete_flag;			    // 接收完成标志

// 循迹变量
extern FlagStatus XJ_01;
extern FlagStatus XJ_02;
extern FlagStatus XJ_03;
extern FlagStatus XJ_04;
extern FlagStatus XJ_05;



/*!
    \brief    main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    // 滴答定时器配置
    systick_config();
    // LED初始化
    led_init();
    // 蜂鸣器初始化
    buzzer_init();
    // 按键初始化
    key_init();
    // 电机初始化
    motor_init();
    // 电机PWM初始化
    pwm1_config(200, 100);      // 10KHz
    pwm2_config(200, 100);      // 10KHz

    // // 蓝牙串口初始化
    // usart6_gpio_config(9600U);  // 波特率9600
    // 串口1初始化
    usart_gpio_config(9600U);   // 波特率9600

    // ADC检测电池电压初始化
    // adc_gpio_init();

    // 循迹初始化
    track_init();
    


    motor_lf_stop(1);
    motor_lb_stop(1);
    motor_rf_stop(1);
    motor_rb_stop(1);
    
    // uint16_t speed = 0;         // 电机速度

    while(1) 
	{
		// 关掉蜂鸣器
		BUZZER_OFF;
		// // 打开车灯
		// led_on();
        // delay_1ms(1000);
        // led_off();
        // delay_1ms(1000);
        // // 扫描按键
        // scan_key();

        /* 简单的电机测试 */
        // // 前进
        // motor_front();
        // // 后退
        // motor_back();
        // // 左转
        // motor_left();
        // // 右转
        // motor_right();
        // // 停止
        // motor_stop();

        // // 左前轮PWM前进
        // motor_lf_forward(9999);


        
        // // 蓝牙接收响应
        // if(g_recv_complete_flag)
        // {
        //     g_recv_complete_flag = 0;
            
        //     switch (g_recv_buff[0])
        //     {
        //         case 1: // 前进
        //         {
        //             motor_lf_forward(speed);
        //             motor_lb_forward(speed);
        //             motor_rf_forward(speed);
        //             motor_rb_forward(speed);
        //         }   break;
        //         case 2: // 后退
        //         {
        //             motor_lf_backward(speed);
        //             motor_lb_backward(speed);
        //             motor_rf_backward(speed);
        //             motor_rb_backward(speed);
        //         }   break;
        //         case 3: // 左转
        //         {
        //             motor_lf_backward(speed);
        //             motor_lb_backward(speed);
        //             motor_rf_forward(speed);
        //             motor_rb_forward(speed);
        //         }   break;
        //         case 4: // 右转
        //         {
        //             motor_lf_forward(speed);
        //             motor_lb_forward(speed);
        //             motor_rf_backward(speed);
        //             motor_rb_backward(speed);
        //         }   break;
        //         case 5: // 停止
        //         {
        //             motor_lf_stop(1);
        //             motor_lb_stop(1);
        //             motor_rf_stop(1);
        //             motor_rb_stop(1);
        //         }   break;
        //         case 6: // 速度1
        //         {
        //             speed = 75;
        //         }   break;
        //         case 7: // 速度2
        //         {
        //             speed = 85;
        //         }   break;
        //         case 8: // 速度3
        //         {
        //             speed = 100;
        //         }   break;
        //         case 9: // 开灯
        //         {
        //             led_on();
        //         }   break;
        //         case 10: // 关灯
        //         {
        //             led_off();
        //         }   break;
                
        //         default:
        //             break;
        //     }

        //     // 清空接收的数组
        //     memset(g_recv_buff, 0, g_recv_length);
        //     // 复位接收的长度
        //     g_recv_length = 0;
        // }
        


    }
}
