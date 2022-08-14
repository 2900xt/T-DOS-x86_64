#include <std/io.hpp>


extern "C" void _start(){

    __TTY_INIT(VGA_COLOR_RED,VGA_COLOR_BLACK);
    setCursorPosition(0);

    cout("Welcome to 2900-OS\n->");
    return;
}