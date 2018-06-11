#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

//funkcja EICALL, wykonująca skok na adres wskazywany przez konkatenacje rejestrów Z i EIND, z zapisaniem na stosie adresu powrotnego
void F_EICALL(){
    //konkatenacja rejestrow RAMPZ, ZH i ZL wskazujaca adres w pamieci
    AddressType jump_address= (AddressType)((getIORegister(EIND_ADRESS)<<16)) | (AddressType)((getRegister(ZH_ADRESS)<<8)) | (AddressType)(getRegister(ZL_ADRESS));
    //PC ma 22 bity, więc pierwsze 2 bity są zerowane;
    jump_address &= ~((1<<23) | (1<<22));

    printf("0x%04X[0x%04X]: EICALL\n", getPC(), getOpcode());
    printf("PC PUSHED TO STACK: %x\n", getPC());
    printf("JUMP TO: %x\n", jump_address);

    //sabing 3 bytes of PC to stack
    AddressType tpc = getPC();
    DataType t = (DataType) (tpc & 0x0000FF);
    pushOnStack(t);
    t = (DataType)((tpc & 0x00FF00)>>8);
    pushOnStack(t);
    t = (DataType)((tpc & 0xFF0000)>>16);
    pushOnStack(t);

    setPC(jump_address);
    addCounter(4);
}
