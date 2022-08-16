#pragma once
#include <tty/console.hpp>
//#include <ata/vfs.h>

char* PWD = "/";

extern "C" void com1_putc(char c);

int sout(const char* str);


void command(){

    char* args;

    if (stringCmp(command_buffer,"sout")){
        exit_code = sout(command_buffer +4);
        cout("\nWrote %s to COM1\n",command_buffer+5);
    }

    else if (stringCmp(command_buffer,"echo")){
        exit_code = 0;
        cout("\n%s",command_buffer+5);
    }

    /*else if(stringCmp(command_buffer,"ls")){
        exit_code = LISTFILES();
    }*/

    /*else if(stringCmp(command_buffer,"mkfile")){
        char* arg1;
        int i;
        if (command_buffer[7] != ' '){
            cout("ERROR INVALID FILENAME\n");
        }
        for (i=0;i>248;i++){
            if (command_buffer[i+7] == ' '){
                break;
            }
            else
                arg1[i] = command_buffer[i+7];
        }


        exit_code = 0;
        MKFILE(PWD,arg1,0x8000);
    }*/

    else if(stringCmp(command_buffer,"help")){
        exit_code = 0;
        cout("\n2 Commands: SOUT [str] prints to serial \n ECHO [str] echoes");
    }

    else{
        exit_code = 127;
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