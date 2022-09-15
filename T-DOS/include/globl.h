#ifndef IOHPP_TDOS
#define IOHPP_TDOS
#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <vga.h>
#define NEW(T) (T*)calloc(sizeof(T))

#define __CLI asm("cli")
#define __STI asm("sti")
#define __HLT asm("hlt")


struct MEMMAPENTRY
{
    uint64_t BaseAddress;
    uint64_t RegionLength;
    uint32_t RegionType;
    uint32_t ExtendedAttributes;
};

struct MemorySegmentHeader_T{
    uint64_t MemoryLength;
    MemorySegmentHeader_T*  NextSegment;
    MemorySegmentHeader_T* PreviousSegment;
    MemorySegmentHeader_T*  NextFreeSegment;
    MemorySegmentHeader_T* PreviousFreeSegment;
    bool Free;
};

extern MemorySegmentHeader_T* FirstFreeMemorySegment;


MEMMAPENTRY** GetUsableMemory();
void memset(void* start, uint64_t value, uint64_t num);
void memcpy(void* destination, void* source, uint64_t num);
void heap_init(uint64_t heap_address, uint64_t heap_length);
void* malloc(uint64_t size);
void CombineFreeSegments(MemorySegmentHeader_T* a, MemorySegmentHeader_T* b);
void free(void* address);
void* calloc(uint64_t size);
void* realloc(void* address, uint64_t newSize);
void PIC_sendEOI(unsigned char irq);

char* strcpy(char* destination, const char* source);
bool stringCmp(const char* a, const char* b);
char* strcat(char* destination, const char* source);
void cout(const char* fmt, ...);
int strlen(const char* str);
void clrscr();
extern "C" void _IDT_INIT();
void _GFS_INIT();
void command();
void putc(char c);
uint16_t rand(void);
void srand(unsigned int seed);

unsigned char inb(unsigned short port);

void outb(unsigned short port, unsigned char val);

void backspace();

uint16_t mkfl(const char* filename);
int LISTFILES();
#define FLAG_SET(number,flag)number |= flag
#define FLAG_UNSET(number,flag)number &= ~flag

static unsigned long int next = 1;

namespace gsl{
    template <class T>
    class Array{
        T* ptr = nullptr;
        uint16_t size = 0;

    public:
        Array(){
            ptr = (T*)(calloc(sizeof(T)));
            size++;
        }
        Array(T* input){
            ptr = (T*)(calloc(sizeof(input)));
            for (int i=0;i<sizeof(input);i++){
                ptr[i] = input[i];
                size++;
            }
        }
        T operator[](uint16_t index){ 
            return ptr[index];
        }
        T* data(){
            return ptr;
        }
    };
    
    class String{

        char* data = nullptr;
        uint16_t size = 0;

    public:
        void INIT(const char* input){
            data = (char*)calloc(sizeof(input));
            for (int i=0;i<sizeof(input);i++){
                data[i] = input[i];
                size++;
            }
        }
        String(){
            data = (char*)calloc(sizeof(char));
            size++;
        }
        char* c_str(){
            return data;
        }
        char operator[](uint16_t index){
            return data[index];
        }
        void operator<<(const char* str){
            char* auxptr = (char*)realloc(data,size+sizeof(str));
            data = auxptr;
            strcpy(data,strcat(data,str));
            return;
        }

        void operator=(const char* str){
            char* auxptr = (char*)realloc(data,size+sizeof(str));
            data = auxptr;
            strcpy(data,str);
            return;
        }
        void print(){
            cout("%s",this->c_str());
        }
    };
}

class FILE_T{
public:
    const char* filename;
    FILE_T* NextFiles = nullptr;
    FILE_T* PreviousFiles = nullptr;
    uint16_t ID;
};

class GVFS_BASE{
public:
    FILE_T* FirstFile;
    uint16_t addFile(const char* name){
        uint16_t id_IT = 0;
        if (FirstFile == nullptr){
            FirstFile = NEW(FILE_T);
            FirstFile->filename = name;
            FirstFile->ID = id_IT;
            return FirstFile->ID;
        }
        FILE_T* CurrentFile = FirstFile;
        while(CurrentFile->NextFiles != 0){
            CurrentFile = CurrentFile->NextFiles;
            id_IT++;
        }
        CurrentFile = NEW(FILE_T);
        CurrentFile->filename = name;
        CurrentFile->ID = id_IT;
        return FirstFile->ID;
    }
    //Searches the linked list for an empty file location and creates a new file there.

    bool removeFile(uint16_t fileID){
        FILE_T* CurrentFile = FirstFile;
        if (!FirstFile){
            return false;
        }
        do {
            if (fileID = CurrentFile->ID){
                free(CurrentFile);
                return true;
            }
            CurrentFile->NextFiles = CurrentFile;
        } while (CurrentFile->NextFiles != 0);
        return false;
    }
    const char* returnFileName(uint16_t fileID){
        FILE_T* CurrentFile = FirstFile;
        if (!FirstFile){
            return nullptr;
        }
        do {
            if (fileID == CurrentFile->ID ){
                return CurrentFile->filename;
            }
            CurrentFile->NextFiles = CurrentFile;
        } while (CurrentFile->NextFiles != 0);

        return nullptr;
    }
    uint64_t returnFileID(const char* filename){
        FILE_T* CurrentFile = FirstFile;
        if (!FirstFile){
            return 0;
        }
        do {
            if (stringCmp(filename,CurrentFile->filename)){
                return CurrentFile->ID;
            }
            CurrentFile->NextFiles = CurrentFile;
        } while (CurrentFile->NextFiles != 0);

        return 0;
    }
    gsl::String* returnFileInDir(const char* DIR = nullptr){
        gsl::String* out= NEW(gsl::String);
        out->INIT("\t");
        if (!FirstFile){
            return out;
        }
        FILE_T* CurrentFile = FirstFile->NextFiles;
        if (!DIR){
            do {
                CurrentFile->NextFiles = CurrentFile;
                *out<<"f";
            } while (CurrentFile->NextFiles != 0);
            return out;
        }
        else{
            cout("WIP\n");
            return out;
        
    }

}
};

extern GVFS_BASE FILESYSTEM;

extern int Shift_BIT ;
extern int SHELL_ACTIVE ;
extern int programEnter ;
extern int PBC ;
extern int TTY_ACTIVE ;
extern char ProgramBuffer[4096];
extern const unsigned SCREEN_WIDTH ;
extern const unsigned SCREEN_HEIGHT ;
extern const uint8_t DEFAULT_COLOR;
extern uint8_t FontColor;
extern uint8_t* g_ScreenBuffer;
extern int g_ScreenX , g_ScreenY ;
extern char command_buffer[256];
extern int exit_code ;
extern int buffer_ptr ;
extern int arg_bit;
extern uint16_t rootID;

extern uint8_t MemoryRegionCount;
extern uint8_t usableMemoryRegionCount;
extern MEMMAPENTRY* usableRegions[10];

extern bool MemRegionsGot ; 

#endif