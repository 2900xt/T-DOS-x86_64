#include <std/io.hpp>
#include <mem/idt.h>
#include <mem/mem.h>
#include <tty/shell.h>
#include <ata/gvfs.h>
#include <mem/heap.h>

void kmain(){

    int* ptr = (int*)malloc(0x10);



    int* ptr2 = (int*)malloc(0x10);

    int* ptr3 = (int*)malloc(0x10);

    cout("\nWelcome to T-DOS\n->%x",ptr);
    cout("\n%x\n",ptr2);
    cout("\n%x\n",ptr3);

    free(ptr);
    free(ptr2);
    free(ptr3);

    void* ptr4 = malloc(0x10);
    cout("\n%x\n",ptr4);

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
