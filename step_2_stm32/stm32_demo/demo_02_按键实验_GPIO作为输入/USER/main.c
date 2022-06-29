#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"

char KEY_Press = -1; // 0 ����KEY0���£� 1 ����KEY1 ���£� 3 ����WK_UP���� - 1����δ����

int main(void)
{
	delay_init();
	LED_Init();
	KEY_Init();
	while(1) {
		KEY_Press = KEY_Scan(1); // ֻ��֧�ֳ������ܵ���LED
		switch(KEY_Press) {
			case 0:
					GPIO_ResetBits(GPIOA,GPIO_Pin_8);
					GPIO_SetBits(GPIOD,GPIO_Pin_2);
				break;
			case 1:
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
					GPIO_ResetBits(GPIOD,GPIO_Pin_2);
				break;
			case 2:
					GPIO_ResetBits(GPIOA,GPIO_Pin_8);
					GPIO_ResetBits(GPIOD,GPIO_Pin_2);
				break;
			default:
					GPIO_SetBits(GPIOA,GPIO_Pin_8);
					GPIO_SetBits(GPIOD,GPIO_Pin_2);
			break;
		}
	}
}