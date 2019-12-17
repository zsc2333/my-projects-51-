/*****************************************************************************************
*																                         *
*	                 LED点阵实验 (显示数字)								         *
		行：高电平有效，低16位  列：低电平有效,高16位

******************************************************************************************/

#include <REG51.H>
#include "dot.h"
#include "charcode.h"
#include <intrins.h>
#define  NOP() _nop_()  // 定义空指令 ，这个函数在库 <intrins.h> 中



//变量声明
unsigned long column;   //点阵列
unsigned long row;      //点阵行
unsigned long dt;

																							
/*************主函数*****************************/	
void main(void)
{
	unsigned char n;
   int k,i,ms;
   i = 16;	
   															  //显示时间
   while(1)
   {
   	for (n = 0; n <= 9; n++)
   	{
   		for(ms = i; ms > 0; ms--)
	 	{
       		for(k = 0; k < 16; k++)												//亲
	   		{	 
         		HC595SendData(~num[n][2*k +1],~num[n][2*k],tab0[2*k],tab0[2*k + 1]); 		 
	   		}
	 	}
	 	HC595SendData(0xff,0xff,0,0);										   //清屏	
   	}
   }
}