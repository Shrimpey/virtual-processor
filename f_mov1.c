#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

void F_MOV1(void){
    DataType R1 = (getOpcode() & 0x01F0)>>4;                   //identyfikacja numeru rejestru arg. 1
    DataType R2 = ( ((getOpcode() & 0x0200)>>5) | (getOpcode() & 0x000F) );                  //identyfikacja numeru rejestru arg. 2

    printf("0x%04X[0x%04X]: MOV R%d, R%d\n", getPC(), getOpcode(), R1, R2);

    setRegister(R1, getRegister(R2));    //Ustawienie wartosci z rejestru R2 do rejestru R1

    setPC(getPC()+1);                                       //zwi�kszenie licznika rozkaz�w
    addCounter(1);
}
