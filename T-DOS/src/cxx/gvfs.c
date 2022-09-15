#include <globl.h>
#include <fs/gvfs.h>
uint16_t rootID;
uint16_t rand_seed = 1;
FileGVFS_T* HEAD_FILE;
FileGVFS_T* CURRENT_FILE;

void _GFS_INIT(){
    srand(rand_seed++);
}


uint16_t mkfl(const char* filename){
    if (HEAD_FILE == nullptr){
        HEAD_FILE = NEW(FileGVFS_T);
        CURRENT_FILE=HEAD_FILE;
        strcpy(CURRENT_FILE->filename,filename);
        srand(rand_seed++);
        CURRENT_FILE->fileID = rand();
    }
    else{
        CURRENT_FILE = HEAD_FILE;
        while(CURRENT_FILE->nextFile != nullptr){
            CURRENT_FILE = CURRENT_FILE->nextFile;
        }
        CURRENT_FILE->nextFile = NEW(FileGVFS_T);
        strcpy(CURRENT_FILE->nextFile->filename,filename);
        srand(rand_seed++);
        CURRENT_FILE->nextFile->fileID = rand();
        CURRENT_FILE = CURRENT_FILE->nextFile;
    }
    cout("\nMade File: %s with file ID of %d",CURRENT_FILE->filename,CURRENT_FILE->fileID);
    CURRENT_FILE = nullptr;
    return 0;
}

int listFiles(){
    if (HEAD_FILE == nullptr)
        return 1;
    CURRENT_FILE = HEAD_FILE;
    cout("\n%s\t",CURRENT_FILE->filename);
    while(CURRENT_FILE->nextFile != nullptr){
        cout(" %s\t",CURRENT_FILE->filename);
        CURRENT_FILE = CURRENT_FILE->nextFile;
    }
    CURRENT_FILE = nullptr;
    return 0;
}