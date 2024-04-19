/* 串口中断DMA接收二合一 */

实验现象：烧录程序之后，在串口助手发送端发送数据，将会在串口助手接收端接收到发送的数据，
并打印出接收到的数据长度。


有两种情况，如果是用串口中断接收，请配置bsp_usart.h文件中的USB_USART_DMA为0
			如果是用串口DMA接收，请配置bsp_usart.h文件中的USB_USART_DMA为1
			
串口中断接收：
下载程序之后串口助手将会打印Interrupt receive
然后可以发送数据
例如发送 ：立创开发板
接收端将会打印：g_recv_length:10 g_recv_buff:立创开发板


串口DMA接收：
下载程序之后串口助手将会打印DMA receive
然后可以发送数据
例如发送 ：立创开发板
接收端将会打印：g_recv_length:10 g_recv_buff:立创开发板

