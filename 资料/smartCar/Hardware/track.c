
#include "track.h"

FlagStatus XJ_01 = RESET;
FlagStatus XJ_02 = RESET;
FlagStatus XJ_03 = RESET;
FlagStatus XJ_04 = RESET;
FlagStatus XJ_05 = RESET;


void track_init(void)
{
    /* 第一路循迹 */
    // 使能时钟
    rcu_periph_clock_enable(RCU_XJ_01);
    // 输入模式 上拉
    gpio_mode_set(PORT_XJ_01, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, PIN_XJ_01);

    /* 第二路循迹 */
    // 使能时钟
    rcu_periph_clock_enable(RCU_XJ_02);
    // 输入模式 上拉
    gpio_mode_set(PORT_XJ_02, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, PIN_XJ_02);

    /* 第三路循迹 */
    // 使能时钟
    rcu_periph_clock_enable(RCU_XJ_03);
    // 输入模式 上拉
    gpio_mode_set(PORT_XJ_03, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, PIN_XJ_03);

    /* 第四路循迹 */
    // 使能时钟
    rcu_periph_clock_enable(RCU_XJ_04);
    // 输入模式 上拉
    gpio_mode_set(PORT_XJ_04, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, PIN_XJ_04);

    /* 第五路循迹 */
    // 使能时钟
    rcu_periph_clock_enable(RCU_XJ_05);
    // 输入模式 上拉
    gpio_mode_set(PORT_XJ_05, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, PIN_XJ_05);

}


void black_detection(void)
{

    XJ_01 = gpio_input_bit_get(PORT_XJ_01, PIN_XJ_01);
    XJ_02 = gpio_input_bit_get(PORT_XJ_02, PIN_XJ_02);
    XJ_03 = gpio_input_bit_get(PORT_XJ_03, PIN_XJ_03);
    XJ_04 = gpio_input_bit_get(PORT_XJ_04, PIN_XJ_04);
    XJ_05 = gpio_input_bit_get(PORT_XJ_05, PIN_XJ_05);

}





