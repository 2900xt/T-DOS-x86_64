#include <std/io.hpp>
#include <mem/idt.h>
#include <mem/mem.h>
#include <tty/shell.h>
#include <ata/gvfs.h>

void kmain(){

    MEMMAPENTRY** UsableMemory = GetUsableMemory();

    for (uint8_t i = 0; i< usableMemoryRegionCount;i++){
        MEMMAPENTRY* memmap = UsableMemory[i];//address of memory map
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
