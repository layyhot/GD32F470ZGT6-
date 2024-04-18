#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stdint.h"

void led_init(void);
void led_on(uint32_t led_id);
void led_off(uint32_t led_id);
void led_toggle(uint32_t led_id);

#endif /* BSP_LED_H */

