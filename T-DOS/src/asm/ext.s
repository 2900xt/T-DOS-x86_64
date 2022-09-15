jmp EnterProtectedMode


%include "T-DOS/src/asm/gdt.s"
%include "T-DOS/include/ostream16"
%include "T-DOS/src/asm/mem.asm"

EnterProtectedMode:
    call MEM_DETECT
    
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

%include "T-DOS/include/CPUID.s"
%include "T-DOS/src/asm/paging.s"


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
[extern data]

start64Bit:


    mov edi,0xb8000
    mov rax,0x1f201f201f201f20
    mov ecx, 500
    rep stosq

    call activateSSE
    call _start

.end:
    hlt
    jmp .end;

%define COM1 0x3F8

global com1_putc
com1_putc:
    mov rax, rdi
    mov dx, COM1
    out dx, al
    ret

activateSSE:
    mov rax , cr0
    and ax, 0b11111101
    or ax, 0b00000001
    mov cr0, rax

    mov rax, cr4
    or ax, 0b1100000000
    mov cr4, rax
    ret

%include "T-DOS/src/asm/idt.asm"