#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "bsp_led.h"
#include "Delay.h"
#include "dht11.h"
#include <string.h>
#include <stdio.h>
#include "OLED.h"

// DHT11±‰¡ø
char str[20];
uint8_t DHT_Buffer[5];

int main(void)
{

    systick_config();
	OLED_Init();

    while(1)
    {      
		OLED_ShowString(1, 1, "Hello!");
		

    }
}


