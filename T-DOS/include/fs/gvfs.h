#ifndef GVFS_TDOS_H
#define GVFS_TDOS_H

#include <gsl.h>

void _GFS_INIT();
uint16_t mkfl(const char* filename);
int listFiles();

struct FileGVFS_T{
    FileGVFS_T* nextFile = nullptr;
    gsl::string filename = nullptr;
};

extern FileGVFS_T* HEAD_FILE;


uint16_t mkfl(const char* filename);

#endif