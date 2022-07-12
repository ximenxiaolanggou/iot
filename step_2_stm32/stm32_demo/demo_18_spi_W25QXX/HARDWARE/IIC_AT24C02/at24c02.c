#include "iic.h"
#include "delay.h"
#include "at24c02.h"
#include "usart.h"

u8 ack;

// 初始化
void AT24C02_Init(void){
	IIC_Init();
}

// 发送一个字节
void AT24C02_SendByte(u8 Address,u8 Data){
	
	IIC_Start();// 开始
	
	IIC_SendByte(WRITE); // 写命令
	
	ack = IIC_Wait_Ack(); // 等待ACK
	printf("1: %d\r\n",ack);
	
	IIC_SendByte(Address); // 数据地址
	
	ack = IIC_Wait_Ack(); // 等待ACK
	
	printf("2: %d\r\n",ack);
	
	IIC_SendByte(Data); // 写数据
	
	ack = IIC_Wait_Ack(); // 等待ACK
	printf("3: %d\r\n",ack);
	
	IIC_Stop();// 截止
	
	delay_ms(10);

}

// 读一个字节
u8 AT24C02_ReadByte(u8 Address){
	u8 Data;
	
	IIC_Start();// 开始
	
	IIC_SendByte(WRITE); // 写命令
	
	ack = IIC_Wait_Ack(); // 等待ACK
	printf("4: %d\r\n",ack);
	IIC_SendByte(Address); // 地址
	
	ack = IIC_Wait_Ack(); // 等待ACK
	printf("5: %d\r\n",ack);
	IIC_Start();// 开始
	
	IIC_SendByte(READ); // 读命令
	
	ack = IIC_Wait_Ack(); // 等待ACK
	printf("6: %d\r\n",ack);
	Data = IIC_Read_Byte(); // 读取数据
	
	IIC_NAck(); // 相应Ack
	
	IIC_Stop();// 截止
	
	return Data;
	
}



 
