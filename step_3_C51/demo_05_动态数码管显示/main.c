#include <REGX52.H>
#include <INTRINS.H>

unsigned char NixieTable[] = {0x3f,0x06,0x5b,0x06,0x08,0x10,0x20,0x40,0x80};
void Nixie(int location,int num)
{
	switch(location)
	{
		case 1:
			P2_2 = 0,P2_3 = 0,P2_4 = 0;
			break;
		case 2:
			P2_2 = 1,P2_3 = 0,P2_4 = 0;
			break;
		case 3:
			P2_2 = 0,P2_3 = 1,P2_4 = 0;
			break;
		case 4:
			P2_2 = 1,P2_3 = 1,P2_4 = 0;
			break;
		case 5:
			P2_2 = 0,P2_3 = 0,P2_4 = 1;
			break;
		case 6:
			P2_2 = 1,P2_3 = 0,P2_4 = 1;
			break;
		case 7:
			P2_2 = 0,P2_3 = 1,P2_4 = 1;
			break;
		case 8:
			P2_2 = 1,P2_3 = 1,P2_4 = 1;
			break;
	}
	P0 = NixieTable[num];

}

void Delay500ms()		
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay1ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}

void main()
{

	while(1)
	{
		Nixie(1,0);
		Delay1ms();
		P0 = 0x00;
		Nixie(2,1);
		Delay1ms();
		P0 = 0x00;
		Nixie(3,2);
		Delay1ms();
		P0 = 0x00;
	}

}