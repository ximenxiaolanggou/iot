#include "key.h"
#include "stm32f10x.h"
#include "delay.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); // GPIOA
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); // GPIOC
	
	// GPIOA初始化 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOA,&GPIO_InitStructure); // WAKE_UP
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_Init(GPIOA,&GPIO_InitStructure); // KEY_1

	
	// GPIOC初始化 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; // KEY_0
	GPIO_Init(GPIOC,&GPIO_InitStructure);
 }

 KEYS* KEY_SCAN(void)
	 
 {
	 KEYS KEY_ACTION = {1,1,0};
	 
	 if(KEY0==0||KEY1==0||WAKEUP==1) { // 有按键按下
		  delay_ms(10);//去抖动 
		  if(KEY0==0) KEY_ACTION.KEY0_P = 0; // KEY_0
			if(KEY0==1) KEY_ACTION.KEY1_P = 0; // KEY_1
			if(WAKEUP == 1) KEY_ACTION.WAKEUP_P = 1; // KEY_WAKEUP  
	 }
		
	 return &KEY_ACTION;
 } 
 