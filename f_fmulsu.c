#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

void F_FMULSU(void){

    //Przedzial rejestrow: R16 <= (R1, R2) <= R23
    DataType R1 = ((getOpcode() & 0x0070) >> 4) + 16;   //identyfikacja numeru rejestru arg. 1
    DataType R2 = (getOpcode() & 0x0007) + 16;          //identyfikacja numeru rejestru arg. 2

    printf("0x%04X[0x%04X]: FMULSU R%d, R%d\n", getPC(), getOpcode(), R1, R2);

    DataType R1_pp = ((getRegister(R1) & 0x80) == 0x80) ? (~(getRegister(R1) - 1)) : (getRegister(R1));     //Przejscie z U2

    CodeTypeAryt result = (CodeTypeAryt)(R1_pp) * (CodeTypeAryt)(getRegister(R2));    //Obliczenie wyniku

    result = ((getRegister(R1) & 0x80) == 0x80) ? (~result + 1) : (result);     //Przejscie do U2

    setRegister(0x00, (result << 1) & 0x00FF);              //Ustawienie bitu niskiego
    setRegister(0x01, ( (result << 1) & 0xFF00) >> 8);      //Ustawienie bitu wysokiego

    if((result & 0x8000) == 0x8000){
        setFlagsRegister(FLAG_C);       //Ustawienie flagi przeniesienia
    }else{
        resetFlagsRegister(FLAG_C);     //Zresetowanie flagi przeniesienia
    }

    if((result << 1) == 0x0000){
        setFlagsRegister(FLAG_Z);       //Ustawienie flagi zero
    }else{
        resetFlagsRegister(FLAG_Z);     //Zresetowanie flagi zero
    }

    setPC(getPC()+1);                   //zwiekszenie licznika rozkazow
    addCounter(2);                      //FMULSU zajmuje 2 cykle
}
