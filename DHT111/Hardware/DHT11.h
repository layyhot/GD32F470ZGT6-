#ifndef __DHT11_H
#define __DHT11_H

#include "gd32f4xx.h" 
#include "Delay.h"

// ����׼��
//char str[20];

//uint8_t DHT_Buffer[5];

#define DHT_GPIO_PORT		GPIOA
#define DHT_GPIO_PIN		GPIO_Pin_4
#define DHT_RCC_PORT		RCC_APB2Periph_GPIOA

uint8_t DHT_Get_Temp_Humi_Data(uint8_t buffer[]);

#endif


