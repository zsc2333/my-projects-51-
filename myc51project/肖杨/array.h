#ifndef __array_H_
#define __array_H_

/**********************************
����ͷ�ļ�
**********************************/
#include<reg52.h>
#include <intrins.h>

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

/**********************************
PIN�ڶ���
**********************************/
sbit MOSIO = P3^4;
sbit R_CLK = P3^5;
sbit S_CLK = P3^6;

/**********************************
��������
**********************************/
/*led������ѭ����ʾ����*/
void cycle();
/*ͨ��595�����ĸ��ֽ����ݵĺ���*/
void HC595SendData(  uchar BT3, uchar BT2,uchar BT1,uchar BT0);				  

#endif
