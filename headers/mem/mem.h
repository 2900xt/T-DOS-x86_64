#pragma once
#include <stdint.h>
#include <std/io.hpp>
#include <mem/heap.h>

struct MEMMAPENTRY
{
    uint64_t BaseAddress;
    uint64_t RegionLength;
    uint32_t RegionType;
    uint32_t ExtendedAttributes;
};

extern uint8_t MemoryRegionCount;
uint8_t usableMemoryRegionCount = 0;
MEMMAPENTRY* usableRegions[10];

bool MemRegionsGot = false; 

MEMMAPENTRY** GetUsableMemory(){
    if (MemRegionsGot)
        return usableRegions;
    
    uint8_t usable_region_index;
    for(uint8_t i = 0;i<MemoryRegionCount;i++){
        MEMMAPENTRY* memMap = (MEMMAPENTRY*)0x5000;
        memMap +=i;
        if (memMap->RegionType == 1)
            usableRegions[usable_region_index++]=memMap;
    }

    usableMemoryRegionCount = usable_region_index; 
    MemRegionsGot = true;
    return usableRegions;
}

void memset(void* start, uint64_t value, uint64_t num) {

	if (num <= 8) {
		uint8_t* valPtr = (uint8_t*)&value;
		for (uint8_t* ptr = (uint8_t*)start; ptr < (uint8_t*)((uint64_t)start + num); ptr++) {
			*ptr = *valPtr;
			valPtr++;
		}

		return;
	}

	uint64_t proceedingBytes = num % 8;
	uint64_t newnum = num - proceedingBytes;

	for (uint64_t* ptr = (uint64_t*)start; ptr < (uint64_t*)((uint64_t)start + newnum); ptr++) {
		*ptr = value;
	}

	uint8_t* valPtr = (uint8_t*)&value;
	for (uint8_t* ptr = (uint8_t*)((uint64_t)start + newnum); ptr < (uint8_t*)((uint64_t)start + num); ptr++)
	{
		*ptr = *valPtr;
		valPtr++;
	}
}

void memcpy(void* destination, void* source, uint64_t num) {
	if (num <= 8) {
		uint8_t* valPtr = (uint8_t*)source;
		for (uint8_t* ptr = (uint8_t*)destination; ptr < (uint8_t*)((uint64_t)destination + num); ptr++) {
			*ptr = *valPtr;
			valPtr++;
		}

		return;
	}

	uint64_t proceedingBytes = num % 8;
	uint64_t newnum = num - proceedingBytes;
	uint64_t* srcptr = (uint64_t*)source;

	for (uint64_t* destptr = (uint64_t*)destination; destptr < (uint64_t*)((uint64_t)destination + newnum); destptr++) {
		*destptr = *srcptr;
		srcptr++;
	}

	uint8_t* srcptr8 = (uint8_t*)((uint64_t)source + newnum);
	for (uint8_t* destptr8 = (uint8_t*)((uint64_t)destination + newnum); destptr8 < (uint8_t*)((uint64_t)destination + num); destptr8++)
	{
		*destptr8 = *srcptr8;
		srcptr8++;
	}

}