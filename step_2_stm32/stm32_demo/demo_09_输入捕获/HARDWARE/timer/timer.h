#ifndef __TIMER_H
#define __TIMER_H

#include "sys.h"


// 定时器3初始化
void TIMER_3_Init(u16 arr, u16 psc);

//定时器3 PWM初始化
void TIMER_1_PWM_Init(u16 arr, u16 psc);

// 定时器2 通道1 输入捕获
void TIMER_2_Cap_Init(u16 arr, u16 psc);

#endif
