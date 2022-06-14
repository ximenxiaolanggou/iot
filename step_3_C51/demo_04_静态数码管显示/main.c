#include <REGX52.H>
#include <INTRINS.H>

unsigned char NixieTable[] = {0x06,0x06,0x06,0x08,0x10,0x20,0x40,0x80};
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

void main()
{

	Nixie(4,1);
	while(1)
	{
		
	}

}