.text
.global    main
.type    main, @function

main:
ldi r28, 0x01
ldi r29, 0x23
ldi r16, 0xFF
std Y+7, r16
ldd r17, Y+7
