#pragma once
#include <tty/console.hpp>

extern "C" void com1_putc(char c);

int sout(const char* str);

void command(){

    char* args;

    if (stringCmp(command_buffer,"sout")){
        exit_code = sout(command_buffer +4);
        cout("\nWrote %s to COM1\n",command_buffer+5);
    }

    if (stringCmp(command_buffer,"echo")){
        exit_code = 0;
        cout("\n%s",command_buffer+5);
    }

    else{
        exit_code = 1;
        cout("\nCOMMAND NOT FOUND: %s",command_buffer);
    }
    resetBuffer();       
}

int sout(const char* str){

    do {
    com1_putc(*(str++));
    } while (*str);
    return 0;
}