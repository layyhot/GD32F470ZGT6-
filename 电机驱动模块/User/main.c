#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "bsp_led.h"
#include "bsp_pwm.h"



int main(void)
{

    systick_config();
    led_init();

    while(1)
    {        
        delay_1ms(1000);
		
        led_toggle(1);// 0-3 四个蓝灯以一秒时间闪烁
    }
}


