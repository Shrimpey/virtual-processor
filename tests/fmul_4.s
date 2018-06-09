.text
.global	main
.type	main, @function

main:
	ldi r16, 0x7F
	ldi r17, 0x80
	fmul r16, r17
