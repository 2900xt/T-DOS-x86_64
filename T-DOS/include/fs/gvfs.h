#ifndef GVFS_TDOS_H
#define GVFS_TDOS_H

void _GFS_INIT();
uint16_t mkfl(const char* filename);
int listFiles();

struct FileGVFS_T{
    FileGVFS_T* nextFile = nullptr;
    FileGVFS_T* previousFile = nullptr;
    char* filename = nullptr;
    int fileID = 0;
};

extern FileGVFS_T* HEAD_FILE;


uint16_t mkfl(const char* filename);

#endif