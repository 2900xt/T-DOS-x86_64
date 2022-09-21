#include <vga/fonts.h>
#include <globl.h>

Font_T fonts[256];

void mkFont(char n, uint8_t a,uint8_t b,uint8_t c,uint8_t d,uint8_t e,uint8_t f,uint8_t g, uint8_t h){
    fonts[n].a = a;
    fonts[n].b = b;
    fonts[n].c = c;
    fonts[n].d = d;
    fonts[n].e = e;
    fonts[n].f = f;
    fonts[n].g = g;
    fonts[n].h = h;
    }

void fontInit(){//8x8

    mkFont('A',
    0b00000000,
    0b00011000,
    0b00111100,
    0b01100110,
    0b01111110,
    0b11000011,
    0b11000011,
    0b00000000
    );
} 