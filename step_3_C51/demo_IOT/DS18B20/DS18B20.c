#include "DS18B20.H"
#include "OneWire.H"
#include "LCD1602.h"


// 转化温度
void DS18B20_ConvertT(void)
{
	OneWire_Init();
	OneWire_SendByte(0xCC);
	OneWire_SendByte(0x44);
}

// 温度读取
float DS18B20_ReadT(char *TLTM)
{
	unsigned char TLSB, TMSB; 
	int Temp;
	float T;
	OneWire_Init();
	OneWire_SendByte(0xCC);
	OneWire_SendByte(0xBE);
	TLSB = OneWire_ReceiveByte();
	TMSB = OneWire_ReceiveByte();
	Temp = (TMSB << 8) | TLSB;
	T = Temp/16.0;
	TLTM[1] = TLSB;
	TLTM[0] = TMSB;
	return T;
}