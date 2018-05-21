//
// Created by Patryk Woźniak on 16.05.2018.
//

#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

void F_LDD(void){


    // lokalizacja rejestru
    DataType Rd = ((getOpcode() & 0x0100) >> 4 | (getOpcode() & 0x00F0) >>4);
    // wczytanie r28
    DataType Y  = getRegister(0x1C);
    // wartość przesuniecie
    DataType Q  = ((getOpcode() & 0x2000)>>8 | (getOpcode() & 0x0C00)>>7 | (getOpcode() & 0x0007));


    printf("0x%04X[0x%04X]: LDD R%04X <- Y + %04X\n", getPC(), getOpcode(), Rd, Q );


    AddressType dataSpace = (Y+Q);   // ustalanie adresu w pamięci

    DataType result = getMEMD(dataSpace);

    setRegister(Rd,result);

    setPC(getPC()+1);                   //zwiekszenie licznika rozkazow


    addCounter(2);

}