#ifndef __DIS_H_
#define __DIS_H_

/**********************************
����ͷ�ļ�
**********************************/
#include<reg52.h>

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

//��������
extern uchar code tab100[];
/**********************************
PIN�ڶ���
**********************************/
sbit MOSIO = P3^4;
sbit R_CLK = P3^5;
sbit S_CLK = P3^6;

/**********************************
��������
**********************************/
/*led������ʾ����*/
void li( uchar x);

/*595�������ݺ���*/					  
void HC595SendData(  uchar BT3, uchar BT2,uchar BT1,uchar BT0);

#endif
