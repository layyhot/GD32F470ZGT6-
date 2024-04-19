#include "motor.h"



void Motor_Init(void)
{
	ENABLE_CLOCK(RCU_GPIOB);
	ENABLE_CLOCK(RCU_GPIOA);
	
    // 左前轮
    SET_GPIO_MODE(GPIOB, GPIO_PIN_4, GPIO_MODE_OUTPUT, GPIO_OSPEED_50MHZ, GPIO_AF_2);
    SET_GPIO_HIGH(GPIOB, GPIO_PIN_4);
    
    
    SET_GPIO_MODE(GPIOA, GPIO_PIN_7, GPIO_MODE_OUTPUT, GPIO_OSPEED_50MHZ, GPIO_AF_2);
    SET_GPIO_HIGH(GPIOA, GPIO_PIN_7);
    
    // 左后轮
    SET_GPIO_MODE(GPIOB, GPIO_PIN_0, GPIO_MODE_OUTPUT, GPIO_OSPEED_50MHZ, GPIO_AF_2);
    SET_GPIO_HIGH(GPIOB, GPIO_PIN_0);
    
    SET_GPIO_MODE(GPIOB, GPIO_PIN_1, GPIO_MODE_OUTPUT, GPIO_OSPEED_50MHZ, GPIO_AF_2);
    SET_GPIO_HIGH(GPIOB, GPIO_PIN_1);
    
    // 右后轮
    SET_GPIO_MODE(GPIOA, GPIO_PIN_0, GPIO_MODE_OUTPUT, GPIO_OSPEED_50MHZ, GPIO_AF_1);
    SET_GPIO_HIGH(GPIOA, GPIO_PIN_0);
    
    SET_GPIO_MODE(GPIOA, GPIO_PIN_1, GPIO_MODE_OUTPUT, GPIO_OSPEED_50MHZ, GPIO_AF_1);
    SET_GPIO_HIGH(GPIOA, GPIO_PIN_1);
    
    // 右后轮
    SET_GPIO_MODE(GPIOA, GPIO_PIN_2, GPIO_MODE_OUTPUT, GPIO_OSPEED_50MHZ, GPIO_AF_1);
    SET_GPIO_HIGH(GPIOA, GPIO_PIN_2);
    
    SET_GPIO_MODE(GPIOA, GPIO_PIN_3, GPIO_MODE_OUTPUT, GPIO_OSPEED_50MHZ, GPIO_AF_1);
    SET_GPIO_HIGH(GPIOA, GPIO_PIN_3);
	
}



//左前轮前进，后退，停止
void motor_LQ_front(uint16_t speed)
{
	gpio_mode_set(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_4);
	LQ_FI = 0;
	
}
//void notor_LQ_back(uint16_t speed)
//void notor_LQ_stop(uint8_t mode)
////左后轮前进，后退，停止
//void notor_LH_front(uint16_t speed)
//void motor_LH_back(uint16_t speed)
//void motor_LH_stop(uint8_t mode)
////右前轮前进，后退，停止
//void motor_RO_front(uint16_t speed)
//void motor_RQ_back(uint16_t speed)
//void notor_RQ_stop(uint8_t mode)
////右后轮前进，后港，停止
//void motor_R_front(uint16_t speed)
//void notor_RH back(uint16_t speed)
//void motor_RH_stop(uint8_t mode)


