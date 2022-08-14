[org 0x7c00]

mov [BOOT_DISK], dl

mov bp, 0x7c00
mov sp, bp

call disc_read

mov bx, str
call PrintStr

jmp PROGRAM_SPACE; EXT

%include "headers/ostream16"
%include "src/disc.asm"
str:
    db "Loading OS",0
times 510-($-$$) db 0;

dw 0xaa55;