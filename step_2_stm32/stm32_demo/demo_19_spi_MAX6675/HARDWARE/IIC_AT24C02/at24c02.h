#ifndef __AT24C02_H
#define __AT24C02_H	 
#include "sys.h"

#define WRITE 0xA0
#define READ 0xA1

// ��ʼ��
void AT24C02_Init(void);

// ����һ���ֽ�
void AT24C02_SendByte(u8 Address, u8 Data);

// ��һ���ֽ�
u8 AT24C02_ReadByte(u8 Address);

#endif
