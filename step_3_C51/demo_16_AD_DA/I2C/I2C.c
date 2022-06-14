#include "I2C.H"

#include <REGX52.H>

sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2^0;

// 初始化
void I2C_Start()
{
	I2C_SDA = 1;
	I2C_SCL = 1;
	I2C_SDA = 0;
	I2C_SCL = 0;
}

// 停止
void I2C_Stop()
{
	I2C_SDA = 0;
	I2C_SCL = 1;
	I2C_SDA = 1;
}

// 发送字节
void I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	I2C_SCL = 0;
	for(i = 0 ; i < 8 ; i++)
	{
		
		I2C_SDA = Byte&(0x80 >> i);
		I2C_SCL = 1;
		I2C_SCL = 0;
	}
	
}

// 接收字节 
unsigned char I2C_ReceiveByte()
{
	unsigned char i;
	unsigned char Byte = 0x00;
	for(i = 0 ; i < 8 ; i++)
	{
		I2C_SCL = 1;
		if(I2C_SDA) Byte |= (0x80 >> i);
		I2C_SCL = 0;
		
	}
	return Byte;
}

// 发送ACK
void I2C_SendAck(unsigned char AckBit)
{
	I2C_SDA = AckBit;
	I2C_SCL = 1;
	I2C_SCL = 0;
}

// 接收ACK
unsigned char I2C_ReceiveAck()
{
	unsigned char AckBit;
	I2C_SCL = 1;
	AckBit = I2C_SDA;
	I2C_SCL = 0;
	return AckBit;
}