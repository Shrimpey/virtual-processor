syko.exe: 
	gcc -c mem_abs.c -o mem_abs.o
	gcc -c f_add1.c -o f_add1.o
	gcc -c f_add2.c -o f_add2.o
	gcc -c f_jmp_memc.c -o f_jmp_memc.o
	gcc -c f_jmp_rel.c -o f_jmp_rel.o
	gcc -c interrupt.c -o interrupt.o
	gcc -c interpreter.c -o interpreter.o
	gcc -c main.c -o main.o
	gcc mem_abs.o f_add1.o f_add2.o f_jmp_memc.o f_jmp_rel.o interrupt.o interpreter.o main.o -o syko.exe

clean:
	rm -f mem_abs.o
	rm -f f_add1.o
	rm -f f_add2.o
	rm -f f_jmp_memc.o
	rm -f f_jmp_rel.o
	rm -f interrupt.o
	rm -f interpreter.o
	rm -f main.o
	rm -f syko.exe
