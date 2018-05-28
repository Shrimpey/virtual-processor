.text
.global    main
.type    main, @function

slave:
mov r18, r30
main:
ldi r30, 0x01
rjmp slave
ldi r16, 0x01
ldi r17, 0x32


