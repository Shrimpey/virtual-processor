syko.exe:
	gcc -c mem_abs.c -o mem_abs.o
	gcc -c f_add1.c -o f_add1.o
	gcc -c f_add2.c -o f_add2.o
	gcc -c f_jmp_memc.c -o f_jmp_memc.o
	gcc -c f_jmp_rel.c -o f_jmp_rel.o
	gcc -c f_mov1.c -o f_mov1.o
	gcc -c f_fmul.c -o f_fmul.o
	gcc -c f_fmuls.c -o f_fmuls.o
	gcc -c f_fmulsu.c -o f_fmulsu.o
	gcc -c f_ldd.c -o f_ldd.o
	gcc -c f_ijmp.c -o f_ijmp.o
	gcc -c f_std.c -o f_std.o
	gcc -c f_ldi.c -o f_ldi.o
	gcc -c f_out.c -o f_out.o
	gcc -c f_elpm_arg1.c -o f_elpm_arg1.o
	gcc -c f_elpm_arg2.c -o f_elpm_arg2.o
	gcc -c f_elpm_noarg.c -o f_elpm_noarg.o
	gcc -c interrupt.c -o interrupt.o
	gcc -c interpreter.c -o interpreter.o
	gcc -c main.c -o main.o
	gcc mem_abs.o f_add1.o f_add2.o f_jmp_memc.o f_jmp_rel.o f_mov1.o f_fmul.o f_fmuls.o f_fmulsu.o  f_ldi.o   f_out.o   f_elpm_arg1.o   f_elpm_arg2.o  f_elpm_noarg.o f_ldd.o f_std.o f_ijmp.o                                     interrupt.o interpreter.o main.o -o syko.exe

clean:
	rm -f mem_abs.o
	rm -f f_add1.o
	rm -f f_add2.o
	rm -f f_jmp_memc.o
	rm -f f_jmp_rel.o
	rm -f f_mov1.o
	rm -f f_fmul.o
	rm -f f_fmuls.o
	rm -f f_fmulsu.o
	rm -f f_ldi.o
	rm -f f_ldd.o
	rm -f f_ijmp.o
	rm -f f_std.o
	rm -f f_out.o
	rm -f f_elpm_arg1.o
	rm -f f_elpm_arg2.o
	rm -f f_elpm_noarg.o
	rm -f interrupt.o
	rm -f interpreter.o
	rm -f main.o
	rm -f syko.exe
