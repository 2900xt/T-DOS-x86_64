#pragma once
#include <std/io.hpp>
uint16_t rand_seed = 1;

void _GFS_INIT(){
    srand(rand_seed++);
    rootID = FILESYSTEM.addFile(0b01110000,"TDOS_ROOT");
}


/*int CD(const char* Foldername){
    my_strcat(PWD,Foldername);
    return 0;
}*/



int LISTFILES(){
    return 0;
}