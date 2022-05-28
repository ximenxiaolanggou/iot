#include "sys.h"

#ifndef __TIMER_H__
#define __TIMER_H__

void TIMER_Init(u16 arr,u16 psc);

void TIM3_IRQHandler(void);
	
#endif
