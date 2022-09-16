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
void bp(int x);
extern "C" void _IDT_INIT();


void command();
void putc(char c);
int rand(void);
void srand(unsigned int seed);

unsigned char inb(unsigned short port);

void outb(unsigned short port, unsigned char val);

void backspace();


#define FLAG_SET(number,flag)number |= flag
#define FLAG_UNSET(number,flag)number &= ~flag


//Garbage Standard Library



//Global Variables for Console/Shell IO

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