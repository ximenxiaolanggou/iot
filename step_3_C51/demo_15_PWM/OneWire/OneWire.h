#ifndef __OneWire_H__
#define __OneWire_H__

// 初始化
unsigned char OneWire_Init(void);

// 发送一位
void OneWire_SendBit(unsigned char Bit);

// 接收一位
unsigned char OneWire_ReceiveBit(void);

// 发送一字节
void OneWire_SendByte(unsigned char Byte);

// 接收一字节
unsigned char OneWire_ReceiveByte();
#endif
