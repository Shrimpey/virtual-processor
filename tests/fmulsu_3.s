.text
.global	main
.type	main, @function

main:
	ldi r16, 0x80
	ldi r17, 0x80
	fmulsu r16, r17
