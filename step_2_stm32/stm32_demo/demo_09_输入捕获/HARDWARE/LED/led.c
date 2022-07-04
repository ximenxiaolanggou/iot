#include "stm32f10x.h"
#include "led.h"

// LED��ʼ��
void LED_Init(){

	GPIO_InitTypeDef GPIO_InitTypeDefStruct;
	
	// GPIOAʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// GPIODʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	
	// ��ʼ�� GPIOA
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStruct);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
	
	// ��ʼ�� GPIOD
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitTypeDefStruct);
	GPIO_SetBits(GPIOD,GPIO_Pin_2);


}
