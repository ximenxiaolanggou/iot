#include <REGX52.H>
#include "AT24C02.H"
#include "I2C.H"

#define AT24C02_ADDRESS 0xA0

// 写
void AT24C02_WriteByte(unsigned char WordAddress, unsigned char Data)
{
	// 启动
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS);
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	I2C_SendByte(Data);
	I2C_ReceiveAck();
	I2C_Stop();
}

// 读
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
	unsigned char Data;
	// 启动
	I2C_Start();
	I2C_SendByte(AT24C02_ADDRESS);
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	I2C_Start();
	I2C_SendByte(0xA1);
	I2C_ReceiveAck();
	Data = I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_Stop();
	return Data;
}