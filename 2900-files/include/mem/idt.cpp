#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <std/io.hpp>
#include <mem/isr.hpp>
#include <mem/idt.h>

idt_entry_t _idt[256]; // Create an array of IDT entries; aligned for performance
idt_desc_t CURRENT_IDT = {sizeof(_idt) - 1, _idt };

extern "C" void _IDT_INIT(idt_desc_t* IDT_DESC);

extern "C" void IDT_SETGATE(int interrupt, void* base, uint16_t segment_desc, uint8_t flags){
	_idt[interrupt].baseLow = ((uint32_t)base) & 0xFFFF;
	_idt[interrupt].segmentSelector = segment_desc;
	_idt[interrupt].Flags = flags;
	_idt[interrupt].Reserved = 0;
	_idt[interrupt].baseHigh = ((uint32_t)base >> 16) & 0xFFFF;
}																		

void IDT_ENABLEGATE(int interrupt){
	FLAG_SET(_idt[interrupt].Flags, IDT_FLAG_PRESENT);
}
void IDT_DISABLEGATE(int interrupt){
	FLAG_UNSET(_idt[interrupt].Flags, IDT_FLAG_PRESENT);
}

void loadidt(){
	_IDT_INIT(&CURRENT_IDT);
}