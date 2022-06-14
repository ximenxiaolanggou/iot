#ifndef __AT24C02_H__
#define __AT24C02_H__

// 写
void AT24C02_WriteByte(unsigned char WordAddress, unsigned char Data);

// 读
unsigned char AT24C02_ReadByte(unsigned char WordAddress);
#endif