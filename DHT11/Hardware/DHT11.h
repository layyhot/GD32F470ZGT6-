#ifndef __DHT11_H
#define __DHT11_H

#include "gd32f4xx.h" 
#include "Delay.h"

// 变量准备
//char str[20];

//uint8_t DHT_Buffer[5];

typedef struct
{
  uint32_t GPIO_Pin;             /*!< Specifies the GPIO pins to be configured.
                                      This parameter can be any value of @ref GPIO_pins_define */

  uint32_t GPIO_Speed;  /*!< Specifies the speed for the selected pins.
                                      This parameter can be a value of @ref GPIOSpeed_TypeDef */

  GPIOMode_TypeDef GPIO_Mode;    /*!< Specifies the operating mode for the selected pins.
                                      This parameter can be a value of @ref GPIOMode_TypeDef */
}GPIO_InitTypeDef;




#define DHT_GPIO_PORT		GPIOA
#define DHT_GPIO_PIN		GPIO_Pin_4
#define DHT_RCC_PORT		RCC_APB2Periph_GPIOA

uint8_t DHT_Get_Temp_Humi_Data(uint8_t buffer[]);

#endif



