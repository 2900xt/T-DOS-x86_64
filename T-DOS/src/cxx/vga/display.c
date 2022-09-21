#include <globl.h>
#include <vga/fonts.h>

void putPixel(uint16_t x, uint16_t y, uint8_t pixel){
    unsigned char* location = (unsigned char*)0xA0000 + 320 * y + x;
    *location = pixel;
}

void putPixelArray(uint16_t x, uint16_t y, uint16_t data){
    for(int i = 0; i<16; i++){
        if((data>>i)&0b0000000000000001)
        putPixel(x++,y,15);
        else{
            putPixel(x++,y,0);
        }
    }
}
/*void putChar(Font_T font, uint16_t x, uint16_t y){
    putPixelArray(x,y++,font.a);
    putPixelArray(x,y++,font.b);
    putPixelArray(x,y++,font.c);
    putPixelArray(x,y++,font.d);
    putPixelArray(x,y++,font.e);
    putPixelArray(x,y++,font.f);
    putPixelArray(x,y++,font.g);
    putPixelArray(x,y++,font.h);
}

*/