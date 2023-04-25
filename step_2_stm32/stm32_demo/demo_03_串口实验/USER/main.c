#include "stm32f10x.h"
#include "delay.h"

// ���ڳ�ʼ������
void My_Uart1_Init(void) {
	GPIO_InitTypeDef GPIO_InitTypeDefStrue;
	NVIC_InitTypeDef NVIC_InitTypeDefStrue;
	USART_InitTypeDef USART_InitTypeDefStrue;
	
	// ʹ��GPIO_Aʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// ʹ��USART1ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	// ����GPIO�������ģʽ
	GPIO_InitTypeDefStrue.GPIO_Mode = GPIO_Mode_AF_PP; // ���츴��
	GPIO_InitTypeDefStrue.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitTypeDefStrue.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStrue);
	
	GPIO_InitTypeDefStrue.GPIO_Mode = GPIO_Mode_IN_FLOATING; // ��������
	GPIO_InitTypeDefStrue.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitTypeDefStrue.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStrue);
	
	// ���ڲ�����ʼ��
	USART_InitTypeDefStrue.USART_BaudRate = 115200; // ������
	USART_InitTypeDefStrue.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //Ӳ��������
	USART_InitTypeDefStrue.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; // ���շ���ģʽ
	USART_InitTypeDefStrue.USART_Parity = USART_Parity_No; // ������żУ��
	USART_InitTypeDefStrue.USART_StopBits = USART_StopBits_1; // ֹͣλ
	USART_InitTypeDefStrue.USART_WordLength = USART_WordLength_8b; // ���ݳ���
	USART_Init(USART1,&USART_InitTypeDefStrue);
	
	// ��ʼ��NVIC
	NVIC_InitTypeDefStrue.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitTypeDefStrue.NVIC_IRQChannelCmd = ENABLE;	// IRQͨ��ʹ��
	NVIC_InitTypeDefStrue.NVIC_IRQChannelPreemptionPriority = 3; // ��ռ���ȼ�
	NVIC_InitTypeDefStrue.NVIC_IRQChannelSubPriority = 3; // �����ȼ�
	NVIC_Init(&NVIC_InitTypeDefStrue);
	
	// �����ж�
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	// ʹ�ܴ���
	USART_Cmd(USART1, ENABLE);
}

 // ����1�ж�
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