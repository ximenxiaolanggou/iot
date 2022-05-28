#include "usart.h"
#include "stm32f10x.h"

void My_USART1_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitTypeDefStruct;
	USART_InitTypeDef USART_InitTypeDefStruct;
	NVIC_InitTypeDef NVIC_InitTypeDefStruct;
	
	
	/**
	
	1) 串口时钟使能，GPIO 时钟使能
	2) 串口复位
	3) GPIO 端口模式设置
	4) 串口参数初始化
	5) 开启中断并且初始化 NVIC（如果需要开启中断才需要这个步骤）
	6) 使能串口
	7) 编写中断处理函数
	*/
	
	// 1. 串口时钟使能，GPIO 时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	// 2.串口复位 - 不是必须的
	USART_DeInit(USART1); 
	
	// 3.  GPIO 端口模式设置
	// 3.1 GPIOA.9 初始化
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_AF_PP; // 复用推挽输出
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitTypeDefStruct);
	
	// 3.2 GPIOA.10 初始化
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING; //浮空输入
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIO_InitTypeDefStruct);
	
	// 4.串口参数初始化
	USART_InitTypeDefStruct.USART_BaudRate = 115200; // 波特率设置
	USART_InitTypeDefStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // //无硬件数据流控制
	USART_InitTypeDefStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; // 收发模式
	USART_InitTypeDefStruct.USART_Parity = USART_Parity_No; // 无奇偶校验
	USART_InitTypeDefStruct.USART_StopBits = USART_StopBits_1; // 一个停止位
	USART_InitTypeDefStruct.USART_WordLength = USART_WordLength_8b; // 字长为 8 位
	USART_Init(USART1,&USART_InitTypeDefStruct);
	
	// 5.开启中断并且初始化 NVIC（如果需要开启中断才需要这个步骤）
	NVIC_InitTypeDefStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitTypeDefStruct.NVIC_IRQChannelCmd = ENABLE; // IRQ 通道使能
	NVIC_InitTypeDefStruct.NVIC_IRQChannelPreemptionPriority = 1; //抢占优先级 1
	NVIC_InitTypeDefStruct.NVIC_IRQChannelSubPriority = 1; // //子优先级 1
	NVIC_Init(&NVIC_InitTypeDefStruct); // //中断优先级初始化
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE); // 开启中断
	// 6.使能串口
	USART_Cmd(USART1,ENABLE);
 }

 // 中断函数
void USART1_IRQHandler()
{
	u8 res;
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		res = USART_ReceiveData(USART1);
		USART_SendData(USART1,res);
	}
}
