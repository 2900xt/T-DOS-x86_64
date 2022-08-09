#include "io.cpp"
#include "console.cpp"



extern "C" void _start(){

    terminal_initialize(VGA_COLOR_RED,VGA_COLOR_BLACK);
    setCursorPosition(0);

    terminal_writestring("Welcome to 2900-OS");
    return;
}