#include "stm32f10x.h"
#include "timer.h"
#include "mqtt.h"
#include "esp8266.h"


// ��ʱ��3��ʼ��
void TIMER_3_Init(u16 arr, u16 psc){
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeDefStrue;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//ʹ�ܶ�ʱ��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//��ʼ����ʱ��������ARR,PSC
	TIM_TimeBaseInitTypeDefStrue.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitTypeDefStrue.TIM_CounterMode = TIM_CounterMode_Up; // ����ģʽ
	TIM_TimeBaseInitTypeDefStrue.TIM_Period = arr; // �Զ�װ��ֵ
	TIM_TimeBaseInitTypeDefStrue.TIM_Prescaler = psc; // Ԥ��Ƶϵ��
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitTypeDefStrue);
	
	//������ʱ���жϣ�����NVIC
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���

	//ʹ�ܶ�ʱ��
	TIM_Cmd(TIM3,DISABLE);
}

// �жϺ���
void TIM3_IRQHandler(){
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) == SET){
		MQTT_Heart();// ��������
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	}
}

