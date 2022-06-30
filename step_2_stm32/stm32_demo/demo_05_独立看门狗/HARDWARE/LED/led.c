#include "stm32f10x.h"
#include "led.h"

// LED初始化
void LED_Init(){

	GPIO_InitTypeDef GPIO_InitTypeDefStruct;
	
	// GPIOA使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// GPIOD使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	
	// 初始化 GPIOA
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStruct);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
	
	// 初始化 GPIOD
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitTypeDefStruct);
	GPIO_SetBits(GPIOD,GPIO_Pin_2);


}
