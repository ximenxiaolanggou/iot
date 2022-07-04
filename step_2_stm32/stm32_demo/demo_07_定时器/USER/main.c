#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "timer.h"



int main(void)
{

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	TIMER_3_Init(4999,7199); // 500ms
	while(1);

}