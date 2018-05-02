#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "mem_abs.h"
#include "interpreter.h"
#include "interrupt.h"

//naglowki poszczegolnych opcodow
//void F_ADD1(void);
//void F_ADD2(void);
//void F_JMP_MEMC(void);
//void F_JMP_REL(void);
void F_MOV1(void);
void F_FMUL(void);
//...

//wzorce opcodow
//#define ID_ADD_R1_R2            0x0C
//#define ID_ADD_R1_MEM_R2        0x02
//#define ID_JMP_MEMC             0x03
//#define ID_JMP_REL              0x04
#define ID_MOV_R1_R2            0x2C
#define ID_FMUL                 0x0C
//...


void doInstr(CodeType T){
    if( ((T & 0xFC00)>>8) == ID_MOV_R1_R2){
        F_MOV1();   //wywolac instrukcje MOV1
    }else if( ((T & 0xF380)>>6) | ((T & 0x0008)>>3) == ID_FMUL){
        F_FMUL();   //wywolac instrukcje FMUL
    }else{
        printf("Wykryto nieznana instrukcje (PC=0x%08x, T=0x%04x)\r\n", getPC(), T);
        saveCPUState();
        exit(-1);
    }
}
