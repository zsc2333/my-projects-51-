DELAY :  MOV  R5 ,#0AH
         MOV  R6 , #00H
DELAY1 : MOV   R7 ,#0B3H
         DJNZ  R7 ,$
         DJNZ  R6 ,DELAY1
         DJNZ  R5 ,DELAY1

        ORG  0000H
        LJMP  START 
        ORG  0040H
START : MOV  A  ,#0FEH    ;
LOOP  : MOV  P1 ,A        ;����1ֻLED
        RL  A            ;��ѭ��
        LCALL  DELAY     ;��ʱ1��
        SJMP  LOOP
