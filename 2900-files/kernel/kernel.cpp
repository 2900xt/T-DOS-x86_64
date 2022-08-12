#include <std/io.hpp>
#include <mem/idt.cpp>
#include <mem/gdt.cpp>



extern "C" const char Finput[];

uint16_t counter  = 0 ;
bool loop(){
    return true;
}

extern "C" void kmain(){
    i686_GDT_Initialize();
    loadidt();
    ISR_INIT();
    __TTY_INIT(VGA_COLOR_RED,VGA_COLOR_BLACK);
    setCursorPosition(0);

   // outb(0x21,0xfd);
   // outb(0xa1,0xff);
    asm("sti");
    asm("int $0x90");
    //while (true){}

    return;
}