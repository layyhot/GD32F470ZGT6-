#include "tcrt5000_tracking.h"



void Tracking_Init(void)
{
	rcu_periph_clock_enable(TRCT5000_RCU_GPIOx_1);
	gpio_mode_set(TRCT5000_PORT_1, GPIO_MODE_INPUT, GPIO_PUPD_NONE, TRCT5000_PIN_x_1);
	
	rcu_periph_clock_enable(TRCT5000_RCU_GPIOx_2);
	gpio_mode_set(TRCT5000_PORT_2, GPIO_MODE_INPUT, GPIO_PUPD_NONE, TRCT5000_PIN_x_2);
	
	rcu_periph_clock_enable(TRCT5000_RCU_GPIOx_3);
	gpio_mode_set(TRCT5000_PORT_3, GPIO_MODE_INPUT, GPIO_PUPD_NONE, TRCT5000_PIN_x_3);

}

