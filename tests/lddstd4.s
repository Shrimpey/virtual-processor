.text
.global    main
.type    main, @function

main:
ldi r28, 0x00
ldi r29, 0x00
ldi r16, 0xFF
std Y+0, r16
ldd r17, Y+0
