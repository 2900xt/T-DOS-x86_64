#include <std/io.hpp>
#include <mem/idt.h>
#include <mem/mem.h>
#include <tty/shell.h>
#include <ata/gvfs.h>
#include <mem/heap.h>
#include <std/scan.hpp>


void kmain(){

    cout("\nWelcome To T-DOS\nfor a list of commands: 'help'\n\n->");

     for(;;) {
        asm("hlt");
        if (!SHELL_ACTIVE){
        command();
		cout("\n%s[%d]->",PWD,exit_code);
		command_buffer[buffer_ptr]=0;
		SHELL_ACTIVE=(!SHELL_ACTIVE);}
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

    for (int i = 0; i<4096;i++){
        ProgramBuffer[i]=0;
    }

    cout(" ...done!\n\n");

    kmain();

}
