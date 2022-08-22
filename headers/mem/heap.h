#pragma once 
#include <stdint.h>
#include <mem/mem.h>

void memset(void* start, uint64_t value, uint64_t num);
void memcpy(void* destination, void* source, uint64_t num);

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
    if (remainder != 0)
        size += 8;
    
    MemorySegmentHeader_T* currentMemorySegment = FirstFreeMemorySegment;

    while (true){
        if(currentMemorySegment->MemoryLength > size + sizeof(MemorySegmentHeader_T)){

            if (currentMemorySegment->MemoryLength != size){
                MemorySegmentHeader_T* newSegmentHeader = (MemorySegmentHeader_T*)((uint64_t)currentMemorySegment + sizeof(MemorySegmentHeader_T) + size);

                newSegmentHeader->Free = true;
                newSegmentHeader->MemoryLength = ((uint64_t)currentMemorySegment->MemoryLength) - (sizeof(MemorySegmentHeader_T) + size);
                newSegmentHeader->NextFreeSegment = currentMemorySegment->NextFreeSegment;
                newSegmentHeader->NextSegment = currentMemorySegment->NextSegment;
                newSegmentHeader->PreviousFreeSegment = currentMemorySegment->PreviousFreeSegment;
                newSegmentHeader->PreviousSegment = currentMemorySegment->PreviousSegment;

                currentMemorySegment->NextFreeSegment = newSegmentHeader;
                currentMemorySegment->NextSegment = newSegmentHeader;
                currentMemorySegment->MemoryLength = size;
            }

            if (currentMemorySegment == FirstFreeMemorySegment){
                FirstFreeMemorySegment = currentMemorySegment->NextFreeSegment;
            }

            currentMemorySegment->Free = false;

            if (currentMemorySegment->PreviousFreeSegment != 0 ){
                currentMemorySegment->PreviousFreeSegment->NextFreeSegment = currentMemorySegment->NextFreeSegment;
            }

            if (currentMemorySegment->NextFreeSegment != 0 ){
                currentMemorySegment->NextFreeSegment->PreviousFreeSegment = currentMemorySegment->PreviousFreeSegment;
            }

            if (currentMemorySegment->PreviousSegment != 0 ){
                currentMemorySegment->PreviousSegment->NextFreeSegment = currentMemorySegment->NextFreeSegment;
            }
            if (currentMemorySegment->NextSegment != 0 ){
                currentMemorySegment->NextSegment->PreviousFreeSegment = currentMemorySegment->PreviousFreeSegment;
            }

            return currentMemorySegment + 1;
        }

        if (currentMemorySegment->NextFreeSegment = 0){
            return 0;
        }

        currentMemorySegment = currentMemorySegment->NextFreeSegment;
    }
    return 0;
}
void CombineFreeSegments(MemorySegmentHeader_T* a, MemorySegmentHeader_T* b) {
	if (a == 0) return;
	if (b == 0) return;
	if (a < b) {
		a->MemoryLength += b->MemoryLength + sizeof(MemorySegmentHeader_T);
		a->NextSegment = b->NextSegment;
		a->NextFreeSegment = b->NextFreeSegment;
		b->NextSegment->PreviousSegment = a;
		b->NextSegment->PreviousFreeSegment = a;
		b->NextFreeSegment->PreviousFreeSegment = a;
	}
	else {
		b->MemoryLength += a->MemoryLength + sizeof(MemorySegmentHeader_T);
		b->NextSegment = a->NextSegment;
		b->NextFreeSegment = a->NextFreeSegment;
		a->NextSegment->PreviousSegment = b;
		a->NextSegment->PreviousFreeSegment = b;
		a->NextFreeSegment->PreviousFreeSegment = b;
	}
}

void free(void* address) {
	MemorySegmentHeader_T* currentMemorySegment = ((MemorySegmentHeader_T*)address) - 1;
	currentMemorySegment->Free = true;

	if (currentMemorySegment < FirstFreeMemorySegment) FirstFreeMemorySegment = currentMemorySegment;

	if (currentMemorySegment->NextFreeSegment != 0) {
		if (currentMemorySegment->NextFreeSegment->PreviousFreeSegment < currentMemorySegment)
			currentMemorySegment->NextFreeSegment->PreviousFreeSegment = currentMemorySegment;
	}
	if (currentMemorySegment->PreviousFreeSegment != 0) {
		if (currentMemorySegment->PreviousFreeSegment->NextFreeSegment > currentMemorySegment)
			currentMemorySegment->PreviousFreeSegment->NextFreeSegment = currentMemorySegment;
	}
	if (currentMemorySegment->NextSegment != 0) {
		currentMemorySegment->NextSegment->PreviousSegment = currentMemorySegment;
		if (currentMemorySegment->NextSegment->Free) CombineFreeSegments(currentMemorySegment, currentMemorySegment->NextSegment);
	}
	if (currentMemorySegment->PreviousSegment != 0) {
		currentMemorySegment->PreviousSegment->NextSegment = currentMemorySegment;
		if (currentMemorySegment->PreviousSegment->Free) CombineFreeSegments(currentMemorySegment, currentMemorySegment->PreviousSegment);

	}
}


void* calloc(uint64_t size) {
	void* mallocVal = malloc(size);
	memset(mallocVal, 0, size);
	return mallocVal;
}


void* realloc(void* address, uint64_t newSize) {
	MemorySegmentHeader_T* oldSegmentHeader = (MemorySegmentHeader_T*)address - 1;
	uint64_t smallerSize = newSize;
	if (oldSegmentHeader->MemoryLength < newSize) smallerSize = oldSegmentHeader->MemoryLength;
	void* newMem = malloc(newSize);
	memcpy(newMem, address, smallerSize);
	free(address);
	return(newMem);
}