#include <globl.h>
#include <fs/gvfs.h>
#include <gsl.h>
uint16_t rootID;
uint16_t rand_seed = 1;
FileGVFS_T* HEAD_FILE = nullptr;
FileGVFS_T* CURRENT_FILE = nullptr;

void _GFS_INIT(){
    
}


uint16_t mkfl(const char* filename){
    if (HEAD_FILE == nullptr){
        HEAD_FILE = NEW(FileGVFS_T);
        CURRENT_FILE=HEAD_FILE;
        CURRENT_FILE->filename = filename;
    }
    else{
        CURRENT_FILE = HEAD_FILE;
        while(CURRENT_FILE->nextFile != nullptr){
            CURRENT_FILE = CURRENT_FILE->nextFile;
        }
        CURRENT_FILE->nextFile = NEW(FileGVFS_T);
        CURRENT_FILE = CURRENT_FILE->nextFile;
        CURRENT_FILE->filename = filename;
    }
    cout("\nMade File: %s",CURRENT_FILE->filename.c_str());
    CURRENT_FILE = nullptr;
    return 0;
}

int listFiles(){
    if (HEAD_FILE == nullptr || CURRENT_FILE != nullptr)
        return 1;
    CURRENT_FILE = HEAD_FILE;
    gsl::sstring out;
    while(CURRENT_FILE->nextFile != nullptr){
        out<<CURRENT_FILE->filename;
        out<<"\t";
        CURRENT_FILE = CURRENT_FILE->nextFile;
    }
    out<<CURRENT_FILE->filename;
    cout(out.c_str());
    CURRENT_FILE = nullptr;
    return 0;
}