.text
.global	main
.type	main, @function

main:
	ldi 0x1F, 0xff	
	ldi 0x1E, 0x0
	out 0x3B, 0x1E
	ldi 0x1E, 0x0
	ldi 0x1F, 0x0
	elpm r16, Z
