#pragma once
#define VGA_MEMORY (uint_8*)0xb8000
#include "io.cpp"
#include "types.h"
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

uint_16 cursorPosition;

void setCursorPosition(uint_16 position){

    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint_8)(position & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint_8)((position >> 8) & 0xFF));

    cursorPosition = position;
}

uint_16 positionFromCoords(uint_8 x, uint_8 y){
    if (x<80 && x>-1 && y<25 && y>-1){
    return y * VGA_WIDTH +x;
    }
    else {
        return 0;
    }
}

void printf(const char* str){
    uint_8* charptr = (uint_8*)str;
    uint_8 index = cursorPosition;
    while (*charptr != 0)
    {
        *(VGA_MEMORY + index *2) = *charptr;
        charptr++;
        index++;
    }
    setCursorPosition(index);
    
}