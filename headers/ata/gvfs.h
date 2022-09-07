#pragma once
#include <std/io.hpp>
uint16_t rand_seed = 1;

void _GFS_INIT(){
    srand(rand_seed++);
    rootID = FILESYSTEM.addFile("TDOS_ROOT");
}


/*int CD(const char* Foldername){
    my_strcat(PWD,Foldername);
    return 0;
}*/

uint16_t mkfl(const char* filename){
    cout("\nAdded file: %s",filename);
    srand(rand_seed++);
    uint16_t newfile = FILESYSTEM.addFile(filename);
    if (newfile != 0)
        return 0;
    else
        cout("\nAdded file: %s",FILESYSTEM.returnFileName(newfile));
    return newfile;
}

int LISTFILES(){
    gsl::String files;
    files = FILESYSTEM.returnFileInDir();
    cout(files.c_str());
    return 0;
}