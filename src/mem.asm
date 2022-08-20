MemoryRegionCount:
    db 0
    GLOBAL MemoryRegionCount

MEM_DETECT:
    mov ax , 0
    mov es , ax
    mov di, 0x5000 ; MEMORY MAP stored at 5K
    mov edx, 0x534d4150
    xor ebx, ebx

    .repeat:
        mov eax, 0xE820
        mov ecx, 24
        int 0x15

        cmp ebx, 0
        je .done

        add di, 24
        inc byte [MemoryRegionCount]
        jmp .repeat
    
    .done:
    ret