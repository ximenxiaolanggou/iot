#include "stm32f10x.h"
#include "exti.h"
#include "key.h"
#include "delay.h"

// 初始化
void EXTIX_Init(void){
	
	GPIO_InitTypeDef GPIO_InitTypeDefStruct;
	EXTI_InitTypeDef EXTI_InitTypeDefStruct;
	NVIC_InitTypeDef NVIC_InitTypeDefStruct;
	
	// GPIOC使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	// 开启IO口复用时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	// 初始化 GPIOC_5  KEY0
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitTypeDefStruct);
	
	//设置IO口与中断线的映射关系
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource5);
	
	// 初始化线上中断，设置触发条件等
	EXTI_InitTypeDefStruct.EXTI_Line = EXTI_Line5;
	EXTI_InitTypeDefStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitTypeDefStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitTypeDefStruct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitTypeDefStruct);
	
	// 配置中断分组（NVIC）
	NVIC_InitTypeDefStruct.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitTypeDefStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitTypeDefStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitTypeDefStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitTypeDefStruct);
	
}

// 中断服务函数
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
	EXTI_ClearITPendingBit(EXTI_Line5); //清除 LINE5 上的中断标志位
}




