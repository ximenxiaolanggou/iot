#include "pwm.h"
#include "stm32f10x.h"


//PWM 输出初始化
//arr：自动重装值
//psc：时钟预分频数
void PWM_Init(u16 arr,u16 psc)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	// 1. 使能定时器3和相关IO口时钟。
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);// 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);  //使能GPIO外设时钟使能
	
	// 2. 设置该引脚为复用输出功能,输出 TIM1 CH1 的 PWM 脉冲波形
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; //复用推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	// 3.初始化定时器：ARR,PSC等：
	TIM_TimeBaseStructure.TIM_Period = arr;// 设置在下一个更新事件装入活动的自动重装载寄存器周期的值 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc;//设置用来作为 TIMx 时钟频率除数的预分频值 不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //向上计数
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //初始化 TIMx
	
	// 4. 初始化输出比较参数
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //脉宽调制模式 2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性高
	TIM_OC1Init(TIM1, &TIM_OCInitStructure); //③初始化外设 TIMx
	
	// 5.MOE 主输出使能
	TIM_CtrlPWMOutputs(TIM1,ENABLE); 
	
	TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable); //CH1 预装载使能
	
	TIM_ARRPreloadConfig(TIM1, ENABLE); //使能 TIMx 在 ARR 上的预装载寄存器
	
	TIM_Cmd(TIM1, ENABLE); //使能 TIM1
	
}


	








