#include <std/io.h>
//#include <mem/idt.cpp>

extern const char Finput[];

extern void kmain(){

    //_IDT_INIT();
    __TTY_INIT(VGA_COLOR_RED,VGA_COLOR_BLACK);
    setCursorPosition(0);
    

    cout("Welcome to 2900-OS",NULL);


    return;
}