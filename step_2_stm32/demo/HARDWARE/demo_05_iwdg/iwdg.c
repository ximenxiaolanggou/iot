#include "sys.h"
#include "iwdg.h"

void IWDG_Init(u8 prer,u16 rlr)

{

	// 1. ȡ���Ĵ���д������
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	
	// 2. ���ö������Ź���Ԥ��Ƶϵ����ȷ��ʱ��:
	IWDG_SetPrescaler(prer);

	// 3. ���ÿ��Ź���װ��ֵ��ȷ�����ʱ��:
    IWDG_SetReload(rlr);
	
	// 5. ���� IWDG ��װ�ؼĴ�����ֵ��װ�� IWDG ������
		IWDG_ReloadCounter();
	
	// 4. ʹ�ܿ��Ź�
		IWDG_Enable();


}
