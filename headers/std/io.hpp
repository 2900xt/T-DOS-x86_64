#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <std/class.hpp>
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
        return NULL;
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

char* my_strcat(char* destination, const char* source)
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

