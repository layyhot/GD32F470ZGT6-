/*!
    \file    bsp_usart.h
    \brief   definitions for the USART
	\author  IronShannon

    \version 20230116, V1.0.0
	
*/

#ifndef BSP_USART_H
#define BSP_USART_H

#include "gd32f4xx.h"
#include "systick.h"
#include "stdio.h"


// 串口1
#define BSP_USART_RX_RCU 	RCU_GPIOA
#define BSP_USART_TX_RCU 	RCU_GPIOA
#define BSP_USART_RCU		RCU_USART0

#define BSP_USART_RX_PORT	GPIOA
#define BSP_USART_TX_PORT	GPIOA
#define BSP_USART_RX_PIN	GPIO_PIN_10
#define BSP_USART_TX_PIN	GPIO_PIN_9
#define BSP_USART_AF		GPIO_AF_7

#define BSP_USART				USART0
#define BSP_USART_IRQ			USART0_IRQn
#define BSP_USART_IRQHandler	USART0_IRQHandler

// 蓝牙串口
#define BSP_USART6_RX_RCU 	RCU_GPIOF               // 串口6的Rx的时钟
#define BSP_USART6_TX_RCU 	RCU_GPIOF               // 串口6的Tx的时钟
#define BSP_USART6_RCU		RCU_UART6               // 串口6的时钟

#define BSP_USART6_RX_PORT	GPIOF                   // 串口6的Rx端口
#define BSP_USART6_TX_PORT	GPIOF                   // 串口6的Tx端口
#define BSP_USART6_RX_PIN	GPIO_PIN_6              // 串口6的Rx引脚
#define BSP_USART6_TX_PIN	GPIO_PIN_7              // 串口6的Tx引脚
#define BSP_USART6_AF		GPIO_AF_8               // 串口6的复用功能

#define BSP_USART6				UART6               // 串口6
#define BSP_USART6_IRQ			UART6_IRQn          // 串口6中断
#define BSP_USART6_IRQHandler	UART6_IRQHandler    // 串口6中断服务函数



#define USART_RECEIVE_LENGTH	4096                // 串口缓冲区的数据长度


// 串口接收数据相关的变量
extern uint8_t 		g_recv_buff[USART_RECEIVE_LENGTH];	// 接收的数据存放的数组
extern uint16_t 	g_recv_length;						// 已经接收的数据的长度
extern uint8_t		g_recv_complete_flag;				// 接收完成标志

// USART配置函数
void usart_gpio_config(uint32_t dwbaud_rate);
// USART6配置函数
void usart6_gpio_config(uint32_t dwbaud_rate);
// 串口发送数据函数，一次只能发送一个字符
void usart_send_data(uint8_t ucch);
// 串口发送数据函数，一次发送一个字符串
void usart_send_string(uint8_t *ucstr);
// 串口输出重定向
int fputc(int ch, FILE *f);

#endif
