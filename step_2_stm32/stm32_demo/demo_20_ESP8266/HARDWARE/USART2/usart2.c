#include "usart2.h"

void USART2_Init()
{
 
	GPIO_InitTypeDef GPIO_InitTypeDefStrue;
	NVIC_InitTypeDef NVIC_InitTypeDefStrue;
	USART_InitTypeDef USART_InitTypeDefStrue;
	
	// ʹ��GPIO_Aʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// ʹ��USART1ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	USART_DeInit(USART2);  //��λ����2
	
	// ����GPIO�������ģʽ
	GPIO_InitTypeDefStrue.GPIO_Mode = GPIO_Mode_AF_PP; // ���츴��
	GPIO_InitTypeDefStrue.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitTypeDefStrue.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStrue);
	
	GPIO_InitTypeDefStrue.GPIO_Mode = GPIO_Mode_IN_FLOATING; // ��������
	GPIO_InitTypeDefStrue.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitTypeDefStrue.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStrue);
	
	// ���ڲ�����ʼ��
	USART_InitTypeDefStrue.USART_BaudRate = 9600; // ������
	USART_InitTypeDefStrue.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //Ӳ��������
	USART_InitTypeDefStrue.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; // ���շ���ģʽ
	USART_InitTypeDefStrue.USART_Parity = USART_Parity_No; // ������żУ��
	USART_InitTypeDefStrue.USART_StopBits = USART_StopBits_1; // ֹͣλ
	USART_InitTypeDefStrue.USART_WordLength = USART_WordLength_8b; // ���ݳ���
	USART_Init(USART2,&USART_InitTypeDefStrue);
	
	// ��ʼ��NVIC
	NVIC_InitTypeDefStrue.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitTypeDefStrue.NVIC_IRQChannelCmd = ENABLE;	// IRQͨ��ʹ��
	NVIC_InitTypeDefStrue.NVIC_IRQChannelPreemptionPriority = 3; // ��ռ���ȼ�
	NVIC_InitTypeDefStrue.NVIC_IRQChannelSubPriority = 3; // �����ȼ�
	NVIC_Init(&NVIC_InitTypeDefStrue);
	
	// �����ж�
	USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
	
	// ʹ�ܴ���
	USART_Cmd(USART2, ENABLE);						 //PD.2 ����� 
}

// �����ַ���
void USART_SendString(char *strData)
{
	while(*strData != '\0')
	{
		 
		USART_SendData(USART2, *strData);
		while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);//��ȡ����״̬
		strData++;
	}
	
	
}

 // ����1�ж�
void USART2_IRQHandler(){
	 
	u8 res;
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
	if(USART_GetITStatus(USART2,USART_IT_RXNE)){
		res = USART_ReceiveData(USART2);
		
	}

}
 
