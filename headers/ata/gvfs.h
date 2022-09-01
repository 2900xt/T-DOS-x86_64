#pragma once
#include <std/io.hpp>
#include <mem/heap.h>
char* PWD;

class FILE_T{
    public:
        char* filename;
        uint8_t properties;
        FILE_T* NextFiles = nullptr;
        FILE_T* PreviousFiles = nullptr;
        uint64_t LBA;
};


FILE_T ROOT;
FILE_T* CURRENTFILE;
char* FILES_IN_PWD;

void _GFS_INIT(){
    PWD = "/";
    ROOT.filename = "/";
    FILES_IN_PWD = ROOT.filename;
    CURRENTFILE = &ROOT;
}

int CD(const char* Foldername){
    my_strcat(PWD,Foldername);
    return 0;
}

int mkfl( char* filename){
    CURRENTFILE->NextFiles = (FILE_T*)calloc(sizeof(FILE_T));
    CURRENTFILE->NextFiles = CURRENTFILE;
    ROOT.NextFiles->filename = filename;
    ROOT.NextFiles->PreviousFiles = &ROOT;
    my_strcat(FILES_IN_PWD,filename);
    return 0;
}

int LISTFILES(const char* DIR = PWD){
    cout("\n%s\n",FILES_IN_PWD);
    return 0;
}