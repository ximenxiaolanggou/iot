#include <REGX52.H>
#include <INTRINS.H>

unsigned char LED_SELECT[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

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
	int i;
	while(1)
	{
		for(i = 0 ; i < 8 ; i++)
		{
			P2 = ~LED_SELECT[i];
			Delay500ms();
		}
	}

}