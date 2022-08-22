#pragma once 
#include <stdint.h>

struct MemorySegmentHeader_T{
    uint64_t MemoryLength;
    MemorySegmentHeader_T*  NextSegment;
    MemorySegmentHeader_T* PreviousSegment;
    MemorySegmentHeader_T*  NextFreeSegment;
    MemorySegmentHeader_T* PreviousFreeSegment;
    bool Free;
};

MemorySegmentHeader_T* FirstFreeMemorySegment;

void heap_init(uint64_t heap_address, uint64_t heap_length){
    FirstFreeMemorySegment = (MemorySegmentHeader_T*)heap_address;
    FirstFreeMemorySegment->MemoryLength = heap_length - sizeof(MemorySegmentHeader_T);
    FirstFreeMemorySegment->NextSegment=0;
    FirstFreeMemorySegment->PreviousSegment=0;
    FirstFreeMemorySegment->NextFreeSegment=0;
    FirstFreeMemorySegment->PreviousFreeSegment=0;
    FirstFreeMemorySegment->Free = true;
}

void* malloc(uint64_t size){
    uint64_t remainder = size % 8;
    size -= remainder;
    if (!remainder)
        size += 8;
    
    MemorySegmentHeader_T* currentMemorySegment = FirstFreeMemorySegment;

    while (true){
        if(currentMemorySegment->MemoryLength >= size){
            return currentMemorySegment + 1;
        }
    }

    

}