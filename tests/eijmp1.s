.text
.global	main
.type	main, @function

main:
	ldi 0x1E, 0xff
	out 0x3C, 0x1E
	ldi 0x1E, 0x0
	ldi 0x1F, 0x0
	eijmp