#include "tsensor.h"
#include "delay.h"
 
void TSENSOR_Init(void){
	
	
	ADC_InitTypeDef ADC_InitStructure;
	
	// 使能时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE);
				 

	//复位ADC1，同时设置ADC1分频因子
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	ADC_DeInit(ADC1);
	
	//初始化ADC1参数，设置ADC1的工作模式以及规则序列的相关信息
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1,&ADC_InitStructure);
	
	// 开启内部温度传感器
	ADC_TempSensorVrefintCmd(ENABLE);
	
	// 配置规则通道参数
	ADC_RegularChannelConfig(ADC1,ADC_Channel_16,1,ADC_SampleTime_55Cycles5);

	
	ADC_Cmd(ADC1, ENABLE);
	
	ADC_ResetCalibration(ADC1); // 复位校准
	while(ADC_GetResetCalibrationStatus(ADC1) == SET);// 等待复位校准完成
  ADC_StartCalibration(ADC1); // 开始校准
	while(ADC_GetCalibrationStatus(ADC1));// 等待开始校准完成
}

u16 AD_Tsensor_GetValue(u8 ch) {
	
	ADC_RegularChannelConfig(ADC1,ch,1,ADC_SampleTime_239Cycles5);
	
	// 开始转换
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	
	// 等待转换完成
	while( ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC) == RESET);
	
	return ADC_GetConversionValue(ADC1);
}

// 获取数据 平均
u16 AD_Tsensor_GetValue_Avg(u8 ch, u8 times) {
	u32 temp_val = 0;
	u8 t;
	
	for(t =0 ; t < times ; t++) {
		temp_val += AD_Tsensor_GetValue(ch);
		delay_ms(5);
	}
	
	
	return temp_val/times;
}

