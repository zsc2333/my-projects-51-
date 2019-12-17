#ifndef __DIS_H_
#define __DIS_H_

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

//变量定义
extern uchar code tab100[];
/**********************************
PIN口定义
**********************************/
sbit MOSIO = P3^4;
sbit R_CLK = P3^5;
sbit S_CLK = P3^6;

/**********************************
函数声明
**********************************/
/*led点阵显示函数*/
void li( uchar x);

/*595发送数据函数*/					  
void HC595SendData(  uchar BT3, uchar BT2,uchar BT1,uchar BT0);

#endif
