#ifndef __SPI1_H
#define __SPI1_H

#include "sys.h"

#define IIC_Port GPIOC // ����port

#define SDA GPIO_Pin_11 // SDA��������
#define SCL GPIO_Pin_12 // SCLʱ������


#define SDA_HIGH GPIO_SetBits(IIC_Port,SDA)  // SDA�ߵ�ƽ
#define SDA_LOW GPIO_ResetBits(IIC_Port,SDA) // SDA�͵�ƽ

#define SCL_HIGH GPIO_SetBits(IIC_Port,SCL)  // SCL�ߵ�ƽ
#define SCL_LOW GPIO_ResetBits(IIC_Port,SCL) // SCL�ߵ�ƽ
 
#define SDA_READ GPIO_ReadInputDataBit(IIC_Port,SDA) // ��ȡSDA��ƽ

// ��ʼ��
void SPI1_Init(void);

// ����Ԥ��Ƶϵ��
void SPI1_SetSpeed(u8 SpeedSet);

// ��дһ���ֽ�
u8 SPI1_ReadWriteByte(u8 TxData);
#endif
