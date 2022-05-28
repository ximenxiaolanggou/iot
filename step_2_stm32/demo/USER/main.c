#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"
#include "exti.h"
#include "iwdg.h"
#include "timer.h"
#include "pwm.h"
#include "inacquire.h"


extern u8 TIM2CH1_CAPTURE_STA; //输入捕获状态
extern u16 TIM2CH1_CAPTURE_VAL; //输入捕获值
int main()
{
	u16 led0pwmval=0;
	u8 dir=1;
	u32 temp=0;
	delay_init();
	LED_Init();
	//KEY_Init();
	My_USART1_Init();
	//EXTIX_Init();
	
	// TIMER_Init(4999,7199); //10Khz 的计数频率，计数到 5000 为 500ms
	
	
	// *****************LED*****************
	
	/**
		while(1)
	{

		GPIO_ResetBits(GPIOA,GPIO_Pin_8);
		GPIO_SetBits(GPIOD,GPIO_Pin_2);
		delay_ms(1000);
		GPIO_SetBits(GPIOA,GPIO_Pin_8);
		GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		delay_ms(1000);
		

	}
	
	**/
	
	// *****************GPIO*****************
	// KEY0 长按灯亮
	// KEY1 长按灯亮
	
	/**
	while(1)
	{
		KEYS* keyAction = KEY_SCAN();
		
		if(keyAction ->KEY0_P == 0)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
		}else {
			GPIO_SetBits(GPIOA,GPIO_Pin_8);
		}
		
		if(keyAction ->KEY1_P == 0)
		{
			GPIO_ResetBits(GPIOD,GPIO_Pin_2);
		}else {
			GPIO_SetBits(GPIOD,GPIO_Pin_2);
		}
	}
	**/
	
	// *****************串口 - USART *****************
	/**
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	My_USART1_Init();
	while(1)
{
	printf("ok");
	delay_ms(1000);
};
**/

// *****************外部中断 *****************
	/**
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断分组
while(1) {
	delay_ms(1000);
 }
**/

// *****************独立看门狗 *****************
// 描述：当无任何操作时，会一直重新装载，这时LED会一直闪动， 当按下key0按键，会进行喂狗，就不会重新装载，灯一直亮着
/**
	delay_ms(200);
	GPIO_ResetBits(GPIOD,GPIO_Pin_2);
	IWDG_Init(4,625); // 1s
	while(1)
	{
		if(!KEY0)
		{
			IWDG_ReloadCounter();
		}
	}
**/

// *****************定时器中断*****************
/**
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
while(1);

**/

// *****************PWD*****************
	/**
	PWM_Init(899,0);//不分频。PWM 频率=72000/(899+1)=80Khz
	while(1)
	{
		delay_ms(10);
		if(dir)led0pwmval++;
		else led0pwmval--;
		if(led0pwmval>300)dir=0;
		if(led0pwmval==0)dir=1;
		TIM_SetCompare1(TIM1,led0pwmval);
	}
	
	**/
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	TIMER_Init(899,0); //不分频。PWM 频率=72000/(899+1)=80Khz
	TIM2_Cap_Init(0XFFFF,72-1); //以 1Mhz 的频率计数
	while(1)
	{
		delay_ms(10);
		TIM_SetCompare1(TIM1,TIM_GetCapture1(TIM1)+1);
		if(TIM_GetCapture1(TIM1)==300)TIM_SetCompare1(TIM1,0);
		if(TIM2CH1_CAPTURE_STA&0X80)//成功捕获到了一次高电平
		{
		temp=TIM2CH1_CAPTURE_STA&0X3F;
		temp*=65536; //溢出时间总和
		temp+=TIM2CH1_CAPTURE_VAL; //得到总的高电平时间
		USART_SendData(USART1,temp);
		TIM2CH1_CAPTURE_STA=0; //开启下一次捕获
	}
}
}

