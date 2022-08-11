#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tty/console.hpp>

#define FLAG_SET(number,flag)number |= flag
#define FLAG_UNSET(number,flag)number &= ~flag


char hexToStringOutput[128];

const char* HexToString(uint16_t value){
  uint16_t* valPtr = &value;
  uint8_t* ptr;
  uint8_t temp;
  uint8_t size = (sizeof(uint16_t)) * 2 - 1;
  uint8_t i;
  for (i = 0; i < size; i++){
    ptr = ((uint8_t*)valPtr + i);
    temp = ((*ptr & 0xF0) >> 4);
    hexToStringOutput[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : 48);
    temp = ((*ptr & 0x0F));
    hexToStringOutput[size - (i * 2 + 0)] = temp + (temp > 9 ? 55 : 48);
  }
  hexToStringOutput[size + 1] = 0;
  return hexToStringOutput;
}


void cout(const char* text , uint16_t data = 0)
{
	terminal_write(text, strlen(text),data);
}


void outb(unsigned short port, unsigned char val){
    asm volatile("outb %0 ,%1" :: "a"(val), "Nd"(port));
}

unsigned char inb(unsigned short port){
    unsigned char returnval = 0;
    asm volatile("outb %0 ,%1" :: "a"(returnval), "Nd"(port));
    return returnval;
}