#pragma once
#include <stdint.h>
#include <std/io.hpp>

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

void printMemory(MEMMAPENTRY* memoryMap){
    asm("cli");
    cout("Memory base: %d\nRegion Length: %d\nRegion Type: %d\nExtendedAttributes: %x\n\n",memoryMap->BaseAddress,memoryMap->RegionLength,memoryMap->RegionType,memoryMap->ExtendedAttributes);
    asm("sti");
}

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