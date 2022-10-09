#ifndef IOHPP_TDOS
#define IOHPP_TDOS
#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <vga/colors.h>
#include <hal/pic.h>
#include <mem.h>
#define NEW(T) (T*)calloc(sizeof(T))

#define __CLI asm("cli")
#define __STI asm("sti")
#define __HLT asm("hlt")


typedef uint8_t db;
typedef uint16_t dw;
typedef uint32_t dd;
typedef uint64_t dq;

struct Time_T{
   unsigned char second;
    unsigned char minute;
    unsigned char hour;
    unsigned char day;
    unsigned char month;
    unsigned int year;
 
};
extern MemorySegmentHeader_T* FirstFreeMemorySegment;

extern "C" void _IDT_INIT();

#define FLAG_SET(number,flag)number |= flag
#define FLAG_UNSET(number,flag)number &= ~flag


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

extern int countDown;
extern bool FLOPPYINT;


void FDCINIT();
void FDCWriteSector(db head, db track, db sector);
uint16_t FDCReadSector(db head, db track, db sector);
#endif