#pragma once
#include <std/io.hpp>
#include <tty/shell.h>
#include <std/class.hpp>
#include <std/vars.h>

void TranslateScanCode(uint8_t scancode){

    char character = 0;

    switch (scancode){
        #include <keysToShell.hpp>
        default:
            return;
    }


}