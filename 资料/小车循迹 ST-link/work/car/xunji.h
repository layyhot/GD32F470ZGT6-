
#ifndef __xunji_H
#define __xunji_H 	

#include "sys.h"  

#define      IN1         PBout(0)
#define      IN2         PBout(1)

#define      IN3         PBout(10)
#define      IN4         PBout(11)


#define      LEFT_ONE      PBin(3)  
#define      LEFT_TWO      PBin(5) 
 
void run(void);
void left(void);
void right(void);
void back(void);;
void stop(void);
void motor_gpio(void);
void xunji_gpio(void);
void pwm(void);
#endif


