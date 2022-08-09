
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



    call Detect_CPUID

    call DetectLongMode

    call setUpIdentityPaging
    call editGDT

    jmp codeseg:start64Bit


[bits 64]
[extern _start]
start64Bit:


    call _start
    hlt;
