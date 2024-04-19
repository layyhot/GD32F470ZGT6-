#include "stm32f10x.h"
#include "xunji.h"
#include "delay.h"


/*
			双轮驱动 

Motor：       PB0、PB1     PB10、PB11
PWM(TIM4)：   PB6(CH1)     PB8(CH3)
IR：          PB3          PB5
 
*/




//初始化小车状态
 void Init()
{
	TIM_SetCompare1(TIM4,25);
	TIM_SetCompare3(TIM4,25);
	IN1=1;
	IN2=0;
	IN3=1;
	IN4=0;
}
 
 int main(void)
 {	

		motor_gpio();   //引脚初始化
		xunji_gpio();
		pwm();           //PWM初始化   
		delay_init();
	  Init();         //初始化小车状态
			while(1)
			{
 
					if(LEFT_ONE==0&&LEFT_TWO==0)        //都没踩到黑线
					{
							 run();
					}
					
					else if(LEFT_ONE==0&&LEFT_TWO==1)   //右边探头踩到黑线
					{
					
							right();
					}
					
					else if(LEFT_ONE==1&&LEFT_TWO==0)  //左边探头踩到黑线
					{
					
							left();
					}
					
		      else if(LEFT_ONE==1&&LEFT_TWO==1)   //都踩到黑线
					{
					
							run();
					}
					
					else
						stop();
				
			 }
	
}

