#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "exti.h"

char KEY_Press = -1; // 0 代表KEY0按下， 1 代表KEY1 按下， 3 代表WK_UP按下 - 1代表未按下

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	KEY_Init();
	LED_Init();
	delay_init();
	EXTIX_Init();
	while(1);
}