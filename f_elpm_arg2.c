#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

//funkcja ELPM Rd, Z ładująca stałą z pamięci programu spod adresu RAMPZ:Z do rejestru
void F_ELPM_ARG2(){
  DataType R1=(getOpcode() & 0x1F0)>>4;                      //identyfikacja numeru rejestru
  unsigned long R2 = (getIORegister(RAMPZ_ADRESS)<<16) | (getRegister(ZH_ADRESS)<<8) | getRegister(ZL_ADRESS); //konkatenacja rejestrow RAMPZ, ZH i ZL wskazujaca adres w pamieci

  printf("0x%04X[0x%04X]: ELPM R%d, Z+ \n", getPC(), getOpcode(), R1);
  printf("RAMPZ:Z = %lx\n", R2);
  printf("DATA: %x\n", getMEMCData(R2));
  setRegister(R1, getMEMCData(R2));

  //inkrementacja adresu zapisanego w RAPMZ:Z
  R2 = R2+1;
  DataType rampz = (R2&0xff0000)>>16;
  DataType zh = (R2&0x00ff00)>>8;
  DataType zl = R2&0x0000ff;
  setIORegister(RAMPZ_ADRESS, rampz);
  setRegister(ZH_ADRESS, zh);
  setRegister(ZL_ADRESS, zl);

  setPC(getPC()+1);                                       //zwiększenie licznika rozkaz�w
  addCounter(3);
}
