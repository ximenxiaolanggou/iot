#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"

void EXTIX_Init(void)
{
		
	EXTI_InitTypeDef EXTI_InitTypeDefStruct;
	NVIC_InitTypeDef NVIC_InitTypeDefStruct;
	
	// 2. 开启IO口复用时钟。
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	// 3.设置IO口与中断线的映射关系
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource5);
	
	// 4.初始化线上中断，设置触发条件等
	EXTI_InitTypeDefStruct.EXTI_Line = EXTI_Line5;
	EXTI_InitTypeDefStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitTypeDefStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitTypeDefStruct.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&EXTI_InitTypeDefStruct);
	
	// 5.配置中断分组（NVIC），并使能中断。
	NVIC_InitTypeDefStruct.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitTypeDefStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitTypeDefStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitTypeDefStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitTypeDefStruct);
	
}
 
// 中断函数
void EXTI9_5_IRQHandler()
{
	static uint8_t pin_8stat = 1;
	delay_ms(10);
	if(pin_8stat)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_8);
		GPIO_ResetBits(GPIOD,GPIO_Pin_2);
	}else{
		GPIO_ResetBits(GPIOA,GPIO_Pin_8);
		GPIO_SetBits(GPIOD,GPIO_Pin_2);
	}
	pin_8stat = !pin_8stat;
	EXTI_ClearITPendingBit(EXTI_Line5);
} 