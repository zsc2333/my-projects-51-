#ifndef __IRCON_H_
#define __IRCON_H_

/**********************************
包含头文件
**********************************/
#include<reg52.h>

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

#ifndef ulong 
#define ulong unsigned long
#endif

/**********************************
PIN口定义
**********************************/
sbit IRIN=P3^2;
/*********************************
变量定义
**********************************/
extern uchar IrValue[6];
/**********************************
函数声明
**********************************/
/*0.14ms延时函数*/
void DelayMs(unsigned int x);   //0.14ms 误差0us

/*红外线接收初始化函数*/
void IrInit();

/*读取红外线数值的中断函数*/
//void ReadIr() interrupt 0 ; 

#endif
