#include "stm32f10x.h"
#include "key.h"
#include "delay.h"

// KEY��ʼ��
void KEY_Init(void) {
	
	GPIO_InitTypeDef GPIO_InitTypeDefStruct;
	
	// GPIOAʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	// GPIOCʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	// ��ʼ�� GPIOC_5  KEY0
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitTypeDefStruct);
	
	// ��ʼ�� GPIOA_15  KEY1
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStruct);
	
	// ��ʼ�� GPIOA_0  WK_UP
	GPIO_InitTypeDefStruct.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitTypeDefStruct.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitTypeDefStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitTypeDefStruct);
}

// ��ȡ���µİ���
// 0 ����KEY0���£� 1 ����KEY1 ���£� 3 ����WK_UP���� - 1����δ����
// mode 0 ��֧�������� 1 ֧��������
char KEY_Scan(char mode){
	
	static u8 key_up = 1; // �����ɿ���ʶλ
	
	if(mode) { // ֧�ֳ���
		key_up = 1;
	}
	
	// �а�������
	if(	key_up && (!GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)  || 
			!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15) || 
			GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0))){
				
				delay_ms(10); // ����
				key_up = 0; // ����
				if(!GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)) return 0;
				else if(!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)) return 1;
				else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)) return 2;
	}else if(	key_up && 
						GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5) && 
						GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15) && 
						!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)){
						key_up = 1;
	}			
		
		return -1; // �ް�������
}




