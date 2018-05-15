.text
.global	main
.type	main, @function

main:
	ldi r16, 0x90
	ldi r17, 0x02
	fmul r16, r17
	mov r2, r0
	mov r3, r1
	mov r0, r29
	mov r1, r29