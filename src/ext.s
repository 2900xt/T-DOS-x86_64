

jmp EnterProtectedMode


%include "src/gdt.s"

EnterProtectedMode:
    call EnableA20
    cli
    lgdt [gdt_descriptor]
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
%include "src/paging.s"


startProtectedMode:

    mov ax, dataseg
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax


    call Detect_CPUID

    call DetectLongMode

    call SetUpIdentityPaging
    call EditGDT

    jmp codeseg:start64Bit


[bits 64]
[extern _start]

start64Bit:
    mov edi,0xb8000
    mov rax,0x1f201f201f201f20
    mov ecx, 500
    rep stosq

    call _start
    jmp $

%define COM1 0x3F8

global com1_putc
com1_putc:
    mov rax, rdi
    mov dx, COM1
    out dx, al
    ret
%include "src/idt.asm"