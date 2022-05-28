#include "sys.h"
#include "iwdg.h"

void IWDG_Init(u8 prer,u16 rlr)

{

	// 1. 取消寄存器写保护：
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	
	// 2. 设置独立看门狗的预分频系数，确定时钟:
	IWDG_SetPrescaler(prer);

	// 3. 设置看门狗重装载值，确定溢出时间:
    IWDG_SetReload(rlr);
	
	// 5. 按照 IWDG 重装载寄存器的值重装载 IWDG 计数器
		IWDG_ReloadCounter();
	
	// 4. 使能看门狗
		IWDG_Enable();


}
