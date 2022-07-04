#ifndef __WWDOG_H
#define __WWDOG_H
#include "stm32f10x.h"
// 窗口看门狗初始化
void WWDG_Init(u8 tr,u8 wr, u32 fprer);

// 喂狗
void WWDG_Set(u8 cnt);
#endif
