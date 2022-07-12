#include "spi1.h"
#include "delay.h"
#include "sys.h"

SPI_InitTypeDef SPI_InitStruce;

// 初始化
void SPI1_Init(){
	
	GPIO_InitTypeDef GPIO_InitStruce;

	
	// 使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_SPI1, ENABLE);
	
	GPIO_InitStruce.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
  GPIO_InitStruce.GPIO_Mode = GPIO_Mode_AF_PP; 		 // 复用推挽输出
  GPIO_InitStruce.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStruce);
	
	GPIO_InitStruce.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStruce.GPIO_Mode = GPIO_Mode_IPU; 		   // 上拉输入
  GPIO_InitStruce.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStruce);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_4);// 片选 上拉 空闲状态
	
	SPI_InitStruce.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256; //预分频 256
	SPI_InitStruce.SPI_CPHA = SPI_CPHA_2Edge; //数据捕获于第二个时钟沿
	SPI_InitStruce.SPI_CPOL = SPI_CPOL_High; //选择了串行时钟的稳态:时钟悬空高
	SPI_InitStruce.SPI_CRCPolynomial = 7; //CRC值计算的多项式
	SPI_InitStruce.SPI_DataSize = SPI_DataSize_8b; // 8 位帧结构
	SPI_InitStruce.SPI_Direction = SPI_Direction_2Lines_FullDuplex; //设置 SPI 全双工
	SPI_InitStruce.SPI_FirstBit = SPI_FirstBit_MSB; // 指定数据传输从MSB还是LSB位开始
	SPI_InitStruce.SPI_Mode = SPI_Mode_Master; // 设置 SPI 工作模式:设置为主 SPI
	SPI_InitStruce.SPI_NSS = SPI_NSS_Soft; // NSS信号由硬件(NSS管脚)还是软件(使用SSI位)管理
	SPI_Init(SPI1, &SPI_InitStruce);
	
	SPI_Cmd(SPI1, ENABLE); // 使能 SPI 外设
	

}

//SPI 速度设置函数
//SpeedSet:
//SPI_BaudRatePrescaler_2 2 分频 (SPI 36M@sys 72M)
//SPI_BaudRatePrescaler_8 8 分频 (SPI 9M@sys 72M)
//SPI_BaudRatePrescaler_16 16 分频 (SPI 4.5M@sys 72M)
//SPI_BaudRatePrescaler_256 256 分频 (SPI 281.25K@sys 72M)
void SPI1_SetSpeed(u8 SpeedSet)
{
		SPI_InitStruce.SPI_BaudRatePrescaler = SpeedSet ;
		SPI_Init(SPI1, &SPI_InitStruce);
		SPI_Cmd(SPI1,ENABLE);
}

//SPIx 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节
u8 SPI1_ReadWriteByte(u8 TxData)
{
	u8 retry=0;
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) //检查指定的 SPI标志位设置与否:发送缓存空标志位
	{
		retry++;
		if(retry>200)return 0;
	}
	SPI_I2S_SendData(SPI1, TxData); //通过外设 SPIx 发送一个数据
	retry=0;
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET)//检查指定的SPI 标志位设置与否:接受缓存非空标志位
	{
		retry++;
		if(retry>200)return 0;
	}
	return SPI_I2S_ReceiveData(SPI1); //返回通过 SPIx 最近接收的数据
}
 
