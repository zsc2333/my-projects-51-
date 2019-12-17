//���⣺����ң��led�������
//���ߣ�ZSC
//���ڣ�20180102
//�汾��V3
//�޸�˵��������ң��led�������
//�ؼ����ض���
#define uint unsigned int
#define uchar unsigned char
#define ulong unsigned long
//ͷ�ļ�
#include <reg52.h>
#include <math.h>
#include <intrins.h>
#include "dis.h"
#include "Ircon.h"
#include "array.h"
#include "mode3.h"

//��������
void mode_1(void);//��ʾ��������
void mode2(void);//��ʾ��Ƭ��ԭ��Ӧ��
//void mode3(void);//���ͼ��ģʽ
void mode_4(void);//��ʾ����ͼ��
//������
void main(void)
{
	uchar control;
	IrInit();
	while(1)
		{//��ѭ�� 
			control=IrValue[2];
					switch(control)//�ж�IrValue[2]����Ϊ��������ŵ���������
						{ 
							case 0x0c: 
								{
									P1=0x01;
									mode_1();
								}//��1������ģʽ1
								break; 
							case 0x18: 
									{
										P1=0x03;
										cycle();//��ʾ��Ƭ��ԭ��Ӧ��
									}	 //��2������ģʽ2     
								break; 
							case 0x5e: 
									{
										P1=0x07;
										mode3();

									} //��3������ģʽ3,���ͼ��ģʽ 
								break;   
							case 0x08: 
									{
										P1=0x0f;
										mode_4();
									} //��4������ģʽ4  
								break;
							default:
									{
										P1=0x00;
										li(10);
									}		
								break;
						}   
		}
	
}
void mode_1()//��ʾ�����ַ�
{
	uchar control;
	while(1)
		{//ģʽ1ѭ�� 
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
							HC595SendData(0xff,0xff,0,0);	 //����
								break;
						}   
					}
		}
}

void mode_4()//��ʾ����ͼ��
{
		uchar control;
	while(1)
		{//ģʽ4ѭ�� 
			uchar k;
			control=IrValue[2];
			if (control == 0x46)
					return;
			else
				{
					for(k = 0; k < 16; k++)											
						{	 
							HC595SendData(~save[2*k +1],~save[2*k],tab100[2*k],tab100[2*k + 1]); 		 
						};
				 }
		}
}
