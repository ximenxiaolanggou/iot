#include "stm32f10x.h"
#include "wwdog.h"

u8 WWDG_CNT = 0x7F;

/*
tr: ������ֵ
wr: ����ֵ
fprer: ��Ƶϵ��

*/
// �������Ź���ʼ��
void WWDG_Init(u8 tr,u8 wr, u32 fprer){
	
	NVIC_InitTypeDef NVIC_InitTypeDefStrue;
	
	//ʹ�ܿ��Ź�ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	
	WWDG_CNT = tr&WWDG_CNT;
	
	// ���÷�Ƶϵ��
	WWDG_SetPrescaler(fprer);
	
	// �����ϴ���ֵ
	WWDG_SetWindowValue(wr);
	
	
	
	// ������ǰ�����жϲ�����
	
	NVIC_InitTypeDefStrue.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitTypeDefStrue.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitTypeDefStrue.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitTypeDefStrue.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitTypeDefStrue);
	WWDG_EnableIT();
	
// ʹ�ܿ��Ź�
	WWDG_Enable(WWDG_CNT);
	
	// �����ǰ�����жϱ�־λ
	WWDG_ClearFlag(); 
	
	
}

// ι��
void WWDG_Set(u8 cnt){
	WWDG_SetCounter(cnt);
}

// WWDG�ж�
void WWDG_IRQHandler() {
	WWDG_SetCounter(WWDG_CNT);
	WWDG_ClearFlag(); // �����ǰ�����жϱ�־λ
}
