#ifndef __MYDMA_H
#define __MYDMA_H	 
#include "sys.h"

// ��ʼ��
void MYDMA_Init(uint32_t AddrA, uint32_t AddrB, uint16_t Size);

// �ֶ�ת��
void MYDMA_Transfer();
#endif
