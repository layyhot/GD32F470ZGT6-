#include "gd32f4xx.h"

typedef struct
{
    rcu_periph_enum clock;
    uint32_t gpio_port;
    uint32_t gpio_pin;
    bit_status init_val;
}led_t;

static const led_t g_led_cfg[] = 
{
    {RCU_GPIOE, GPIOE, GPIO_PIN_3, RESET},
    {RCU_GPIOD, GPIOD, GPIO_PIN_7, RESET},
    {RCU_GPIOG, GPIOG, GPIO_PIN_3, RESET},
    {RCU_GPIOA, GPIOA, GPIO_PIN_5, RESET},
    
};

static const uint32_t g_led_num = sizeof(g_led_cfg) / sizeof(led_t);

void led_init(void)
{
    uint32_t i = 0;
    
    for (i = 0; i < g_led_num; i++)
    {
        /* 使能时钟 */
        rcu_periph_clock_enable(g_led_cfg[i].clock);
        /* 配置为输出模式 浮空模式 */
        gpio_mode_set(g_led_cfg[i].gpio_port, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, g_led_cfg[i].gpio_pin);
        /* 配置为推挽输出 50MHZ */
        gpio_output_options_set(g_led_cfg[i].gpio_port, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, g_led_cfg[i].gpio_pin);
    }
}


void led_on(uint32_t led_id)
{
    if (led_id >= g_led_num)
    {
        return;
    }
    
    gpio_bit_write(g_led_cfg[led_id].gpio_port, g_led_cfg[led_id].gpio_pin, (bit_status)!g_led_cfg[led_id].init_val);
    
}


void led_off(uint32_t led_id)
{    
    if (led_id >= g_led_num)
    {
        return;
    }
    
    gpio_bit_write(g_led_cfg[led_id].gpio_port, g_led_cfg[led_id].gpio_pin, g_led_cfg[led_id].init_val);
    
}



void led_toggle(uint32_t led_id)
{
    if (led_id >= g_led_num)
    {
        return;
    }
    
    gpio_bit_toggle(g_led_cfg[led_id].gpio_port, g_led_cfg[led_id].gpio_pin);
}
