#include "stm32f10x.h"
#include "timer.h"
#include "mqtt.h"
#include "esp8266.h"


// 定时器3初始化
void TIMER_3_Init(u16 arr, u16 psc){
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeDefStrue;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//使能定时器时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//初始化定时器，配置ARR,PSC
	TIM_TimeBaseInitTypeDefStrue.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitTypeDefStrue.TIM_CounterMode = TIM_CounterMode_Up; // 出发模式
	TIM_TimeBaseInitTypeDefStrue.TIM_Period = arr; // 自动装载值
	TIM_TimeBaseInitTypeDefStrue.TIM_Prescaler = psc; // 预分频系数
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitTypeDefStrue);
	
	//开启定时器中断，配置NVIC
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器

	//使能定时器
	TIM_Cmd(TIM3,DISABLE);
}

// 中断函数
void TIM3_IRQHandler(){
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) == SET){
		MQTT_Heart();// 发送心跳
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	}
}

