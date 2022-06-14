#include <REGX52.H>
#include "Timer0.h"
#include "DELAY.h"


unsigned char LevelNum[] = {0,25,50,100};
unsigned count = 0;
int main()
{
	
		Timer0_Init();
		P2_1 = 0;
		while(1)
		{
			if(P3_1 == 0)
			{
				delay(20);
				while(P3_1 == 0);
				delay(20);
				count++;
				SetCompareNum(LevelNum[count % 4]);
				
			}
		}

}