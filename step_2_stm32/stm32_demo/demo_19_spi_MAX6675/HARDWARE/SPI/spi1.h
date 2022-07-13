#ifndef __SPI1_H
#define __SPI1_H

#include "sys.h"

#define IIC_Port GPIOC // 定义port

#define SDA GPIO_Pin_11 // SDA数据引脚
#define SCL GPIO_Pin_12 // SCL时钟引脚


#define SDA_HIGH GPIO_SetBits(IIC_Port,SDA)  // SDA高电平
#define SDA_LOW GPIO_ResetBits(IIC_Port,SDA) // SDA低电平

#define SCL_HIGH GPIO_SetBits(IIC_Port,SCL)  // SCL高电平
#define SCL_LOW GPIO_ResetBits(IIC_Port,SCL) // SCL高电平
 
#define SDA_READ GPIO_ReadInputDataBit(IIC_Port,SDA) // 读取SDA电平

// 初始化
void SPI1_Init(void);

// 设置预分频系数
void SPI1_SetSpeed(u8 SpeedSet);

// 读写一个字节
u8 SPI1_ReadWriteByte(u8 TxData);
#endif
