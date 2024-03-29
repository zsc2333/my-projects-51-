#include"dis.h"
#include"Ircon.h"
/*led点阵显示数字函数*/

//---全局变量声明--//
ulong column;   //点阵列
ulong row;      //点阵行
ulong dt;

//--点阵显示数组--//
uchar code tab10[] = 
{0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08,
 0x00, 0x10, 0x00, 0x20, 0x00, 0x40, 0x00, 0x80,
 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08, 0x00,
 0x10, 0x00, 0x20, 0x00, 0x40, 0x00, 0x80, 0x00}; 


uint code tab[21][32]=
{
	{0, 0, 0, 0, 0, 0, 24, 24, 36, 36, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 36, 36, 24, 24, 0, 0, 0, 0},//--00字模--//
	
	{0, 0, 0, 0, 0, 0, 24, 8, 36, 14, 66, 8, 66, 8, 66, 8, 66, 8, 66, 8, 66, 8, 66, 8, 36, 8, 24, 62, 0, 0, 0, 0},//--01字模--//
		
	{0, 0, 0, 0, 0, 0, 24, 60, 36, 66, 66, 66, 66, 66, 66, 32, 66, 32, 66, 16, 66, 8, 66, 4, 36, 66, 24, 126, 0, 0, 0, 0},//--02字模--//
		
	{0, 0, 0, 0, 0, 0, 24, 60, 36, 66, 66, 66, 66, 32, 66, 24, 66, 32, 66, 64, 66, 64, 66, 66, 36, 34, 24, 28, 0, 0, 0, 0},//--03字模--//
		
	{0, 0, 0, 0, 0, 0, 24, 32, 36, 48, 66, 40, 66, 36, 66, 36, 66, 34, 66, 34, 66, 126, 66, 32, 36, 32, 24, 120, 0, 0, 0, 0},//--04字模--//
		
	{0, 0, 0, 0, 0, 0, 24, 126, 36, 2, 66, 2, 66, 2, 66, 26, 66, 38, 66, 64, 66, 64, 66, 66, 36, 34, 24, 28, 0, 0, 0, 0},//--05字模--//
		
	{0, 0, 0, 0, 0, 0, 24, 56, 36, 36, 66, 2, 66, 2, 66, 26, 66, 38, 66, 66, 66, 66, 66, 66, 36, 36, 24, 24, 0, 0, 0, 0},//--06字模--//
		
	{0, 0, 0, 0, 0, 0, 24, 126, 36, 34, 66, 34, 66, 16, 66, 16, 66, 8, 66, 8, 66, 8, 66, 8, 36, 8, 24, 8, 0, 0, 0, 0},//--07字模--//
		
	{0, 0, 0, 0, 0, 0, 24, 60, 36, 66, 66, 66, 66, 66, 66, 36, 66, 24, 66, 36, 66, 66, 66, 66, 36, 66, 24, 60, 0, 0, 0, 0},//--08字模--//
	
	{0, 0, 0, 0, 0, 0, 24, 24, 36, 36, 66, 66, 66, 66, 66, 66, 66, 100, 66, 88, 66, 64, 66, 64, 36, 36, 24, 28, 0, 0, 0, 0},//--09字模--//	
	
	{0,0,0,0,60,240,102,156,67,130,0,0,0,0,0,0,	0,0,0,0,48,24,96,8,192,7,0,0,0,0,0,0},//--∩_∩--//
		
	{0,0,0,0,0,0,0,0,0,0,0,1,32,9,16,17,16,17,16,17,16,17,16,17,16,16,16,16,32,8,192,7},	 //关机
		
	{0,0,96,0,80,0,200,64,78,33,74,18,74,12,74,12,74,18,78,33,200,64,80,0,96,0,0,0,0,0,0,0},	 //quiet
		
	{0,0,0,0,132,2,140,2,148,2,164,2,196,2,132,2,132,2,196,2,164,2,148,2,140,2,132,2,0,0,0,0},  //play
		
	{0,0,0,0,65,16,97,24,81,20,73,18,69,17,195,16,195,16,69,17,73,18,81,20,97,24,65,16,0,0,0,0},	  //左移
		
	{0,0,0,0,8,130,24,134,40,138,72,146,136,162,8,195,8,195,136,162,72,146,40,138,24,134,8,130,0,0,0,0},  //右移
		
	{0,0,127,28,66,34,2,65,18,65,30,65,18,65,2,93,66,34,127,60,0,64,0,0,0,0,0,0,0,0,0,0},	  //EQ
		
	{128,0,192,1,160,2,144,4,128,0,128,0,128,0,128,0,0,0,145,9,81,10,81,10,81,10,81,10,74,10,132,121},	//V+
		
	{128,0,128,0,128,0,128,0,144,4,160,2,192,1,128,0,145,9,81,10,81,10,81,10,81,10,81,10,74,10,132,121}, //V-

	{0,0,0,0,63,126,66,132,130,132,130,132,66,132,62,124,34,4,66,4,66,4,66,4,199,15,0,0,0,0,0,0},  //REPLAY
		
	{0,0,231,0,66,0,66,0,66,8,66,4,66,2,66,1,194,0,124,0,32,119,16,145,8,150,4,148,2,119,0,0},	  //U/SD
		
}; 
//--09字模--//
//uchar code tab9[] = 
//{0, 0, 0, 0, 0, 0, 24, 24, 36, 36, 66, 66, 66, 66, 66,
// 66, 66, 100, 66, 88, 66, 64, 66, 64, 36, 36, 24, 28, 0, 0, 0, 0} ;

//--08字模--//
//uchar code tab8[] = 
//{0, 0, 0, 0, 0, 0, 24, 60, 36, 66, 66, 66, 66, 66, 66, 36,
//66, 24, 66, 36, 66, 66, 66, 66, 36, 66, 24, 60, 0, 0, 0, 0};

//--07字模--//
//uchar code tab7[] = 
//{0, 0, 0, 0, 0, 0, 24, 126, 36, 34, 66, 34, 66, 16, 66, 16,
// 66, 8, 66, 8, 66, 8, 66, 8, 36, 8, 24, 8, 0, 0, 0, 0};

//--06字模--//
//uchar code tab6[] = 
//{0, 0, 0, 0, 0, 0, 24, 56, 36, 36, 66, 2, 66, 2, 66, 26, 66,
// 38, 66, 66, 66, 66, 66, 66, 36, 36, 24, 24, 0, 0, 0, 0};

//--05字模--//
//uchar code tab5[] = 
//{0, 0, 0, 0, 0, 0, 24, 126, 36, 2, 66, 2, 66, 2, 66, 26, 66,
// 38, 66, 64, 66, 64, 66, 66, 36, 34, 24, 28, 0, 0, 0, 0};

//--04字模--//
//uchar code tab4[] = 
//{0, 0, 0, 0, 0, 0, 24, 32, 36, 48, 66, 40, 66, 36, 66, 36, 66,
//34, 66, 34, 66, 126, 66, 32, 36, 32, 24, 120, 0, 0, 0, 0};

//--03字模--//
//uchar code tab3[] = 
//{0, 0, 0, 0, 0, 0, 24, 60, 36, 66, 66, 66, 66, 32, 66, 24, 66,
// 32, 66, 64, 66, 64, 66, 66, 36, 34, 24, 28, 0, 0, 0, 0};

//--02字模--//
//uchar code tab2[] = 
//{0, 0, 0, 0, 0, 0, 24, 60, 36, 66, 66, 66, 66, 66, 66, 32, 66,
// 32, 66, 16, 66, 8, 66, 4, 36, 66, 24, 126, 0, 0, 0, 0};

//--01字模--//
//uchar code tab1[] = 
//{0, 0, 0, 0, 0, 0, 24, 8, 36, 14, 66, 8, 66, 8, 66, 8, 66, 8, 66,
//8, 66, 8, 66, 8, 36, 8, 24, 62, 0, 0, 0, 0};

//--00字模--//
//uchar code tab0[] = 
//{0, 0, 0, 0, 0, 0, 24, 24, 36, 36, 66, 66, 66, 66, 66, 66, 66, 66,
//66, 66, 66, 66, 66, 66, 36, 36, 24, 24, 0, 0, 0, 0};

/*led点阵显示函数*/
void li( uchar x )
{			
			
		uchar k;
					for(k = 0; k < 16; k++)											
						{	 
							HC595SendData(~tab[x][2*k +1],~tab[x][2*k],tab10[2*k],tab10[2*k + 1]); 		 
						
						}
}

/*通过595发送四个字节的数据*/
void HC595SendData(  uchar BT3, uchar BT2,uchar BT1,uchar BT0)
{  
	uchar i;
	
	//--发送第一个字节--//
	for(i=0;i<8;i++)
	{
		MOSIO = BT3 >> 7 ;	//从高位到低位
		BT3 <<= 1;

		S_CLK = 0;
		S_CLK = 1;		
	}

	//--发送第一个字节--//
	for(i=0;i<8;i++)
	{
		MOSIO = BT2 >>7;		//从高位到低位
		BT2 <<= 1;

		S_CLK = 0;
		S_CLK = 1;	
	}

	//--发送第一个字节--//
	for(i=0;i<8;i++)
	{
		MOSIO = BT1 >> 7;		//从高位到低位
		BT1 <<= 1;
		S_CLK = 0;
		S_CLK = 1;	
	}

	//--发送第一个字节--//
	for(i=0;i<8;i++)
	{
		MOSIO = BT0 >> 7;		//从高位到低位
		BT0 <<= 1;
		S_CLK = 0;
		S_CLK = 1;
	}
   
	//--输出--//
	R_CLK = 0; //set dataline low
	R_CLK = 1; //片选
	R_CLK = 0; //set dataline low
}