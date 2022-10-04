[org 0x7c00]

jmp short start
nop

start:


    mov bp, 0x7c00
    mov sp, bp

    call disc_read

    mov bx, str
    call PrintStr

    jmp PROGRAM_SPACE; EXT

    %include "T-DOS/include/ostream16"
    %include "T-DOS/src/asm/disc.asm"

    str:
        db "ERROR LOADING OS (-1)",0
    times 510-($-$$) db 0;

    dw 0xaa55;