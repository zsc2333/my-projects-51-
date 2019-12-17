#ifndef __MODE3_H_
#define __MODE3_H_

//---包含头文件---//
#include <reg52.h>
#include <intrins.h>
#include <math.h>
#include <string.h>
#include "dis.h"
#include "Ircon.h"

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

//---变量定义---//
extern unsigned char save[];

//---函数定义---//
void mode3(void);

#endif