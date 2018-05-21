cmake_minimum_required(VERSION 3.9)
project(atmega C)

set(CMAKE_C_STANDARD 11)

add_executable(atmega
        f_add1.c
        f_add2.c
        f_jmp_memc.c
        f_jmp_rel.c
        interpreter.c
        interpreter.h
        interrupt.c
        interrupt.h
        main.c
        mem_abs.c
        mem_abs.h
        types.h
        f_ijmp.c
        f_fmulsu.c
        f_fmul.c
        f_fmuls.c
        f_ldi.c
        f_mov1.c
        f_ldd.c
        f_std.c)
