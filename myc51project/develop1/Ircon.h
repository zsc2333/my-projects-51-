#ifndef __IRCON_H_
#define __IRCON_H_

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

/**********************************
PIN�ڶ���
**********************************/
sbit IRIN=P3^2;
/*********************************
��������
**********************************/
extern uchar IrValue[6];
/**********************************
��������
**********************************/
/*0.14ms��ʱ����*/
void DelayMs(unsigned int x);   //0.14ms ���0us

/*�����߽��ճ�ʼ������*/
void IrInit();

/*��ȡ��������ֵ���жϺ���*/
//void ReadIr() interrupt 0 ; 

#endif
