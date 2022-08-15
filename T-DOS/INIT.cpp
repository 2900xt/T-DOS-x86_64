#include <std/io.hpp>
#include <mem/idt.h>
#include <tty/shell.h>

void kmain(){
     for(;;) {
    asm("hlt");
 }
}

extern "C" void _start(){
    clrscr();
    cout("Welcome to T-DOS\n->");
    _IDT_INIT();
    kmain();
}
