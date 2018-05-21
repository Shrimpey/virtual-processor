//
// Created by Patryk Woźniak on 16.05.2018.
//

#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

void F_STD(void) {


    // lokalizacja rejestru
    DataType Rr = ((getOpcode() & 0x0100) | (getOpcode() & 0x00F0));
    // wczytanie r28
    DataType Y = getRegister(0x1C);
    // wartość przesuniecie
    DataType Q = ((getOpcode() & 0x2000) | (getOpcode() & 0x0F00) | (getOpcode() & 0x0007));


    printf("0x%04X[0x%04X]: STD R%04X -> Y + %04X\n", getPC(), getOpcode(), Rr, Q);


    AddressType result = Y + Q;

    setMEMD(result,Rr);

    setPC(getPC() + 1);                   //zwiekszenie licznika rozkazow


    addCounter(2);
}