#define uint unsigned int
#define uchar unsigned char
#define ulong unsigned long
//头文件
#include <reg52.h>
#include <intrins.h>
#include <math.h>
#include <string.h>
#include "mode3.h"
#include "dis.h"
#include "Ircon.h"


//全局变量定义
unsigned char save[] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//主函数
void mode3(void)
{
	unsigned char k,hang=0;
	unsigned char lie=0;
	unsigned char LED[16][16]={0};
	unsigned char cur[]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned char temp[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	while(1)
		{//主循环 
			if (IrValue[2] == 0x46)
					return;
			else
				{
							for(k = 0; k < 16; k++)											    
								 {	 
										 HC595SendData(~cur[2*k +1],~cur[2*k],tab100[2*k],tab100[2*k + 1]); 
										 HC595SendData(~temp[2*k +1],~temp[2*k],tab100[2*k],tab100[2*k + 1]);
								 }																//显示正在画的内容
							if(keyflag==1)
								{
									P2=IrValue[2];
									switch(IrValue[2])
													{
															case 0x08:keyflag=0;memset(cur,0,32);HC595SendData(0xff,0xff,0,0);
																				if(lie==0)lie=16;
																				lie--;
																				if(lie>=8)
																				cur[hang*2+1]+=pow(2,lie%8);
																				else
																				cur[hang*2]+=pow(2,lie%8);
																				break;		//4-光标左移
															case 0x5a:keyflag=0;memset(cur,0,32);HC595SendData(0xff,0xff,0,0);
																				lie++;
																				if(lie==16)lie=0;
																				if(lie>=8)
																				cur[hang*2+1]+=pow(2,lie%8);
																				else
																				cur[hang*2]+=pow(2,lie%8);
																				break;		//6-光标右移
															case 0x18:keyflag=0;memset(cur,0,32);HC595SendData(0xff,0xff,0,0);
																				if(hang==0)hang=16;
																				hang--;
																				if(lie>=8)
																				cur[hang*2+1]+=pow(2,lie%8);
																				else
																				cur[hang*2]+=pow(2,lie%8);
																				break;		//2-光标上移
															case 0x52:keyflag=0;memset(cur,0,32);HC595SendData(0xff,0xff,0,0);
																				hang++;
																				if(hang==16)hang=0;
																				if(lie>=8)
																				cur[hang*2+1]+=pow(2,lie%8);
																				else
																				cur[hang*2]+=pow(2,lie%8);
																				break;		//8-光标下移
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
																			};break;		//5-写入该点 
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
																		};break;		//0-擦除该点
															case 0x0d:keyflag=0;
																	for(k=0;k<32;k++){save[k]=temp[k];}
																	break;				//U/SD-将缓存数组存入指定数组
															case 0x19:keyflag=0;
																	for(k=0;k<32;k++){temp[k]=0x00;}
																	break;				//RPT-清屏											
													}	
								}
					}
		}
}