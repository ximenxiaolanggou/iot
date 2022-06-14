#ifndef __DS1302_H__
#define __DS1302_H__

//引脚定义
sbit DS1302_CE = P3^5;
sbit DS1302_IO = P3^4;
sbit DS1302_SCLK = P3^6;

//寄存器写入地址/指令定义
#define DS1302_SECOND		0x80
#define DS1302_MINUTE		0x82
#define DS1302_HOUR			0x84
#define DS1302_DATE			0x86
#define DS1302_MONTH			0x88
#define DS1302_DAY			0x8A
#define DS1302_YEAR			0x8C
#define DS1302_WP				0x8E

//时间数组，索引0~6分别为年、月、日、时、分、秒、星期
unsigned char DS1302_Time[];

// 初始化
void DS1302_Init();

// 设置值
void DS1302_WriteByte(unsigned char Command, unsigned char Data);

// 读取值
unsigned char DS1302_ReadByte(unsigned char Command);

// 设置时间
void DS1302_SetTime();

// 读取时间
void DS1302_ReadTime();

#endif
