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
        switch (*charptr)
        {
        case 10:
            index+=VGA_WIDTH;
            break;
        case 13:
            index -=index %VGA_WIDTH;
            break;
        default:
            *(VGA_MEMORY + index *2) = *charptr;
            index++;
            break;
        }

        
        charptr++;
        
    }
    setCursorPosition(index);
    
}


char hexToStringOutput[128];
template<typename T>
const char* HexToString(T value){
  T* valPtr = &value;
  uint_8* ptr;
  uint_8 temp;
  uint_8 size = (sizeof(T)) * 2 - 1;
  uint_8 i;
  for (i = 0; i < size; i++){
    ptr = ((uint_8*)valPtr + i);
    temp = ((*ptr & 0xF0) >> 4);
    hexToStringOutput[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : 48);
    temp = ((*ptr & 0x0F));
    hexToStringOutput[size - (i * 2 + 0)] = temp + (temp > 9 ? 55 : 48);
  }
  hexToStringOutput[size + 1] = 0;
  return hexToStringOutput;
}