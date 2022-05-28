#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
#include "exti.h"
#include "iwdg.h"
#include "timer.h"
#include "pwm.h"
#include "inacquire.h"


extern u8 TIM2CH1_CAPTURE_STA; //���벶��״̬
extern u16 TIM2CH1_CAPTURE_VAL; //���벶��ֵ
int main()
{
	u16 led0pwmval=0;
	u8 dir=1;
	u32 temp=0;
	delay_init();
	LED_Init();
	//KEY_Init();
	My_USART1_Init();
	//EXTIX_Init();
	
	// TIMER_Init(4999,7199); //10Khz �ļ���Ƶ�ʣ������� 5000 Ϊ 500ms
	
	
	// *****************LED*****************
	
	/**
		while(1)
	{

		GPIO_ResetBits(GPIOA,GPIO_Pin_8);
		GPIO_SetBits(GPIOD,GPIO_Pin_2);
		delay_ms(1000);
		GPIO_SetBits(GPIOA,GPIO_Pin_8);
		GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		delay_ms(1000);
		

	}
	
	**/
	
	// *****************GPIO*****************
	// KEY0 ��������
	// KEY1 ��������
	
	/**
	while(1)
	{
		KEYS* keyAction = KEY_SCAN();
		
		if(keyAction ->KEY0_P == 0)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
		}else {
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
		}
		
		if(keyAction ->KEY1_P == 0)
		{
			GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		}else {
			GPIO_SetBits(GPIOD,GPIO_Pin_2);
		}
	}
	**/
	
	// *****************���� - USART *****************
	/**
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	My_USART1_Init();
	while(1)
{
	printf("ok");
	delay_ms(1000);
};
**/

// *****************�ⲿ�ж� *****************
	/**
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����жϷ���
while(1) {
	delay_ms(1000);
 }
**/

// *****************�������Ź� *****************
// �����������κβ���ʱ����һֱ����װ�أ���ʱLED��һֱ������ ������key0�����������ι�����Ͳ�������װ�أ���һֱ����
/**
	delay_ms(200);
	GPIO_ResetBits(GPIOD,GPIO_Pin_2);
	IWDG_Init(4,625); // 1s
	while(1)
	{
		if(!KEY0)
		{
			IWDG_ReloadCounter();
		}
	}
**/

// *****************��ʱ���ж�*****************
/**
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
while(1);

**/

// *****************PWD*****************
	/**
	PWM_Init(899,0);//����Ƶ��PWM Ƶ��=72000/(899+1)=80Khz
	while(1)
	{
		delay_ms(10);
		if(dir)led0pwmval++;
		else led0pwmval--;
		if(led0pwmval>300)dir=0;
		if(led0pwmval==0)dir=1;
		TIM_SetCompare1(TIM1,led0pwmval);
	}
	
	**/
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	TIMER_Init(899,0); //����Ƶ��PWM Ƶ��=72000/(899+1)=80Khz
	TIM2_Cap_Init(0XFFFF,72-1); //�� 1Mhz ��Ƶ�ʼ���
	while(1)
	{
		delay_ms(10);
		TIM_SetCompare1(TIM1,TIM_GetCapture1(TIM1)+1);
		if(TIM_GetCapture1(TIM1)==300)TIM_SetCompare1(TIM1,0);
		if(TIM2CH1_CAPTURE_STA&0X80)//�ɹ�������һ�θߵ�ƽ
		{
		temp=TIM2CH1_CAPTURE_STA&0X3F;
		temp*=65536; //���ʱ���ܺ�
		temp+=TIM2CH1_CAPTURE_VAL; //�õ��ܵĸߵ�ƽʱ��
		USART_SendData(USART1,temp);
		TIM2CH1_CAPTURE_STA=0; //������һ�β���
	}
}
}

