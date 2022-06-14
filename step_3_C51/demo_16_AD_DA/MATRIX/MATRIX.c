#include "MATRIX.h"
#include "delay.h"
#include <REGX52.H>
unsigned char getPressKey()
{
	unsigned int num;
	P1 = 0xff;
	P1_3 = 0;
	if(P1_7 == 0) { delay(20); while(P1_7 == 0); delay(20); num = 1;}
	if(P1_6 == 0) { delay(20); while(P1_6 == 0); delay(20); num = 5;}
	if(P1_5 == 0) { delay(20); while(P1_5 == 0); delay(20); num = 9;}
	if(P1_4 == 0) { delay(20); while(P1_4 == 0); delay(20); num = 13;}
	
	P1_2 = 0;
	if(P1_7 == 0) { delay(20); while(P1_7 == 0); delay(20); num = 2;}
	if(P1_6 == 0) { delay(20); while(P1_6 == 0); delay(20); num = 6;}
	if(P1_5 == 0) { delay(20); while(P1_5 == 0); delay(20); num = 10;}
	if(P1_4 == 0) { delay(20); while(P1_4 == 0); delay(20); num = 14;}
	
	P1_1 = 0;
	if(P1_7 == 0) { delay(20); while(P1_7 == 0); delay(20); num = 3;}
	if(P1_6 == 0) { delay(20); while(P1_6 == 0); delay(20); num = 7;}
	if(P1_5 == 0) { delay(20); while(P1_5 == 0); delay(20); num = 11;}
	if(P1_4 == 0) { delay(20); while(P1_4 == 0); delay(20); num = 15;}
	
	P1_0 = 0;
	if(P1_7 == 0) { delay(20); while(P1_7 == 0); delay(20); num = 4;}
	if(P1_6 == 0) { delay(20); while(P1_6 == 0); delay(20); num = 8;}
	if(P1_5 == 0) { delay(20); while(P1_5 == 0); delay(20); num = 12;}
	if(P1_4 == 0) { delay(20); while(P1_4 == 0); delay(20); num = 16;}
	
	return num;
}
