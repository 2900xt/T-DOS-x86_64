#include <globl.h>
#include <gsl/io.h>
#include <fs/gvfs.h>
extern "C" void com1_putc(char c);

void resetBuffer(){
    buffer_ptr=0;
    for (int i = 0; i < 256; i++)
        command_buffer[i] = 0;

}


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
        exit_code = listFiles();
    }

    else if(stringCmp(command_buffer,"mkfl")){
        const char* str = command_buffer+5;
        if (str[0] == '\0' || str[0] == ' '){
            cout("\nERROR: Missing Parameter\n");
            exit_code = -1;
        }
        else {
            mkfl(str);
            putc('\n');
            exit_code = 0;
        }
        
    }

    else if(stringCmp(command_buffer,"help")){
        exit_code = 0;
        cout("\nCommands:\n\nSOUT [str] \t\t\tprints to serial \nECHO [str]\t\t\t\t prints to tty\nTEDIT\t\t\t\t\t Experimantal File Editor? WIP\nTIME\t\t\t Tells time\nmkfl \t\t\t makes file\nlf\t\t\t lists files\n");
    }
    else if(stringCmp(command_buffer,"time")){
        cout("\nThe time is: \n\n");
        printTime(read_rtc());
        cout("\n");
        exit_code = 0;
    }
    else if(stringCmp(command_buffer,"sleep")){
       
        cout("\n");
        sleep(5);
        
        exit_code = 0;
    }
    else if(stringCmp(command_buffer,"break")){
       
        cout("\n");
        
        outw(0x8A00,0x8A00); outw(0x8A00,0x08AE0);
        
        exit_code = 0;
    }
    else if(stringCmp(command_buffer,"cd")){
        const char* str = command_buffer+3;
        if (str[0] == '\0' || str[0] == ' '){
            cout("\nERROR: Missing Parameter\n");
            exit_code = -1;
        }
        else {
            changeDir(str);
            putc('\n');
            exit_code = 0;
        }
    }
    else{
        exit_code = 127;
        cout("\nCOMMAND NOT FOUND: %s",command_buffer);
    }
    resetBuffer();  
    programEnter=0;   
}

