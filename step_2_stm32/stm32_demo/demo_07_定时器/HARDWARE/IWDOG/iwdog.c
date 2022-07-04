#include "stm32f10x.h"
#include "iwdog.h"


// �������Ź���ʼ��
void IWDG_Init(u8 prer, u16 rlr){
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
//ʹ�ܶԼĴ��� IWDG_PR �� IWDG_RLR ��д����
IWDG_SetPrescaler(prer); //���� IWDG Ԥ��Ƶֵ:���� IWDG Ԥ��ƵֵΪ 64
	IWDG_SetReload(rlr); //���� IWDG ��װ��ֵ
IWDG_ReloadCounter(); //���� IWDG ��װ�ؼĴ�����ֵ��װ�� IWDG ������
IWDG_Enable(); //ʹ�� IWDG
}

// ι��
void IWDG_Feed(void){
	IWDG->KR=0XAAAA;//reload
}
