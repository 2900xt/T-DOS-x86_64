#include "io.h"
#include "console.h"



extern void kmain(){

    terminal_initialize(VGA_COLOR_RED,VGA_COLOR_BLACK);
    setCursorPosition(0);

    terminal_writestring("Welcome to 2900-OS");
    return;
}