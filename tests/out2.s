.text
.global	main
.type	main, @function

main:
	ldi r16, 0x2f
	out 0x3C, r16
