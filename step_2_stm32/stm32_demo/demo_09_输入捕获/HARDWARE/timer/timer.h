#ifndef __TIMER_H
#define __TIMER_H

#include "sys.h"


// ��ʱ��3��ʼ��
void TIMER_3_Init(u16 arr, u16 psc);

//��ʱ��3 PWM��ʼ��
void TIMER_1_PWM_Init(u16 arr, u16 psc);

// ��ʱ��2 ͨ��1 ���벶��
void TIMER_2_Cap_Init(u16 arr, u16 psc);

#endif
