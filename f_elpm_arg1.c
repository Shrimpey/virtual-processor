#include <stdio.h>
#include "types.h"
#include "mem_abs.h"

//funkcja ELPM Rd, Z ładująca stałą z pamięci programu spod adresu RAMPZ:Z do rejestru
void F_ELPM_ARG1(){
  DataType R1=(getOpcode() & 0x1F0)>>4;                      //identyfikacja numeru rejestru
  //konkatenacja rejestrow RAMPZ, ZH i ZL wskazujaca adres w pamieci
  AddressType R2 = (AddressType)((getIORegister(RAMPZ_ADRESS)<<16)) | (AddressType)((getRegister(ZH_ADRESS)<<8)) | (AddressType)(getRegister(ZL_ADRESS));

  printf("0x%04X[0x%04X]: ELPM R%d, Z \n", getPC(), getOpcode(), R1);
  printf("RAMPZ:Z = %lx\n", R2);
  printf("DATA: %x\n", getMEMCData(R2));

  //wpisanie stałej do rejestru
  setRegister(R1, getMEMCData(R2));

  //zwiększenie PC i licznika cykli
  setPC(getPC()+1);
  addCounter(3);
}
