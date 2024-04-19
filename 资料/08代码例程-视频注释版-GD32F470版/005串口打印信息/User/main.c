/********************************************************************************
  * 文 件 名: main.c
  * 版 本 号: 初版
  * 修改作者: LC
  * 修改日期: 2022年04月12日
  * 功能介绍:          
  ******************************************************************************
  * 注意事项:
*********************************************************************************/

#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "bsp_led.h"
#include "sys.h"
#include "bsp_usart.h"




/************************************************
函数名称 ： main
功    能 ： 主函数
参    数 ： 无
返 回 值 ： 无
作    者 ： LC
*************************************************/
int main(void)
{

	  uint16_t uicount = 0;
	  float fcount = 0.0;
	
    systick_config();          // 滴答定时器初始化
	  led_gpio_config();   			 // led初始化
		usart_gpio_config(9600U);  // 串口0初始化

   // gpio_bit_set(GPIOD,GPIO_PIN_7);     // PD7输出高电平
	 // gpio_bit_reset(GPIOD,GPIO_PIN_7);   // PD7输出低电平
	
    while(1) {
				//gpio_bit_write(PORT_LED2,PIN_LED2,SET);     // LED2输出高电平
		  	PDout(7) = 1;                                 // PD7输出高电平
			  delay_1ms(1000);                           		// 延时1s
			  //gpio_bit_write(PORT_LED2,PIN_LED2,RESET);   // LED2输出低电平
			  PDout(7) = 0;                                 // PD7输出低电平
			  delay_1ms(1000);                              // 延时1s
			
			  uicount ++;     // 整形变量+1
		  	fcount += 0.11; // 浮点变量+1
			  printf("uicount = %d,fcount = %.2f\r\n",uicount,fcount);  // 打印输出信息
    }
}
