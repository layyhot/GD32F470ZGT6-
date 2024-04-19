/*
 * @Author       : Shannon
 * @Date         : 2023-02-20 21:00:01
 * @LastEditors  : Shannon
 * @LastEditTime : 2023-02-21 20:39:56
 * @FilePath     : \0000smartCar\Hardware\motor_pwm.c
 * @Description  : motor PWM driver
 * Copyright (c) 2023 by Shannon, All Rights Reserved. 
 */
#include "motor_pwm.h"

/**
 * @description: 定时器1配置
 * @param {uint16_t} pre：预分频系数，1~65536
 * @param {uint16_t} per：一个周期的脉冲数，1~65536
 * @return {*}
 */
void pwm1_config(uint16_t pre, uint16_t per)
{
    timer_parameter_struct      timer_initpara;				// 声明定时器参数结构体
    timer_oc_parameter_struct   timer_ocpara;               // 声明定时器比较输出结构体
	
	/* 配置定时器时钟 */
	rcu_periph_clock_enable(RCU_TIMER1);                    // 开启定时器时钟
	rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);	// 配置定时器时钟为200MHz， 计算公式：CK_TIMERx = 4*CK_APB1 = 4*50MHz = 200MHz
	timer_deinit(TIMER1); 							        // 复位定时器

	/* 配置定时器参数 */
	timer_initpara.prescaler = pre - 1; 					// 时钟预分频值0-65535，预分频后的时钟频率：psc_clk=TIMER_CK/pre [Hz]
    timer_initpara.period = per - 1; 						// 计数周期，0-65535，每个周期的时长：T=per/psc_clk [s]
    timer_initpara.alignedmode = TIMER_COUNTER_EDGE;		// 边缘对齐                     
    timer_initpara.counterdirection = TIMER_COUNTER_UP;     // 向上计数           
    timer_initpara.clockdivision = TIMER_CKDIV_DIV1;        // 分频因子，在输入捕获的时候使用，定时器时钟频率与死区发生器和数字滤波器使用的采样频率之间的分频比                                   
    timer_initpara.repetitioncounter = 0; 					// 重复计数器 0-255，只有高级计数器才有，配置为x，就重复x+1次才进入中断
	
	timer_init(TIMER1, &timer_initpara);				    // 初始化定时器
	
	/* 配置输出结构体 */
	timer_ocpara.outputstate = TIMER_CCX_ENABLE;            // 配置比较输出模式的状态，也就是使能PWM输出到端口     
	timer_ocpara.ocpolarity = TIMER_OC_POLARITY_HIGH;       // 有效电平的极性

    /* 配置定时器输出功能 */
	timer_channel_output_config(TIMER1, TIMER_CH_0, &timer_ocpara); // 通道0
    timer_channel_output_config(TIMER1, TIMER_CH_1, &timer_ocpara); // 通道1
    timer_channel_output_config(TIMER1, TIMER_CH_2, &timer_ocpara); // 通道2
    timer_channel_output_config(TIMER1, TIMER_CH_3, &timer_ocpara); // 通道3

    /* 配置占空比 */
	timer_channel_output_mode_config(TIMER1, TIMER_CH_0, TIMER_OC_MODE_PWM0);           // 配置定时器通道输出比较模式
	timer_channel_output_pulse_value_config(TIMER1, TIMER_CH_0, 0);                     // 配置定时器输通道输出脉冲值， 配置为x，占空比=x/per
	timer_channel_output_shadow_config(TIMER1, TIMER_CH_0, TIMER_OC_SHADOW_DISABLE);    // 配置定时器通道输出影子寄存器

    timer_channel_output_mode_config(TIMER1, TIMER_CH_1, TIMER_OC_MODE_PWM0);           // 配置定时器通道输出比较模式
	timer_channel_output_pulse_value_config(TIMER1, TIMER_CH_1, 0);                     // 配置定时器输通道输出脉冲值， 配置为x，占空比=x/per
	timer_channel_output_shadow_config(TIMER1, TIMER_CH_1, TIMER_OC_SHADOW_DISABLE);    // 配置定时器通道输出影子寄存器

    timer_channel_output_mode_config(TIMER1, TIMER_CH_2, TIMER_OC_MODE_PWM0);           // 配置定时器通道输出比较模式
	timer_channel_output_pulse_value_config(TIMER1, TIMER_CH_2, 0);                     // 配置定时器输通道输出脉冲值， 配置为x，占空比=x/per
	timer_channel_output_shadow_config(TIMER1, TIMER_CH_2, TIMER_OC_SHADOW_DISABLE);    // 配置定时器通道输出影子寄存器

    timer_channel_output_mode_config(TIMER1, TIMER_CH_3, TIMER_OC_MODE_PWM0);           // 配置定时器通道输出比较模式
	timer_channel_output_pulse_value_config(TIMER1, TIMER_CH_3, 0);                     // 配置定时器输通道输出脉冲值， 配置为x，占空比=x/per
	timer_channel_output_shadow_config(TIMER1, TIMER_CH_3, TIMER_OC_SHADOW_DISABLE);    // 配置定时器通道输出影子寄存器

	timer_auto_reload_shadow_enable(TIMER1);                                            // 自动重载影子使能
	
	/* 只有高级定时器需要设置 */
	// timer_primary_output_config(TIMER0, ENABLE);         // 输出优先级配置
	
	/* 使能定时器 */ 
	timer_enable(TIMER1);

}

/**
 * @description: 定时器2配置
 * @param {uint16_t} pre：预分频系数，1~65536
 * @param {uint16_t} per：一个周期的脉冲数，1~65536
 * @return {*}
 */
void pwm2_config(uint16_t pre, uint16_t per)
{
    timer_parameter_struct      timer_initpara;				// 声明定时器参数结构体
    timer_oc_parameter_struct   timer_ocpara;               // 声明定时器比较输出结构体


	/* 调用GPIO引脚配置函数 */
	// pwm_gpio_config();
	
	/* 配置定时器时钟 */
	rcu_periph_clock_enable(RCU_TIMER2);                    // 开启定时器时钟
	rcu_timer_clock_prescaler_config(RCU_TIMER_PSC_MUL4);	// 配置定时器时钟为200MHz， 计算公式：CK_TIMERx = 4*CK_APB1 = 4*50MHz = 200MHz
	timer_deinit(TIMER2); 							        // 复位定时器

	/* 配置定时器参数 */
	timer_initpara.prescaler = pre - 1; 					// 时钟预分频值，0-65535，预分频后的时钟频率：psc_clk=TIMER_CK/pre [Hz]
    timer_initpara.period = per - 1; 						// 计数周期，0-65535，每个周期的时长：T=per/psc_clk [s]
    timer_initpara.alignedmode = TIMER_COUNTER_EDGE;		// 边缘对齐                     
    timer_initpara.counterdirection = TIMER_COUNTER_UP;     // 向上计数           
    timer_initpara.clockdivision = TIMER_CKDIV_DIV1;        // 分频因子，在输入捕获的时候使用，定时器时钟频率与死区发生器和数字滤波器使用的采样频率之间的分频比                                   
    timer_initpara.repetitioncounter = 0; 					// 重复计数器 0-255，只有高级计数器才有，配置为x，就重复x+1次才进入中断
	
	timer_init(TIMER2, &timer_initpara);				    // 初始化定时器
	
	/* 配置输出结构体 */
	timer_ocpara.outputstate = TIMER_CCX_ENABLE;            // 配置比较输出模式的状态，也就是使能PWM输出到端口     
	timer_ocpara.ocpolarity = TIMER_OC_POLARITY_HIGH;       // 有效电平的极性

    /* 配置定时器输出功能 */
	timer_channel_output_config(TIMER2, TIMER_CH_0, &timer_ocpara); // 通道0
    timer_channel_output_config(TIMER2, TIMER_CH_1, &timer_ocpara); // 通道1
    timer_channel_output_config(TIMER2, TIMER_CH_2, &timer_ocpara); // 通道2
    timer_channel_output_config(TIMER2, TIMER_CH_3, &timer_ocpara); // 通道3

    /* 配置占空比 */
	timer_channel_output_mode_config(TIMER2, TIMER_CH_0, TIMER_OC_MODE_PWM0);           // 配置定时器通道输出比较模式
	timer_channel_output_pulse_value_config(TIMER2, TIMER_CH_0, 0);                     // 配置定时器输通道输出脉冲值， 配置为x，占空比=x/per
	timer_channel_output_shadow_config(TIMER2, TIMER_CH_0, TIMER_OC_SHADOW_DISABLE);    // 配置定时器通道输出影子寄存器

    timer_channel_output_mode_config(TIMER2, TIMER_CH_1, TIMER_OC_MODE_PWM0);           // 配置定时器通道输出比较模式
	timer_channel_output_pulse_value_config(TIMER2, TIMER_CH_1, 0);                     // 配置定时器输通道输出脉冲值， 配置为x，占空比=x/per
	timer_channel_output_shadow_config(TIMER2, TIMER_CH_1, TIMER_OC_SHADOW_DISABLE);    // 配置定时器通道输出影子寄存器

    timer_channel_output_mode_config(TIMER2, TIMER_CH_2, TIMER_OC_MODE_PWM0);           // 配置定时器通道输出比较模式
	timer_channel_output_pulse_value_config(TIMER2, TIMER_CH_2, 0);                     // 配置定时器输通道输出脉冲值， 配置为x，占空比=x/per
	timer_channel_output_shadow_config(TIMER2, TIMER_CH_2, TIMER_OC_SHADOW_DISABLE);    // 配置定时器通道输出影子寄存器

    timer_channel_output_mode_config(TIMER2, TIMER_CH_3, TIMER_OC_MODE_PWM0);           // 配置定时器通道输出比较模式
	timer_channel_output_pulse_value_config(TIMER2, TIMER_CH_3, 0);                     // 配置定时器输通道输出脉冲值， 配置为x，占空比=x/per
	timer_channel_output_shadow_config(TIMER2, TIMER_CH_3, TIMER_OC_SHADOW_DISABLE);    // 配置定时器通道输出影子寄存器

	timer_auto_reload_shadow_enable(TIMER2);                                            // 自动重载影子使能
	
	/* 只有高级定时器需要设置 */
	// timer_primary_output_config(TIMER0, ENABLE);         // 输出优先级配置
	
	/* 使能定时器 */ 
	timer_enable(TIMER2);

}


