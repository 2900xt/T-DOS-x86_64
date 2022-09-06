#include <std/io.hpp>

void kmain(){

    cout("\nWelcome To T-DOS\nfor a list of commands: 'help'\n\n->");
    __STI;
     for(;;) {
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
        FontColor=GREEN_FONT;}
 }
}

extern "C" void _start(){

    
    clrscr();

    cout("Initializing IDT");

    _IDT_INIT();

    __CLI;

    cout("  ...done!\nInitializing Heap");

    heap_init(0x100000,0x100000);

    cout("  ...done!\nInitializing GVFS");

    _GFS_INIT();

    for (int i = 0; i<4096;i++){
        ProgramBuffer[i]=0;
    }

    cout(" ...done!\n\n");

    cout("%s:",FILESYSTEM.returnFileName(rootID));

    kmain();

    __CLI;
    __HLT;
}
