#ifndef __MEM_ABS_H__
#define __MEM_ABS_H__

#include "types.h"

void dumpMEMConfiguration(void);

void loadCounter(char *file);

void loadPC(char *file);
void savePC(char *file);
void loadMEMC(char *file);
void loadMEMD(char *file);
void saveMEMD(char *file);
void saveCounter(char *file);
void loadCounter(char *file);

CodeType getMEMC(AddressType p);
DataType getMEMD(AddressType p);

void setPC(AddressType v);
AddressType getPC(void);
CodeType getOpcode(void);

CounterType getCounter(void);
void addCounter(CounterType n);

DataType getRegister(int n);
void setRegister(int n, DataType v);

void setFlagsRegister(int b);
void resetFlagsRegister(int b);
int getFlagsRegister(int b);
void saveCPUState(void);
void setMEMD(AddressType p, DataType i);  //Dopisana na potrzeby STD
#endif //__MEM_ABS_H__
