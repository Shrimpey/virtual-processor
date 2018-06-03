#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

//funkcja EICALL, wykonująca skok na adres wskazywany przez konkatenacje rejestrów Z i EIND, z zapisaniem na stosie adresu powrotnego
void F_EICALL(){
    AddressType jump_address= (getIORegister(EIND_ADRESS)<<16) | (getRegister(ZH_ADRESS)<<8) | getRegister(ZL_ADRESS); //konkatenacja rejestrow RAMPZ, ZH i ZL wskazujaca adres w pamieci

    printf("0x%04X[0x%04X]: EICALL\n", getPC(), getOpcode());
    printf("PC PUSHED TO STACK: %d\n", getPC());
    printf("JUMP TO: %x\n", jump_address);
    AddressType tpc = getPC();

    DataType t = tpc & 0x0000FF;
    printf("%x\n", t);
    pushOnStack(t);
    t = (tpc & 0x00FF00)>>8;
    printf("%x\n", t);
    pushOnStack(t);
    t = (tpc & 0xFF0000)>>16;
    printf("%x\n", t);
    pushOnStack(t);

    setPC(jump_address);
    addCounter(4);
}
