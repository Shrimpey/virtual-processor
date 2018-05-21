#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "mem_abs.h"
#include "interpreter.h"
#include "interrupt.h"

#define FILE_COUNTER            "file_counter.bin"
#define FILE_PC                 "file_pc.bin"
#define FILE_DATA               "file_data.bin"
#define FILE_CODE               "file_code.bin"



int main(int argc, char *argv[]) {
    long counter=0, max_counter=0;      //liczba wykonanych instrukcji i zadana liczba instrukcji do wykonania
    long int_gen=-1;
    CodeType T;                         //zmienna pomocnicza - ma przechowywa� opcode instrukcji

    loadMEMC(FILE_CODE);                //�adowanie pami�ci kodu z pliku
    loadMEMD(FILE_DATA);                //�adowanie pami�ci danych z pliku (w tym rejestr�wm)
    //sprawdzenie czy w drugim lub trzecim argumencie występuje zerowanie PC
    if(argc > 3){
        if(strcmp(argv[3], "zeroPC")==0){
            printf("PC SET TO 0 \n");
            if(getPC != 0){
                setPC(0);
            }
        }else{
            loadPC(FILE_PC);
        }
    }else if(argc > 2){
        if(strcmp(argv[2], "zeroPC")==0){
            printf("PC SET TO 0 \n");
            if(getPC != 0){
                setPC(0);
            }
        }else{
            loadPC(FILE_PC);
        }
    }else if(argc > 1){
        if(strcmp(argv[1], "zeroPC")==0){
            printf("PC SET TO 0 \n");
            if(getPC != 0){
                setPC(0);
            }
        }else{
            loadPC(FILE_PC);
        }
    }else{
        loadPC(FILE_PC);    //Ladowanie wartosci PC
    }

    loadCounter(FILE_COUNTER);          //�adowanie licznika cykli

    dumpMEMConfiguration();

    if(argc>1){	                        //pierwszy parametr wywolania okresla liczbe instrukcji do wykonania
        if(strcmp(argv[1], "zeroPC") != 0){
            max_counter=strtoul(argv[1], NULL, 10);
            max_counter+=getCounter();
        }
    }
    if(max_counter==0){
        max_counter=getCounter()+1;     //nie podanie argumentu wywolania lub b�edne jego podanie - ustala wykonanie jednego cyklu
    }
    if(argc>2){                         //drugi parametr wywolania okresla liczbe instrukcji po ktorych ma byc wygenerowane przerwanie
        if(strcmp(argv[2], "zeroPC") != 0){
            int_gen=strtoul(argv[2], NULL, 10);
        }
    }
    if(int_gen==0){
        int_gen=-1;                     //nie podanie argumentu wywolania lub b�edne jego podanie - ustala wykonanie jednej instrukcji
    }
    if(int_gen>0)
        set_intterrupt(int_gen);        //zapamietaj kiedy wywolac przerwanie

    for(;;){
        T=getOpcode();                  //T=opcode operacji (w��cznie z arg. wbudowanym)
        doInstr(T);                     //wykonaj instrukcje
        checkInterrupt(getCounter());   //sprawd� czy trzeba wygenerowac przerwanie

        if(getCounter()>=max_counter){  //czy wykonano zadan� liczb� cykli
            saveCPUState();
            return 0;
        }
    }

    printf("Bledne wykonanie emulacji (PC=0x%08x, T=0x%08x)\r\n", getPC(), T);
    saveCPUState();                     //!!! - Tu niepowinnismy si� nigdy znale��
    return -2;
}
