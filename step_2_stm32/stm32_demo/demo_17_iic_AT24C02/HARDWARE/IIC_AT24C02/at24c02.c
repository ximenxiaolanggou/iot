#include "iic.h"
#include "delay.h"
#include "at24c02.h"
#include "usart.h"

u8 ack;

// ��ʼ��
void AT24C02_Init(void){
	IIC_Init();
}

// ����һ���ֽ�
void AT24C02_SendByte(u8 Address,u8 Data){
	
	IIC_Start();// ��ʼ
	
	IIC_SendByte(WRITE); // д����
	
	ack = IIC_Wait_Ack(); // �ȴ�ACK
	printf("1: %d\r\n",ack);
	
	IIC_SendByte(Address); // ���ݵ�ַ
	
	ack = IIC_Wait_Ack(); // �ȴ�ACK
	
	printf("2: %d\r\n",ack);
	
	IIC_SendByte(Data); // д����
	
	ack = IIC_Wait_Ack(); // �ȴ�ACK
	printf("3: %d\r\n",ack);
	
	IIC_Stop();// ��ֹ
	
	delay_ms(10);

}

// ��һ���ֽ�
u8 AT24C02_ReadByte(u8 Address){
	u8 Data;
	
	IIC_Start();// ��ʼ
	
	IIC_SendByte(WRITE); // д����
	
	ack = IIC_Wait_Ack(); // �ȴ�ACK
	printf("4: %d\r\n",ack);
	IIC_SendByte(Address); // ��ַ
	
	ack = IIC_Wait_Ack(); // �ȴ�ACK
	printf("5: %d\r\n",ack);
	IIC_Start();// ��ʼ
	
	IIC_SendByte(READ); // ������
	
	ack = IIC_Wait_Ack(); // �ȴ�ACK
	printf("6: %d\r\n",ack);
	Data = IIC_Read_Byte(); // ��ȡ����
	
	IIC_NAck(); // ��ӦAck
	
	IIC_Stop();// ��ֹ
	
	return Data;
	
}



 
