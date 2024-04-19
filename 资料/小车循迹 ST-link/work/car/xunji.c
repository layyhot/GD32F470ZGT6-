#include "xunji.h"  
#include "stm32f10x.h"

void motor_gpio()
{

  GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_10|GPIO_Pin_11; 		
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	  //推挽输出 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     

}

void xunji_gpio()
{

  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_5;		
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  //上拉输入
  GPIO_Init(GPIOB, &GPIO_InitStructure);		

}
void pwm()
{

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_8; 		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //复用输出 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 
  GPIO_Init(GPIOB, &GPIO_InitStructure);

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	  //使能定时器4时钟 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);   //使能GPIOB时钟
	  

	
	TIM_TimeBaseStructure.TIM_Period =99;    //设置在下一个更新事件装入活动的自动重装载寄存器周期的值
	TIM_TimeBaseStructure.TIM_Prescaler =71;     //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;   //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;   //TIM向上计数模式 
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);    
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  //选择定时器模式:TIM脉冲宽度调制模式1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;    //输出极性:TIM输出比较极性高
  TIM_OCInitStructure.TIM_Pulse=0;
	
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);  
	

	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);   //使能TIM4在CCR1上的预装载寄存器
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);   //使能TIM4在CCR3上的预装载寄存器

	
	TIM_Cmd(TIM4, ENABLE);   //使能TIM4
}
void run()
{

		TIM_SetCompare1(TIM4,30);  
   	TIM_SetCompare3(TIM4,30);
		IN1 = 1;
		IN2 = 0;
		
		IN3 = 1;
		IN4 = 0;
}
void back()
{
		TIM_SetCompare1(TIM4,70);
		TIM_SetCompare3(TIM4,70);
	
		IN1 = 0;
		IN2 = 1;
		
 
		IN3 = 0;
		IN4 = 1;
}
void right()
{
		TIM_SetCompare1(TIM4,0);
		TIM_SetCompare3(TIM4,30);
	
		IN1 = 1;
		IN2 = 0;
	  
		IN3 = 0;
		IN4 = 0;
}
void left()
{
		TIM_SetCompare1(TIM4,30);
		TIM_SetCompare3(TIM4,0);
		
		IN1 = 0;
		IN2 = 0;
		
		IN3 = 1;
		IN4 = 0;
}

void stop()
{

		 IN1 = 0;
		 IN2 = 0;
		
		 IN3 = 0;
		 IN4 = 0;
	}
