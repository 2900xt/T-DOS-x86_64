#pragma once
#include <std/io.hpp>
#include <std/class.hpp>
char* PWD;

class FILE_T{
        gsl::String filename;
        uint8_t properties;
        FILE_T* SubFiles = nullptr;
};


FILE_T ROOT;
char* FILES_IN_PWD;

void _GFS_INIT(){
    PWD = "/";
    FILES_IN_PWD = "\nkernel\t";
}

int CD(const char* Foldername){
    my_strcat(PWD,Foldername);
    return 0;
}

int mkfl(const char* filename){
    my_strcat(FILES_IN_PWD,filename);
    return 0;
}

int LISTFILES(const char* DIR = PWD){
    cout("\n%s\n",FILES_IN_PWD);
    return 0;
}