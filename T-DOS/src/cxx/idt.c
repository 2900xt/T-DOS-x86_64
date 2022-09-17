#include <globl.h>
#include <stdint.h>
void TranslateScanCode(uint8_t scancode);
struct IDT64{
    uint16_t offset_low;
    uint16_t selector;
    uint8_t ist;
    uint8_t types_attribute;
    uint16_t offset_mid;
    uint32_t offset_high;
    uint32_t zero;
};

extern "C" IDT64 _idt[256];
extern uint64_t isr1;
extern uint64_t isr8;
extern "C" void LoadIDT();


extern "C" void _IDT_INIT(){
    for (uint64_t t = 0;t<256;t++){
        _idt[t].zero = 0;
        _idt[t].offset_low = (uint16_t)(((uint64_t)&isr1 &0x000000000000ffff));
        _idt[t].offset_mid = (uint16_t)(((uint64_t)&isr1 &0x00000000ffff0000) >> 16);
        _idt[t].offset_high = (uint32_t)(((uint64_t)&isr1 &0xffffffff00000000) >> 32);
        _idt[t].ist = 0;
        _idt[t].selector = 0x08;
        _idt[t].types_attribute = 0x8e;
    }

    outb(0x21,0xfd);
    outb(0xa1,0xff);
    LoadIDT();
}

extern "C" void keyboard_handler(){
    uint8_t scancode = inb(0x60);
    TranslateScanCode(scancode);
    outb(0x20, 0x20);
    outb(0xa0, 0x20);
}

void TranslateScanCode(uint8_t scancode){

    char character = 0;

    switch (scancode){
        #include <keysToShell.hpp>
        default:
            return;
    }


}