#include <vga/fonts.h>
#include <globl.h>

void mkFont(char c, uint16_t a,uint16_t b,uint16_t c,uint16_t d,uint16_t e,uint16_t f,uint16_t g, uint16_t h,uint16_t i){
    fonts[c].a = a;
    fonts[c].b = b;
    fonts[c].c = c;
    fonts[c].d = d;
    fonts[c].e = e;
    fonts[c].f = f;
    fonts[c].g = g;
    fonts[c].h = h;
    fonts[c].i = i;
}

void fontInit(){//12x9
    //A
    mkFont('A',
    0b0000/**/000000000000
    0b0000/**/000000100000
    0b0000/**/000001010000
    0b0000/**/000010001000
    0b0000/**/000100000100
    0b0000/**/001111111110
    0b0000/**/011000000011
    0b0000/**/010000000001
    0b0000/**/000000000000
    );

    mkFont('b'
    0b0000
    0b0000
    0b0000
    0b0000
    0b0000
    0b0000
    0b0000
    0b0000
    0b0000
    );
} 