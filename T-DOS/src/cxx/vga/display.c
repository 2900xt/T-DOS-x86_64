#include <globl.h>
#include <vga/fonts.h>

const unsigned SCREEN_WIDTH = 320;
const unsigned SCREEN_HEIGHT = 200;
const uint8_t DEFAULT_COLOR = 0x1;
uint8_t FontColor = 1;
uint8_t* g_ScreenBuffer = (uint8_t*)0xA0000;
int g_ScreenX = 0, g_ScreenY = 0;

void clearScreen(){
    for(int i = 0; i<320;i++){
        for(int j = 0;j<200;j++){
            putPixel(i,j,0);
        }
    }
}

void putPixel(uint16_t x, uint16_t y, uint8_t pixel){
    unsigned char* location = (unsigned char*)0xA0000 + 320 * y + x;
    *location = pixel;
}

void putPixelArray(uint16_t x, uint16_t y, uint8_t data, int color){
    for(int i = 0; i<16; i++){
        if((data<<i)&0b10000000)
        putPixel(x++,y,color);
        else{
            putPixel(x++,y,0);
        }
    }
}
void putChar(Font_T font, uint16_t x, uint16_t y, int color){
    putPixelArray(x,y++,font.a,color);
    putPixelArray(x,y++,font.b,color);
    putPixelArray(x,y++,font.c,color);
    putPixelArray(x,y++,font.d,color);
    putPixelArray(x,y++,font.e,color);
    putPixelArray(x,y++,font.f,color);
    putPixelArray(x,y++,font.g,color);
    putPixelArray(x,y++,font.h,color);
}

void writeChar(char c){
    switch(c){
        case '\n':
            g_ScreenX = 0;
            g_ScreenY +=8;
            break;
        default:
            if(g_ScreenY >= 190){
                g_ScreenY = 0;
                g_ScreenX = 0;
                clearScreen();
                putChar(fonts[c],g_ScreenX,g_ScreenY,FontColor);
                g_ScreenX+=9;
            }
            else if(g_ScreenX >=310){
                g_ScreenX = 0;
                g_ScreenY+=8;
                putChar(fonts[c],g_ScreenX,g_ScreenY,FontColor);
                g_ScreenX+=9;
            }else{
                putChar(fonts[c],g_ScreenX,g_ScreenY,FontColor);
                g_ScreenX+=9;
            }
            break;
        }
    return;
}

void putString(const char* str, int color = FontColor){
    FontColor = color;
    for(int i = 0; i<strlen(str);i++){
        writeChar(str[i]);
    }
    return;
}