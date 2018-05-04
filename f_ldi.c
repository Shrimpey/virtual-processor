#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

//Wczytuje 8-bitową stałą do rejestru rd 16 - 31
void F_LDI(){
    DataType R1=getOpcode() & 0x00F0;                                  //identyfikacja numeru rejestru
    DataType R2=(getOpcode() & 0x0F00)>>4 | (getOpcode() & 0x000F);       //identyfikacja argumentu - stałej 8-bitowej

    printf("0x%04X[0x%04X]: LDI R%d, %x /n", getPC(), getOpcode(), R1, R2);

    setRegister(R1, (getRegister(R1) + getRegister(R2)) % MAX_DATA_VAL);    //w�a�ciwe obliczenie

    setPC(getPC()+1);                                       //zwi�kszenie licznika rozkaz�w

    addCounter(1);
}
