#include "dma_adc.h"
#include "delay.h"

uint16_t DMA_ADC_VALUES[8];

uint16_t DMA_ADC_SIZE;

// 初始化
void DMA_ADC_Init(uint16_t Size){
	
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	DMA_InitTypeDef DMA_InitStrture;
	
	DMA_ADC_SIZE = Size;
	
	//开启PA口时钟和ADC1时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA,ENABLE);
	// 开启DMA1时钟
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	//复位ADC1，同时设置ADC1分频因子
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	//设置PA1为模拟输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 		 //模拟输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 


	ADC_DeInit(ADC1);
	// 配置规则通道参数
	ADC_RegularChannelConfig(ADC1,ADC_Channel_0,1,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_1,2,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_2,3,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_3,4,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_4,5,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_5,6,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_6,7,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_7,8,ADC_SampleTime_55Cycles5);
	
	//初始化ADC1参数，设置ADC1的工作模式以及规则序列的相关信息
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
	ADC_InitStructure.ADC_NbrOfChannel = DMA_ADC_SIZE;
	ADC_Init(ADC1,&ADC_InitStructure);
	
	// 初始化DMA   外设站点3个参数、存储器站点3个参数
	DMA_InitStrture.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR; // 外设基本地址
	DMA_InitStrture.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; // 外设数据宽度
	DMA_InitStrture.DMA_PeripheralInc = DMA_PeripheralInc_Disable; // 地址是否自增
	DMA_InitStrture.DMA_MemoryBaseAddr = (uint32_t)DMA_ADC_VALUES; //存储器基本地址
	DMA_InitStrture.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord; // 存储器数据宽度
	DMA_InitStrture.DMA_MemoryInc = DMA_MemoryInc_Enable; // 地址是否自增
	DMA_InitStrture.DMA_DIR = DMA_DIR_PeripheralSRC; // 指定外设站点是源端还是目的地
	DMA_InitStrture.DMA_BufferSize = DMA_ADC_SIZE; // 传输次数
	DMA_InitStrture.DMA_Mode = DMA_Mode_Normal; // 传输模式
	DMA_InitStrture.DMA_M2M = DMA_M2M_Disable; // 是否为存储器到存储器转运（软件触发）（硬件触发）
	DMA_InitStrture.DMA_Priority = DMA_Priority_Medium; // 优先级
	DMA_Init(DMA1_Channel1, &DMA_InitStrture);
	
	// 使能
	DMA_Cmd(DMA1_Channel1,ENABLE);
	 
	// 开启ADC到DMA输出 
	ADC_DMACmd(ADC1,ENABLE);
	
	ADC_Cmd(ADC1, ENABLE);
	
	ADC_ResetCalibration(ADC1); // 复位校准
	while(ADC_GetResetCalibrationStatus(ADC1) == SET);// 等待复位校准完成
  ADC_StartCalibration(ADC1); // 开始校准
	while(ADC_GetCalibrationStatus(ADC1));// 等待开始校准完成

}

void DMA_ADC_GetValue() {
	
	//失能
	 DMA_Cmd(DMA1_Channel1,DISABLE);
	//设置转运次数
	 DMA_SetCurrDataCounter(DMA1_Channel1,DMA_ADC_SIZE);
	//使能
	 DMA_Cmd(DMA1_Channel1,ENABLE);
	
	// 开始转换
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	
	// 等待转运完成
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);
	
	// 清除标志位
	DMA_ClearFlag(DMA1_FLAG_TC1);

}


