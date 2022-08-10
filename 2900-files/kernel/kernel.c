#include <std/io.h>

extern const char Test[];

extern void kmain(){

    __TTY_INIT(VGA_COLOR_RED,VGA_COLOR_BLACK);
    setCursorPosition(0);


    cout(Test,NULL);


    return;
}