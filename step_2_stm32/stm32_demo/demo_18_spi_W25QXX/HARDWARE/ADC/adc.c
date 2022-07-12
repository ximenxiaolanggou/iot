#include "adc.h"
#include "delay.h"


// ��ʼ��
void Adc_Init(){
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	
	//����PA��ʱ�Ӻ�ADC1ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA,ENABLE);
	
	//����PA1Ϊģ������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 		 //ģ������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 

	//��λADC1��ͬʱ����ADC1��Ƶ����
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	ADC_DeInit(ADC1);
	
	//��ʼ��ADC1����������ADC1�Ĺ���ģʽ�Լ��������е������Ϣ
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1,&ADC_InitStructure);
	
	// ���ù���ͨ������
	ADC_RegularChannelConfig(ADC1,ADC_Channel_0,1,ADC_SampleTime_55Cycles5);

	
	ADC_Cmd(ADC1, ENABLE);
	
	ADC_ResetCalibration(ADC1); // ��λУ׼
	while(ADC_GetResetCalibrationStatus(ADC1) == SET);// �ȴ���λУ׼���
  ADC_StartCalibration(ADC1); // ��ʼУ׼
	while(ADC_GetCalibrationStatus(ADC1));// �ȴ���ʼУ׼���

}

u16 AD_GetValue(u8 ch) {
	
	ADC_RegularChannelConfig(ADC1,ch,1,ADC_SampleTime_239Cycles5);
	
	// ��ʼת��
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	
	// �ȴ�ת�����
	while( ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC) == RESET);
	
	return ADC_GetConversionValue(ADC1);
}

// ��ȡ���� ƽ��
u16 AD_GetValue_Avg(u8 ch, u8 times) {
	u32 temp_val = 0;
	u8 t;
	
	for(t =0 ; t < times ; t++) {
		temp_val += AD_GetValue(ch);
		delay_ms(5);
	}
	
	
	return temp_val/times;
}
 
