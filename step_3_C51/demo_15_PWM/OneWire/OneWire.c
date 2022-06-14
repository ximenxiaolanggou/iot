#include <REGX52.H>
#include "OneWire.H"

sbit OneWire_DQ = P3^7;


// 初始化
unsigned char OneWire_Init(void)
{
	unsigned char i;
	unsigned char AckBit;

	// 拉低总线
	OneWire_DQ = 1;
	OneWire_DQ = 0; 
	
	
	i = 247;while (--i); // 延迟 500us
	
	// 释放总线
	OneWire_DQ = 1;
	
	i = 32;while (--i); // 延迟70us
	AckBit = OneWire_DQ;
	
	i = 85;while (--i); // 延迟170us
	return AckBit;
}

// 发送一位
void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	
	// 1.主机将总线拉低60~120us,然后释放总线，表示发送0
	if(Bit == 0)
	{
		OneWire_DQ = 0;
		i = 60;
		while (--i);
		OneWire_DQ = 1;
	}else{
		// 2.主机将总线拉低1~15us,  然后释放总线，表示发送1
		OneWire_DQ = 0;
		i = 4;
		while (--i);
		OneWire_DQ = 1;
		i = 24;
		while (--i);      //延时50us 
	}	
}


/*
	接收一位：
		主机将总线拉低1~15us，然后释放总线，并在拉低后15us内读取总线电平（尽量贴近15us的末尾），
		读取为低电平则为接收0，读取为高电平则为接收1 ，整个时间片应大于60us

	*/
unsigned char OneWire_ReceiveBit(void)
{
	unsigned char Data;
	unsigned char i;
	
	OneWire_DQ = 0;
	
	i = 2;while (--i);      //延时5us
	OneWire_DQ = 1;
	
	i = 2;while (--i);      //延时5us
	Data = OneWire_DQ;
	
	i = 24;while (--i);      //延时50us
	
	return Data;
}

// 发送一字节
void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i = 0 ; i < 8 ; i++)
	{
		OneWire_SendBit((0x01 << i) & Byte);
	}
}

// 接收一字节
unsigned char OneWire_ReceiveByte()
{
	unsigned char Data = 0x00,i;
	for(i = 0 ; i < 8 ; i++)
	{
		if(OneWire_ReceiveBit()) Data |= (0x01 << i);
	}
	return Data;
}

