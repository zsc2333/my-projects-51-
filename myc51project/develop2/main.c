//���⣺����ң��led�������
//���ߣ�ZSC
//���ڣ�20180102
//�汾��V2
//�޸�˵��������ң��led�������
//�ؼ����ض���
#define uint unsigned int
#define uchar unsigned char
#define ulong unsigned long
//ͷ�ļ�
#include <reg52.h>
#include "dis.h"
#include "Ircon.h"
#include "array.h"
//��������
void mode1(void);//��ʾ��������
void mode2(void);//��ʾ��Ƭ��ԭ��Ӧ��
void mode3(void);//���ͼ��ģʽ
void mode4(void);//��ʾ���ͼ��
//������
void main(void)
{
	uchar control;
	IrInit();
	while(1)
		{//��ѭ�� 
			
//			P0 = IrValue[2];
			control=IrValue[2];
					switch(control)//�ж�IrValue[2]����Ϊ��������ŵ���������
						{ 
							case 0xF3: 
								{
									P0=0x01;
									mode1();
								}//��1������ģʽ1
								break; 
							case 0xE7: 
									{
										P0=0x03;
										mode2();
									}	 //��2������ģʽ2     
								break; 
							case 0xA1: 
									{
										P0=0x07;
										mode3();

									} //��3������ģʽ3   
								break;   
							case 0xF7: 
									{
										P0=0x0f;
										mode4();
									} //��4������ģʽ4  
								break;
							default:
									{
										P0=0x00;
										li(10);
									}		
								break;
						}   
//					HC595SendData(0xff,0xff,0,0);	 //����
		}
	
}
void mode1()//��ʾ��������
{
	uchar control;
//	IrInit();
	while(1)
		{//ģʽ1ѭ�� 
			
//			P0 = IrValue[2];
			control=IrValue[2];
			if (control == 0xBB)
					return;
			else
				{
					switch(control)//�ж�IrValue[2]����Ϊ��������ŵ���������
						{ 
							case 0xE9: li(0);//��0������ʾ0 
								break;
							case 0xF3: li(1); //��1������ʾ1
								break; 
							case 0xE7: li(2); //��2������ʾ2     
								break; 
							case 0xA1: li(3); //��3������ʾ3   
								break;   
							case 0xF7: li(4); //��4������ʾ4  
								break;
							case 0xE3: li(5); //��5������ʾ5  
								break;
							case 0xA5: li(6); //��6������ʾ6  
								break;
							case 0xBD: li(7); //��7������ʾ7  
								break;
							case 0xAD: li(8); //��8������ʾ8  
								break;
							case 0xB5: li(9); //��9������ʾ9  
								break;
							default: li(10);
								break;
						}   
//					HC595SendData(0xff,0xff,0,0);	 //����
					}
		}
}
void mode2()//��ʾ��Ƭ��ԭ��Ӧ��
{
	uchar control;
//	IrInit();
	while(1)
		{//ģʽ2ѭ�� 
			
//			P0 = IrValue[2];
			control=IrValue[2];
			if (control == 0xBB)
					return;
			else
				{
						cycle();
				 }
		}
}
void mode3()//���ͼ��ģʽ
{
		uchar control;
//	IrInit();
	while(1)
		{//ģʽ3ѭ�� 
			
//			P0 = IrValue[2];
			control=IrValue[2];
			if (control == 0xBB)
					return;
			else
				{
						li(8);
				 }
		}
}
void mode4()//��ʾ���ͼ��
{
		uchar control;
//	IrInit();
	while(1)
		{//ģʽ4ѭ�� 
			
//			P0 = IrValue[2];
			control=IrValue[2];
			if (control == 0xBB)
					return;
			else
				{
						li(9);
				 }
		}
}
//�жϷ�����
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