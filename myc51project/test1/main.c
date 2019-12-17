//主题：红外遥控led点阵控制
//作者：ZSC
//日期：20180102
//版本：V3
//修改说明：红外遥控led点阵控制
//关键词重定义
#define uint unsigned int
#define uchar unsigned char
#define ulong unsigned long
//头文件
#include <reg52.h>
#include <math.h>
#include <intrins.h>
#include "dis.h"
#include "Ircon.h"
#include "array.h"
#include "mode3.h"

//函数声明
void mode_1(void);//显示键盘数字
void mode2(void);//显示单片机原理及应用
//void mode3(void);//描绘图形模式
void mode_4(void);//显示描绘的图形
//主函数
void main(void)
{
	uchar control;
	IrInit();
	while(1)
		{//主循环 
			control=IrValue[2];
					switch(control)//判断IrValue[2]，因为这个里面存放的是数据码
						{ 
							case 0x0c: 
								{
									P1=0x01;
									mode_1();
								}//按1键，进模式1
								break; 
							case 0x18: 
									{
										P1=0x03;
										cycle();//显示单片机原理及应用
									}	 //按2键，进模式2     
								break; 
							case 0x5e: 
									{
										P1=0x07;
										mode3();

									} //按3键，进模式3,描绘图形模式 
								break;   
							case 0x08: 
									{
										P1=0x0f;
										mode_4();
									} //按4键，进模式4  
								break;
							default:
									{
										P1=0x00;
										li(10);
									}		
								break;
						}   
		}
	
}
void mode_1()//显示键盘字符
{
	uchar control;
	while(1)
		{//模式1循环 
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
							HC595SendData(0xff,0xff,0,0);	 //清屏
								break;
						}   
					}
		}
}

void mode_4()//显示描绘的图形
{
		uchar control;
	while(1)
		{//模式4循环 
			uchar k;
			control=IrValue[2];
			if (control == 0x46)
					return;
			else
				{
					for(k = 0; k < 16; k++)											
						{	 
							HC595SendData(~save[2*k +1],~save[2*k],tab100[2*k],tab100[2*k + 1]); 		 
						};
				 }
		}
}
