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
							case 0x0c: 
								{
									P0=0x01;
									mode1();
								}//��1������ģʽ1
								break; 
							case 0x18: 
									{
										P0=0x03;
										cycle();
//										mode2();
									}	 //��2������ģʽ2     
								break; 
							case 0x5e: 
									{
										P0=0x07;
										mode3();

									} //��3������ģʽ3   
								break;   
							case 0x08: 
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
			if (control == 0x46)
					return;
			else
				{
					switch(control)//�ж�IrValue[2]����Ϊ��������ŵ���������
						{ 
							case 0x16: li(0);//��0������ʾ0 
								break;
							case 0x0c: li(1); //��1������ʾ1
								break; 
							case 0x18: li(2); //��2������ʾ2     
								break; 
							case 0x5e: li(3); //��3������ʾ3   
								break;   
							case 0x08: li(4); //��4������ʾ4  
								break;
							case 0x1c: li(5); //��5������ʾ5  
								break;
							case 0x5a: li(6); //��6������ʾ6  
								break;
							case 0x42: li(7); //��7������ʾ7  
								break;
							case 0x52: li(8); //��8������ʾ8  
								break;
							case 0x4a: li(9); //��9������ʾ9  
								break;
							case 0x45: li(11); //����Դ������ʾ��Դ  
								break;
							case 0x47: li(12); //������������ʾ����  
								break;
							case 0x44: li(13); //�����ż�����ʾ����  
								break;
							case 0x40: li(14); //�����˼�����ʾ����  
								break;
							case 0x43: li(15); //�����������ʾ���  
								break;
							case 0x07: li(16); //��EQ������ʾEQ  
								break;
							case 0x09: li(17); //��V+������ʾV+  
								break;
							case 0x15: li(18); //��V-������ʾV-  
								break;
							case 0x19: li(19); //��REP������ʾREP  
								break;
							case 0x0d: li(20); //��U/SD������ʾU/SD
								break;
							default: 
//								li(10);
							HC595SendData(0xff,0xff,0,0);	 //����
								break;
						}   
//					HC595SendData(0xff,0xff,0,0);	 //����
					}
		}
}
//void mode2()//��ʾ��Ƭ��ԭ��Ӧ��
//{
//	uchar control;
////	IrInit();
//	while(1)
//		{//ģʽ2ѭ�� 
//			
////			P0 = IrValue[2];
//			control=IrValue[2];
//			if (control == 0x46)
//					return;
//			else
//				{
//						cycle();
//				 }
//		}
//}
void mode3()//���ͼ��ģʽ
{
		uchar control;
//	IrInit();
	while(1)
		{//ģʽ3ѭ�� 
			
//			P0 = IrValue[2];
			control=IrValue[2];
			if (control == 0x46)
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
			if (control == 0x46)
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