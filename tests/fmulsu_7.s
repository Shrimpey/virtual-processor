.text
.global	main
.type	main, @function

main:
	ldi r16, 0x00
	ldi r17, 0xFF
	fmulsu r16, r17
