.text
.global	main
.type	main, @function

main:
	ldi r28, 0x01
	ldi r29, 0x23
	ldi r16, 0xFF
	std Y+13, r16
	ldd r20, Y+13
