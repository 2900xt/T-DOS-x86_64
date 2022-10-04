#ifndef GVFS_TDOS_H
#define GVFS_TDOS_H

#include <gsl.h>
#include <globl.h>

struct gvfsFile{
    Time_T lastModified;
    char* filepath;
    char* filename;
    gvfsFile* nextFile = NULL;
};
void _GFS_INIT();
uint16_t mkfl(const char* filename);
int listFiles();

#endif