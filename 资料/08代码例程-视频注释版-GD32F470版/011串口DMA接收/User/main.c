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
#include "bsp_basic_timer.h"
#include "bsp_pwm.h"
#include "stdlib.h"
#include "string.h"
#include "bsp_dma.h"



/************************************************
函数名称 ： main
功    能 ： 主函数
参    数 ： 无
返 回 值 ： 无
作    者 ： LC
*************************************************/
int main(void)
{

	  nvic_priority_group_set(NVIC_PRIGROUP_PRE2_SUB2);  // 优先级分组
	
    systick_config();          					// 滴答定时器初始化
	  led_gpio_config();   								// led初始化
    key_gpio_config(); 				 					// key初始化
	  usart_gpio_config(9600U);  					// 串口0初始化
	  dma_config();												// DMA配置

    while(1) {
			
			/* 等待数据传输完成 */
			if(g_recv_complete_flag)  										// 数据接收完成
			{ 
				g_recv_complete_flag = 0;                   // 等待下次接收
				printf("g_recv_length:%d ",g_recv_length);  // 打印接收的数据长度
				printf("g_recv_buff:%s\r\n",g_recv_buff);		// 打印接收的数据
				memset(g_recv_buff,0,g_recv_length);				// 清空数组
				g_recv_length = 0;													// 清空长度
			}
		
    }
}
