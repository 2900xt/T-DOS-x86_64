#include <std/io.hpp>
#include <mem/idt.h>
#include <mem/mem.h>
#include <tty/shell.h>
#include <ata/gvfs.h>
#include <mem/heap.h>

void kmain(){

    int* ptr = (int*)malloc(2048);

    cout("\nWelcome to T-DOS\n->%x",ptr);

     for(;;) {
    asm("hlt");
 }
}

extern "C" void _start(){

    
    clrscr();

    cout("Initializing IDT");

    _IDT_INIT();

    cout("  ...done!\nInitializing Malloc");

    heap_init(0x100000,0x100000);

    cout("  ...done!\nInitializing VFS");

    _GFS_INIT();

    cout(" ...done!\n\n");

    kmain();
}
