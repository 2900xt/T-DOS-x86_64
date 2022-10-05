[bits 16]
jmp EnterProtectedMode


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



gdt_nulldesc:
	dd 0
	dd 0	
gdt_codedesc:
	dw 0xFFFF			; Limit
	dw 0x0000			; Base (low)
	db 0x00				; Base (medium)
	db 10011010b		; Flags
	db 11001111b		; Flags + Upper Limit
	db 0x00				; Base (high)
gdt_datadesc:
	dw 0xFFFF
	dw 0x0000
	db 0x00
	db 10010010b
	db 11001111b
	db 0x00

gdt_end:

gdt_descriptor:
	gdt_size: 
		dw gdt_end - gdt_nulldesc - 1
		dq gdt_nulldesc

codeseg equ gdt_codedesc - gdt_nulldesc
dataseg equ gdt_datadesc - gdt_nulldesc

MemoryRegionCount:
    db 0
    GLOBAL MemoryRegionCount


[bits 32]

EditGDT:
	mov [gdt_codedesc + 6], byte 10101111b

	mov [gdt_datadesc + 6], byte 10101111b
	ret

Detect_CPUID:
    pushfd 
    pop eax
    mov ecx,eax
    xor eax, 1 << 21
    push eax
    popfd

    pushfd
    pop eax

    push ecx
    popfd
    
    xor eax,ecx
    jz nocpuID
    ret

DetectLongMode:
    mov eax, 0x80000001
    cpuid
    test edx, 1 << 29
    jz noLongMode
    ret

noLongMode:
    hlt;

nocpuID:
    hlt;

PageTableEntry equ 0x1000

SetUpIdentityPaging:

	mov edi, PageTableEntry
	mov cr3, edi

	mov dword [edi], 0x2003
	add edi, 0x1000
	mov dword [edi], 0x3003
	add edi, 0x1000
	mov dword [edi], 0x4003
	add edi, 0x1000

	mov ebx, 0x00000003
	mov ecx, 512

	.SetEntry:
		mov dword [edi], ebx
		add ebx, 0x1000
		add edi, 8
		loop .SetEntry

	mov eax, cr4
	or eax, 1 << 5
	mov cr4, eax

	mov ecx, 0xC0000080
	rdmsr
	or eax, 1 << 8
	wrmsr

	mov eax, cr0
	or eax, 1 << 31
	mov cr0, eax

	ret


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
    mov ecx,500
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
[global enablePit]
enablePit:                              ;Disabled interrupts (just in case)
    
    mov ax, 8008

    mov al,00110100b                  ;channel 0, lobyte/hibyte, rate generator
    out 0x43, al
    
    out 0x40,al                       ;Set low byte of PIT reload value
    mov al,ah                         ;ax = high 8 bits of reload value
    out 0x40,al                       ;Set high byte of PIT reload value


;IDT


[extern _idt]
idtDescriptor:
  dw 4095
  dq _idt

  %macro PUSHALL 0
  	push rax
  	push rcx
  	push rdx
  	push r8
  	push r9
  	push r10
  	push r11
  %endmacro

  %macro POPALL 0
  	pop r11
  	pop r10
  	pop r9
  	pop r8
  	pop rdx
  	pop rcx
  	pop rax
  %endmacro

  %macro _ISR 2
  [extern %1]
  GLOBAL %2
  %2:
   PUSHALL
   call %1
   POPALL
   iretq
  %endmacro

_ISR keyboard_handler, isr1

_ISR pit_handler, isr0

GLOBAL LoadIDT
LoadIDT:
  lidt [idtDescriptor]
  sti
  ret

_ISR common_ISR, comisr

_ISR floppy_handler, isr6
GLOBAL panic
