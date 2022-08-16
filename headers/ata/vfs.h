#include <std/io.hpp>   

struct FOLDERS_T{
    char* NAME;
    char* FILES[128];
    FOLDERS_T Subdirs[8];
};



FOLDERS_T* ROOT = {"/",0,0}; 
char* FILES_IN_PWD = "kernel\t";
int filecount = 0;

const char* ReadDir(FOLDERS_T FOLDERS){
    for (int i; i>128; i++){
            cout("%s\t",FOLDERS.FILES);
        }


    }
}

int MKFILE(const char* DIR, const char* Filename, int address, uint8_t permissions = 0b11111111){

}


int LISTFILES(const char* DIR = PWD){
    cout("\n%s\n",FILES_IN_PWD);
    return 0;
}