#include <REGX52.H>
#include <DS1302.H>

unsigned char DS1302_Time[]={19,11,16,12,59,55,6};
// 初始化函数
void DS1302_Init()
{
	DS1302_CE = 0;
	DS1302_SCLK = 0;
}

// 设置值
void DS1302_WriteByte(unsigned char Command, unsigned char Data)
{
	int index;
	DS1302_CE = 1;
	// 写命令
	for(index = 0; index < 8; index++)
	{
		DS1302_IO = Command & (0x01 << index);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	
	// 写数据
	for(index = 0; index < 8; index++)
	{
		DS1302_IO = Data & (0x01 << index);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	
	DS1302_CE = 0;
}

// 读取值
unsigned char DS1302_ReadByte(unsigned char Command)
{
	int index;
	unsigned char Data = 0x00;
	
	Command |= 0x01; // //将指令转换为读指令
	
	DS1302_CE = 1;
	
	
	// 写命令
	for(index = 0; index < 8; index++)
	{
		DS1302_IO = Command & (0x01 << index);
		DS1302_SCLK = 0;
		DS1302_SCLK = 1;
	}
	
	// 读取数据
	for(index = 0; index < 8; index++)
	{
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
		if(DS1302_IO) Data |= (0x01 << index);
	}
	DS1302_CE = 0;
	DS1302_IO=0;	//读取后将IO设置为0，否则读出的数据会出错
	return Data;
}

// 设置时间
void DS1302_SetTime()
{
	// 关闭写保护
	DS1302_WriteByte(0x8E,0x00);
	DS1302_WriteByte(DS1302_WP,0x00);
	DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);//十进制转BCD码后写入
	DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	// 开启写保护
	DS1302_WriteByte(DS1302_WP,0x80);
}

// 读取时间
void DS1302_ReadTime()
{
	unsigned char Temp;
	Temp=DS1302_ReadByte(DS1302_YEAR);
	DS1302_Time[0]=Temp/16*10+Temp%16;//BCD码转十进制后读取
	Temp=DS1302_ReadByte(DS1302_MONTH);
	DS1302_Time[1]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_DATE);
	DS1302_Time[2]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_HOUR);
	DS1302_Time[3]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_MINUTE);
	DS1302_Time[4]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_SECOND);
	DS1302_Time[5]=Temp/16*10+Temp%16;
	Temp=DS1302_ReadByte(DS1302_DAY);
	DS1302_Time[6]=Temp/16*10+Temp%16;
}