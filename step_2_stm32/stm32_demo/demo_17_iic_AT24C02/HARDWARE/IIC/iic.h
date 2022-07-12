#ifndef __IIC_H
#define __IIC_H	 
#include "sys.h"

#define IIC_Port GPIOC // 定义port

#define SDA GPIO_Pin_11 // SDA数据引脚
#define SCL GPIO_Pin_12 // SCL时钟引脚


#define SDA_HIGH GPIO_SetBits(IIC_Port,SDA)  // SDA高电平
#define SDA_LOW GPIO_ResetBits(IIC_Port,SDA) // SDA低电平

#define SCL_HIGH GPIO_SetBits(IIC_Port,SCL)  // SCL高电平
#define SCL_LOW GPIO_ResetBits(IIC_Port,SCL) // SCL高电平
 
#define SDA_READ GPIO_ReadInputDataBit(IIC_Port,SDA) // 读取SDA电平

// 为0时表示输入 1时表示输出
void IIC_SDA_IO(u8 io);
		 				    
// 初始化
void IIC_Init(void);

// 开始
void IIC_Start(void);

// 截止
void IIC_Stop(void);

// 等待应答 1 非应答 0 应答
u8 IIC_Wait_Ack();

// 产生ACK
void IIC_Ack(void);

// 产生非ACK
void IIC_NAck();

// 发送数据
void IIC_SendByte(u8 Data);

// 接收数据
u8 IIC_Read_Byte();

#endif
