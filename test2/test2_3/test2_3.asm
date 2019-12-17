MOV  20H, #67H
MOV  21H, #45H
MOV  22H, #23H
MOV  01H, #01H
MOV  30H, #65H
MOV  31H, #72H
MOV  32H, #98H
MOV  33H, #89H
;;;;;;;;;主程序 ;;;;;;;;;;
MOV  R0,#20H        ;置被加数首地址
      MOV  R1, #30H       ;置加数首地址
      MOV  R2, #04H       ;置被加数和加数的长度(字节数)
	  ACALL   ADD_BCD    ;调用多字节十进制数加法子程序ADD_BCD
STOP:SJMP  STOP          ;停止

;;;;;;;;;; 多字节十进制数加法子程序  ;;;;;;;
;入口:  R0、R1为被加数和加数的首地址，按低位到高位存放
;出口:  R0为运算结果的首地址，也按低位到高位存放
ADD_BCD:CLR C              ;进位清零
LOOP: MOV  A, @ R0       ;一字节的被加数→A
ADDC  A, @ R1       ;一字节加
DA  A              ;十进制数调整
MOV  @ R0, A       ;存一字节的运算结果
INC  R0            ;被加数指向下一字节
INC  R1            ;加数指向下一字节
DJNZ  R2 , LOOP     ;循环控制
RET                ;子程序返回
END
