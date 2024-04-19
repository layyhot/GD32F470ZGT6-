/*
 * @Author       : Shannon
 * @Date         : 2023-02-25 20:31:25
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-25 22:01:33
 * @FilePath     : \0000smartCar\Hardware\hcsr04.c
 * @Description  : driver for the HCSR04 ultrasound module 
 * Copyright (c) 2023 by Shannon, All Rights Reserved. 
 */
#include "hcsr04.h"


/**
 * @description: 超声波模块初始函数
 * @return {*}
 */
void hcsr04_init(void)
{
    // 使能时钟
    rcu_periph_clock_enable(RCU_HCSR04);
    // Trig: 输出模式 推挽输出
    gpio_mode_set(PORT_HCSR04, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, PIN_HCSR04_TRIG);
    // Trig: 输出选项 50MHZ
    gpio_output_options_set(PORT_HCSR04, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, PIN_HCSR04_TRIG);

    // Echo: 输入模式 下拉输入 
    gpio_mode_set(PORT_HCSR04, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, PIN_HCSR04_ECHO);

    // 初始化Trig输出低电平
    gpio_bit_write(PORT_HCSR04,PIN_HCSR04_TRIG, RESET);

}


/**
 * @description: 超声波模块测距函数
 * @return: 返回测量的距离，单位为mm
 *          当返回-1，设备响应超时
 *          当返回-2，超出测量范围
 */
int32_t hcsr04_distance(void)
{
    uint32_t count = 0;     // 延时次数的计数
    uint32_t distance = 0;  // 距离，单位mm

    HCSR04_TRIG = 1;        // 开始触发测量
    delay_1us(20);          // 延时20us
    HCSR04_TRIG = 0;        // 触发信号恢复为0
    while(HCSR04_ECHO == 0) // 当超声波模块回响信号为0
    {
        delay_1us(1);
        count ++;
        if(count > 1000000)
        {
            return -1;      // 设备响应超时
        }
    }
    count = 0;
    while(HCSR04_ECHO)      // 当超声波模块回响信号为1
    {
        delay_1us(3);       // 延时3us，约等于1/2mm的距离（即来回1mm的距离）
        count ++;
        if(count > 100000)  // 100000，约等于50m的距离
        {
            return -2;      // 超出测量范围
        }
    }
    distance = count/2;     // 距离计算，单位mm

    return distance;
}
