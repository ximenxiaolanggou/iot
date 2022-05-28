#include "timer.h"
#include "stm32f10x.h"

void TIMER_Init(u16 arr,u16 psc)

{
	
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeDefStruct;
		NVIC_InitTypeDef NVIC_InitTypeDefStruct;
	

	 // 1. �ܶ�ʱ��ʱ�ӡ�
       RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	 // 2.��ʼ����ʱ��������ARR,PSC��
			TIM_TimeBaseInitTypeDefStruct.TIM_ClockDivision = TIM_CKD_DIV1;//����ʱ�ӷָ�
			TIM_TimeBaseInitTypeDefStruct.TIM_CounterMode = TIM_CounterMode_Up;//TIM ���ϼ���
			TIM_TimeBaseInitTypeDefStruct.TIM_Period = arr;//�����Զ���װ�ؼĴ������ڵ�ֵ
			TIM_TimeBaseInitTypeDefStruct.TIM_Prescaler = psc;//����ʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
      TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitTypeDefStruct);
	 // 3.������ʱ���жϣ�����NVIC��
      TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	
	// 5.�����жϲ��ҳ�ʼ�� NVIC�������Ҫ�����жϲ���Ҫ������裩
			NVIC_InitTypeDefStruct.NVIC_IRQChannel = TIM3_IRQn;
			NVIC_InitTypeDefStruct.NVIC_IRQChannelCmd = ENABLE; // IRQ ͨ��ʹ��
			NVIC_InitTypeDefStruct.NVIC_IRQChannelPreemptionPriority = 2; //��ռ���ȼ� 2
			NVIC_InitTypeDefStruct.NVIC_IRQChannelSubPriority = 2; // //�����ȼ� 2
			NVIC_Init(&NVIC_InitTypeDefStruct); // //�ж����ȼ���ʼ��
      
   // 4.ʹ�ܶ�ʱ����
      TIM_Cmd(TIM3, ENABLE); 


}

//TIM3 �ж�
void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //��� TIM3 �����жϷ������
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update); //��� TIM3 �����жϱ�־
		
		if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2))
		{
			GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		}else {
			GPIO_SetBits(GPIOD,GPIO_Pin_2);
		}
}

}	
	








