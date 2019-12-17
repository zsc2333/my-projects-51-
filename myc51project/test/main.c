//主题：红外遥控led点阵控制
//作者：ZSC
//日期：20180102
//版本：V2
//修改说明：红外遥控led点阵控制
//关键词重定义
#define uint unsigned int
#define uchar unsigned char
#define ulong unsigned long
//头文件
#include <reg52.h>
#include <intrins.h>
#include <math.h>
#include <string.h>
#include "dis.h"
#include "Ircon.h"
#include "array.h"
//函数声明
//void mode1(void);//显示键盘数字
//void mode2(void);//显示单片机原理及应用
//void mode3(void);//描绘图形模式
//void mode4(void);//显示描绘图形
//全局变量定义

//主函数
void main(void)
{
	unsigned char k,hang=0;
	unsigned char lie=0;
	unsigned char LED[16][16]={0};
	unsigned char move[]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
												0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
	unsigned char temp[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
					  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned char tab0[] = 
		{0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08,
		 0x00, 0x10, 0x00, 0x20, 0x00, 0x40, 0x00, 0x80,
		 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08, 0x00,
		 0x10, 0x00, 0x20, 0x00, 0x40, 0x00, 0x80, 0x00}; 
	IrInit();
	while(1)
		{//主循环 
			for(k = 0; k < 16; k++)											    
				 {	 
						 HC595SendData(~move[2*k +1],~move[2*k],tab0[2*k],tab0[2*k + 1]); 
						 HC595SendData(~temp[2*k +1],~temp[2*k],tab0[2*k],tab0[2*k + 1]);
				 };//显示正在画的内容
//				keyflag==1;
				 if(keyflag==1)
				{
					P2=IrValue[2];
					switch(IrValue[2])
									{
											case 0x08:keyflag=0;memset(move,0,32);HC595SendData(0xff,0xff,0,0);
																if(lie==0)lie=16;
																lie--;
																if(lie>=8)
																move[hang*2+1]+=pow(2,lie%8);
																else
																move[hang*2]+=pow(2,lie%8);
//																keyflag=0;
																break;//left  光标左移
											case 0x5a:keyflag=0;memset(move,0,32);HC595SendData(0xff,0xff,0,0);
																lie++;
																if(lie==16)lie=0;
																if(lie>=8)
																move[hang*2+1]+=pow(2,lie%8);
																else
																move[hang*2]+=pow(2,lie%8);
//																keyflag=0;
																break;//right  光标右移
											case 0x18:keyflag=0;memset(move,0,32);HC595SendData(0xff,0xff,0,0);
																if(hang==0)hang=16;
																hang--;
																if(lie>=8)
																move[hang*2+1]+=pow(2,lie%8);
																else
																move[hang*2]+=pow(2,lie%8);
//																keyflag=0;
																break;//up		光标上移
											case 0x52:keyflag=0;memset(move,0,32);HC595SendData(0xff,0xff,0,0);
																hang++;
																if(hang==16)hang=0;
																if(lie>=8)
																move[hang*2+1]+=pow(2,lie%8);
																else
																move[hang*2]+=pow(2,lie%8);
//																keyflag=0;
																break;//down     光标下移
											case 0x1c:keyflag=0;
														if(lie>=8)
															{
																if(LED[hang][lie]==0)
																{	
																	temp[hang*2+1]+=pow(2,lie%8);
																	LED[hang][lie]=1;	
																}
															}
														else
															{
																if(LED[hang][lie]==0)
																{
																temp[hang*2]+=pow(2,lie%8);
																LED[hang][lie]=1;
																};
															};break;//      写入该点
											case 0x16:keyflag=0;
															if(lie>=8)
																{
																		if(LED[hang][lie]==1)
																	{	
																		temp[hang*2+1]-=pow(2,lie%8);
																		LED[hang][lie]=0;	
																	}
																}
																else
																{
																if(LED[hang][lie]==1)
																	{
																	temp[hang*2]-=pow(2,lie%8);
																	LED[hang][lie]=0;
																	};
																};break;//quiet      擦出改点
									}	
				}									
		}
	
}

//中断服务函数
//void Int0_ISR(void) interrupt 0
//{
//
//}
//
//void Timer0_ISR(void) interrupt 1
//{
//
//}
//
//void Int1_ISR(void) interrupt 2
//{
//
//}
//
//void Timer1_ISR(void) interrupt 3
//{
//
//}
//
//void UART_ISR(void) interrupt 4
//{
//	
//}