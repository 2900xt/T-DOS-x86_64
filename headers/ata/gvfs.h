#pragma once
#include <std/io.hpp>

void _GFS_INIT(){
    srand(2026);
    rootID = FILESYSTEM.addFile(0b01110000,"TDOS_ROOT");
}


/*int CD(const char* Foldername){
    my_strcat(PWD,Foldername);
    return 0;
}*/



int LISTFILES(){
    return 0;
}