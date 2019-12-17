//主题：STC89C5xRC系列单片机模板
//作者：ZSC
//日期：20180102
//版本：V1
//修改说明：红外遥控led点阵控制
#define uint unsigned int
#define uchar unsigned char
//头文件
#include <reg52.h>
#include "dis.h"
#include "Ircon.h"

//函数声明

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