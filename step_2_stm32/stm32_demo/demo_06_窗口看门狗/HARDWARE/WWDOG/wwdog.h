#ifndef __WWDOG_H
#define __WWDOG_H
#include "stm32f10x.h"
// ���ڿ��Ź���ʼ��
void WWDG_Init(u8 tr,u8 wr, u32 fprer);

// ι��
void WWDG_Set(u8 cnt);
#endif
