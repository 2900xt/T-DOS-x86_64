#include <std/io.hpp>
//#include <mem/idt.cpp>

extern const char Finput[];

extern "C" void kmain(){

    //_IDT_INIT();
    __TTY_INIT(VGA_COLOR_RED,VGA_COLOR_BLACK);
    setCursorPosition(0);
    
    cout("Welcome to 2900-OS");


    return;
}