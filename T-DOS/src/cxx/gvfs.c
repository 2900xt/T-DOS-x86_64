
#include <globl.h>
uint16_t rootID;
bool MemRegionsGot = false; 
uint16_t rand_seed = 1;
GVFS_BASE FILESYSTEM;

void _GFS_INIT(){
    srand(rand_seed++);
    rootID = FILESYSTEM.addFile("TDOS_ROOT");
}


/*int CD(const char* Foldername){
    my_strcat(PWD,Foldername);
    return 0;
}*/

uint16_t mkfl(const char* filename){
    srand(rand_seed++);
    uint16_t newfile = FILESYSTEM.addFile(filename);
    cout("%d",newfile);
    //if (newfile != 0)
        //sreturn 0;
    //else
        //cout("\nAdded file: %s",FILESYSTEM.returnFileName(newfile));
    return newfile;
}

int LISTFILES(){
    gsl::String* files;
    files = FILESYSTEM.returnFileInDir();
    cout(files->c_str());
    return 0;
}