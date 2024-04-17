#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "bsp_led.h"
#include "tcrt5000_tracking.h"


int main(void)
{

    systick_config();
    led_init();
	Tracking_Init();

    while(1)
    {        
        delay_1ms(1000);
		if(gpio_input_bit_get(GPIOA, GPIO_PIN_15) == 0) led_toggle(1);
        // 0-3 四个蓝灯以一秒时间闪烁
    }
}
