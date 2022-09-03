#pragma once
#include <tty/console.hpp>
#include <std/class.hpp>
#include <ata/gvfs.h>
#include <std/io.hpp>
#include <std/scan.hpp>
#include <std/vars.h>

char ProgramBuffer[4096];

bool stringCmp(const char* a, const char* b);
int sout(const char* str);
extern "C" void com1_putc(char c);
char* charin();

void command(){

    char* args;

    if (stringCmp(command_buffer,"sout")){
        const char* str = command_buffer+5;
        do {
        com1_putc(*(str++));
        } while (*str);
        exit_code = 0;
        cout("\nWrote %s to COM1\n",command_buffer+5);
    }

    else if (stringCmp(command_buffer,"echo")){
        exit_code = 0;
        cout("\n%s",command_buffer+5);
    }

    else if(stringCmp(command_buffer,"lf")){
        exit_code = LISTFILES();
    }

    else if(stringCmp(command_buffer,"mkfl")){

        cout("\nFILENAME: ");
        while(!programEnter){
        }
        exit_code = mkfl(my_strcat(ProgramBuffer,"\0"));
        programEnter=0; 
    }

    else if(stringCmp(command_buffer,"help")){
        exit_code = 0;
        cout("\nCommands:\n\nSOUT [str] \t\t\tprints to serial \nECHO [str]\t\t\t\t prints to tty\nTEDIT\t\t\t\t\t Experimantal File Editor? WIP");
    }
    else if(stringCmp(command_buffer,"tedit")){
        #include <tedit.cpp>
    }
    else{
        exit_code = 127;
        cout("\nCOMMAND NOT FOUND: %s",command_buffer);
    }
    resetBuffer();  
    programEnter=0;   
}