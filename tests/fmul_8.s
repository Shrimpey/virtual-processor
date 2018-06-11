.text
.global	main
.type	main, @function

main:
	ldi r16, 0xFF
	ldi r17, 0x00
	fmul r16, r17
