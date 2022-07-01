#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "iwdog.h"
#include "usart.h"

static int count = 0;

int main(void)
{

	KEY_Init();
	LED_Init();
	delay_init();
	IWDG_Init(4,625);  // ���Ƶ��Ϊ 64,����ֵΪ 625,���ʱ��Ϊ 1s
	delay_ms(200);
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
	while(1){
		if(KEY_Scan(1)==0){// KEY0��������ι��
			IWDG_Feed();
		}
	}
}