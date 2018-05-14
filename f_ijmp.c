//
// Created by Patryk Woźniak on 10.05.2018.
//

#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

void F_IJMP(void){


    DataType R30 = getRegister(ZL_ADRESS);
    DataType R31 = getRegister(ZH_ADRESS);


    CodeType jmpAddress = (R31 & 0xFF) + R30;

    printf("0x%04X[0x%04X]: IJMP PC=%04X\n", getPC(), getOpcode(), jmpAddress);

    setPC(jmpAddress);

    addCounter(2);

}