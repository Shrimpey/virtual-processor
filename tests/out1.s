.text
.global	main
.type	main, @function

main:
	ldi r16, 0x01
	out 0x3B, r16
