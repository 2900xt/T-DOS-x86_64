#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "../std/io.hpp"
#include "console.hpp"

#ifndef VGA_WIDTH
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#endif
static inline uint16_t vga_entry(unsigned char uc, uint8_t color);
uint16_t* terminal_buffer_copy;

void scroll(uint16_t* terminal_buffer){
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
	    for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
	        terminal_buffer_copy[index]=terminal_buffer[index]; 
	    }
    }

    for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', VGA_COLOR_BLACK);
		}
	}

    for (size_t y = 0; y < VGA_HEIGHT; y++) {
	    for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
	        terminal_buffer[index-80] = terminal_buffer_copy[index];
	    }
    }
}