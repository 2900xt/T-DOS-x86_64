#ifndef IOHPP_TDOS
#define IOHPP_TDOS
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <fstypes.h>
#include <std/vga.h>
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

MemorySegmentHeader_T* FirstFreeMemorySegment;


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

uint16_t mkfl(const char* filename);
int LISTFILES();
#define FLAG_SET(number,flag)number |= flag
#define FLAG_UNSET(number,flag)number &= ~flag

static unsigned long int next = 1; 

uint16_t rand(void) // RAND_MAX assumed to be 32767 
{ 
    next = next * 1103515245 + 12345; 
    return (unsigned int)(next/131072) % 65535; 
} 

void srand(unsigned int seed) 
{ 
    next = seed; 
} 

int sout(const char* str);
extern "C" void com1_putc(char c);

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
        void INIT(char* input){
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
    id_t ID;
};

class GVFS_BASE{
public:
    FILE_T* FirstFile;
    uint16_t addFile(const char* name){
        if (FirstFile == nullptr){
            FirstFile = NEW(FILE_T);
            FirstFile->filename = name;
            FirstFile->ID = rand();
            return FirstFile->ID;
        }
        FILE_T* CurrentFile = FirstFile;
        while(CurrentFile->NextFiles != 0){
            CurrentFile = CurrentFile->NextFiles;
        }
        CurrentFile = NEW(FILE_T);
        CurrentFile->filename = name;
        CurrentFile->ID = rand();
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
            return NULL;
        }
        do {
            if (stringCmp(filename,CurrentFile->filename)){
                return CurrentFile->ID;
            }
            CurrentFile->NextFiles = CurrentFile;
        } while (CurrentFile->NextFiles != 0);

        return 0;
    }
    gsl::String returnFileInDir(const char* DIR = nullptr){
        gsl::String out;
        if (!FirstFile){
            return out;
        }
        out.INIT("\n");
        FILE_T* CurrentFile = FirstFile->NextFiles;
        if (!DIR){
            do {
                //out<<(CurrentFile->filename);
                out<<" ";
                CurrentFile->NextFiles = CurrentFile;
            } while (CurrentFile->NextFiles != 0);
            return out;
        }
        else{
            cout("WIP\n");
            return out;
        }
    }

};


GVFS_BASE FILESYSTEM;

int Shift_BIT = 0;
int SHELL_ACTIVE = 1;
int programEnter = 0;
int PBC = 0;
int TTY_ACTIVE = 1;
char ProgramBuffer[4096];
const unsigned SCREEN_WIDTH = 80;
const unsigned SCREEN_HEIGHT = 25;
const uint8_t DEFAULT_COLOR = 0x15;
uint8_t FontColor = 15;
uint8_t* g_ScreenBuffer = (uint8_t*)0xB8000;
int g_ScreenX = 0, g_ScreenY = 0;
char command_buffer[256];
int exit_code = 0;
int buffer_ptr = 0;
int arg_bit = 0;
uint16_t rootID;

extern uint8_t MemoryRegionCount;
uint8_t usableMemoryRegionCount = 0;
MEMMAPENTRY* usableRegions[10];

bool MemRegionsGot = false; 


bool stringCmp(const char* a, const char* b){
  for (int j=-1;b[++j] != 0;){
    if (a[j] != b[j]){
      return false;
    }
  }
  return true;
}

int strlen(const char* str){
  int i = 0;
  while(*str != 0){
    str++;
    i++;
  }
  return i;
}

char* strcpy(char* destination, const char* source)
{
    // return if no memory is allocated to the destination
    if (destination == NULL) {
        return nullptr;
    }
 
    // take a pointer pointing to the beginning of the destination string
    char *ptr = destination;
 
    // copy the C-string pointed by source into the array
    // pointed by destination
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
 
    // include the terminating null character
    *destination = '\0';
 
    // the destination is returned by standard `strcpy()`
    return ptr;
}

char* strcat(char* destination, const char* source)
{
    // make `ptr` point to the end of the destination string
    char* ptr = destination + strlen(destination);
 
    // appends characters of the source to the destination string
    while (*source != '\0') {
        *ptr++ = *source++;
    }
 
    // null terminate destination string
    *ptr = '\0';
 
    // the destination is returned by standard `strcat()`
    return destination;
}


void outb(unsigned short port, unsigned char val){
  asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

unsigned char inb(unsigned short port){
  unsigned char returnVal;
  asm volatile ("inb %1, %0"
  : "=a"(returnVal)
  : "Nd"(port));
  return returnVal;
}

void putchr(int x, int y, char c)
{
    g_ScreenBuffer[2 * (y * SCREEN_WIDTH + x)] = c;
}

void putcolor(int x, int y, uint8_t color)
{
    g_ScreenBuffer[2 * (y * SCREEN_WIDTH + x) + 1] = color;
}

char getchr(int x, int y)
{
    return g_ScreenBuffer[2 * (y * SCREEN_WIDTH + x)];
}

uint8_t getcolor(int x, int y)
{
    return g_ScreenBuffer[2 * (y * SCREEN_WIDTH + x) + 1];
}

void setcursor(int x, int y)
{
    int pos = y * SCREEN_WIDTH + x;

    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t)(pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t)((pos >> 8) & 0xFF));
}

void backspace(){
	if (--g_ScreenX==0 || buffer_ptr==0){
		return;
	}

	setcursor(g_ScreenX, g_ScreenY);
	putchr(g_ScreenX,g_ScreenY,' ');
    command_buffer[--buffer_ptr] = '\0';
    
}

void resetBuffer(){
    buffer_ptr=0;
    for (int i = 0; i < 256; i++)
        command_buffer[i] = 0;

}

void clrscr()
{
    for (int y = 0; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            putchr(x, y, '\0');
            putcolor(x, y, 15);
        }

    g_ScreenX = 0;
    g_ScreenY = 0;
    setcursor(g_ScreenX, g_ScreenY);
}

void scrollback(int lines)
{
    for (int y = lines; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            putchr(x, y - lines, getchr(x, y));
            putcolor(x, y - lines, getcolor(x, y));
        }

    for (int y = SCREEN_HEIGHT - lines; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            putchr(x, y, '\0');
            putcolor(x, y, 15);
        }

    g_ScreenY -= lines;
}

void putc(char c)
{
    switch (c)
    {
        case '\n':
            g_ScreenX = 0;
            g_ScreenY++;
            break;
    
        case '\t':
            for (int i = 0; i < 4 - (g_ScreenX % 4); i++)
                putc(' ');
            break;

        case '\r':
            g_ScreenX = 0;
            break;

        default:
            putchr(g_ScreenX, g_ScreenY, c);
            putcolor(g_ScreenX,g_ScreenY, FontColor);
            g_ScreenX++;
            break;
    }

    if (g_ScreenX >= SCREEN_WIDTH)
    {
        g_ScreenY++;
        g_ScreenX = 0;
    }
    if (g_ScreenY >= SCREEN_HEIGHT)
        scrollback(1);

    setcursor(g_ScreenX, g_ScreenY);
}

void puts(const char* str)
{
    while(*str)
    {
        putc(*str);
        str++;
    }
}

const char g_HexChars[] = "0123456789abcdef";

void printf_unsigned(unsigned long long number, int radix)
{
    char buffer[32];
    int pos = 0;

    // convert number to ASCII
    do 
    {
        unsigned long long rem = number % radix;
        number /= radix;
        buffer[pos++] = g_HexChars[rem];
    } while (number > 0);

    // print number in reverse order
    while (--pos >= 0)
        putc(buffer[pos]);
}

void printf_signed(long long number, int radix)
{
    if (number < 0)
    {
        putc('-');
        printf_unsigned(-number, radix);
    }
    else printf_unsigned(number, radix);
}

#define PRINTF_STATE_NORMAL         0
#define PRINTF_STATE_LENGTH         1
#define PRINTF_STATE_LENGTH_SHORT   2
#define PRINTF_STATE_LENGTH_LONG    3
#define PRINTF_STATE_SPEC           4

#define PRINTF_LENGTH_DEFAULT       0
#define PRINTF_LENGTH_SHORT_SHORT   1
#define PRINTF_LENGTH_SHORT         2
#define PRINTF_LENGTH_LONG          3
#define PRINTF_LENGTH_LONG_LONG     4


void cout(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    int state = PRINTF_STATE_NORMAL;
    int length = PRINTF_LENGTH_DEFAULT;
    int radix = 10;
    bool sign = false;
    bool number = false;

    while (*fmt)
    {
        switch (state)
        {
            case PRINTF_STATE_NORMAL:
                switch (*fmt)
                {
                    case '%':   state = PRINTF_STATE_LENGTH;
                                break;
                    default:    putc(*fmt);
                                break;
                }
                break;

            case PRINTF_STATE_LENGTH:
                switch (*fmt)
                {
                    case 'h':   length = PRINTF_LENGTH_SHORT;
                                state = PRINTF_STATE_LENGTH_SHORT;
                                break;
                    case 'l':   length = PRINTF_LENGTH_LONG;
                                state = PRINTF_STATE_LENGTH_LONG;
                                break;
                    default:    goto PRINTF_STATE_SPEC_;
                }
                break;

            case PRINTF_STATE_LENGTH_SHORT:
                if (*fmt == 'h')
                {
                    length = PRINTF_LENGTH_SHORT_SHORT;
                    state = PRINTF_STATE_SPEC;
                }
                else goto PRINTF_STATE_SPEC_;
                break;

            case PRINTF_STATE_LENGTH_LONG:
                if (*fmt == 'l')
                {
                    length = PRINTF_LENGTH_LONG_LONG;
                    state = PRINTF_STATE_SPEC;
                }
                else goto PRINTF_STATE_SPEC_;
                break;

            case PRINTF_STATE_SPEC:
            PRINTF_STATE_SPEC_:
                switch (*fmt)
                {
                    case 'c':   putc((char)va_arg(args, int));
                                break;

                    case 's':   
                                puts(va_arg(args, const char*));
                                break;

                    case '%':   putc('%');
                                break;

                    case 'd':
                    case 'i':   radix = 10; sign = true; number = true;
                                break;

                    case 'u':   radix = 10; sign = false; number = true;
                                break;

                    case 'X':
                    case 'x':
                    case 'p':   radix = 16; sign = false; number = true;
                                break;

                    case 'o':   radix = 8; sign = false; number = true;
                                break;

                    // ignore invalid spec
                    default:    break;
                }

                if (number)
                {
                    if (sign)
                    {
                        switch (length)
                        {
                        case PRINTF_LENGTH_SHORT_SHORT:
                        case PRINTF_LENGTH_SHORT:
                        case PRINTF_LENGTH_DEFAULT:     printf_signed(va_arg(args, int), radix);
                                                        break;

                        case PRINTF_LENGTH_LONG:        printf_signed(va_arg(args, long), radix);
                                                        break;

                        case PRINTF_LENGTH_LONG_LONG:   printf_signed(va_arg(args, long long), radix);
                                                        break;
                        }
                    }
                    else
                    {
                        switch (length)
                        {
                        case PRINTF_LENGTH_SHORT_SHORT:
                        case PRINTF_LENGTH_SHORT:
                        case PRINTF_LENGTH_DEFAULT:     printf_unsigned(va_arg(args, unsigned int), radix);
                                                        break;
                                                        
                        case PRINTF_LENGTH_LONG:        printf_unsigned(va_arg(args, unsigned  long), radix);
                                                        break;

                        case PRINTF_LENGTH_LONG_LONG:   printf_unsigned(va_arg(args, unsigned  long long), radix);
                                                        break;
                        }
                    }
                }

                // reset state
                state = PRINTF_STATE_NORMAL;
                length = PRINTF_LENGTH_DEFAULT;
                radix = 10;
                sign = false;
                number = false;
                break;
        }

        fmt++;
    }

    va_end(args);
}

void print_buffer(const char* msg, const void* buffer, uint32_t count)
{
    const uint8_t* u8Buffer = (const uint8_t*)buffer;
    
    puts(msg);
    for (uint16_t i = 0; i < count; i++)
    {
        putc(g_HexChars[u8Buffer[i] >> 4]);
        putc(g_HexChars[u8Buffer[i] & 0xF]);
    }
    puts("\n");
}

uint32_t bintohex(uint32_t binaryval){
    uint32_t hexadecimalval = 0, i = 1, remainder = 0;
        while (binaryval != 0)

    {

        remainder = binaryval % 10;

        hexadecimalval = hexadecimalval + remainder * i;

        i = i * 2;

        binaryval = binaryval / 10;

    }
    return hexadecimalval;
}


void command(){

    char* args;

    if (stringCmp(command_buffer,"sout")){
        const char* str = command_buffer+5;
        do {
        com1_putc(*(str++));
        } while (*str);
        exit_code = 0;
        cout("\nWrote %s to COM1\n",command_buffer+5);
    }

    else if (stringCmp(command_buffer,"echo")){
        exit_code = 0;
        cout("\n%s",command_buffer+5);
    }

    else if(stringCmp(command_buffer,"lf")){
        exit_code = LISTFILES();
    }

    else if(stringCmp(command_buffer,"mkfl")){
        const char* str = command_buffer+5;
        if (str[0] == '\0' || str[0] == ' '){
            cout("\nERROR: Missing Parameter\n");
            exit_code = -1;
        }
        else {
            mkfl(str);
            putc('\n');
            exit_code = 0;
        }
        
    }

    else if(stringCmp(command_buffer,"help")){
        exit_code = 0;
        cout("\nCommands:\n\nSOUT [str] \t\t\tprints to serial \nECHO [str]\t\t\t\t prints to tty\nTEDIT\t\t\t\t\t Experimantal File Editor? WIP");
    }
    else if(stringCmp(command_buffer,"tedit")){
        #include <tedit.cpp>
    }
    else{
        exit_code = 127;
        cout("\nCOMMAND NOT FOUND: %s",command_buffer);
    }
    resetBuffer();  
    programEnter=0;   
}

#include <mem/mem.h>
#include <mem/idt.h>
#include <ata/gvfs.h>
#include <std/scan.hpp>
#include <../T-DOS/Programs/time.h>
#endif