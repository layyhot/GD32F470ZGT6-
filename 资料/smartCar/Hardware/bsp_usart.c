/*!
    \file    bsp_usart.c
    \brief   USART driver
	\author  IronShannon

    \version 20230116, V1.0.0
	
*/

#include "bsp_usart.h"

// 串口接收数据相关的变量
uint8_t 	g_recv_buff[USART_RECEIVE_LENGTH];	// 接收的数据存放的数组
uint16_t 	g_recv_length = 0;					// 已经接收的数据的长度
uint8_t		g_recv_complete_flag = 0;			// 接收完成标志


/*!
    \brief    	串口1配置函数
    \param[in]  dwbaud_rate: baud rate value
    \param[out] none
    \retval     none
*/
void usart_gpio_config(uint32_t dwbaud_rate)
{
	// 开启时钟
	rcu_periph_clock_enable(BSP_USART_RX_RCU);
	rcu_periph_clock_enable(BSP_USART_TX_RCU);
	rcu_periph_clock_enable(BSP_USART_RCU);
	
	
	// 配置GPIO复用功能
	gpio_af_set(BSP_USART_RX_PORT, BSP_USART_AF, BSP_USART_RX_PIN);
	gpio_af_set(BSP_USART_TX_PORT, BSP_USART_AF, BSP_USART_TX_PIN);
	
	
	// 配置GPIO模式
	// 配置TX为复用模式，上拉模式
	gpio_mode_set(BSP_USART_TX_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, BSP_USART_TX_PIN);
	// 配置RX为复用模式，上拉模式
	gpio_mode_set(BSP_USART_RX_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, BSP_USART_RX_PIN);
	
	
	// 配置GPIO输出
	// 配置TX为推挽输出 50MHz
	gpio_output_options_set(BSP_USART_TX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_USART_TX_PIN);
	// 配置RX为推挽输出 50MHz
	gpio_output_options_set(BSP_USART_RX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_USART_RX_PIN);
	
	
	// 配置串口的参数
	usart_deinit(BSP_USART);						// 复位串口
	usart_baudrate_set(BSP_USART, dwbaud_rate);		// 设置波特率
	usart_parity_config(BSP_USART, USART_PM_NONE);	// 没有校验位
	usart_word_length_set(BSP_USART, USART_WL_8BIT);// 8位数据位
	usart_stop_bit_set(BSP_USART, USART_STB_1BIT);	// 1位停止位
	
	
	// 使能串口
	usart_enable(BSP_USART);									// 使能串口
	usart_transmit_config(BSP_USART, USART_TRANSMIT_ENABLE);	// 使能串口发送
	usart_receive_config(BSP_USART, USART_RECEIVE_ENABLE);		// 使能串口接收
	
	
	// 配置NVIC中断
	// 配置中断优先级
	nvic_irq_enable(BSP_USART_IRQ, 2, 2);
	// 使能串口中断
	// 使能串口接收中断（缓冲区不为空就会产生中断）
	usart_interrupt_enable(BSP_USART, USART_INT_RBNE);
	// 使能串口空闲中断（帧中断）
	usart_interrupt_enable(BSP_USART, USART_INT_IDLE);
	
}


/*!
    \brief    	串口6配置函数
    \param[in]  dwbaud_rate: baud rate value
    \param[out] none
    \retval     none
*/
void usart6_gpio_config(uint32_t dwbaud_rate)
{
	// 开启时钟
	rcu_periph_clock_enable(BSP_USART6_RX_RCU);
	rcu_periph_clock_enable(BSP_USART6_TX_RCU);
	rcu_periph_clock_enable(BSP_USART6_RCU);
	
	
	// 配置GPIO复用功能
	gpio_af_set(BSP_USART6_RX_PORT, BSP_USART6_AF, BSP_USART6_RX_PIN);
	gpio_af_set(BSP_USART6_TX_PORT, BSP_USART6_AF, BSP_USART6_TX_PIN);
	
	
	// 配置GPIO模式
	// 配置TX为复用模式，上拉模式
	gpio_mode_set(BSP_USART6_TX_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, BSP_USART6_TX_PIN);
	// 配置RX为复用模式，上拉模式
	gpio_mode_set(BSP_USART6_RX_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLUP, BSP_USART6_RX_PIN);
	
	
	// 配置GPIO输出
	// 配置TX为推挽输出 50MHz
	gpio_output_options_set(BSP_USART6_TX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_USART6_TX_PIN);
	// 配置RX为推挽输出 50MHz
	gpio_output_options_set(BSP_USART6_RX_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, BSP_USART6_RX_PIN);
	
	
	// 配置串口的参数
	usart_deinit(BSP_USART6);							// 复位串口
	usart_baudrate_set(BSP_USART6, dwbaud_rate);		// 设置波特率
	usart_parity_config(BSP_USART6, USART_PM_NONE);		// 没有校验位
	usart_word_length_set(BSP_USART6, USART_WL_8BIT);	// 8位数据位
	usart_stop_bit_set(BSP_USART6, USART_STB_1BIT);		// 1位停止位
	
	
	// 使能串口
	usart_enable(BSP_USART6);									// 使能串口
	usart_transmit_config(BSP_USART6, USART_TRANSMIT_ENABLE);	// 使能串口发送
	usart_receive_config(BSP_USART6, USART_RECEIVE_ENABLE);		// 使能串口接收
	
	
	// 配置NVIC中断
	// 配置中断优先级
	nvic_irq_enable(BSP_USART6_IRQ, 2, 2);
	// 使能串口中断
	// 使能串口接收中断（缓冲区不为空就会产生中断）
	usart_interrupt_enable(BSP_USART6, USART_INT_RBNE);
	// 使能串口空闲中断（帧中断）
	usart_interrupt_enable(BSP_USART6, USART_INT_IDLE);
	
}


/*!
    \brief    	发送数据的函数,一次只能发送一个字节的数据
    \param[in]  ucch: 发送的字符
    \param[out] none
    \retval     none
*/
void usart_send_data(uint8_t ucch)
{
	usart_data_transmit(BSP_USART, (uint8_t)ucch);
	while(RESET == usart_flag_get(BSP_USART, USART_FLAG_TBE)); // 等待直到一个字节的数据发送完成
}


/*!
    \brief    	发送数据的函数，一次发送一个字符串
    \param[in]  *ucstr: 发送的字符串的指针
    \param[out] none
    \retval     none
*/
void usart_send_string(uint8_t *ucstr)
{
	while(ucstr && *ucstr)  // 地址为空或值为空跳出
	{
		usart_send_data(*ucstr++);
	}
}

// printf输出的串口重定向
int fputc(int ch, FILE *f)
{
	usart_send_data(ch);
	
	return ch;
}


/*!
	\brief    	串口接收中断服务函数
    \param[in]  none
    \param[out] none
    \retval     none
*/
void BSP_USART_IRQHandler(void)
{
	if(usart_interrupt_flag_get(BSP_USART, USART_INT_FLAG_RBNE) != RESET)	// 接收缓冲区不为空
	{
		g_recv_buff[g_recv_length++] = usart_data_receive(BSP_USART);		// 将接收的到的数据存入数组
		// 清除标志位，由于上面的usart_data_receive函数会自动清除标志位，故注释掉
		// usart_interrupt_flag_clear(BSP_USART, USART_INT_FLAG_RBNE);
	}
	if(usart_interrupt_flag_get(BSP_USART, USART_INT_FLAG_IDLE) == SET)		// 检测数据帧标志是否为SET
	{
		usart_data_receive(BSP_USART);			// 使用数据接收函数进行标志位清除，不能直接进行标志位清除
		g_recv_buff[g_recv_length] = '\0';		// 数据帧接收完成，加'\0'表示数组结束
		g_recv_complete_flag = 1;				// 数据帧接收完成标志

	}
}


/*!
	\brief    	串口6接收中断服务函数
    \param[in]  none
    \param[out] none
    \retval     none
*/
void BSP_USART6_IRQHandler(void)
{
	if(usart_interrupt_flag_get(BSP_USART6, USART_INT_FLAG_RBNE) != RESET)	// 接收缓冲区不为空
	{
		g_recv_buff[g_recv_length++] = usart_data_receive(BSP_USART6);		// 将接收的到的数据存入数组
		// 清除标志位，由于上面的usart_data_receive函数会自动清除标志位，故注释掉
		// usart_interrupt_flag_clear(BSP_USART6, USART_INT_FLAG_RBNE);
	}
	if(usart_interrupt_flag_get(BSP_USART6, USART_INT_FLAG_IDLE) == SET)		// 检测数据帧标志是否为SET
	{
		usart_data_receive(BSP_USART6);			// 使用数据接收函数进行标志位清除，不能直接进行标志位清除
		g_recv_buff[g_recv_length] = '\0';		// 数据帧接收完成，加'\0'表示数组结束
		g_recv_complete_flag = 1;				// 数据帧接收完成标志

	}
}
	

