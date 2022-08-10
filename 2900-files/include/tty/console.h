#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "../std/io.h"
#include <tty/scroll.h>

const char* HexToString(uint16_t value);

#ifndef VGA_WIDTH
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#endif
 
size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;
uint16_t cursorPosition;
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};
 
static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
	return fg | bg << 4;
}
 
static inline uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}
 
size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}
 
void setCursorPosition(uint16_t position){

    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint8_t)(position & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t)((position >> 8) & 0xFF));

    cursorPosition = position;
}

uint16_t positionFromCoords(int8_t x, int8_t y){
    if (x<80 && x>-1 && y<25 && y>-1){
    return y * VGA_WIDTH +x;
    }
    else {
        return 0;
    }
}

void __TTY_INIT(enum vga_color fg, enum vga_color bg) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(fg,bg);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}


void terminal_setcolor(uint8_t color) 
{
	terminal_color = color;
}
 
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_putchar(char c) 
{	
	switch (c){
		case '\n':
			terminal_row+=1;
			terminal_column = 0;
			setCursorPosition(positionFromCoords(terminal_column,terminal_row));
			return;
		default:
			setCursorPosition(++cursorPosition);
			terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
			break;
	}
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT){
			terminal_row--;
			setCursorPosition(cursorPosition-80);
			scroll(terminal_buffer);
			//__TTY_INIT(VGA_COLOR_RED,VGA_COLOR_BLACK);
			}
	}
}

void terminal_write(const char* text, size_t size,uint16_t data) 
{
	for (size_t i = 0; i < size; i++){
		if (text[i]=='%'){
			switch (text[i+1])
			{
			case 'd':
				const char* tmp = HexToString(data);
				cout(tmp,NULL);
				i+=2;
				break;
			
			default:
				break;
			}
		}
		terminal_putchar(text[i]);
	}
	
}


