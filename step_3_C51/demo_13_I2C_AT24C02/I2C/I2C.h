#ifndef __I2C_H__
#define __I2C_H__


// 启动
void I2C_Start();

// 停止
void I2C_Stop();

// 发送字节
void I2C_SendByte(unsigned char Byte);

// 接收字节 
unsigned char I2C_ReceiveByte();

// 发送ACK
void I2C_SendAck(unsigned char AckBit);

// 接收ACK
unsigned char I2C_ReceiveAck();

#endif
