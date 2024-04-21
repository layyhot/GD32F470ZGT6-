#include "dht11.h"

/**
  * @brief  DHT11_GPIO初始化函数
  * @param  Mode：指定输入或输出模式
  * @return None
  */
void DHT_GPIO_Init(uint32_t gpio_periph, uint32_t pin, uint32_t mode)
{
    gpio_deinit(gpio_periph); // 重置 GPIO 端口

    gpio_mode_set(gpio_periph, mode, GPIO_PUPD_PULLUP, pin); // 设置 GPIO 模式为指定模式
}

/**
  * @brief  DHT11模块起始信号函数
  * @param  None
  * @return 1或0，标志起动信号成功与否
  */
uint8_t DHT_Start(void)
{
    DHT_GPIO_Init(DHT_GPIO_PORT, DHT_GPIO_PIN, GPIO_MODE_OUTPUT); // 输出模式

    gpio_bit_reset(DHT_GPIO_PORT, DHT_GPIO_PIN); // 输出20ms低电平后拉高
    Delay_ms(20);
    gpio_bit_set(DHT_GPIO_PORT, DHT_GPIO_PIN);

    DHT_GPIO_Init(DHT_GPIO_PORT, DHT_GPIO_PIN, GPIO_MODE_INPUT); // 输入模式
    Delay_us(20);

    if (!gpio_input_bit_get(DHT_GPIO_PORT, DHT_GPIO_PIN))
    {
        while (!gpio_input_bit_get(DHT_GPIO_PORT, DHT_GPIO_PIN))
            ;
        while (gpio_input_bit_get(DHT_GPIO_PORT, DHT_GPIO_PIN))
            ;
        return 1;
    }
    return 0;
}

/**
  * @brief  接收DHT11发送来8位的数据
  * @param  None
  * @return 返回接收到的8位数据
  */
uint8_t DHT_Get_Byte_Data(void)
{
	int i;
    uint8_t temp = 0;
    for (i = 0; i < 8; i++)
    {
        temp <<= 1;
        while (!gpio_input_bit_get(DHT_GPIO_PORT, DHT_GPIO_PIN))
            ;
        Delay_us(28);
        if (gpio_input_bit_get(DHT_GPIO_PORT, DHT_GPIO_PIN))
        {
            temp |= 0x01;
        }
        while (gpio_input_bit_get(DHT_GPIO_PORT, DHT_GPIO_PIN))
            ;
    }
    return temp;
}

/**
  * @brief  获取DHT11的温度湿度数据
  * @param  buffer[]：需要传入一个存储数据的数组
  * @return 返回数据校验是否正确 1：正确 0：失败
  */
uint8_t DHT_Get_Temp_Humi_Data(uint8_t buffer[])
{
    if (DHT_Start())
    {
        buffer[0] = DHT_Get_Byte_Data();
        buffer[1] = DHT_Get_Byte_Data();
        buffer[2] = DHT_Get_Byte_Data();
        buffer[3] = DHT_Get_Byte_Data();
        buffer[4] = DHT_Get_Byte_Data();
    }
    return (buffer[0] + buffer[1] + buffer[2] + buffer[3] == buffer[4]) ? 1 : 0;
}
