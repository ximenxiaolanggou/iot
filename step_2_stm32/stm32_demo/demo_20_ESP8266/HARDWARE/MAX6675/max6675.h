#ifndef __MAX6675_H
#define __MAX6675_H

#include "sys.h"

#define W25Q80 	0XEF13 	
#define W25Q16 	0XEF14
#define W25Q32 	0XEF15
#define W25Q64 	0XEF16

#define NM25Q80 	0X5213 
#define NM25Q16 	0X5214
#define NM25Q32 	0X5215
#define NM25Q64 	0X5216

extern u16 SPI_FLASH_TYPE;		//定义我们使用的flash芯片型号		

#define	SPI_MAX6675_CS PAout(4)  //选中FLASH					 
////////////////////////////////////////////////////////////////////////////

extern u8 SPI_FLASH_BUF[4096];
//W25X16读写
#define FLASH_ID 0XEF14
//指令表
#define W25X_WriteEnable		0x06 
#define W25X_WriteDisable		0x04 
#define W25X_ReadStatusReg		0x05 
#define W25X_WriteStatusReg		0x01 
#define W25X_ReadData			0x03 
#define W25X_FastReadData		0x0B 
#define W25X_FastReadDual		0x3B 
#define W25X_PageProgram		0x02 
#define W25X_BlockErase			0xD8 
#define W25X_SectorErase		0x20 
#define W25X_ChipErase			0xC7 
#define W25X_PowerDown			0xB9 
#define W25X_ReleasePowerDown	0xAB 
#define W25X_DeviceID			0xAB 
#define W25X_ManufactDeviceID	0x90 
#define W25X_JedecDeviceID		0x9F 

// MAX6675初始化
void MAX6675_Init(void);

// 读取数据
unsigned char MAX6675_ReadByte(void);
#endif
