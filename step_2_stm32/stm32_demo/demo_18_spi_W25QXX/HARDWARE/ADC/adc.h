#ifndef __ADC_H
#define __ADC_H	 
#include "sys.h"

// ��ʼ��
void Adc_Init(void);

// ��ȡADֵ
u16 AD_GetValue(u8 ch); 

// ��ȡ���� ƽ��
u16 AD_GetValue_Avg(u8 ch, u8 times);
#endif
