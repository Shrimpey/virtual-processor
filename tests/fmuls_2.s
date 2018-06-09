.text
.global	main
.type	main, @function

main:
	ldi r16, 0x7F
	ldi r17, 0x7F
	fmuls r16, r17
