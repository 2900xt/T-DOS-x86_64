[org 0x7c00]

mov [BOOT_DISK], dl

mov bp, 0x7c00
mov sp, bp

call disc_read

jmp PROGRAM_SPACE; EXT

%include "headers/ostream16"
%include "boot/disc.asm"
times 510-($-$$) db 0;

dw 0xaa55;