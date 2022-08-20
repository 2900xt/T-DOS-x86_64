#pragma once
#include <tty/console.hpp>
#include <../T-DOS/Programs/programinc.h>

#include <ata/gvfs.h>


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

    else if(stringCmp(command_buffer,"lf")){
        exit_code = LISTFILES();
    }

    else if(stringCmp(command_buffer,"mkfl")){

        exit_code = mkfl("HELLO");
    }

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