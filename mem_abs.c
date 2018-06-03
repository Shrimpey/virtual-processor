#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "types.h"
#include <unistd.h>
#include <sys/types.h>
//Linux compliance
#ifndef O_BINARY
    #define O_BINARY 0
#endif

#define GEN_REGISTERS_IN_MEMD_OFFSET    0x0000
#define IO_REGISTERS_IN_MEMD_OFFSET     GEN_REGISTERS_IN_MEMD_OFFSET+REGISTERS_COUNT
#define EIO_REGISTERS_IN_MEMD_OFFSET    IO_REGISTERS_IN_MEMD_OFFSET+IO_REGISTERS_COUNT
#define INTERNAL_SRAM_OFFSET            EIO_REGISTERS_IN_MEMD_OFFSET+EIO_REGISTERS_COUNT
#define FILE_COUNTER            "file_counter.bin"
#define FILE_PC                 "file_pc.bin"
#define FILE_DATA               "file_data.bin"
#define FILE_CODE               "file_code.bin"

CodeType    MEMC[MAX_ADDRESS_MEMC+1];    //obszar pami�ci kodu
DataType    MEMD[MAX_ADDRESS+1];    //obszar pami�ci danych
DataType    *GEN_REG=(DataType*)(&(MEMD[GEN_REGISTERS_IN_MEMD_OFFSET]));    //deklaracja miejsca przechowywania rejestr�w ogolnego przeznaczenia
DataType    *IO_REG=(DataType*)(&(MEMD[IO_REGISTERS_IN_MEMD_OFFSET]));      //deklaracja miejsca przechowywania rejestr�w IO
DataType    *EIO_REG=(DataType*)(&(MEMD[EIO_REGISTERS_IN_MEMD_OFFSET]));    //deklaracja miejsca przechowywania rejestr�w EIO
DataType    *INTERNAL_SRAM=(DataType*)(&(MEMD[INTERNAL_SRAM_OFFSET]));

AddressType   PC;                   //licznik rozkaz�w
DataType    FLAGS;                  //flagi procesora
CounterType counter;                //licznik wykonanych cykli

void dumpMEMConfiguration(void){
    printf("REGISTERS_COUNT:     0x%08x\n", REGISTERS_COUNT);
    printf("MAX_REGISTER:        0x%08x\n", MAX_REGISTER);
    printf("IO_REGISTERS_COUNT:  0x%08x\n", IO_REGISTERS_COUNT);
    printf("MAX_IO_REGISTERS:    0x%08x\n", MAX_IO_REGISTERS);
    printf("EIO_REGISTERS_COUNT: 0x%08x\n", EIO_REGISTERS_COUNT);
    printf("MAX_EIO_REGISTERS:   0x%08x\n", MAX_EIO_REGISTERS);
    printf("GEN_REGISTERS_IN_MEMD_OFFSET: 0x%08x\n", GEN_REGISTERS_IN_MEMD_OFFSET);
    printf("IO_REGISTERS_IN_MEMD_OFFSET:  0x%08x\n", IO_REGISTERS_IN_MEMD_OFFSET);
    printf("EIO_REGISTERS_IN_MEMD_OFFSET: 0x%08x\n", EIO_REGISTERS_IN_MEMD_OFFSET);
}
void loadPC(char *file){          //�adowanie nowej warto�ci PC
    int file_ptr;
    AddressType tPC;
    file_ptr=open(file, O_RDWR | O_BINARY, 0);
    if(file_ptr<0){
        printf("PC file not found (%s)!\n", file);
        exit(-2);
    }
    lseek(file_ptr, 0, SEEK_SET);
    printf("Read PC file (%s) in %ld bytes ", file, read(file_ptr, &tPC, sizeof(AddressType)));
    tPC=(tPC&0xFF000000)>>24 | (tPC&0x00FF0000)>>8 | (tPC&0x0000FF00)<<8 | (tPC&0x000000FF)<<24;   //Endianess correction
    printf("[PC=0x%04X]\n", PC);
    close(file_ptr);
}
void loadCounter(char *file){          //�adowanie ostatnio zapisanego licznika cykli
    int file_ptr;
    file_ptr=open(file, O_RDWR | O_BINARY, 0);
    if(file_ptr<0){
        printf("Counter file not found (%s)!\n", file);
        exit(-2);
    }
    lseek(file_ptr, 0, SEEK_SET);
    printf("Read counter file (%s) in %ld bytes ", file, read(file_ptr, &counter, sizeof(CounterType)));
    printf("[counter=0x%08lX]\n", counter);
    close(file_ptr);
}
void loadMEMC(char *file){          //�adowanie pami�ci kodu z pliku
    int file_ptr;
    file_ptr=open(file, O_RDWR | O_BINARY, 0);
    if(file_ptr<0){
        printf("MEMC file not found (%s)!\n", file);
        exit(-3);
    }
    lseek(file_ptr, 0, SEEK_SET);
    printf("Read MEMC (%s) file in %ld bytes\n", file, read(file_ptr, (void*)MEMC, MAX_ADDRESS_MEMC+1));
    close(file_ptr);
}
void loadMEMD(char *file){        //�adowanie pami�ci danych z pliku
    int file_ptr;
    file_ptr=open(file, O_RDWR | O_BINARY, 0);
    if(file_ptr<0){
        printf("MEMD file not found (%s)!\n", file);
        exit(-4);
    }
    lseek(file_ptr, 0, SEEK_SET);
    printf("Read MEMD (%s) file in %ld bytes\n", file, read(file_ptr, (void*)MEMD, MAX_ADDRESS+1));
    close(file_ptr);
}
void savePC(char *file){        //Zapisz warto�c PC
    int file_ptr;
    AddressType tPC=PC;
    file_ptr=open(file, O_RDWR | O_BINARY, 0);
    if(file_ptr<0){
        printf("PC cannot open to write (%s)!\n", file);
        exit(-5);
    }
    lseek(file_ptr, 0, SEEK_SET);
    //TODO poprawic to
    tPC=(tPC&0xFF000000)>>24 | (tPC&0x00FF0000)>>8 | (tPC&0x0000FF00)<<8 | (tPC&0x000000FF)<<24;		//Endianess correction
    printf("Write PC (%s) file in %ld bytes [PC=0x%04X]\n", file, write(file_ptr, &tPC, sizeof(AddressType)), PC);
    close(file_ptr);
}
void saveCounter(char *file){        //Zapisz warto�c licznika cykli
    int file_ptr;
    file_ptr=open(file, O_RDWR | O_BINARY, 0);
    if(file_ptr<0){
        printf("Cannot open to write (%s)!\n", file);
        exit(-5);
    }
    lseek(file_ptr, 0, SEEK_SET);
    printf("Write counter (%s) file in %ld bytes [counter=0x%08lX]\n", file, write(file_ptr, &counter, sizeof(CounterType)), counter);
    close(file_ptr);
}
void saveMEMD(char *file){        //zapisz zawarto�� pami�ci danych do pliku
    int file_ptr;
    file_ptr=open(file, O_RDWR | O_BINARY, 0);
    if(file_ptr<0){
        printf("MEMD cannot open to write (%s)!\n", file);
        exit(-6);
    }
    lseek(file_ptr, 0, SEEK_SET);
    printf("Saved MEMD file (%s) in %ld bytes\n", file, write(file_ptr, (void*)MEMD, MAX_ADDRESS));
    close(file_ptr);
}
CodeType getMEMC(AddressType p){
    //CodeType t=(MEMC[p] & 0xFF00)>>8 | (MEMC[p] & 0x00FF)<<8;		//Endianess correction
    CodeType t=MEMC[p];
    return t;
}

DataType getMEMD(AddressType p){
    return MEMD[p];
}
void setPC(AddressType v){
    PC=v;
}
AddressType getPC(void){
    return PC;
}
CodeType getOpcode(void){
    return getMEMC(PC);
}
CounterType getCounter(void){
    return counter;
}
void addCounter(CounterType n){
    counter+=n;
}
DataType getRegister(int n){
    return GEN_REG[n];
}
void setRegister(int n, DataType v){
    GEN_REG[n]=v;
}
DataType getIORegister(int n){
    return IO_REG[n];
}
DataType getMEMCData(AddressType n){
    //pamiec MEMC jest podzielna na wyrazy po 16 bitow, najmniej znaczacy bit oznacza wyzszy lub nizszy bajt w wyrazie
    short LSB = n & 0x1;
    n = n>>1;
    CodeType data = getMEMC(n);
    if(LSB){
      return data&0xff;
    }else
      return data>>8;
}
void setIORegister(int n, DataType v){
    IO_REG[n]=v;
}
void setFlagsRegister(int b){
    FLAGS = FLAGS | (1<<b);
    MEMD[SREG_ADDRESS] = FLAGS;
}
void resetFlagsRegister(int b){
    FLAGS = FLAGS & (~(1<<b));
    MEMD[SREG_ADDRESS] = FLAGS;
}
int getFlagsRegister(int b){
    return FLAGS & (1<<b);
}
void saveCPUState(void){
    saveMEMD(FILE_DATA);        //Zapisz zawarto�� pami�ci danych do pliku
    savePC(FILE_PC);            //Zapisz warto�c PC
    saveCounter(FILE_COUNTER);  //Zapisz liczbe wykonanych cykli
}

void setMEMD(AddressType p, DataType i){    //Dopisana na potrzeby STD
    MEMD[p]=i;
}
AddressType getSP(){
    return (getIORegister(SPH_ADRESS)<<8 | getIORegister(SPL_ADRESS));
}
void setSP(AddressType sp){
    setIORegister(SPH_ADRESS, (sp & 0xff00)>>8);
    setIORegister(SPL_ADRESS, (sp & 0x00ff));
}
DataType popFromStack(){
    //preinkrementacja SP, wskazuje on na pierwsze wolne miejsce w pamieci
    setSP(getSP()+1);
    DataType t = getMEMD(getSP());
}
void pushOnStack(DataType data){
    setMEMD(getSP(), data);
    printf("pushing on stack\nSP:%x, data:%x\n", getSP(), data);
    //postdekrementacja SP, wskazuje on na pierwsze wolne miejsce w pamieci
    setSP(getSP()-1);
}
