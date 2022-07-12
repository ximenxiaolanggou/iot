#ifndef __MYDMA_H
#define __MYDMA_H	 
#include "sys.h"

// 初始化
void MYDMA_Init(uint32_t AddrA, uint32_t AddrB, uint16_t Size);

// 手动转运
void MYDMA_Transfer();
#endif
