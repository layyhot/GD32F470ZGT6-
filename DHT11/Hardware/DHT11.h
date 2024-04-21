#ifndef __DHT11_H
#define __DHT11_H

#include "gd32f4xx.h"
#include "Delay.h"


//// DHT11变量
//char str[20];
//uint8_t DHT_Buffer[5];


// 定义 DHT11 使用的 GPIO 端口和引脚
#define DHT_GPIO_PORT       GPIOA
#define DHT_GPIO_PIN        GPIO_PIN_4
#define DHT_RCU_GPIOx       RCU_GPIOA
#define DHT_RCC_PORT        RCU_APB2Periph_GPIOA

// 函数声明
void DHT_GPIO_Init(uint32_t gpio_periph, uint32_t pin, uint32_t mode);
uint8_t DHT_Start(void);
uint8_t DHT_Get_Byte_Data(void);
uint8_t DHT_Get_Temp_Humi_Data(uint8_t buffer[]);

#endif /* __DHT11_H */
