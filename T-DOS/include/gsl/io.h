#pragma once


// String Functions
char* strcpy(char* destination, const char* source);
bool stringCmp(const char* a, const char* b);
char* strcat(char* destination, const char* source);
void cout(const char* fmt, ...);
int strlen(const char* str);
const char* subStr(const char* str, int start, int finish);

// MISC

void outw(unsigned short port, unsigned short val);

void clrscr();
void bp(int x);
void KERNELPANIC(const char* message);
void backspace();

//IO

unsigned char inb(unsigned short port);

void outb(unsigned short port, unsigned char val);


void command();
void putc(char c);

void printTime(Time_T);
void changeDir(const char* dir);


void sleep(int seconds);

void PIC_sendEOI(unsigned char irq);
Time_T read_rtc() ;

void command();