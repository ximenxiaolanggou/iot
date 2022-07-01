#ifndef __IWDOG_H
#define __IWDOG_H
#include "stm32f10x.h"
// 独立看门狗初始化
void IWDG_Init(u8 prer, u16 rlr);

// 喂狗
void IWDG_Feed(void);
#endif
