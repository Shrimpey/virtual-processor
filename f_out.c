#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

//Wczytuje bajt z rejestru ogolnego przeznaczenia do rejstru polozonego w obszarze I/O
void F_OUT(){
    DataType A=(getOpcode() & 0xF) | ((getOpcode() & 0x600)>>5);                  //identyfikacja argumentu - adresu w przestrzeni I/O
    DataType R=(getOpcode() & 0x01F0)>>4 ;                                        //identyfikacja argumentu - adresu rejestru

    printf("0x%04X[0x%04X]: OUT %x, R%d \n", getPC(), getOpcode(), A, R);

    setIORegister(A, getRegister(R));                         //wczytanie do rejestru o adresie A z rejestru o adresie R

    setPC(getPC()+1);                                       //zwiększenie licznika rozkaz�w
    addCounter(1);
}
