#include <std/io.hpp>
#include <tty/shell.h>

void TranslateScanCode(uint8_t scancode){

    char character = 0;
    switch (scancode){
        #include <keys.hpp>
        default:
            return;
    }


}