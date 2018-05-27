#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

void F_STD(void) {

    // lokalizacja rejestru
    DataType Rr = getRegister( ((getOpcode() & 0x01F0) >> 4) );
    // wczytanie adresu Y
    AddressType Y = (getRegister(YL_ADRESS) << 8) | getRegister(YH_ADRESS);
    // wartość przesuniecie
    AddressType Q = (((getOpcode() & 0x2000) >> 8) | ((getOpcode() & 0x0C00) >> 7) | (getOpcode() & 0x0007));


    printf("0x%04X[0x%04X]: STD 0x%02X -> Y + 0x%04X\n", getPC(), getOpcode(), Rr, Q);


    AddressType result = Y + Q;

    setMEMD(result, Rr);
    setPC(getPC() + 1);                   //zwiekszenie licznika rozkazow


    addCounter(2);
}
