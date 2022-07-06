#include "dma_adc.h"
#include "delay.h"

uint16_t DMA_ADC_VALUES[8];

uint16_t DMA_ADC_SIZE;

// ��ʼ��
void DMA_ADC_Init(uint16_t Size){
	
	
	GPIO_InitTypeDef  GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	DMA_InitTypeDef DMA_InitStrture;
	
	DMA_ADC_SIZE = Size;
	
	//����PA��ʱ�Ӻ�ADC1ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA,ENABLE);
	// ����DMA1ʱ��
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	//��λADC1��ͬʱ����ADC1��Ƶ����
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	//����PA1Ϊģ������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN; 		 //ģ������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 


	ADC_DeInit(ADC1);
	// ���ù���ͨ������
	ADC_RegularChannelConfig(ADC1,ADC_Channel_0,1,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_1,2,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_2,3,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_3,4,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_4,5,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_5,6,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_6,7,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_7,8,ADC_SampleTime_55Cycles5);
	
	//��ʼ��ADC1����������ADC1�Ĺ���ģʽ�Լ��������е������Ϣ
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
	ADC_InitStructure.ADC_NbrOfChannel = DMA_ADC_SIZE;
	ADC_Init(ADC1,&ADC_InitStructure);
	
	// ��ʼ��DMA   ����վ��3���������洢��վ��3������
	DMA_InitStrture.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR; // ���������ַ
	DMA_InitStrture.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord; // �������ݿ��
	DMA_InitStrture.DMA_PeripheralInc = DMA_PeripheralInc_Disable; // ��ַ�Ƿ�����
	DMA_InitStrture.DMA_MemoryBaseAddr = (uint32_t)DMA_ADC_VALUES; //�洢��������ַ
	DMA_InitStrture.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord; // �洢�����ݿ��
	DMA_InitStrture.DMA_MemoryInc = DMA_MemoryInc_Enable; // ��ַ�Ƿ�����
	DMA_InitStrture.DMA_DIR = DMA_DIR_PeripheralSRC; // ָ������վ����Դ�˻���Ŀ�ĵ�
	DMA_InitStrture.DMA_BufferSize = DMA_ADC_SIZE; // �������
	DMA_InitStrture.DMA_Mode = DMA_Mode_Normal; // ����ģʽ
	DMA_InitStrture.DMA_M2M = DMA_M2M_Disable; // �Ƿ�Ϊ�洢�����洢��ת�ˣ������������Ӳ��������
	DMA_InitStrture.DMA_Priority = DMA_Priority_Medium; // ���ȼ�
	DMA_Init(DMA1_Channel1, &DMA_InitStrture);
	
	// ʹ��
	DMA_Cmd(DMA1_Channel1,ENABLE);
	 
	// ����ADC��DMA��� 
	ADC_DMACmd(ADC1,ENABLE);
	
	ADC_Cmd(ADC1, ENABLE);
	
	ADC_ResetCalibration(ADC1); // ��λУ׼
	while(ADC_GetResetCalibrationStatus(ADC1) == SET);// �ȴ���λУ׼���
  ADC_StartCalibration(ADC1); // ��ʼУ׼
	while(ADC_GetCalibrationStatus(ADC1));// �ȴ���ʼУ׼���

}

void DMA_ADC_GetValue() {
	
	//ʧ��
	 DMA_Cmd(DMA1_Channel1,DISABLE);
	//����ת�˴���
	 DMA_SetCurrDataCounter(DMA1_Channel1,DMA_ADC_SIZE);
	//ʹ��
	 DMA_Cmd(DMA1_Channel1,ENABLE);
	
	// ��ʼת��
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	
	// �ȴ�ת�����
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);
	
	// �����־λ
	DMA_ClearFlag(DMA1_FLAG_TC1);

}


