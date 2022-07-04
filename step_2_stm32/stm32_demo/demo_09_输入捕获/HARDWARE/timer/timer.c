#include "stm32f10x.h"
#include "timer.h"
#include "usart.h"


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


// 定时器2 通道1 输入捕获
void TIMER_2_Cap_Init(u16 arr, u16 psc){
	
	TIM_ICInitTypeDef TIM_ICInitTypeDefStrue;
	NVIC_InitTypeDef NVIC_InitStructure;
	GPIO_InitTypeDef GPIO_InitTypeDefStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitTypeDefStrue;
	
	//使能 TIM2 时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 
	// GPIOA使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	// 初始化 GPIOA_0  WK_UP
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStruct);
	
	// 初始化定时器：ARR,PSC等
	TIM_TimeBaseInitTypeDefStrue.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitTypeDefStrue.TIM_CounterMode = TIM_CounterMode_Up; // 出发模式
	TIM_TimeBaseInitTypeDefStrue.TIM_Period = arr; // 自动装载值
	TIM_TimeBaseInitTypeDefStrue.TIM_Prescaler = psc; // 预分频系数
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitTypeDefStrue);
	
	//初始化输入捕获通道
	TIM_ICInitTypeDefStrue.TIM_Channel = TIM_Channel_1;
	TIM_ICInitTypeDefStrue.TIM_ICFilter = 0x00;
	TIM_ICInitTypeDefStrue.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICInitTypeDefStrue.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICInitTypeDefStrue.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM2,&TIM_ICInitTypeDefStrue);
	
	//开启定时器中断，配置NVIC
	
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
	TIM_ITConfig(TIM2,TIM_IT_Update | TIM_IT_CC1,ENABLE);
	//使能定时器
	TIM_Cmd(TIM2,ENABLE);

}

// 中断服务
u8 TIM3CH1_CAPTURE_STA = 0; // 输入捕获状态
u16 TIM3CH1_CAPTURE_VAL; // 输入捕获值
void TIM2_IRQHandler(){
	if((TIM3CH1_CAPTURE_STA & 0x80) == 0){ // 还未完成
	
		// 更新时间
		if(TIM_GetITStatus(TIM3,TIM_IT_Update) == SET){
			if(TIM3CH1_CAPTURE_STA & 0x40) { // 已捕获到上升沿
				if((TIM3CH1_CAPTURE_STA & 0x3f) == 0x3f){// 按的时间太长
					TIM3CH1_CAPTURE_STA |= 0x80;
					TIM3CH1_CAPTURE_VAL = 0xffff;
				}else TIM3CH1_CAPTURE_STA ++;
			
			}
		}
	
	}
	
	// 输入捕获 
	if(TIM_GetITStatus(TIM2,TIM_IT_CC1) == SET){ 
		printf("asd");
		if((TIM3CH1_CAPTURE_STA & 0x40) == 0) { // 上升沿捕获 - WK_UP按下
			// 清空值
			TIM3CH1_CAPTURE_STA = 0;
			TIM3CH1_CAPTURE_VAL = 0;
			TIM3CH1_CAPTURE_STA |= 0x40;
			TIM_SetCounter(TIM2,0);
			TIM_OC1PolarityConfig(TIM2,TIM_ICPolarity_Falling);
		}else{ // // 下降沿捕获 - WK_UP松开
			TIM3CH1_CAPTURE_STA |= 0x80;
			TIM3CH1_CAPTURE_VAL = TIM_GetCapture1(TIM2);
			TIM_OC1PolarityConfig(TIM2,TIM_ICPolarity_Rising);
		}
	}
}

