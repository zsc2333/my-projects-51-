 ORG     0000H
        AJMP    START
        ORG     000BH           ;T0中断入口地
        CPL      P1.0
        RETI
        ORG     0100H
START:
        MOV     TMOD,#02H       ;置T0为方式2
        MOV     TL0,#1AH         ;延时0.25mS的定时器初始值
        MOV     TH0,#1AH
        SETB     PT0				;设定优先级,只有一个中断的情况下，没什么意义
        SETB     ET0				;中断使能
        SETB     EA              ;开中断
SETB     TR0				;启动定时器
        SJMP     $
END
