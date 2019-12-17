/**************************************************************
程序名称：模拟电子琴
**************************************************************/ 
#include<reg52.h>	    		 	//定义头文件
#define uchar unsigned char			//宏定义
#define uint unsigned int			//宏定义
#define led P0					//定义LED等位P0口
#define sw_port P1				//中间变量。。。使按键和led对应
sbit buzzer=P2^7;				//扬声器管脚
sbit key1=P3^2;					//播放音乐与弹奏歌曲转换
sbit key3=P3^4;					//掉电存储按键
sbit key4=P3^5;                 //播放掉电存储的歌曲                                         
sbit keybofang=P3^3;			//播放刚才弹奏的歌曲
sbit key7=P3^0;					//音调键。。。 和  歌曲键
sbit key8=P3^1;					//音调键。。。 和  歌曲键
sbit key6=P1^7;
sbit key5=P1^6; 				  
sbit sda=P1^1;				      	//24c02数据线  
sbit scl=P1^0;					//24c02时钟线
uchar keyd,i,keys,b;			  	//定义变量
uchar tone_H;					//定义变量
uchar tone_L;					//定义变量
void beat_125(unsigned char);			//声明函数
uchar code beat1[]={16,8,8,8,8,4,4,16,8,4,4,8,4,4,4,	//歌曲1节拍 
4,4,4,16,16,8,8,4,4,12,8,16,16,8,4,4,4,4,16};
uchar code song1[]={6,5,3,5,7,6,5,6,3,5,6,5,3,		//歌曲1简谱
2,1,6,5,3,2,2,3,5,5,6,3,2,1,5,3,2,1,6,1,1,15};

uchar code beat2[]={7,7,7, 7,8,9, 1,2,3, 6,2,4, 4,4,4, 12, 	//歌曲二节拍
8,2,2, 4,4,4, 8,2,2, 4,4,4, 2,2,4,4, 12,};
uchar code song2[]={1,2,8, 8,5,1, 3,3,3, 5,4,3,		//歌曲二简谱
 5,4,3, 2, 2,1,0, 1,2,3, 4,3,2, 3,4,5, 5,4,3, 2,1,15};

uchar code beat4[]={4,4,4, 6,2,4, 4,4,4, 6,2,4, 4,4,4, 12, 
8,2,2, 4,4,4, 8,2,2, 4,4,4, 2,2,4,4, 12,};
uchar code song4[]={1,1,1, 3,2,1, 3,3,3, 5,4,3,
 5,4,3, 2, 2,1,0, 1,2,3, 4,3,2, 3,4,5, 5,4,3, 2,1, 15};

uchar code tone[]={115,102,91,86,77,68,61,57};		//歌曲音调
unsigned int code tone1[]={1012,956,852,759,716,638,568,506,478,426,379,531,10}; //歌曲音调
uchar song3[43];				      	//定义空数组
void play(uchar*,uchar*);			  	//演奏歌曲函数
void delay8um(uchar);				  	//第一8um延时函数
void sound(uchar);					//弹奏发声函数
/*******************************************
函数功能：节拍的延时的基本单位，用于24c08简单延时
******************************************/					 
void delay()						//简单延时函数
{;;}
/*******************************************
函数功能：节拍的延时的基本单位，延时1ms
******************************************/
void delay1ms(uchar x)				  	//1um延时函数
{
	uchar j;
	while(x--)
		for(j=120;j>0;j--);
}
/**************************************************************
函数功能：24c02驱动程序      用IIC总线进行传输
**************************************************************/ 
void init_c02()						//24c02初始化
{
	sda=1;
	delay();
	scl=1;
	delay();
}
void start_c02()	             			//24c02的启动信号
{
	scl=1;
	delay();	  
	sda=1;	 
	delay();
	sda=0;
	delay();

}
void stop_c02()				   		//24c02停止信号
{
	sda=0;
	delay();
	scl=1;
	delay();
	sda=1;
	delay();
}
void response_c02()					//24c02的应答信号
{
	uchar i;
	scl=1;
	delay();
	while((sda==1)&&(i<250))i++;
	scl=0;
	delay();
}
void write_c02byte(uchar date)	    			//对24c02写一个字节
{
	uchar i,temp;
	temp=date;
	for(i=0;i<8;i++)
	{	
		temp=temp<<1;
		scl=0;
		delay();
		sda=CY;
		delay();
		scl=1;
		delay();
	}
	scl=0;
	delay();
	sda=1;
	delay();
}
uchar read_c02byte()					//对24c02读一个字节
{
	 uchar i,k;
	 scl=0;
	 delay();
	 sda=1;
	 delay();
	 for(i=0;i<8;i++)
	 {
	 	scl=1;
		delay();
		k=(k<<1)|sda;
		scl=0;
		delay();
	}
	return k;
}
void write_addc02(uchar address,uchar date)		//对24c02写一个数据	
{
	start_c02();
 	write_c02byte(0xa0);
	response_c02();
	write_c02byte(address);
	response_c02();
	write_c02byte(date);
	response_c02();
	stop_c02();
}
uchar read_addc02(uchar address)			//从24c02读一个数据
{
	uchar date;
	start_c02();
	write_c02byte(0xa0);
	response_c02();
	write_c02byte(address);
	response_c02();
	start_c02();	
	write_c02byte(0xa1);
	response_c02();
	date=read_c02byte();
//	response_c02;
	stop_c02();
	return date;
}
/**************************************************************
函数功能：主函数。。。。。。。。。。。。
**************************************************************/  
void main()						//主函数
{	
	uchar yd,temp,jj,tt;				//定义变量
	uchar t1,i;					//定义变量
	t1=0;						//初始化 t1
	yd=0;	                    //初始化t2
	buzzer=1; 					//初始化蜂鸣器
	EA=1;						//打开定时总中断
	TMOD=0x01;					//设置定时器模式  定时器0工作在方式1	
	ET0=1;						//打开定时器0中断
	while(1)					//主循环
	{
		led=0x3c;
		sw_port=0xff;
		keys=~sw_port;				//将led与按键结合起来
		switch(keys)				//进入键盘选择
		{
			case 0x04:sound(0);temp=1;yd=0;break;	 //如果键盘1被按下发音do，同时设置标志temp，将数字计入yd
			case 0x08:sound(1);temp=1;yd=1;break;	 //如果键盘2被按下发音ruai，同时设置标志temp，将数字计入yd
			case 0x10:sound(2);temp=1;yd=2;break;	 //如果键盘3被按下发音mi，同时设置标志temp，将数字计入yd
		  case 0x20:sound(3);temp=1;yd=3;break;	 //如果键盘4被按下发音fa，同时设置标志temp，将数字计入yd

		}
		if(key5==0)				//如果键盘5被按下发音la，同时设置标志temp，将数字计入yd
		{
				while(!key5)		// 松手检测
			 	sound(4);
				temp=1;yd=4;	
		}
		if(key6==0)				//如果键盘6被按下发音xi，同时设置标志temp，将数字计入yd
		{
				while(!key6)		// 松手检测
			 	sound(5);
				temp=1;yd=5;	
		}
		if(key7==0)				//如果键盘7被按下发音xi，同时设置标志temp，将数字计入yd
		{
				while(!key7)		// 松手检测
			 	sound(6);
				temp=1;yd=6;	
		}
		if(key8==0)				//如果键盘8被按下发音高音do，同时设置标志temp，将数字计入yd
		{
				while(!key8)	 	//松手检测
			 	sound(7);		//播放高音do。。
				temp=1;yd=7;
		}
		if(temp==1)				//标志位，如果标志位为1，则说明有按键被按下
		{
			
			temp=0;				//将标识位归零
			song3[t1++]=yd;		//将数据存入song3[]数组
		}

		if(key3==0)				//将数据存入24c02 ，掉电存储按键
		{
			delay1ms(10);
			if(key3==0)			//检测是否key3被按下
			{	
				P0=0;			//如果被按下，将led打开
				while(!key3);	 	//松手检测
				song3[t1++]=30;	
				init_c02();		//初始化24c02
					for(i=0;i<40;)	//进入循环
					{
						 write_addc02(i,song3[i++]);	//将数据依次写入24c02
						 delay1ms(10);			//延时
					}
			     	P0=1;						//led关闭
			}
		}
		if(key4==0)				//读取24c02中的数据，掉电播放
		{
			delay1ms(10);
			if(key4==0)
			{				//检测是否有键被按下
				
				while(!key4);		//松手检测
				init_c02(); 		//初始化
				P0=0;			//将led打开					
				tt=1;			//将tt初值设为0
				while(read_addc02(tt)!=30)			//进入while循环
				{
					jj=read_addc02(tt++);
					tone_H=(65536-tone1[jj])/256;		//设定初值
					tone_L=(65536-tone1[jj])%256;		//设定初值				 
				     TH0=tone_H;				//赋值TH0高八位
					 TL0=tone_L;				//赋值TL0低八位
					 TR0=1;				    	//打开定时器
					 beat_125(3);			 	//延时
					 TR0=0;
					 beat_125(4);				//关闭定时器
				}
				P0=1;						//关闭led
            }
		}

		if(keybofang==0)
		{
			while(!keybofang);					//检测回放键是否被按下
			song3[t1++]=30;
		   //	t1=0;
			while(song3[i]!=30)					//进入while循环。
			{
			 	 tone_H=(65536-tone1[song3[i]])/256;
				 tone_L=(65536-tone1[song3[i]])%256;
				 TH0=tone_H;
				 TL0=tone_L;
				 TR0=1;						//开启定时器
			     beat_125(3);			 									   
				 TR0=0;						//关闭定时器
				 i++;
				 beat_125(4);					//将i值加一							
		    }												  
		}
		if(key1==0)
		{
			delay1ms(10);
			if(key1==0)						//检测key1是否被按下
			{	
				while(!key1);
				P0=0;						//关闭led
				while(key1)					//进入循环
				{		
				   if(key7==0)				   	//检测key7是否被按下
					{
						delay1ms(10);
						if(key7==0)
						{
							P0=0xaa;		//设置led灯亮个数
							while(!key7);		//等待释放
							play(song1,beat1);	//演奏歌曲1
							P0=0xff;		//关闭led
						}
					}
					if(key8==0)				//检测是否key8键被按下
					{
						delay1ms(10);
						if(key8==0)
						{
							P0=0xaa;		//设置led灯亮
							while(!key8);		//松手检测
							play(song2,beat2);	//播放歌曲2
							P0=0xff;		//关闭led
						}			
					}
					if(key6==0)				//检测是否key6键被按下
					{
						delay1ms(10);
						if(key6==0)
						{
							P0=0xaa;		//设置led灯亮
							while(!key6);		//松手检测
							play(song4,beat4);	//播放歌曲4
							P0=0xff;		//关闭led
						}			
					}  
				}
					while(!key1);				//检测key1是否被按下
					P0=1;					//如果被按下。退出该函数。。并关闭led
				
			}
		}
	
	}
}
/**************************************************************
函数功能：从数组中播放歌曲
**************************************************************/ 
void play(uchar*song,uchar*beat)			//播放歌曲函数
{
	 i=0;						//设置初始值
	 while(song[i]!=15)				//  进入循环函数
	 {
	 	 tone_H=(65536-tone1[song[i]])/256;	//定义初值
		 tone_L=(65536-tone1[song[i]])%256;	//定义初值
		 TH0=tone_H;				//赋值
		 TL0=tone_L;		 		//赋值
		 TR0=1;					//打开定时器0
		 beat_125(beat[i]);			//读取节拍函数
		 i++;					//自加 
		 TR0=0;					//关闭led
	 }
}
/**************************************************************
函数功能：定时器T0的中断服务子程序，使P2.7引脚输出音频方波
**************************************************************/ 
void tone_timer() interrupt 1	 			//中断子程序
{
	 TH0=tone_H;
	 TL0=tone_L;
	 buzzer=~buzzer;				//扬声器开关控制
}
/**************************************************************
函数功能：产生节拍的函数
**************************************************************/ 
void beat_125(uchar x)					//节拍。。
{
	uchar i,j,k;					//125ms延时函数。。
	for(i=0;i<x;i++)
		for(j=0;j<125;j++)
			for(k=0;k<120;k++);
}
/**************************************************************
函数功能：8um简易延时
**************************************************************/ 
void delay8um(uchar x)					//8ms延时函数
{
	uchar i,j;
	for(i=0;i<x;i++)
		for(j=0;j<1;j++);
}
/**************************************************************
函数功能：产生音调
**************************************************************/ 
void sound(uchar x)					//音调函数
{
	uchar i;
	led=sw_port;					//定义led
	for(i=0;i<255;i++)
	{
		buzzer=0;delay8um(tone[x]);		//开关频率。。从而产生节拍
		buzzer=1;delay8um(tone[x]);
	}
	led=0xff;
} 
