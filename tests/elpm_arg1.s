.text
.global	main
.type	main, @function

main:
	ldi 0x1E, 0x00
	out 0x3B, 0x1E
	ldi 0x1F, 0x00
	ldi 0x1E, 0x03
	elpm r16, Z
