#include<reg51.h>
#include<stdio.h>
#include<string.h>
#include <math.h>
#define uchar unsigned char
#define uint unsigned int

typedef unsigned int u16;
typedef unsigned char u8;

sbit LCDEN=P2^7;  //液晶屏三个端口定义
sbit LCDRS=P2^6;
sbit LCDRW=P2^5;
sbit WaveA=P3^0; //参考波形
sbit WaveB=P3^1; //相位变化波形
sbit test=P3^7;
uchar T0count=0;//T0计数
//void UART_Init(void);
//void Delay10ms(u16 c);
void INT0_Init(void);
void INT1_Init(void);
void TIMER0_Init(void);
void TIMER1_Init(void);
void Delay(uint);	//延时函数
void Write_Cmd(uchar cmd);	  //写指令函数
void Write_Data(uchar Data);	//写数据函数
void Display_fre_phs();	
void LCD_Init();	 //初始化函数


u16 buf,phs,fre;
u16 Frequency , Phase_Difference;
int th1,tl1,th2,tl2,num1,num2,T1_num;
uchar a[8];
bit flag; 
/************************************************************************************************************/
void main()
{
	INT0_Init();				//初始化外部中断0
	INT1_Init();				//初始化外部中断1
	TIMER0_Init();				//初始化定时器0
	LCD_Init();
	EA = 1;						//打开总中断
	while(1)
	{
	  Display_fre_phs();
	}

}
/************************************************************************************************************/
void Write_Cmd(uchar cmd)
{
 LCDEN=1;  //允许
 LCDRS=0;  //指令
 P0=cmd;   
 Delay(5);
 LCDEN=0;
}

void Write_Data(uchar Data)
{
 LCDEN=1;
 LCDRS=1;  //指令
 P0=Data;  //写入
 Delay(5); //允许
 LCDEN=0;
}

void LCD_Init()
{
 	
 LCDRW=0;
 LCDRS=0;
 Write_Cmd(0x01); //清除屏幕显示
 Write_Cmd(0x38); //设置8位格式，2行，5*7
 Write_Cmd(0x0C); //整体显示，关光标，不闪烁
 Write_Cmd(0x06); //设定输入方式，增量不移位
 Write_Cmd(0x80); //第一行第一个字符地址
 Write_Data('f');
 Write_Data('r');
 Write_Data('e');
 Write_Data(':');
 Write_Cmd(0x80+0x40); //第二行第一个字符地址
 Write_Data('p');
 Write_Data('h');
 Write_Data('s');
 Write_Data(':');	
}
/************************************************************************************************************/


void INT0_Init(void)			//外部中断0初始化函数
{
	IT0 = 1;					//下降沿触发
	EX0 = 1;					//打开INT0的中断允许
}

void INT1_Init(void)			//外部中断1初始化函数
{
	IT1 = 1;					//下降沿触发
	EX1 = 1;					//打开INT1的中断允许
}


void TIMER0_Init(void)			//定时器0初始化函数
{
	TMOD |= 0X01;				//定时器0方式1
	TH0 = 0;					//初值
	TL0 = 0;
	TR0 = 1;					//打开定时器0
	ET0 = 1;
}



void Int0() interrupt 0			//外部中断0的中断函数
{
	fre = 1000000 / (TH0 * 256 + TL0);		//单位us
	TH0 = 0;					//重载初值
	TL0 = 0;
}

void Int1() interrupt 2			//外部中断1的中断函数
{
	buf =( TH0*256+TL0)/1000000;		//计算两个波形下降沿时间差
	
	phs = buf * fre * 360;	//相位差 = 时间差 * f * 360			
}
 

void Display_fre_phs()
{
	uchar i,j;
	a[0]=fre/1000;
	a[1]=(fre%1000)/100;
	a[2]=(fre%100)/10;
	a[3]=fre%10;
	a[4]=Phase_Difference/1000;
	a[5]=(Phase_Difference%1000)/100;
	a[6]=(Phase_Difference%100)/10;
	a[7]=Phase_Difference%10;
	Write_Cmd(0x80+5);
	for(i=0;i<=3;i++)
	{
	Write_Data(a[i]+48);	
	Delay(5);
	}
	Write_Cmd(0x80+0x40+5);
	for(j=4;j<=7;j++)
	{
	Write_Data(a[j]+48);
	Delay(5);
	}
	test=0;
}

void Delay(uint i)	 
{
	uint j,k;
	for(k=i;k>0;k--)
	for(j=110;j>0;j--);
}