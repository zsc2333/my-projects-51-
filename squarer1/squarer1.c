#include<reg51.h>
sbit recout=P1^0;
//int i=0;

//void int0()interrupt 1
//{ 

//	EA=0;	
//	if(++i%10==0)
//	recout=1;
//	else
//	recout=0;
//	if(i==10)
//	i=0;
//	TL0=216;//工作方式2
//	TH0=216;
//	EA=1;

//}
void main()
{
//	TMOD=0x02;
//	TL0=216;//40us
//	TH0=216;
//	TR0=1;
//	ET0=1;
//	EA=1;
	
	while(1)
		recout=0;

}