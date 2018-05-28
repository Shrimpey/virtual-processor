.text
.global    main
.type    main, @function

slave:
mov r17, r30

main:
ldi r30, 0x01
rjmp ok
ldi r16, 0x01

ok:
mov r18, r30
rjmp slave
