#ifndef __DOT_H
#define __DOT_H

//头文件
#include <reg51.h>

//宏定义
#define ON 0
#define OFF 1

//SPI IO
sbit MOSIO = P3^4;
sbit R_CLK = P3^5;
sbit S_CLK = P3^6;

//函数声明
//函数声明
void HC595SendData(unsigned char BT3, unsigned char BT2,unsigned char BT1,unsigned char BT0);

#endif
