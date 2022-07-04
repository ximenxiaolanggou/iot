#include "stm32f10x.h"
#include "timer.h"


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
	TIM_Cmd(TIM3,ENABLE);
}

// �жϺ���
void TIM3_IRQHandler(){
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) == SET){
		if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_8)){
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
		}else{
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
		}
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	}
}


//��ʱ��3 PWM��ʼ��
void TIMER_1_PWM_Init(u16 arr, u16 psc){
	GPIO_InitTypeDef GPIO_InitTypeDefStrue;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeDefStrue;
	TIM_OCInitTypeDef TIM_OCInitTypeDefStrue;
	
	//ʹ�ܶ�ʱ��1ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	//ʹ��GPIOAʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//��ʼ��IO��Ϊ���ù������
	GPIO_InitTypeDefStrue.GPIO_Pin = GPIO_Pin_8; //PA.8
	GPIO_InitTypeDefStrue.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitTypeDefStrue.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStrue);//��ʼ��GPIOA.8
	
	//PA8������ʱ����PWM������ţ�����Ҫ��ӳ�����ã�������Ҫ����AFIOʱ�ӡ�ͬʱ������ӳ��
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM1, ENABLE); 
	
	// ��ʼ����ʱ����ARR,PSC��
	TIM_TimeBaseInitTypeDefStrue.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitTypeDefStrue.TIM_CounterMode = TIM_CounterMode_Up; // ����ģʽ
	TIM_TimeBaseInitTypeDefStrue.TIM_Period = arr; // �Զ�װ��ֵ
	TIM_TimeBaseInitTypeDefStrue.TIM_Prescaler = psc; // Ԥ��Ƶϵ��
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitTypeDefStrue);
	
	//��ʼ������Ƚϲ���
	TIM_OCInitTypeDefStrue.TIM_OCMode = TIM_OCMode_PWM2;//PWMģʽ1����ģʽ2
	TIM_OCInitTypeDefStrue.TIM_OutputState = TIM_OutputState_Enable; //���ʹ�� ORʧ��
	TIM_OCInitTypeDefStrue.TIM_Pulse = 0;// �Ƚ�ֵ��дCCRx
	TIM_OCInitTypeDefStrue.TIM_OCPolarity = TIM_OCPolarity_High; // �Ƚ��������
	TIM_OC1Init(TIM1,&TIM_OCInitTypeDefStrue);
	
	/*
		���� MOE �����ʹ�� PWM ����� ��
		��ͨ��ʱ�����������������֮�󣬾Ϳ������ PWM �ˣ����Ǹ߼���ʱ�������ǻ���Ҫ
		ʹ��ɲ���������Ĵ�����TIM1_BDTR���� MOE λ����ʹ������ OCx���� PWM��������⺯
		�������ú���Ϊ
	*/
	TIM_CtrlPWMOutputs(TIM1,ENABLE);	//MOE �����ʹ��	
	//ʹ��Ԥװ�ؼĴ���
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); //CH1Ԥװ��ʹ��	 
	
	
	
	//ʹ�ܶ�ʱ��
	TIM_Cmd(TIM1,ENABLE);
}

