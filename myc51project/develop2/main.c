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
#include "dis.h"
#include "Ircon.h"
#include "array.h"
//函数声明
void mode1(void);//显示键盘数字
void mode2(void);//显示单片机原理及应用
void mode3(void);//描绘图形模式
void mode4(void);//显示描绘图形
//主函数
void main(void)
{
	uchar control;
	IrInit();
	while(1)
		{//主循环 
			
//			P0 = IrValue[2];
			control=IrValue[2];
					switch(control)//判断IrValue[2]，因为这个里面存放的是数据码
						{ 
							case 0xF3: 
								{
									P0=0x01;
									mode1();
								}//按1键，进模式1
								break; 
							case 0xE7: 
									{
										P0=0x03;
										mode2();
									}	 //按2键，进模式2     
								break; 
							case 0xA1: 
									{
										P0=0x07;
										mode3();

									} //按3键，进模式3   
								break;   
							case 0xF7: 
									{
										P0=0x0f;
										mode4();
									} //按4键，进模式4  
								break;
							default:
									{
										P0=0x00;
										li(10);
									}		
								break;
						}   
//					HC595SendData(0xff,0xff,0,0);	 //清屏
		}
	
}
void mode1()//显示键盘数字
{
	uchar control;
//	IrInit();
	while(1)
		{//模式1循环 
			
//			P0 = IrValue[2];
			control=IrValue[2];
			if (control == 0xBB)
					return;
			else
				{
					switch(control)//判断IrValue[2]，因为这个里面存放的是数据码
						{ 
							case 0xE9: li(0);//按0键，显示0 
								break;
							case 0xF3: li(1); //按1键，显示1
								break; 
							case 0xE7: li(2); //按2键，显示2     
								break; 
							case 0xA1: li(3); //按3键，显示3   
								break;   
							case 0xF7: li(4); //按4键，显示4  
								break;
							case 0xE3: li(5); //按5键，显示5  
								break;
							case 0xA5: li(6); //按6键，显示6  
								break;
							case 0xBD: li(7); //按7键，显示7  
								break;
							case 0xAD: li(8); //按8键，显示8  
								break;
							case 0xB5: li(9); //按9键，显示9  
								break;
							default: li(10);
								break;
						}   
//					HC595SendData(0xff,0xff,0,0);	 //清屏
					}
		}
}
void mode2()//显示单片机原理及应用
{
	uchar control;
//	IrInit();
	while(1)
		{//模式2循环 
			
//			P0 = IrValue[2];
			control=IrValue[2];
			if (control == 0xBB)
					return;
			else
				{
						cycle();
				 }
		}
}
void mode3()//描绘图形模式
{
		uchar control;
//	IrInit();
	while(1)
		{//模式3循环 
			
//			P0 = IrValue[2];
			control=IrValue[2];
			if (control == 0xBB)
					return;
			else
				{
						li(8);
				 }
		}
}
void mode4()//显示描绘图形
{
		uchar control;
//	IrInit();
	while(1)
		{//模式4循环 
			
//			P0 = IrValue[2];
			control=IrValue[2];
			if (control == 0xBB)
					return;
			else
				{
						li(9);
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