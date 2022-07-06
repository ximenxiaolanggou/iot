#include "mydma.h"
#include "delay.h"

uint16_t MYDMA_SIZE;
// 初始化
void MYDMA_Init(uint32_t AddrA, uint32_t AddrB, uint16_t Size) {
	
	
	DMA_InitTypeDef DMA_InitStrture;
	
	MYDMA_SIZE = Size;

	// 开启时钟
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	// 初始化DMA   外设站点3个参数、存储器站点3个参数
	DMA_InitStrture.DMA_PeripheralBaseAddr = AddrA; // 外设基本地址
	DMA_InitStrture.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; // 外设数据宽度
	DMA_InitStrture.DMA_PeripheralInc = DMA_PeripheralInc_Enable; // 地址是否自增
	DMA_InitStrture.DMA_MemoryBaseAddr = AddrB; //存储器基本地址
	DMA_InitStrture.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; // 存储器数据宽度
	DMA_InitStrture.DMA_MemoryInc = DMA_MemoryInc_Enable; // 地址是否自增
	DMA_InitStrture.DMA_DIR = DMA_DIR_PeripheralSRC; // 指定外设站点是源端还是目的地
	DMA_InitStrture.DMA_BufferSize = Size; // 传输次数
	DMA_InitStrture.DMA_Mode = DMA_Mode_Normal; // 传输模式
	DMA_InitStrture.DMA_M2M = DMA_M2M_Enable; // 是否为存储器到存储器转运（软件触发）（硬件触发）
	DMA_InitStrture.DMA_Priority = DMA_Priority_Medium; // 优先级
	DMA_Init(DMA1_Channel1, &DMA_InitStrture);
	
		
	// 使能DMA
	// DMA_Cmd(DMA1_Channel1,ENABLE);

}

/*
手动转运
1. 先失能
2. 设置转运次数
3. 使能

*/

void MYDMA_Transfer() {
	//失能
	 DMA_Cmd(DMA1_Channel1,DISABLE);
	//设置转运次数
	 DMA_SetCurrDataCounter(DMA1_Channel1,MYDMA_SIZE);
	//使能
	 DMA_Cmd(DMA1_Channel1,ENABLE);
	
	// 等待转运完成
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);
	
	// 清除标志位
	DMA_ClearFlag(DMA1_FLAG_TC1);
	
	
}
