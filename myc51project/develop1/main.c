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
							case 0x0c: 
								{
									P0=0x01;
									mode1();
								}//按1键，进模式1
								break; 
							case 0x18: 
									{
										P0=0x03;
										cycle();
//										mode2();
									}	 //按2键，进模式2     
								break; 
							case 0x5e: 
									{
										P0=0x07;
										mode3();

									} //按3键，进模式3   
								break;   
							case 0x08: 
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
			if (control == 0x46)
					return;
			else
				{
					switch(control)//判断IrValue[2]，因为这个里面存放的是数据码
						{ 
							case 0x16: li(0);//按0键，显示0 
								break;
							case 0x0c: li(1); //按1键，显示1
								break; 
							case 0x18: li(2); //按2键，显示2     
								break; 
							case 0x5e: li(3); //按3键，显示3   
								break;   
							case 0x08: li(4); //按4键，显示4  
								break;
							case 0x1c: li(5); //按5键，显示5  
								break;
							case 0x5a: li(6); //按6键，显示6  
								break;
							case 0x42: li(7); //按7键，显示7  
								break;
							case 0x52: li(8); //按8键，显示8  
								break;
							case 0x4a: li(9); //按9键，显示9  
								break;
							case 0x45: li(11); //按电源键，显示电源  
								break;
							case 0x47: li(12); //按静音键，显示静音  
								break;
							case 0x44: li(13); //按播放键，显示播放  
								break;
							case 0x40: li(14); //按快退键，显示快退  
								break;
							case 0x43: li(15); //按快进键，显示快进  
								break;
							case 0x07: li(16); //按EQ键，显示EQ  
								break;
							case 0x09: li(17); //按V+键，显示V+  
								break;
							case 0x15: li(18); //按V-键，显示V-  
								break;
							case 0x19: li(19); //按REP键，显示REP  
								break;
							case 0x0d: li(20); //按U/SD键，显示U/SD
								break;
							default: 
//								li(10);
							HC595SendData(0xff,0xff,0,0);	 //清屏
								break;
						}   
//					HC595SendData(0xff,0xff,0,0);	 //清屏
					}
		}
}
//void mode2()//显示单片机原理及应用
//{
//	uchar control;
////	IrInit();
//	while(1)
//		{//模式2循环 
//			
////			P0 = IrValue[2];
//			control=IrValue[2];
//			if (control == 0x46)
//					return;
//			else
//				{
//						cycle();
//				 }
//		}
//}
void mode3()//描绘图形模式
{
		uchar control;
//	IrInit();
	while(1)
		{//模式3循环 
			
//			P0 = IrValue[2];
			control=IrValue[2];
			if (control == 0x46)
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
			if (control == 0x46)
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