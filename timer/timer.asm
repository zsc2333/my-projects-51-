;================================================================
;程序编写人：兰建文 
;编写地点：51hei培训机构
;时间5月24日晚间  星期日
;功能：本程序实现P0口的对数码管动态显示秒表的分、秒、1/100秒；
;      计时程序由中断服务程序实现，采用定时计数器T0工作方式1；
;      P2口实现对数码管的片选功能
;================================================================
;==========================初始化================================
    SHUCHU        EQU    P0               ;定义P0口为输出口
    PIANXUAN      EQU    P2        ;定义P2口为片选口
    MIAO          EQU    30H
FEN           EQU    31H
MIAO0         EQU    32H
SHUZI    EQU    33H
C_0           BIT    20H.0
;======================系统程序开始==============================                  
      ORG   00H            
            LJMP  START
       ORG   03H
       LJMP  ON_OFF
         ORG   0BH
        LJMP  T0_1
        ORG   13H
        LJMP  RESET
        ORG   30H          
   START:
           CALL   INIT
      SETB   C_0
      MOV    MIAO,#00
      MOV    MIAO0,#00
      MOV    FEN,#00
      MOV    DPTR,#TAB
      MOV     R2,#5  
MAIN:
         JNB    C_0,$
      CLR    C_0
   LL:   CALL   DISPLAY
         CALL   SHIJIAN
      JMP    MAIN      
;========================时间子程序=============================
;输入:"30H、31H、32H"
;输出:无
;实现的功能：分、秒、百分之秒的计算。
;===============================================================
      SHIJIAN:
     DJNZ    R2,TIAOCHU
     MOV     R2,#5
      INC     MIAO0
     MOV     R3,MIAO0
     CJNE    R3,#100,TIAOCHU
     MOV     MIAO0,#00
     INC     MIAO
     MOV     R3,MIAO
     CJNE    R3,#60,TIAOCHU
     MOV     MIAO,#00
     INC     FEN
     MOV     R3,FEN
     CJNE    R3,#60,TIAOCHU
     MOV     FEN,#00
   TIAOCHU:RET
;========================显示子程序=============================
;输入:"A"
;输出:"P2口"
;实现的功能：显示秒、分、百分之妙
;===============================================================
       DISPLAY:MOV   SHUZI,MIAO0
           CALL  JISUAN
     MOVC  A,@A+DPTR
     MOV   SHUCHU,A         ;显示十位
     MOV   PIANXUAN,#10H    ;片选
               CALL  DELAY
     MOV   PIANXUAN,#00H
    
     MOV   A,B              
     MOVC   A,@A+DPTR
       MOV   SHUCHU,A         ;显示个位
     MOV   PIANXUAN,#20H    ;片选
     CALL  DELAY            ;延时
     MOV   PIANXUAN,#00H
          
     MOV   SHUZI,MIAO
           CALL  JISUAN          
           MOVC  A,@A+DPTR
     MOV   SHUCHU,A         ;显示十位
     MOV   PIANXUAN,#04H    ;片选
               CALL  DELAY
     MOV   PIANXUAN,#00H
    
     MOV   A,B              
     MOVC   A,@A+DPTR
       MOV   SHUCHU,A         ;显示个位
     MOV   PIANXUAN,#08H    ;片选
     CALL  DELAY            ;延时
     MOV   PIANXUAN,#00H
    
     MOV   SHUZI,FEN
     CALL  JISUAN
     MOVC  A,@A+DPTR
     MOV   SHUCHU,A         ;显示十位
     MOV   PIANXUAN,#01H    ;片选
               CALL  DELAY
     MOV   PIANXUAN,#00H
    
     MOV   A,B              
     MOVC   A,@A+DPTR
       MOV   SHUCHU,A         ;显示个位
     MOV   PIANXUAN,#02H    ;片选
     CALL  DELAY            ;延时
     MOV   PIANXUAN,#00H
               RET
;========================计算子程序=============================
;输入:30H
;输出:"A和B"
;实现的功能：把33H中的数据十位和个位分离出来
;===============================================================
          JISUAN:MOV   A,SHUZI      ;数据放在A中  
     MOV   B,#10        ;除数放在B中
     DIV   AB           ;商放在A中，余数放在B中
     RET
;====================复位中断服务程序============================
;输入；无
;输出: 无
;实现的功能：把30H、31H、32H中的数据清零。
;================================================================
            RESET:PUSH ACC
         MOV   30H,#00H
            MOV   3H,#00H
      MOV   32H,#00H
      CALL  DELAY
      POP   ACC
      RETI
;====================启停中断服务程序============================
;输入；无
;输出: 无
;实现的功能：关闭定时器
;================================================================
          ON_OFF:CPL    TR0
           CALL   DELAY
     RETI
;====================定时中断0服务子程序========================
;输入:无
;输出:无
;实现的功能：实现定时20MS，影响标中断志位C_0
;===============================================================
   T0_1:MOV    TL0,50H          ;设置定时初值
        MOV    TH0,51H
        SETB   C_0            ;定时标志位清0
     RETI
;========================中断设置子程序=========================
;输入:无
;输出:无
;实现的功能：初始化设置定时器，设置初值，开中断0、中断1，定时器0.
;===============================================================
            INIT:MOV    TMOD,#01H      ;定时器0工作方式1
        MOV    DPTR,#65536-20000
     MOV    50H,DPL
     MOV    51H,DPH
         MOV    TL0,50H    ;设置定时初值
        MOV    TH0,51H
     MOV    IE,#87H       ;开定时器中断0
     MOV    TCON,#15H
     RET
;======================延时程序==================================
;输入；无
;输出: 无
;实现的功能：延时一段时间
;================================================================
            DELAY:MOV  R6,#80
               L7:MOV  R5,#60
         L8:DJNZ R5,$
                  DJNZ R6,L7
      RET
;======================共阳查表数据==============================
        TAB:DB 3fH,06H,5bH,4fH,66H,6dH,7dH,07H, 7fH,6fH,77H,7cH,39H,5eH,79H,71H
			;0C0H,0F9H,0A4H,0B0H,99H,92H,82H,0F8H,80H,90H
;===========================结束=================================
         END 