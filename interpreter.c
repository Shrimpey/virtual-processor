#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "mem_abs.h"
#include "interpreter.h"
#include "interrupt.h"

//naglowki poszczegolnych opcodow
void F_MOV1(void);
void F_FMUL(void);
void F_FMULS(void);
void F_FMULSU(void);
void F_LDI(void);
void F_JMP_REL(void);
void F_OUT(void);
void F_ELPM_ARG1(void);
void F_ELPM_ARG2(void);
void F_ELPM_NOARG(void);
void F_IJMP(void);
void F_LDD(void);
void F_STD(void);
void F_EIJMP(void);
void F_EICALL(void);
void F_NOP(void);

//wzorce opcodow
#define ID_MOV_R1_R2            0x2C
#define ID_FMUL                 0x0D
#define ID_FMULS                0x0E
#define ID_FMULSU               0x0F
#define ID_LDI                  0xE
#define ID_OUT                  0x17
#define ID_JMP_REL              0xC
#define ID_ELPM_ARG1            0x9006
#define ID_ELPM_ARG2            0x9007
#define ID_ELPM_NOARG           0x95D8
#define ID_LDD                  0x11
#define ID_STD                  0x13
#define ID_EIJMP                0x9419
#define ID_EICALL               0x9519

void doInstr(CodeType T){
    if( ((T & 0xFC00)>>8) == ID_MOV_R1_R2){
        F_MOV1();   //wywolac instrukcje MOV1
    }else if( ((T & 0xF000)>>12) == ID_JMP_REL){
        F_JMP_REL();   //wywolac instrukcje RJMP
    }else if( (((T & 0xFF80)>>6) | ((T & 0x0008)>>3)) == ID_FMUL){
        F_FMUL();   //wywolac instrukcje FMUL
    }else if( (((T & 0xFF80)>>6) | ((T & 0x0008)>>3)) == ID_FMULS){
        F_FMULS();   //wywolac instrukcje FMULS
    }else if( (((T & 0xFF80)>>6) | ((T & 0x0008)>>3)) == ID_FMULSU){
        F_FMULSU();   //wywolac instrukcje FMULSU
    }else if(((T & 0xF000) >> 12) == ID_LDI){
        F_LDI();
    }else if(((T & (0xF800))>>11) == ID_OUT){
        F_OUT();
    }else if((T & (0xFE0F)) == ID_ELPM_ARG1){
        F_ELPM_ARG1();
    }else if((T & (0xFE0F)) == ID_ELPM_ARG2){
        F_ELPM_ARG2();
    }else if(T  == ID_ELPM_NOARG){
        F_ELPM_NOARG();
    }else if( T == 0x9409 ){
        F_IJMP();
    }else if ((((T & 0xC000) >> 11) | ((T & 0x1000) >> 10) | ((T & 0x0200) >> 8) | ((T & 0x0008) >> 3)) == ID_LDD){
        F_LDD();
    }else if ((((T & 0xC000) >> 11) | ((T & 0x1000) >> 10) | ((T & 0x0200) >> 8) | ((T & 0x0008) >> 3)) == ID_STD){
        F_STD();
    }else if( T == ID_EIJMP ){
        F_EIJMP();
    }else if ( T == ID_EICALL){
        F_EICALL();
    }else{
        printf("Wykryto nieznana instrukcje (PC=0x%08x, T=0x%04x)\r\n", getPC(), T);
        saveCPUState();
        exit(-1);
    }
}
