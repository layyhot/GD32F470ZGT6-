#ifndef __OLED_H
#define __OLED_H

#include <stdint.h>
#include "gd32f4xx.h" 
#include "systick.h" 

//SDA端口移植
#define	RCU_SDA		RCU_GPIOB
#define	PORT_SDA	GPIOB
#define	GPIO_SDA	GPIO_PIN_9
//SCL端口移植
#define	RCU_SCL		RCU_GPIOB
#define	PORT_SCL	GPIOB
#define	GPIO_SCL	GPIO_PIN_8
 
//设置SDA输出模式
#define SDA_OUT()   gpio_mode_set(PORT_SDA,GPIO_MODE_OUTPUT,GPIO_PUPD_PULLUP,GPIO_SDA)
 
//设置SDA输入模式
#define SDA_IN()        gpio_mode_set(PORT_SDA,GPIO_MODE_INPUT,GPIO_PUPD_PULLUP,GPIO_SDA)
 
//获取SDA引脚的电平变化
#define SDA_GET()        gpio_input_bit_get(PORT_SDA,GPIO_SDA) 
 
#define OLED_COMM_DELAY_MS  1000 // 设置为1毫秒，可以根据实际情况调整

#define OLED_W_SDA(x)    gpio_bit_write(PORT_SDA, GPIO_SDA, (x ? SET : RESET)); delay_1ms(OLED_COMM_DELAY_MS)
#define OLED_W_SCL(x)    gpio_bit_write(PORT_SCL, GPIO_SCL, (x ? SET : RESET)); delay_1ms(OLED_COMM_DELAY_MS)



void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

#endif
