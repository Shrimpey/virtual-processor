.text
.global	main
.type	main, @function

main:
	ldi r16, 0x20
	ldi r17, 0xE0
	fmul r16, r16
	mov r2, r0
	mov r3, r1
	fmuls r17, r17
	mov r4, r0
	mov r5, r1
	fmulsu r17, r16
	mov r6, r0
	mov r7, r1
	fmulsu r16, r17
	mov r8, r0
	mov r9, r1