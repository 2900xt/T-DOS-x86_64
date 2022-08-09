OUTPUT_FORMAT(binary)

ENTRY(_start)

SEARCH_DIR(build)

INPUT(
    ext.elf
    kernel.o
)

OUTPUT(
    build/kernel.bin
)

SECTIONS{
    . = 0x8000;

    .text : ALIGN(0x1000)
    {
        *(.text)
    }
    .data : ALIGN(0x1000)
    {
        *(.data)
    }
    .rodata : ALIGN(0x1000)
    {
        *(.rodata)
    }
    .bss : ALIGN(0x1000)
    {
        *(COMMON)
        *(.bss)
    }
}