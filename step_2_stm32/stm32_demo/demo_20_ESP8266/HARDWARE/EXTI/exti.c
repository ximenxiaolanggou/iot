#include "sys.h"
#include "exti.h"
#include "key.h"
#include "delay.h"
#include "mqtt.h"
#include "esp8266.h"
#include "usart2.h"



// ��ʼ��
void EXTIX_Init(void){
	
	GPIO_InitTypeDef GPIO_InitTypeDefStruct;
	EXTI_InitTypeDef EXTI_InitTypeDefStruct;
	NVIC_InitTypeDef NVIC_InitTypeDefStruct;
	
	// GPIOCʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	// ����IO�ڸ���ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	// ��ʼ�� GPIOC_5  KEY0
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitTypeDefStruct);
	
	//����IO�����ж��ߵ�ӳ���ϵ
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource5);
	
	// ��ʼ�������жϣ����ô���������
	EXTI_InitTypeDefStruct.EXTI_Line = EXTI_Line5;
	EXTI_InitTypeDefStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitTypeDefStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitTypeDefStruct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypeDefStruct);
	
	// �����жϷ��飨NVIC��
	NVIC_InitTypeDefStruct.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitTypeDefStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitTypeDefStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitTypeDefStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitTypeDefStruct);
	
}


// �жϷ�����
void EXTI9_5_IRQHandler(){

	u8 key;
	delay_ms(10);

	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_8)){
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
			GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		}else {
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
			GPIO_SetBits(GPIOD,GPIO_Pin_2);
		}
		

	USART_SendString(AT_CIPSTART);
	delay_ms(1000); // 1000

	USART_SendString(AT_CIPMODE);
	delay_ms(1000); // 2000ms
	
	USART_SendString(AT_CIPSEND);
	delay_ms(1000); // 2000ms
		
	MQTT_Login("test","wogua","wogua");
	delay_ms(1000); // 2000ms
	
	delay_ms(1000); // 1s
	MQTT_Sub("test");
	delay_ms(1000); // 1000ms
    //ʹ�ܶ�ʱ�� ��������
	TIM_Cmd(TIM3,ENABLE);
	EXTI_ClearITPendingBit(EXTI_Line5); //��� LINE5 �ϵ��жϱ�־λ
}




