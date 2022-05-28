#include "timer.h"
#include "stm32f10x.h"

void TIMER_Init(u16 arr,u16 psc)

{
	
		TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeDefStruct;
		NVIC_InitTypeDef NVIC_InitTypeDefStruct;
	

	 // 1. 能定时器时钟。
       RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	 // 2.初始化定时器，配置ARR,PSC。
			TIM_TimeBaseInitTypeDefStruct.TIM_ClockDivision = TIM_CKD_DIV1;//设置时钟分割
			TIM_TimeBaseInitTypeDefStruct.TIM_CounterMode = TIM_CounterMode_Up;//TIM 向上计数
			TIM_TimeBaseInitTypeDefStruct.TIM_Period = arr;//设置自动重装载寄存器周期的值
			TIM_TimeBaseInitTypeDefStruct.TIM_Prescaler = psc;//设置时钟频率除数的预分频值
      TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitTypeDefStruct);
	 // 3.开启定时器中断，配置NVIC。
      TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	
	// 5.开启中断并且初始化 NVIC（如果需要开启中断才需要这个步骤）
			NVIC_InitTypeDefStruct.NVIC_IRQChannel = TIM3_IRQn;
			NVIC_InitTypeDefStruct.NVIC_IRQChannelCmd = ENABLE; // IRQ 通道使能
			NVIC_InitTypeDefStruct.NVIC_IRQChannelPreemptionPriority = 2; //抢占优先级 2
			NVIC_InitTypeDefStruct.NVIC_IRQChannelSubPriority = 2; // //子优先级 2
			NVIC_Init(&NVIC_InitTypeDefStruct); // //中断优先级初始化
      
   // 4.使能定时器。
      TIM_Cmd(TIM3, ENABLE); 


}

//TIM3 中断
void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //检查 TIM3 更新中断发生与否
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update); //清除 TIM3 更新中断标志
		
		if(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2))
		{
			GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		}else {
			GPIO_SetBits(GPIOD,GPIO_Pin_2);
		}
}

}	
	








