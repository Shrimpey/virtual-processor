.text
.global    main
.type    main, @function

main:
ldi r28, 0x1D
ldi r29, 0x3A
ldi r16, 0xFF
std Y+64, r16
ldd r17, Y+64

