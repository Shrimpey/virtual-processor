.text
.global	main
.type	main, @function

main:
	ldi r16, 0xFF
	ldi r17, 0xFF
	fmul r16, r17
