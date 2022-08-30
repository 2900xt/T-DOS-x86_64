#pragma once
#include <std/io.hpp>
#include <tty/shell.h>
#include <std/class.hpp>

int Shift_BIT = 0;
int Disable_terminal = 0;
int cin_out = 0;
char characterPressedCin = '\0';

void TranslateScanCode(uint8_t scancode){

    char character = 0;

    if (cin_out){
        switch (scancode)
        {
            #include <keysToCin.hpp>
            default:
                return;
        }
    }

    switch (scancode){
        #include <keysToShell.hpp>
        default:
            return;
    }


}