#include <reg52.h>
sbit P1_0=P1^0;
sbit P1_1=P1^1;
unsigned char n;
void main (void)
{
	TMOD = 0x22;
	TH0 = 236;
	TLO = 236;
	EA = 1;
	ET0 = 1;
	while(1)
	{
		n=0;
		TR0=1;
		while(n<=1&&P1_0==1);
		TR0=0;
		P1_0=0;
		n=0;
		TR0=1;
		while(n<=9&&P1_0==0);
		TR0=0;
		P1_0=1;
	}
}
void timer0 (void) interrupt1
{
	TL0=236;
	n++;
//	P1_1=~P1_1;
}