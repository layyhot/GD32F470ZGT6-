#include "gd32f4xx.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "bsp_led.h"



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


//#include "gd32f4xx.h"
//#include "gd32f450i_eval.h"
//#include <stdio.h>

///*!
//    \brief      main function
//    \param[in]  none
//    \param[out] none
//    \retval     none
//*/
//int main(void)
//{
//    /* enable GPIO clock */
//    rcu_periph_clock_enable(RCU_GPIOA);

//    /* enable USART clock */
//    rcu_periph_clock_enable(RCU_USART0);

//    /* configure the USART0 TX pin and USART0 RX pin */
//    gpio_af_set(GPIOA, GPIO_AF_7, GPIO_PIN_9);
//    gpio_af_set(GPIOA, GPIO_AF_7, GPIO_PIN_10);

//    /* configure USART0 TX as alternate function push-pull */
//    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_9);
//    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_9);

//    /* configure USART0 RX as alternate function push-pull */
//    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_10);
//    gpio_output_options_set(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_10);

//    /* USART configure */
//    usart_deinit(USART0);
//    usart_baudrate_set(USART0, 115200U);
//    usart_receive_config(USART0, USART_RECEIVE_ENABLE);
//    usart_transmit_config(USART0, USART_TRANSMIT_ENABLE);
//    usart_enable(USART0);

//    printf("a usart transmit test example!");
//    while(1);
//}

///* retarget the C library printf function to the USART */
//int fputc(int ch, FILE *f)
//{
//    usart_data_transmit(EVAL_COM0, (uint8_t)ch);
//    while(RESET == usart_flag_get(EVAL_COM0, USART_FLAG_TBE));
//    return ch;
//}
