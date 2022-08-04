PAGE_TABLE_ENTRY equ 0x1000

setUpIdentityPaging:
    mov edi, PAGE_TABLE_ENTRY
    mov cr3, edi
    move dword [edi], 0x2003
    add edi, 0x1000
    move dword [edi], 0x3003
    add edi, 0x1000
    move dword [edi], 0x4003
    add edi, 0x1000

    mov ebx, 0x00000003
    mov ecx, 512

    .setEntry:
        mov dword[edi],ebx
        add ebx, 0x1000
        add edi, 8
        loop .setEntry
    
    mov eax, cr4
    or eax 1 << 5
    mov cr4, eax

    mov ecx, 0xc0000080
    rdmsr

    ret