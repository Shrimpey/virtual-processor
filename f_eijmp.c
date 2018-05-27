#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

//funkcja EIJMP, wykonująca skok na adres wskazywany przez konkatenacje rejestrów Z i EIND
void F_EIJMP(){
    //konkatenacja rejestrow RAMPZ, ZH i ZL wskazujaca adres w pamieci
    AddressType jump_address= (getIORegister(EIND_ADRESS)<<16) | (getRegister(ZH_ADRESS)<<8) | getRegister(ZL_ADRESS);
    //PC ma 22 bity, więc pierwsze 2 bity są zerowane;
    jump_address &= ~((1<<23) | (1<<22));

    printf("0x%04X[0x%04X]: EIJMP\n", getPC(), getOpcode());
    printf("JUMP TO: %lx\n", jump_address);

    setPC(jump_address);
    addCounter(2);
}
