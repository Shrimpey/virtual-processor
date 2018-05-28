.text
.global    main
.type    main, @function

master:
    mov r16, r30

slave:
    mov r17, r30

main:
    ldi r30, 0x01
    rjmp master
    ldi r20, 0x01

