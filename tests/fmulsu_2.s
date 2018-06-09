.text
.global	main
.type	main, @function

main:
	ldi r16, 0x7F
	ldi r17, 0x7F
	fmulsu r16, r17
