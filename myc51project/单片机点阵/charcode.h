#ifndef __CHARCODE_H
#define __CHARCODE_H

// unsigned char code tab1[] = {0,0,0,0,0,0,120,0,132,0,2,1,2,1,2,1,2,
// 							1,2,1,2,1,2,1,2,1,2,1,132,0,120,0};      //0
// unsigned char code tab2[] = {0,0,0,0,0,0,32,0,60,0,32,0,32,0,32,0,
// 								32,0,32,0,32,0,32,0,32,0,32,0,32,0,252,1}; //1
// unsigned char code tab3[] = {0,0,0,0,0,0,120,0,132,0,2,1,2,1,128,0,64,0,32,
// 								0,16,0,8,0,4,1,4,1,130,0,254,0};     //2
// unsigned char code tab4[] = {0,0,0,0,0,0,120,0,132,0,2,1,0,1,128,0,112,
// 								0,128,0,0,1,0,1,0,1,2,1,132,0,120,0};  //3
// unsigned char code tab5[] = {0,0,0,0,0,0,96,0,96,0,80,0,80,0,72,0,72,0,
// 								68,0,68,0,66,0,254,1,64,0,64,0,240,1}; //4
// unsigned char code tab6[] = {0,0,0,0,0,0,254,1,2,0,2,0,2,0,122,0,134,0,
// 								2,1,0,1,0,1,0,1,2,1,132,0,120,0};	 //5
// unsigned char code tab7[] = {0,0,0,0,0,0,120,0,132,0,2,1,2,1,2,0,122,0,
// 								134,0,2,1,2,1,2,1,2,1,132,0,120,0} ;  //6
// unsigned char code tab8[] = {0,0,0,0,0,0,252,1,4,1,130,0,130,0,64,0,
// 							64,0,32,0,32,0,32,0,16,0,16,0,16,0,16,0}; //7
// unsigned char code tab9[] = {0,0,0,0,0,0,120,0,132,0,2,1,2,1,132,0,
// 							120,0,132,0,2,1,2,1,2,1,2,1,132,0,120,0}; //8
// unsigned char code tab10[] = {0,0,0,0,0,0,120,0,132,0,2,1,2,1,2,1,
// 							2,1,132,1,120,1,0,1,0,1,2,1,132,0,120,0}; //9
const unsigned char code num[][32] = {
	 //{0,0,0,0,0,0,120,0,132,0,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,132,0,120,0},
	// {0,0,0,0,0,0,120,0,132,0,2,1,2,1,2,1,2},
	// {1,2,1,2,1,2,1,2,1,2,1,132,0,120,0},
	 {0,0,0,0,0,0,0,0,56,0,68,0,130,0,130,0,130,0,130,0,130,0,130,0,130,0,68,0,56,0,0,0},
	 {0,0,0,0,0,0,0,0,16,0,28,0,16,0,16,0,16,0,16,0,16,0,16,0,16,0,16,0,124,0,0,0},
	 {0,0,0,0,0,0,0,0,60,0,66,0,66,0,66,0,32,0,32,0,16,0,8,0,4,0,66,0,126,0,0,0},
	 {0,0,0,0,0,0,0,0,60,0,66,0,66,0,32,0,24,0,32,0,64,0,64,0,66,0,66,0,60,0,0,0},
	 {0,0,0,0,0,0,32,0,32,0,48,0,40,0,36,0,36,0,34,0,34,0,124,0,32,0,32,0,248,0,0,0},
	 {0,0,0,0,0,0,0,0,126,0,2,0,2,0,2,0,58,0,70,0,64,0,64,0,66,0,66,0,60,0,0,0},
	 {0,0,0,0,0,0,0,0,120,0,68,0,2,0,2,0,58,0,70,0,130,0,130,0,130,0,68,0,56,0,0,0},
	 {0,0,0,0,0,0,0,0,254,0,66,0,34,0,32,0,16,0,16,0,8,0,8,0,8,0,8,0,8,0,0,0},
	 {0,0,0,0,0,0,0,0,56,0,68,0,130,0,130,0,68,0,56,0,68,0,130,0,130,0,68,0,56,0,0,0},
	 {0,0,0,0,0,0,0,0,56,0,68,0,130,0,130,0,130,0,196,0,184,0,128,0,128,0,68,0,60,0,0,0},
};

const unsigned char code tab0[] = {0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08, 0x00, 0x10, 0x00, 0x20, 0x00, 0x40, 0x00, 0x80,
                             0x01, 0x00, 0x02, 0x00, 0x04, 0x00, 0x08, 0x00, 0x10, 0x00, 0x20, 0x00, 0x40, 0x00, 0x80, 0x00};

#endif