#include <std/io.hpp>
#include <mem/idt.h>
#include <mem/mem.h>
#include <tty/shell.h>
#include <ata/gvfs.h>
#include <mem/heap.h>




void kmain(){

    cout("\nWelcome To T-DOS\nfor a list of commands: 'help'\n\n->");

     for(;;) {
    asm("hlt");
 }
}

extern "C" void _start(){

    
    clrscr();

    cout("Initializing IDT");

    _IDT_INIT();

    cout("  ...done!\nInitializing Heap");

    heap_init(0x100000,0x100000);

    cout("  ...done!\nInitializing GVFS");

    _GFS_INIT();

    cout(" ...done!\n\n");

    kmain();
}
