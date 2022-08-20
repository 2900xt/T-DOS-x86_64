#include <std/io.hpp>
#include <mem/idt.h>
#include <mem/mem.h>
#include <tty/shell.h>
#include <ata/gvfs.h>

void kmain(){


    for (uint8_t i = 0; i< MemoryRegionCount;i++){
        MEMMAPENTRY* memmap = (MEMMAPENTRY*)0x5000;//address of memory map
        memmap+=i;
        printMemory(memmap);
    }

    cout("\nWelcome to T-DOS\n->");

     for(;;) {
    asm("hlt");
 }
}

extern "C" void _start(){

    
    clrscr();

    cout("MEMORY REGIONS AVALIBLE: \n%d\n",MemoryRegionCount);

    _IDT_INIT();
    _GFS_INIT();

    kmain();
}
