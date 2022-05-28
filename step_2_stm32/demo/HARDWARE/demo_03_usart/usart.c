#include "usart.h"
#include "stm32f10x.h"

void My_USART1_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitTypeDefStruct;
	USART_InitTypeDef USART_InitTypeDefStruct;
	NVIC_InitTypeDef NVIC_InitTypeDefStruct;
	
	
	/**
	
	1) ����ʱ��ʹ�ܣ�GPIO ʱ��ʹ��
	2) ���ڸ�λ
	3) GPIO �˿�ģʽ����
	4) ���ڲ�����ʼ��
	5) �����жϲ��ҳ�ʼ�� NVIC�������Ҫ�����жϲ���Ҫ������裩
	6) ʹ�ܴ���
	7) ��д�жϴ�����
	*/
	
	// 1. ����ʱ��ʹ�ܣ�GPIO ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	// 2.���ڸ�λ - ���Ǳ����
	USART_DeInit(USART1); 
	
	// 3.  GPIO �˿�ģʽ����
	// 3.1 GPIOA.9 ��ʼ��
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_AF_PP; // �����������
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitTypeDefStruct);
	
	// 3.2 GPIOA.10 ��ʼ��
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING; //��������
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIO_InitTypeDefStruct);
	
	// 4.���ڲ�����ʼ��
	USART_InitTypeDefStruct.USART_BaudRate = 115200; // ����������
	USART_InitTypeDefStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // //��Ӳ������������
	USART_InitTypeDefStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; // �շ�ģʽ
	USART_InitTypeDefStruct.USART_Parity = USART_Parity_No; // ����żУ��
	USART_InitTypeDefStruct.USART_StopBits = USART_StopBits_1; // һ��ֹͣλ
	USART_InitTypeDefStruct.USART_WordLength = USART_WordLength_8b; // �ֳ�Ϊ 8 λ
	USART_Init(USART1,&USART_InitTypeDefStruct);
	
	// 5.�����жϲ��ҳ�ʼ�� NVIC�������Ҫ�����жϲ���Ҫ������裩
	NVIC_InitTypeDefStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitTypeDefStruct.NVIC_IRQChannelCmd = ENABLE; // IRQ ͨ��ʹ��
	NVIC_InitTypeDefStruct.NVIC_IRQChannelPreemptionPriority = 1; //��ռ���ȼ� 1
	NVIC_InitTypeDefStruct.NVIC_IRQChannelSubPriority = 1; // //�����ȼ� 1
	NVIC_Init(&NVIC_InitTypeDefStruct); // //�ж����ȼ���ʼ��
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE); // �����ж�
	// 6.ʹ�ܴ���
	USART_Cmd(USART1,ENABLE);
 }

 // �жϺ���
void USART1_IRQHandler()
{
	u8 res;
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		res = USART_ReceiveData(USART1);
		USART_SendData(USART1,res);
	}
}
