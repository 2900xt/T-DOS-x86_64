#pragma once
#include <std/io.hpp>

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