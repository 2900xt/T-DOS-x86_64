#pragma once
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
	uint16_t    isr_low;      // The lower 16 bits of the ISR's address
	uint16_t    kernel_cs;    // The GDT segment selector that the CPU will load into CS before calling the ISR
	uint8_t     reserved;     // Set to zero
	uint8_t     attributes;   // Type and attributes; see the IDT page
	uint16_t    isr_high;     // The higher 16 bits of the ISR's address
} __attribute__((packed)) idt_entry_t;

__attribute__((aligned(0x10))) 
extern idt_entry_t _idt[256]; // Create an array of IDT entries; aligned for performance

extern uint32_t isr1;

void _IDT_INIT(){
    for (uint8_t i = 0; i < 256;i++){
		_idt[t].reserved=0;
		_idt[t].isr_low=(uint16_t)(((uint32_t)&isr1 &0x0000FFFF));
		_idt[t].isr_low=(uint16_t)(((uint32_t)&isr1 &0xFFFFFFFF));
	}
	}
}