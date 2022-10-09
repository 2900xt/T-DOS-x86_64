#include <globl.h>
#include <stdint.h>
#include <gsl/io.h>
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
extern uint64_t isr6;
extern uint64_t isr1;
extern uint64_t isr0;
extern uint64_t comisr;
extern uint64_t comexc;
extern "C" void LoadIDT();

void IDT_ENABLEINT(int interrupt, uint64_t* isr, uint8_t ist = 0, uint8_t flags = 0x8e, uint16_t selector = 0x08){
        _idt[interrupt].zero = 0;
        _idt[interrupt].offset_low = (uint16_t)(((uint64_t)isr & 0x000000000000ffff));
        _idt[interrupt].offset_mid = (uint16_t)(((uint64_t)isr & 0x00000000ffff0000) >> 16);
        _idt[interrupt].offset_high = (uint32_t)(((uint64_t)isr & 0xffffffff00000000) >> 32);
        _idt[interrupt].ist = 0;
        _idt[interrupt].selector = 0x08;
        _idt[interrupt].types_attribute = 0x8e;
}


extern "C" void _IDT_INIT(){
    for (uint64_t t = 0;t<255;t++){
        _idt[t].zero = 0;
        _idt[t].offset_low = (uint16_t)(((uint64_t)&comisr &0x000000000000ffff));
        _idt[t].offset_mid = (uint16_t)(((uint64_t)&comisr &0x00000000ffff0000) >> 16);
        _idt[t].offset_high = (uint32_t)(((uint64_t)&comisr &0xffffffff00000000) >> 32);
        _idt[t].ist = 0;
        _idt[t].selector = 0x08;
        _idt[t].types_attribute = 0x8e;
    }

    IDT_ENABLEINT(1,&isr1); //PS2

    IDT_ENABLEINT(0,&isr0); //PIT

    IDT_ENABLEINT(6,&isr6); //FDC

    pic_Remap(0x00,0x0F);

    LoadIDT();
}

int countDown = 0;

extern "C" void pit_handler(){
    if(countDown!=0)
        countDown--;
    sendEOI(0);
}

extern "C" void keyboard_handler(){
    uint8_t scancode = inb(0x60);
    TranslateScanCode(scancode);
    sendEOI(1);
}

bool FLOPPYINT = false;

extern "C" void floppy_handler(){
    FLOPPYINT = true;
    sendEOI(6);
}

extern "C" void common_ISR(){
    asm("mov $0xb8000, %edi\n\t"
    "mov $0x1f201f201f201f20, %rax\n\t"
    "mov $500, %ecx\n\t"
    "rep stosq");

    cout("Unhandled Exception! (Missing IDT entry)");
    __HLT;
    __CLI;
}


void TranslateScanCode(uint8_t scancode){

    char character = 0;

    switch (scancode){
        #include <keysToShell.hpp>
        default:
            return;
    }


}