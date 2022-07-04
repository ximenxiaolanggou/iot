#include "stm32f10x.h"
#include "timer.h"


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
	TIM_Cmd(TIM3,ENABLE);
}

// 中断函数
void TIM3_IRQHandler(){
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) == SET){
		if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_8)){
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
		}else{
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
		}
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	}
}


//定时器3 PWM初始化
void TIMER_1_PWM_Init(u16 arr, u16 psc){
	GPIO_InitTypeDef GPIO_InitTypeDefStrue;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeDefStrue;
	TIM_OCInitTypeDef TIM_OCInitTypeDefStrue;
	
	//使能定时器1时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	
	//使能GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//初始化IO口为复用功能输出
	GPIO_InitTypeDefStrue.GPIO_Pin = GPIO_Pin_8; //PA.8
	GPIO_InitTypeDefStrue.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitTypeDefStrue.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStrue);//初始化GPIOA.8
	
	//PA8用作定时器的PWM输出引脚，所以要重映射配置，所以需要开启AFIO时钟。同时设置重映射
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM1, ENABLE); 
	
	// 初始化定时器：ARR,PSC等
	TIM_TimeBaseInitTypeDefStrue.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitTypeDefStrue.TIM_CounterMode = TIM_CounterMode_Up; // 出发模式
	TIM_TimeBaseInitTypeDefStrue.TIM_Period = arr; // 自动装载值
	TIM_TimeBaseInitTypeDefStrue.TIM_Prescaler = psc; // 预分频系数
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitTypeDefStrue);
	
	//初始化输出比较参数
	TIM_OCInitTypeDefStrue.TIM_OCMode = TIM_OCMode_PWM2;//PWM模式1或者模式2
	TIM_OCInitTypeDefStrue.TIM_OutputState = TIM_OutputState_Enable; //输出使能 OR失能
	TIM_OCInitTypeDefStrue.TIM_Pulse = 0;// 比较值，写CCRx
	TIM_OCInitTypeDefStrue.TIM_OCPolarity = TIM_OCPolarity_High; // 比较输出极性
	TIM_OC1Init(TIM1,&TIM_OCInitTypeDefStrue);
	
	/*
		设置 MOE 输出，使能 PWM 输出。 。
		普通定时器在完成以上设置了之后，就可以输出 PWM 了，但是高级定时器，我们还需要
		使能刹车和死区寄存器（TIM1_BDTR）的 MOE 位，以使能整个 OCx（即 PWM）输出。库函
		数的设置函数为
	*/
	TIM_CtrlPWMOutputs(TIM1,ENABLE);	//MOE 主输出使能	
	//使能预装载寄存器
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); //CH1预装载使能	 
	
	
	
	//使能定时器
	TIM_Cmd(TIM1,ENABLE);
}

