#include "adc.h"

#define DEBUG   // 打开这个将会使能 adc_get_val下面的打印信息

uint16_t     adcValue;


void adc_gpio_init(void)
{
    // 使能时钟
    rcu_periph_clock_enable(RCU_ADC);
    // 模拟输入模式
    gpio_mode_set(PORT_ADC, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, PIN_ADC);

    // ADC复位
    adc_deinit();
    // 配置ADC的模式
    adc_sync_mode_config(ADC_SYNC_MODE_INDEPENDENT); // 所有ADC都工作在独立模式

    /* ADC contineous function disable */
    adc_special_function_config(ADC0, ADC_CONTINUOUS_MODE, DISABLE); // 关闭连续模式
    /* ADC scan mode disable */
    adc_special_function_config(ADC0, ADC_SCAN_MODE, DISABLE); // 关闭扫描模式
    
    /* ADC data alignment config */
    adc_data_alignment_config(ADC0, ADC_DATAALIGN_RIGHT); // LSB对齐，低位对齐
    
    /* ADC channel length config */
    adc_channel_length_config(ADC0, ADC_ROUTINE_CHANNEL, 1U); //  ADC规则通道 长度为1

    /* enable ADC interface */
    adc_enable(ADC0);
    /* wait for ADC stability */
    delay_1ms(1);
    /* ADC calibration and reset calibration */
    adc_calibration_enable(ADC0);  // ADC校准
    /* wait for ADC stability */
    delay_1ms(1);
        
    /* adc 引脚初始化 */
    adc_gpio_init();
}


/**
 * @description: ADC通道采样
 * @param {uint8_t} channel
 * @return {*}
 */
uint16_t adc_channel_sample(uint8_t channel)
{
    /* ADC regular channel config */
    // adc_regular_channel_config(ADC0, 0U, channel, ADC_SAMPLETIME_15); // 15个采样周期 
    adc_routine_channel_config(ADC0, 0U, channel, ADC_SAMPLETIME_15); // 15个采样周期 
    /* ADC software trigger enable */
    adc_software_trigger_enable(ADC0, ADC_ROUTINE_CHANNEL); // ADC软件触发使能

    /* wait the end of conversion flag */
    while(!adc_flag_get(ADC0, ADC_FLAG_EOC));
    /* clear the end of conversion flag */
    adc_flag_clear(ADC0, ADC_FLAG_EOC);
    /* return regular channel sample value */
    // return (adc_regular_data_read(ADC0));
    return(adc_sync_routine_data_read());
}

void adc_get_val(void)
{
    adcValue = adc_channel_sample(ADC_CHANNEL_15);  // 采样
    
#ifdef DEBUG
    printf("adcValue is :%d\r\n ",adcValue);
#endif
    
}














// #include "adc.h"
// #include "stdio.h"

// #define DEBUG   // 打开这个将会使能 adc_get_val下面的打印信息

// uint16_t 	adcValue;

// /************************************************
// 函数名称 ： adc_gpio_init
// 功    能 ： adc_gpio引脚配置,ADC的附加功能,优先于普通GPIO
// 参    数 ： 无
// 返 回 值 ： 无
// *************************************************/
// static void adc_gpio_init(void)
// {
// 	/* enable the clock */
//     rcu_periph_clock_enable(ADC_RCU);
//     /* configure GPIO port 附加功能需要配置为 GPIO_MODE_ANALOG */ 
//     gpio_mode_set(ADC_PORT, GPIO_MODE_ANALOG, GPIO_PUPD_NONE,ADC_PIN);
// }

// void adc_config(void)
// {
// 	/* enable ADC0 clock */
//     rcu_periph_clock_enable(RCU_ADC0);
// 	/* config ADC clock */
//     adc_clock_config(ADC_ADCCK_PCLK2_DIV8);
// 	/* reset ADC */
// 	adc_deinit();
// 	/* configure the ADC  mode */
//     adc_sync_mode_config(ADC_SYNC_MODE_INDEPENDENT); // 所有ADC都工作在独立模式
	
//     /* ADC contineous function disable */
//     adc_special_function_config(ADC0, ADC_CONTINUOUS_MODE, DISABLE); // 关闭连续模式
//     /* ADC scan mode disable */
//     adc_special_function_config(ADC0, ADC_SCAN_MODE, DISABLE); // 关闭扫描模式
	
// 	/* ADC data alignment config */
//     adc_data_alignment_config(ADC0,ADC_DATAALIGN_RIGHT); // LSB对齐，低位对齐
	
//     /* ADC channel length config */
//     adc_channel_length_config(ADC0,ADC_ROUTINE_CHANNEL,1U); //  ADC规则通道 长度为1

//     /* enable ADC interface */
//     adc_enable(ADC0);
//     /* wait for ADC stability */
//     delay_1ms(1);
//     /* ADC calibration and reset calibration */
//     adc_calibration_enable(ADC0);  // ADC校准
//     /* wait for ADC stability */
//     delay_1ms(1);
		
// 	/* adc 引脚初始化 */
// 	adc_gpio_init();
// }

// /*!
//     \brief      ADC channel sample  ADC通道采样
//     \param[in]  none
//     \param[out] none
//     \retval     none
// */
// uint16_t adc_channel_sample(uint8_t channel)
// {
//     /* ADC regular channel config */
//     adc_routine_channel_config(ADC0, 0U, channel, ADC_SAMPLETIME_15); // 15个采样周期 
//     /* ADC software trigger enable */
//     adc_software_trigger_enable(ADC0, ADC_ROUTINE_CHANNEL); // ADC软件触发使能

//     /* wait the end of conversion flag */
//     while(!adc_flag_get(ADC0, ADC_FLAG_EOC));
//     /* clear the end of conversion flag */
//     adc_flag_clear(ADC0, ADC_FLAG_EOC);
//     /* return regular channel sample value */
//     return (adc_sync_routine_data_read());
// }

// void adc_get_val(void)
// {
// 	adcValue = adc_channel_sample(ADC_CHANNEL_15);  // 采样
	
// #ifdef DEBUG
// 	printf("adcValue is :%d\r\n ",adcValue);
// #endif
	
// }


