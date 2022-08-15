#include <std/io.hpp>
#include <tty/shell.h>

int Shift_BIT = 0;

void TranslateScanCode(uint8_t scancode){

    char character = 0;
    switch (scancode){
        #include <keys.hpp>
        default:
            return;
    }


}