#include "pwm.h"
#include "stm32f10x.h"


//PWM �����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void PWM_Init(u16 arr,u16 psc)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	// 1. ʹ�ܶ�ʱ��3�����IO��ʱ�ӡ�
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);// 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);  //ʹ��GPIO����ʱ��ʹ��
	
	// 2. ���ø�����Ϊ�����������,��� TIM1 CH1 �� PWM ���岨��
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //�����������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	// 3.��ʼ����ʱ����ARR,PSC�ȣ�
	TIM_TimeBaseStructure.TIM_Period = arr;// ��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc;//����������Ϊ TIMx ʱ��Ƶ�ʳ�����Ԥ��Ƶֵ ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //���ϼ���
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //��ʼ�� TIMx
	
	// 4. ��ʼ������Ƚϲ���
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //�������ģʽ 2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0; //���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //������Ը�
	TIM_OC1Init(TIM1, &TIM_OCInitStructure); //�۳�ʼ������ TIMx
	
	// 5.MOE �����ʹ��
	TIM_CtrlPWMOutputs(TIM1,ENABLE); 
	
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); //CH1 Ԥװ��ʹ��
	
	TIM_ARRPreloadConfig(TIM1, ENABLE); //ʹ�� TIMx �� ARR �ϵ�Ԥװ�ؼĴ���
	
	TIM_Cmd(TIM1, ENABLE); //ʹ�� TIM1
	
}


	








