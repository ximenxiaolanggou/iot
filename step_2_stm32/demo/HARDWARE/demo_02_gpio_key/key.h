#ifndef __KEY__H
#define __KEY__H
#include "sys.h"


#define KEY0 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5)
#define KEY1 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)
#define WAKEUP GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)


#define KEY0_PRESS 1
#define KEY1_PRESS 2
#define WAKEUP_PRESS 3

typedef struct 
{
	u8 KEY0_P;
	u8 KEY1_P;
	u8 WAKEUP_P;
} KEYS;

void KEY_Init(void);

KEYS* KEY_SCAN(void);

#endif

