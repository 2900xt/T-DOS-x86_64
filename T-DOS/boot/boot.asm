[org 0x7c00]

jmp short start
nop

;fat 12 header

bdb_oem:                    db 'MSWIN4.1'
bdb_bytes_per_sector:       dw 512
bdb_sectors_per_cluster:    db 2
bdb_reserved_sectors:       db 1
bdb_fat_count:              db 2
bdb_dir_entry_count:        db 0E0h
bdb_total_sectors:          dw 2880 ;512*2880 = 1.4M
bdb_media_desscripto_type:  db 0F0h ;1.44 Mb floppy
bdb_sectors_per_fat:        dw 9
bdb_sectors_per_track:      dw 18
bdb_head_count:             dw 2
bdb_hidden_sector_count:    dd 0
bdb_large_sector_count:     dd 0

;extended boot record

ebr_drive_number:           db 0
db 0 ; reserved
ebr_signature:              db 29h
ebr_volume_id:              db 1h, 2h, 3h, 4h, ;serial number
ebr_volume_label:           db 'TDOS-BOOT  '   ; 11 bytes padded with spaces
ebr_system_id:              db 'FAT12  '        ;fs type


start:

    mov [ebr_drive_number], dl

    mov bp, 0x7c00
    mov sp, bp

    call disc_read

    mov bx, str
    call PrintStr

    jmp PROGRAM_SPACE; EXT

    %include "T-DOS/include/ostream16"
    %include "T-DOS/src/asm/disc.asm"

    str:
        db "ERROR LOADING OS (-1)",0
    times 510-($-$$) db 0;

    dw 0xaa55;