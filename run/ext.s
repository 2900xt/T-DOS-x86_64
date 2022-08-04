[org 0x7e00]

jmp EnterProtectedMode


%include "run/gdt.s"
%include "headers/ostream32.s"
EnterProtectedMode:
    call EnableA20
    cli
    lgdt [gdt_desc]
    mov eax, cr0
    or eax, 1 
    mov cr0, eax
    jmp codeseg:startProtectedMode

EnableA20:
    in al, 0x92
    or al, 2
    out 0x92, al
    ret

[bits 32]

startProtectedMode:

    mov ax, dataseg
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov [0xb8000],byte 'H'
    mov [0xb8002],byte 'e'
    mov [0xb8004],byte 'l'
    mov [0xb8006],byte 'l'
    mov [0xb8008],byte 'o'

    jmp $

teststr:
    db 'Hello World',0
times 2048-($-$$) db 0