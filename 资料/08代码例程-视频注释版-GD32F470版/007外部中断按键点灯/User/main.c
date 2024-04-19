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
#include "bsp_key.h"



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
	
	  nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);  // 优先级分组
	
    systick_config();          // 滴答定时器初始化
	  led_gpio_config();   			 // led初始化
    key_gpio_config(); 				 // key初始化
	  usart_gpio_config(9600U);  // 串口0初始化
	
    while(1) {
		
    }
}
