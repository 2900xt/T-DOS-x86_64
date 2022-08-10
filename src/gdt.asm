gdt_null_desc:
    dd $0
    dd $0
gdt_code_seg:
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 10011010b
    db 11001111b
    db 0x00
gdt_data_seg:
    dw 0xFFFF
    dw 0x0000
    db 0x00
    db 10010010b
    db 11001111b
    db 0x00
gdt_end:

gdt_desc:
    gdt_size:
        dw gdt_end - gdt_null_desc - 1
        dq gdt_null_desc
    
codeseg equ gdt_code_seg - gdt_null_desc
dataseg equ gdt_data_seg - gdt_null_desc