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

/**********************************
PIN口定义
**********************************/
sbit MOSIO = P3^4;
sbit R_CLK = P3^5;
sbit S_CLK = P3^6;

//变量定义
//uchar code tab10[] = 
//{0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08,
// 0x00, 0x10, 0x00, 0x20, 0x00, 0x40, 0x00, 0x80,
// 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08, 0x00,
// 0x10, 0x00, 0x20, 0x00, 0x40, 0x00, 0x80, 0x00}; 

/**********************************
函数声明
**********************************/
/*led点阵显示函数*/
void li( uchar x);

/*595发送数据函数*/					  
void HC595SendData(  uchar BT3, uchar BT2,uchar BT1,uchar BT0);

#endif
