#include "dot.h"
/**
  * @brief  HC595数据发送函数
  * @param  
  * 		BIT3 ：
  * 		BIT2 ：
  * 		BIT1 ：
  * 		BIT0 ：
  * @retval None
  */
void HC595SendData( unsigned char BIT3, 
					unsigned char BIT2, 
					unsigned char BIT1, 
					unsigned char BIT0 )
{
	unsigned char i;
	for (i = 0; i < 32; i++)
	{
		if (i > 23)
		{
			if ((BIT0 << (i - 24)) & 0x80)
			{
				MOSIO = 1;
			}
			else
			{
				MOSIO = 0;
			}
		}
		else if (i > 15 & i < 24)
		{
			if ((BIT1 << (i - 16)) & 0x80)
			{
				MOSIO = 1;
			}
			else
			{
				MOSIO = 0;
			}
		}
		else if (i < 16 & i > 7)
		{
			if ((BIT2 << (i - 8)) & 0x80)
			{
				MOSIO = 1;
			}
			else
			{
				MOSIO = 0;
			}
		}
		else
		{
			if ((BIT3 << i) & 0x80)
			{
				MOSIO = 1;
			}
			else
			{
				MOSIO = 0;
			}
		}
		S_CLK = 0;
		S_CLK = 1;
	}
	R_CLK = 0;
	R_CLK = 1;
}