#include <globl.h>
#include <vga/fonts.h>

#define VGA_MAX_X 1024
#define VGA_MAX_Y 768

void* g_VGABuffer = 0xA0000;

uint16_t g_VGA_image_x;
uint16_t g_VGA_image_y;

uint16_t g_VGA_TTY_x;
uint16_t g_VGA_TTY_y;

namespace VGA{

static void putpixel(unsigned char* screen, int x,int y, int color) {
    unsigned where = x*pixelwidth + y*pitch;
    screen[where] = color & 255;              // BLUE
    screen[where + 1] = (color >> 8) & 255;   // GREEN
    screen[where + 2] = (color >> 16) & 255;  // RED
}

void putchar(Font_T font, uint16_t x, uint16_t y){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<12;j++){
            putpixel()
        }
    }
}

}