#include <globl.h>
#include <fs/gvfs.h>
#include <math/math.h>
#include <gsl.h>

void * __gxx_personality_v0=0;
void * _Unwind_Resume =0;

void kmain(){

    cout("\nWelcome To T-DOS\nfor a list of commands: 'help'\n\n->");

    __STI;
     for(;;) {
        //TSH Backend
        FontColor=GREEN_FONT;
        __HLT;
        if (!SHELL_ACTIVE){
        FontColor=WHITE_FONT;
        command();
		cout("\nT-SH [");
        if(!exit_code)
            FontColor = BLUE_FONT;
        else 
            FontColor = RED_FONT;
        cout("%d",exit_code);
        FontColor = WHITE_FONT;
        cout("]->");
		command_buffer[buffer_ptr]=0;
		SHELL_ACTIVE=(!SHELL_ACTIVE);
        FontColor=GREEN_FONT;
        }
 }
}

extern "C" void _start(){

    fontInit();

    putPixelArray(g_ScreenX,g_ScreenY++,0b0000001111000000);
    putPixelArray(g_ScreenX,g_ScreenY++,0b0000111001110000);
    putPixelArray(g_ScreenX,g_ScreenY++,0b0001110000111000);
    putPixelArray(g_ScreenX,g_ScreenY++,0b0001100000011000);
    putPixelArray(g_ScreenX,g_ScreenY++,0b0011111111111100);
    putPixelArray(g_ScreenX,g_ScreenY++,0b0111000000001110);
    putPixelArray(g_ScreenX,g_ScreenY++,0b1100000000000011);
    putPixelArray(g_ScreenX,g_ScreenY++,0b0000000000000000);
    

    //putChar(fonts['A'],g_ScreenX,g_ScreenY);

    __HLT;

    cout("Initializing IDT");

    _IDT_INIT();

    __CLI;
    
    FontColor=GREEN_FONT;
    cout("...done!");
    FontColor = WHITE_FONT;
    cout(" \nInitializing Heap");

    heap_init(0x100000,0x100000);

    FontColor=GREEN_FONT;
    cout("...done!");
    FontColor = WHITE_FONT;
    cout("\nInitializing GVFS");

    _GFS_INIT();

    for (int i = 0; i<4096;i++){
        ProgramBuffer[i]=0;
    }

    FontColor=GREEN_FONT;
    cout(" ...done!\n\n");
    FontColor = WHITE_FONT;

    printTime();

    mkRow('_');

    kmain();

    __CLI;
    __HLT;
}
