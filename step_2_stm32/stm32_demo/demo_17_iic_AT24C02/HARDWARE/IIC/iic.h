#ifndef __IIC_H
#define __IIC_H	 
#include "sys.h"

#define IIC_Port GPIOC // ����port

#define SDA GPIO_Pin_11 // SDA��������
#define SCL GPIO_Pin_12 // SCLʱ������


#define SDA_HIGH GPIO_SetBits(IIC_Port,SDA)  // SDA�ߵ�ƽ
#define SDA_LOW GPIO_ResetBits(IIC_Port,SDA) // SDA�͵�ƽ

#define SCL_HIGH GPIO_SetBits(IIC_Port,SCL)  // SCL�ߵ�ƽ
#define SCL_LOW GPIO_ResetBits(IIC_Port,SCL) // SCL�ߵ�ƽ
 
#define SDA_READ GPIO_ReadInputDataBit(IIC_Port,SDA) // ��ȡSDA��ƽ

// Ϊ0ʱ��ʾ���� 1ʱ��ʾ���
void IIC_SDA_IO(u8 io);
		 				    
// ��ʼ��
void IIC_Init(void);

// ��ʼ
void IIC_Start(void);

// ��ֹ
void IIC_Stop(void);

// �ȴ�Ӧ�� 1 ��Ӧ�� 0 Ӧ��
u8 IIC_Wait_Ack();

// ����ACK
void IIC_Ack(void);

// ������ACK
void IIC_NAck();

// ��������
void IIC_SendByte(u8 Data);

// ��������
u8 IIC_Read_Byte();

#endif
