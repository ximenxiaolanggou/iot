#ifndef __IWDOG_H
#define __IWDOG_H
#include "stm32f10x.h"
// �������Ź���ʼ��
void IWDG_Init(u8 prer, u16 rlr);

// ι��
void IWDG_Feed(void);
#endif
