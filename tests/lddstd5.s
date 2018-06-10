.text
.global    main
.type    main, @function

main:
ldi r28, 0xFF
ldi r16, 0xFF
std Y+0, r16
ldd r17, Y+0
