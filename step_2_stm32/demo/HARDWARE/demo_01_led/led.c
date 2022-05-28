#include "led.h"
#include "stm32f10x.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); // GPIOA
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE); // GPIOD
	
	// GPIOA初始化 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	// 设置为高电平 - 不点亮
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
	
	// GPIOD初始化 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	// 设置为高电平 - 不点亮
	GPIO_SetBits(GPIOD,GPIO_Pin_2);
 }

 
 
 
 
 