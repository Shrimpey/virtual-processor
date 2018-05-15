.text
.global	main
.type	main, @function

main:
	ldi r22, 0xA0
	ldi r23, 0xA0
	fmul r22, r23
	mov r2, r0
	mov r3, r1
	mov r0, r29
	mov r1, r29