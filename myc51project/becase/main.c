//���⣺STC89C5xRCϵ�е�Ƭ��ģ��
//���ߣ�ZSC
//���ڣ�20180102
//�汾��V1
//�޸�˵��������ң��led�������
#define uint unsigned int
#define uchar unsigned char
//ͷ�ļ�
#include <reg52.h>
#include "dis.h"
#include "Ircon.h"

//��������

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