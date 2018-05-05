#ifndef __TYPES_H__
#define __TYPES_H__

//definicje nowych typow danych
typedef unsigned char               DataType;
typedef unsigned short              CodeType;
typedef unsigned short              AddressType;
typedef unsigned long               CounterType;
//najwieksze wartosci
#define MAX_ADDRESS                 0xFFFF
#define MAX_DATA_VAL                0xFF

//Numer ostatniego rejestru
#define REGISTERS_COUNT             (0x001F-0x0000)+1
#define MAX_REGISTER                REGISTERS_COUNT-1
#define IO_REGISTERS_COUNT          (0x005F-0x0020)+1
#define MAX_IO_REGISTERS            IO_REGISTERS_COUNT-1
#define EIO_REGISTERS_COUNT         (0x00FF-0x0060)+1
#define MAX_EIO_REGISTERS           EIO_REGISTERS_COUNT-1

#define SREG_ADDRESS                0x5F
#define RAMPZ_ADRESS                0x3B
#define ZL_ADRESS                   0x1E
#define ZH_ADRESS                   0x1F

//Znaczenie flag
#define FLAG_C                      0x00
#define FLAG_Z                      0x01
#define FLAG_N                      0x02
#define FLAG_V                      0x03
#define FLAG_S                      0x04
#define FLAG_H                      0x05
#define FLAG_T                      0x06
#define FLAG_I                      0x07

#endif //__TYPES_H__
