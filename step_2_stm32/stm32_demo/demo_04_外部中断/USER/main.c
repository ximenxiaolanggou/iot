#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "exti.h"

char KEY_Press = -1; // 0 ����KEY0���£� 1 ����KEY1 ���£� 3 ����WK_UP���� - 1����δ����

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	KEY_Init();
	LED_Init();
	delay_init();
	EXTIX_Init();
	while(1);
}