#include <REGX52.H>
#include "DELAY.H"

sbit beep = P1^5;

void main()
{
	int i;
	for(i = 0 ; i < 1000 ; i++)
	{
		beep = ~beep;
		delay(10);
	}
	while(1);
}