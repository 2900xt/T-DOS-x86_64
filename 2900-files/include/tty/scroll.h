#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "../std/io.h"
#include <tty/console.h>

void scroll(){
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
	    for (size_t x = 0; x < VGA_WIDTH; x++) {
        const size_t index = y * VGA_WIDTH + x;
	    terminal_buffer[index] = vga_entry(' ', terminal_color);
	    }
    }
}

