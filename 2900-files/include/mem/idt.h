#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <std/io.hpp>
#include <mem/idt.cpp>

extern "C" void IDT_SETGATE(int interrupt, void* base, uint16_t segment_desc, uint8_t flags);
typedef struct {
	uint16_t    baseLow;      // The lower 16 bits of the ISR's address
	uint16_t    segmentSelector;    // The GDT segment selector that the CPU will load into CS before calling the ISR
	uint8_t     Reserved;     // Set to zero
	uint8_t     Flags;   // Type and attributes; see the IDT page
	uint16_t    baseHigh;     // The higher 16 bits of the ISR's address
} __attribute__((packed)) idt_entry_t;

typedef struct{
	uint16_t Limit;
	idt_entry_t* ptr;
} __attribute__((packed)) idt_desc_t;

typedef enum{
	IDT_FLAG_GATE_TASK				= 0x5,
	IDT_FLAG_GATE_16BIT_INT			= 0x6,
	IDT_FLAG_GATE_16BIT_TRAP		= 0x7,
	IDT_FLAG_GATE_32BIT_INT			= 0xE,
	IDT_FLAG_GATE_32BIT_TRAP		= 0xF,

	IDT_FLAG_RING0					= (0 << 5),
	IDT_FLAG_RING1					= (1 << 5),
	IDT_FLAG_RING2					= (2 << 5),
	IDT_FLAG_RING3					= (3 << 5),

	IDT_FLAG_PRESENT				= 0x80,

} IDT_FLAGS;

void IDT_ENABLEGATE(int interrupt);

