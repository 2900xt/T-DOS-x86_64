#pragma once
#include <std/io.hpp>
#include <tty/shell.h>
#include <std/class.hpp>

int Shift_BIT = 0;
int SHELL_ACTIVE = 1;
int PBC = 0;

void TranslateScanCode(uint8_t scancode){

    gsl::String ProgramBuffer;

    char character = 0;

    switch (scancode){
        #include <keysToShell.hpp>
        default:
            return;
    }


}