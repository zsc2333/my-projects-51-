#ifndef __MODE3_H_
#define __MODE3_H_

//---����ͷ�ļ�---//
#include <reg52.h>
#include <intrins.h>
#include <math.h>
#include <string.h>
#include "dis.h"
#include "Ircon.h"

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

#ifndef ulong 
#define ulong unsigned long
#endif

//---��������---//
extern unsigned char save[];

//---��������---//
void mode3(void);

#endif