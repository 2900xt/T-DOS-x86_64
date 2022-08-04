[org 0x7e00]

jmp EnterProtectedMode


%include "run/gdt.s"

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

%include "headers/CPUID.s"
%include "run/paging.s"

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

    call Detect_CPUID

    call DetectLongMode

    call setUpIdentityPaging
    call editGDT

    jmp codeseg:start64Bit


[bits 64]
start64Bit:
    mov edi,0xb8000
    mov rax,0x1f201f201f201f20
    mov ecx, 500
    rep stosq
    jmp $;

times 2048-($-$$) db 0