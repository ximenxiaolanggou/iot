#include "stm32f10x.h"
#include "key.h"
#include "delay.h"

// KEY初始化
void KEY_Init(void) {
	
	GPIO_InitTypeDef GPIO_InitTypeDefStruct;
	
	// GPIOA使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// GPIOC使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	// 初始化 GPIOC_5  KEY0
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitTypeDefStruct);
	
	// 初始化 GPIOA_15  KEY1
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStruct);
	
	// 初始化 GPIOA_0  WK_UP
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStruct);
}

// 获取按下的按键
// 0 代表KEY0按下， 1 代表KEY1 按下， 3 代表WK_UP按下 - 1代表未按下
// mode 0 不支持连续按 1 支持连续按
char KEY_Scan(char mode){
	
	static u8 key_up = 1; // 按键松开标识位
	
	if(mode) { // 支持长按
		key_up = 1;
	}
	
	// 有按键按下
	if(	key_up && (!GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)  || 
			!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15) || 
			GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0))){
				
				delay_ms(10); // 消抖
				key_up = 0; // 按下
				if(!GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)) return 0;
				else if(!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)) return 1;
				else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)) return 2;
	}else if(	key_up && 
						GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5) && 
						GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15) && 
						!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)){
						key_up = 1;
	}			
		
		return -1; // 无按键按下
}




