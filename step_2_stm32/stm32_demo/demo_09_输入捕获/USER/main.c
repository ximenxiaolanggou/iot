#include "stm32f10x.h"
#include "delay.h"
#include "led.h"
#include "timer.h"
#include "usart.h"

extern u8 TIM3CH1_CAPTURE_STA; // 输入捕获状态
extern u16 TIM3CH1_CAPTURE_VAL; // 输入捕获值


int main(void)
{
	u32 temp = 0;
	u16 led0pwmval=0;
	u8 dir=1;
	delay_init(); //延时函数初始化
	LED_Init();
	uart_init(115200);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	TIMER_1_PWM_Init(899,0); //不分频。PWM 频率=72000/(899+1)=80Khz
	TIMER_2_Cap_Init(65535,71); // 1MHZ
	while(1){
		delay_ms(10);
		if(dir) led0pwmval++;
		else led0pwmval--;
		if(led0pwmval > 300) dir = 0;
		if(led0pwmval == 0) dir = 1;
		TIM_SetCompare1(TIM1,led0pwmval);
		
		if(TIM3CH1_CAPTURE_STA & 0x80) {
			temp = TIM3CH1_CAPTURE_STA & 0x3f;
			temp = temp*65532 + TIM3CH1_CAPTURE_VAL;
			printf("HIGH:%d\r\n",temp);
			TIM3CH1_CAPTURE_STA = 0;
		}
	}

}