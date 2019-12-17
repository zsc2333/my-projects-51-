#include<reg51.h>
#include<stdio.h>
#include<string.h>
#include <math.h>
#define uchar unsigned char
#define uint unsigned int

typedef unsigned int u16;
typedef unsigned char u8;

sbit LCDEN=P2^7;  //Һ���������˿ڶ���
sbit LCDRS=P2^6;
sbit LCDRW=P2^5;
sbit WaveA=P3^0; //�ο�����
sbit WaveB=P3^1; //��λ�仯����
sbit test=P3^7;
uchar T0count=0;//T0����
//void UART_Init(void);
//void Delay10ms(u16 c);
void INT0_Init(void);
void INT1_Init(void);
void TIMER0_Init(void);
void TIMER1_Init(void);
void Delay(uint);	//��ʱ����
void Write_Cmd(uchar cmd);	  //дָ���
void Write_Data(uchar Data);	//д���ݺ���
void Display_fre_phs();	
void LCD_Init();	 //��ʼ������


u16 buf,phs,fre;
u16 Frequency , Phase_Difference;
int th1,tl1,th2,tl2,num1,num2,T1_num;
uchar a[8];
bit flag; 
/************************************************************************************************************/
void main()
{
	INT0_Init();				//��ʼ���ⲿ�ж�0
	INT1_Init();				//��ʼ���ⲿ�ж�1
	TIMER0_Init();				//��ʼ����ʱ��0
	LCD_Init();
	EA = 1;						//�����ж�
	while(1)
	{
	  Display_fre_phs();
	}

}
/************************************************************************************************************/
void Write_Cmd(uchar cmd)
{
 LCDEN=1;  //����
 LCDRS=0;  //ָ��
 P0=cmd;   
 Delay(5);
 LCDEN=0;
}

void Write_Data(uchar Data)
{
 LCDEN=1;
 LCDRS=1;  //ָ��
 P0=Data;  //д��
 Delay(5); //����
 LCDEN=0;
}

void LCD_Init()
{
 	
 LCDRW=0;
 LCDRS=0;
 Write_Cmd(0x01); //�����Ļ��ʾ
 Write_Cmd(0x38); //����8λ��ʽ��2�У�5*7
 Write_Cmd(0x0C); //������ʾ���ع�꣬����˸
 Write_Cmd(0x06); //�趨���뷽ʽ����������λ
 Write_Cmd(0x80); //��һ�е�һ���ַ���ַ
 Write_Data('f');
 Write_Data('r');
 Write_Data('e');
 Write_Data(':');
 Write_Cmd(0x80+0x40); //�ڶ��е�һ���ַ���ַ
 Write_Data('p');
 Write_Data('h');
 Write_Data('s');
 Write_Data(':');	
}
/************************************************************************************************************/


void INT0_Init(void)			//�ⲿ�ж�0��ʼ������
{
	IT0 = 1;					//�½��ش���
	EX0 = 1;					//��INT0���ж�����
}

void INT1_Init(void)			//�ⲿ�ж�1��ʼ������
{
	IT1 = 1;					//�½��ش���
	EX1 = 1;					//��INT1���ж�����
}


void TIMER0_Init(void)			//��ʱ��0��ʼ������
{
	TMOD |= 0X01;				//��ʱ��0��ʽ1
	TH0 = 0;					//��ֵ
	TL0 = 0;
	TR0 = 1;					//�򿪶�ʱ��0
	ET0 = 1;
}



void Int0() interrupt 0			//�ⲿ�ж�0���жϺ���
{
	fre = 1000000 / (TH0 * 256 + TL0);		//��λus
	TH0 = 0;					//���س�ֵ
	TL0 = 0;
}

void Int1() interrupt 2			//�ⲿ�ж�1���жϺ���
{
	buf =( TH0*256+TL0)/1000000;		//�������������½���ʱ���
	
	phs = buf * fre * 360;	//��λ�� = ʱ��� * f * 360			
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