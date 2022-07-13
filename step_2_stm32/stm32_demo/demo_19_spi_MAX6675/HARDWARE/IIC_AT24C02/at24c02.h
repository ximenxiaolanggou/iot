#ifndef __AT24C02_H
#define __AT24C02_H	 
#include "sys.h"

#define WRITE 0xA0
#define READ 0xA1

// 初始化
void AT24C02_Init(void);

// 发送一个字节
void AT24C02_SendByte(u8 Address, u8 Data);

// 读一个字节
u8 AT24C02_ReadByte(u8 Address);

#endif
