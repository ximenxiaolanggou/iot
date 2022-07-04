#include "stm32f10x.h"
#include "wwdog.h"

u8 WWDG_CNT = 0x7F;

/*
tr: 计数器值
wr: 窗口值
fprer: 分频系数

*/
// 独立看门狗初始化
void WWDG_Init(u8 tr,u8 wr, u32 fprer){
	
	NVIC_InitTypeDef NVIC_InitTypeDefStrue;
	
	//使能看门狗时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	
	WWDG_CNT = tr&WWDG_CNT;
	
	// 设置分频系数
	WWDG_SetPrescaler(fprer);
	
	// 设置上窗口值
	WWDG_SetWindowValue(wr);
	
	
	
	// 开启提前唤醒中断并分组
	
	NVIC_InitTypeDefStrue.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitTypeDefStrue.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitTypeDefStrue.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitTypeDefStrue.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitTypeDefStrue);
	WWDG_EnableIT();
	
// 使能看门狗
	WWDG_Enable(WWDG_CNT);
	
	// 清楚提前唤醒中断标志位
	WWDG_ClearFlag(); 
	
	
}

// 喂狗
void WWDG_Set(u8 cnt){
	WWDG_SetCounter(cnt);
}

// WWDG中断
void WWDG_IRQHandler() {
	WWDG_SetCounter(WWDG_CNT);
	WWDG_ClearFlag(); // 清楚提前唤醒中断标志位
}
