#pragma once
#include <std/io.hpp>

void TranslateScanCode(uint8_t scancode){

    char character = 0;

    switch (scancode){
        #include <keysToShell.hpp>
        default:
            return;
    }


}