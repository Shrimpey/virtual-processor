.text
.global    main, ok
.type    main, @function

main:
    ldi r30, 0x02
    rjmp ok
    ldi r16, 0x03
ok:
    ldi r17, 0x01
