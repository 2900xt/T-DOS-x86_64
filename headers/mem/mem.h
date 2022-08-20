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

void printMemory(MEMMAPENTRY* memoryMap){
    asm("cli");
    cout("Memory base: %d\nRegion Length: %d\nRegion Type: %d\nExtendedAttributes: %x\n\n",memoryMap->BaseAddress,memoryMap->RegionLength,memoryMap->RegionType,memoryMap->ExtendedAttributes);
    asm("sti");
}