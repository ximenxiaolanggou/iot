#ifndef __DMA_ADC_H
#define __DMA_ADC_H	 
#include "sys.h"
extern uint16_t DMA_ADC_VALUES[8];
// 初始化
void DMA_ADC_Init(uint16_t Size);

// 手动转化
void DMA_ADC_GetValue(void); 

#endif
