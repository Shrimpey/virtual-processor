.text
.global	main
.type	main, @function

main:
	ldi r16, 0x90
	ldi r17, 0x02
	fmul r16, r17
	mov r2, r0
	mov r3, r1
	fmuls r16, r17
	mov r4, r0
	mov r5, r1
	fmulsu r16, r17
	mov r6, r0
	mov r7, r1