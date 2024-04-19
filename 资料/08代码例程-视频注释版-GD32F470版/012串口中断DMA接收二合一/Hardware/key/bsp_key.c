/********************************************************************************
  * 文 件 名: bsp_key.c
  * 版 本 号: 初版
  * 修改作者: LC
  * 修改日期: 2022年04月15日
  * 功能介绍:          
  ******************************************************************************
  * 注意事项:
*********************************************************************************/
#include "bsp_key.h"
#include "sys.h"
#include "bsp_led.h"
#include "stdio.h"

void key_gpio_config(void)
{
	/* 开启时钟 */
	rcu_periph_clock_enable(BSP_KEY_RCU);
	rcu_periph_clock_enable(RCU_SYSCFG);    // 系统配置时钟
	
	/* 配置为输入模式 下拉模式 */ 
	gpio_mode_set(BSP_KEY_PORT,GPIO_MODE_INPUT,GPIO_PUPD_PULLDOWN,BSP_KEY_PIN);  // 按键默认状态是低电平，配置为下拉
	
	/* 使能NVIC中断 中断分组为2位抢占优先级，2位子优先级 */
	nvic_irq_enable(BSP_KEY_EXTI_IRQN,3U,3U);  // 抢占优先级3，子优先级3
	/* 连接中断线到GPIO */
	syscfg_exti_line_config(BSP_KEY_EXTI_PORT_SOURCE,BSP_KEY_EXTI_PIN_SOURCE);
	/* 初始化中断线 */
	exti_init(BSP_KEY_EXTI_LINE,EXTI_INTERRUPT,EXTI_TRIG_BOTH);
	
	/* 使能中断 */
	exti_interrupt_enable(BSP_KEY_EXTI_LINE);
	/* 清除中断标志位 */
	exti_interrupt_flag_clear(BSP_KEY_EXTI_LINE);
}

/************************************************
函数名称 ： BSP_KEY_EXTI_IRQHandler
功    能 ： 中断处理函数
参    数 ： 无
返 回 值 ： 无
作    者 ： LCEDA
*************************************************/
void BSP_KEY_EXTI_IRQHANDLER(void)
{
  if(exti_interrupt_flag_get(BSP_KEY_EXTI_LINE) == SET)   // 中断标志位为1，按键按下	
	{
		if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)  // 按键按下
		{
			 /* 按键按下操作的功能 */ 
			gpio_bit_toggle(PORT_LED2,PIN_LED2);                   // led电平状态翻转
			printf("key press!\r\n");                              // 串口打印key press!
		}else{                                                   // 按键释放 
			/* 按键松开操作的功能 */ 
			printf("key release!\r\n");                            // 串口打印key release!
		}
	  exti_interrupt_flag_clear(BSP_KEY_EXTI_LINE);            // 清中断标志位
	}
}

/************************************************
函数名称 ： key_scan
功    能 ： 按键扫描函数
参    数 ： 无
返 回 值 ： 无
作    者 ： LC
*************************************************/
void key_scan(void)
{
	/* 先读取按键引脚的电平 如果高电平，按键按下 */
	if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)         // 按键按下
	{
		delay_1ms(20);  // 延迟消抖 
		if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET)       // 再次检测按键是否按下 
		{
			/* 执行对应的功能 */
			gpio_bit_toggle(PORT_LED2,PIN_LED2);    // led电平状态翻转
			printf("key press!\r\n");								// 串口打印key press!
			while(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN) == SET);  // 检测按键松开
			printf("key release!\r\n");             // 串口打印key release!
		}
	}
}