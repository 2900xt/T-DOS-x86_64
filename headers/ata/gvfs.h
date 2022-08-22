#pragma once
#include <std/io.hpp>
char* PWD;

struct FILE_T{
    char* filename;
    uint8_t properties;
};

struct FOLDER_T{
    char* NAME;
    FILE_T** FILES;
    FOLDER_T** subdir;
};


FOLDER_T ROOT; 
char* FILES_IN_PWD;
/*
const char* ReadDir(FOLDER_T* DIR){

    const char* output;

    for (int i; i>128; i++){
            if (!stringCmp(DIR->FILES[i],"\r"))
                cout("%s\t",DIR->FILES[i]);
            else 
                break;
        }

}*/

void _GFS_INIT(){
    ROOT.NAME = "/";
    PWD = ROOT.NAME;
    //ROOT.FILES[0]="kernel";
    FILES_IN_PWD = "kernel\t";
    //ROOT.FILES[1]= "\r";
}

int CD(const char* Foldername){
    my_strcat(PWD,Foldername);
    return 0;
}

int mkfl(const char* foldername){
    my_strcat(FILES_IN_PWD,foldername);
}

int mkf(const char* filename){
    my_strcat(FILES_IN_PWD,filename);
    return 0;
}

int LISTFILES(const char* DIR = PWD){
    cout("\n%s\n",FILES_IN_PWD);
    return 0;
}