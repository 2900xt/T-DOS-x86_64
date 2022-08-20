#pragma once
#include <std/io.hpp>
char* PWD = "/";

struct FOLDERS_T2{
    char* NAME;
    char* FILES[128];
    //FOLDERS_T2 Subdirs[8]; 
};

//GARBAGE VFS :)
struct FOLDER_T{
    char* NAME;
    char* FILES[128];
    FOLDERS_T2 Subdirs[8];
};




FOLDER_T ROOT; 
char* FILES_IN_PWD;
//int filecount = 0;
/*
const char* ReadDir(FOLDER_T* DIR){

    const char* output;

    for (int i; i>128; i++){
            if (!stringCmp(DIR->FILES[i],"\r"))
                cout("%s\t",DIR->FILES[i]);
            else 
                break;
        }

}
*/
void _GFS_INIT(){
    //ROOT.NAME = "/";
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