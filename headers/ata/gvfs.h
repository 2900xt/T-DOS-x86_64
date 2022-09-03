#pragma once
#include <std/io.hpp>
#include <mem/heap.h>
#include <std/class.hpp>

class FILE_T{
    public:
        const char* filename;
        uint8_t properties; //0b (FILE(0) OR DIR(1)) 3(Permisson string (RWE))
        FILE_T* NextFiles = nullptr;
        FILE_T* PreviousFiles = nullptr;
        uint64_t LBA;
};


FILE_T ROOT;
FILE_T* CURRENTFILE;
FILE_T* FILES_IN_PWD[1024];
const char* PWD;
int filenum  = 0;

void _GFS_INIT(){
    for (int i = 0; i<1024;i++){

    }
    CURRENTFILE = &ROOT;
    CURRENTFILE->filename = "//";
    CURRENTFILE->LBA = 0;
    CURRENTFILE->properties = 0b11110000;
    FILES_IN_PWD[filenum++]->filename = CURRENTFILE->filename;
    PWD = CURRENTFILE->filename;
}

void _GFS_UPDATE(){

}

/*int CD(const char* Foldername){
    my_strcat(PWD,Foldername);
    return 0;
}*/

int mkfl(const char* filename){
    CURRENTFILE->NextFiles = (FILE_T*)calloc(sizeof(FILE_T));
    CURRENTFILE = CURRENTFILE->NextFiles;
    CURRENTFILE->filename = filename;
    cout("%s",CURRENTFILE->filename);
    FILES_IN_PWD[filenum++]->filename=CURRENTFILE->filename;
    return 0;
}

int LISTFILES(const char* DIR = PWD){
    for (int i=0;i<filenum;i++){
        cout("\n%s",FILES_IN_PWD[i]->filename);
    }
    cout("\n%d files in total\n",filenum);
    return 0;
}