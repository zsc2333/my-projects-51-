 ORG     0000H
        AJMP    START
        ORG     000BH           ;T0�ж���ڵ�
        CPL      P1.0
        RETI
        ORG     0100H
START:
        MOV     TMOD,#02H       ;��T0Ϊ��ʽ2
        MOV     TL0,#1AH         ;��ʱ0.25mS�Ķ�ʱ����ʼֵ
        MOV     TH0,#1AH
        SETB     PT0				;�趨���ȼ�,ֻ��һ���жϵ�����£�ûʲô����
        SETB     ET0				;�ж�ʹ��
        SETB     EA              ;���ж�
SETB     TR0				;������ʱ��
        SJMP     $
END
