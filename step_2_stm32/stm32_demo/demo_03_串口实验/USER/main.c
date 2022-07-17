#include "stm32f10x.h"
#include "delay.h"

// 串口初始化函数
void My_Uart1_Init(void) {
	GPIO_InitTypeDef GPIO_InitTypeDefStrue;
	NVIC_InitTypeDef NVIC_InitTypeDefStrue;
	USART_InitTypeDef USART_InitTypeDefStrue;
	
	// 使能GPIO_A时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// 使能USART1时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	// 设置GPIO输入输出模式
	GPIO_InitTypeDefStrue.GPIO_Mode = GPIO_Mode_AF_PP; // 推挽复用
	GPIO_InitTypeDefStrue.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitTypeDefStrue.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStrue);
	
	GPIO_InitTypeDefStrue.GPIO_Mode = GPIO_Mode_IN_FLOATING; // 浮空输入
	GPIO_InitTypeDefStrue.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitTypeDefStrue.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStrue);
	
	// 串口参数初始化
	USART_InitTypeDefStrue.USART_BaudRate = 115200; // 波特率
	USART_InitTypeDefStrue.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //硬件流控制
	USART_InitTypeDefStrue.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; // 接收发送模式
	USART_InitTypeDefStrue.USART_Parity = USART_Parity_No; // 有无奇偶校验
	USART_InitTypeDefStrue.USART_StopBits = USART_StopBits_1; // 停止位
	USART_InitTypeDefStrue.USART_WordLength = USART_WordLength_8b; // 数据长度
	USART_Init(USART1,&USART_InitTypeDefStrue);
	
	// 初始化NVIC
	NVIC_InitTypeDefStrue.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitTypeDefStrue.NVIC_IRQChannelCmd = ENABLE;	// IRQ通道使能
	NVIC_InitTypeDefStrue.NVIC_IRQChannelPreemptionPriority = 3; // 抢占优先级
	NVIC_InitTypeDefStrue.NVIC_IRQChannelSubPriority = 3; // 子优先级
	NVIC_Init(&NVIC_InitTypeDefStrue);
	
	// 启动中断
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	// 使能串口
	USART_Cmd(USART1, ENABLE);
}

 // 串口1中断
void USART2_IRQHandler(){
	u8 res;
	if(USART_GetITStatus(USART1,USART_IT_RXNE)){
		res = USART_ReceiveData(USART1);
		USART_SendData(USART1,res);
	}

}

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	My_Uart1_Init();
	while(1);
}