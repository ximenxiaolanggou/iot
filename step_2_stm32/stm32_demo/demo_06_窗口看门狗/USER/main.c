#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "wwdog.h"


static int count = 0;

int main(void)
{

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	delay_init();
	delay_ms(200);
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
	delay_ms(200);
	WWDG_Init(0x7F,0x5F,WWDG_Prescaler_8);  // ������ֵΪ7F,���ڼĴ���ֵΪ5F ��Ƶϵ��Ϊ8
	while(1);
}