#include "DELAY.h"
#include <INTRINS.H>
void delay(unsigned char ms)		//@12.000MHz
{
	unsigned char i, j;
	while(--ms)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}

	
}

void delay_ls()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);

	
}

void delay_ns(unsigned char s)
{
	while(s--)
	{
		delay_ls();
	}
}