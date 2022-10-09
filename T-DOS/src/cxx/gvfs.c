#include <globl.h>
#include <fs/gvfs.h>
#include <gsl/gsl.h>
uint16_t rootID;

char* pwd;

gvfsFile* ROOT;


void _GFS_INIT(){
    ROOT = NEW(gvfsFile);
    ROOT->filepath = (char*)"/";
    ROOT->lastModified = read_rtc();
    pwd = ROOT->filepath;
}

uint16_t mkfl(const char* filename){
    gvfsFile* CurrentFile = ROOT;
    if(ROOT->nextFile == NULL){
        ROOT->nextFile = (gvfsFile*)calloc(sizeof(gvfsFile));
        CurrentFile = ROOT->nextFile;
    }
    else{
       
        while(CurrentFile->nextFile != NULL){
            CurrentFile = CurrentFile->nextFile;
        }
        CurrentFile->nextFile = (gvfsFile*)calloc(sizeof(gvfsFile));
        CurrentFile = CurrentFile->nextFile;
    }
    CurrentFile->filepath = (char*)calloc(strlen(pwd));
     CurrentFile->filename = (char*)calloc(strlen(filename));
    CurrentFile->lastModified = read_rtc();
    strcpy(CurrentFile->filepath,pwd);
    strcpy(CurrentFile->filename,filename);

    return 0;
}

int listFiles(){
    gvfsFile* CurrentFile = ROOT->nextFile;
    if(CurrentFile == NULL){
        return -1;
    }
    while(CurrentFile != NULL){
        if(stringCmp(pwd,CurrentFile->filepath) && (strlen(pwd) == strlen(CurrentFile->filepath)))
            cout("\n%s%s",CurrentFile->filepath ,CurrentFile->filename);
        CurrentFile = CurrentFile->nextFile;
    }
    return 0;
}

void changeDir(const char* dir){
    int length = strlen(pwd);
    if(stringCmp(dir,"/")){
        pwd = (char*)"/";
    }
    strcat(pwd,dir);
}