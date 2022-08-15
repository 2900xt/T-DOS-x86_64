#pragma once
#include <tty/console.hpp>

extern "C" void com1_putc(char c);

void command(char cmd){
    cout("COMMAND: %c",cmd);
}
