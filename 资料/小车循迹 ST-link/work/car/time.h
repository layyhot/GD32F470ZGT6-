#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"

#define IN1 PBout(12)          
#define IN2 PBout(13)          
#define IN3 PBout(14)         
#define IN4 PBout(15) 

void TIM3_PWM_Init(u16 arr,u16 psc);

#endif
