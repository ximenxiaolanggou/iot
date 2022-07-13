#ifndef __ADC_H
#define __ADC_H	 
#include "sys.h"

// 初始化
void Adc_Init(void);

// 获取AD值
u16 AD_GetValue(u8 ch); 

// 获取数据 平均
u16 AD_GetValue_Avg(u8 ch, u8 times);
#endif
