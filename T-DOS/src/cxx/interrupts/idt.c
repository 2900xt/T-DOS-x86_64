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
extern uint64_t exp0;
extern uint64_t exp1;
extern uint64_t exp2;
extern uint64_t exp3;
extern uint64_t exp4;
extern uint64_t exp5;
extern uint64_t exp6;
extern uint64_t exp7;
extern uint64_t exp8;
extern uint64_t exp9;
extern uint64_t exp10;
extern uint64_t exp11;
extern uint64_t exp12;
extern uint64_t exp13;
extern uint64_t exp14;
extern uint64_t exp16;
extern uint64_t exp17;
extern uint64_t exp18;
extern uint64_t exp19;
extern uint64_t exp20;
extern uint64_t exp21;
extern uint64_t exp28;
extern uint64_t exp29;
extern uint64_t exp30;

extern "C" void LoadIDT();

bool BREAK;

void IDT_ENABLEINT(int interrupt, uint64_t* isr, uint8_t ist = 0, uint8_t flags = 0x8e, uint16_t selector = 0x08){
        _idt[interrupt].zero = 0;
        _idt[interrupt].offset_low = (uint16_t)(((uint64_t)isr & 0x000000000000ffff));
        _idt[interrupt].offset_mid = (uint16_t)(((uint64_t)isr & 0x00000000ffff0000) >> 16);
        _idt[interrupt].offset_high = (uint32_t)(((uint64_t)isr & 0xffffffff00000000) >> 32);
        _idt[interrupt].ist = 0;
        _idt[interrupt].selector = 0x08;
        _idt[interrupt].types_attribute = 0x8e;
}

void IDT_ENABLEEXC(int interrupt, uint64_t* isr){
        _idt[interrupt].zero = 0;
        _idt[interrupt].offset_low = (uint16_t)(((uint64_t)isr & 0x000000000000ffff));
        _idt[interrupt].offset_mid = (uint16_t)(((uint64_t)isr & 0x00000000ffff0000) >> 16);
        _idt[interrupt].offset_high = (uint32_t)(((uint64_t)isr & 0xffffffff00000000) >> 32);
        _idt[interrupt].ist = 0;
        _idt[interrupt].selector = 0x08;
        _idt[interrupt].types_attribute = 0x8F;
}

extern "C" void _IDT_INIT(){
    for (uint64_t t = 16;t<255;t++){
        _idt[t].zero = 0;
        _idt[t].offset_low = (uint16_t)(((uint64_t)&comisr &0x000000000000ffff));
        _idt[t].offset_mid = (uint16_t)(((uint64_t)&comisr &0x00000000ffff0000) >> 16);
        _idt[t].offset_high = (uint32_t)(((uint64_t)&comisr &0xffffffff00000000) >> 32);
        _idt[t].ist = 0;
        _idt[t].selector = 0x08;
        _idt[t].types_attribute = 0x8e;
    }
    for (uint64_t t = 0;t<32;t++){
        _idt[t].zero = 0;
        _idt[t].offset_low = (uint16_t)(((uint64_t)&comisr &0x000000000000ffff));
        _idt[t].offset_mid = (uint16_t)(((uint64_t)&comisr &0x00000000ffff0000) >> 16);
        _idt[t].offset_high = (uint32_t)(((uint64_t)&comisr &0xffffffff00000000) >> 32);
        _idt[t].ist = 0;
        _idt[t].selector = 0x08;
        _idt[t].types_attribute = 0x8F;
    }

    IDT_ENABLEINT(33,&isr1); //PS2
    IDT_ENABLEINT(32,&isr0); //PIT
    IDT_ENABLEINT(38,&isr6); //FDC

    IDT_ENABLEEXC(0 ,&exp0);
    IDT_ENABLEEXC(1 ,&exp1);
    IDT_ENABLEEXC(2 ,&exp2);
    IDT_ENABLEEXC(3 ,&exp3);
    IDT_ENABLEEXC(4 ,&exp4);
    IDT_ENABLEEXC(5 ,&exp5);
    IDT_ENABLEEXC(6 ,&exp6);
    IDT_ENABLEEXC(7 ,&exp7);
    IDT_ENABLEEXC(8 ,&exp8);
    IDT_ENABLEEXC(9 ,&exp9);
    IDT_ENABLEEXC(10,&exp10);
    IDT_ENABLEEXC(11,&exp11);
    IDT_ENABLEEXC(12,&exp12);
    IDT_ENABLEEXC(13,&exp13);
    IDT_ENABLEEXC(14,&exp14);
    IDT_ENABLEEXC(16,&exp16);
    IDT_ENABLEEXC(17,&exp17);
    IDT_ENABLEEXC(18,&exp18);
    IDT_ENABLEEXC(19,&exp19);
    IDT_ENABLEEXC(20,&exp20);
    IDT_ENABLEEXC(21,&exp21);
    IDT_ENABLEEXC(28,&exp28);
    IDT_ENABLEEXC(29,&exp29);
    IDT_ENABLEEXC(30,&exp30);


    pic_Remap(32,40);

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
    if(!FLOPPYINT)
        FLOPPYINT = true;
    else
        KERNELPANIC("ERROR: UNHANDLED FDC INTERRUPT!");
    sendEOI(6);
}

extern "C" void common_ISR(){
    asm("mov $0xb8000, %edi\n\t"
    "mov $0x1f201f201f201f20, %rax\n\t"
    "mov $500, %ecx\n\t"
    "rep stosq");

    cout("Unhandled Interrupt! (Missing IDT entry)");
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

void disableInts(){
    for(int i = 32;i < 48;i++)
        maskIRQ(i);
}

void enableInts(){
    for(int i = 32;i < 48;i++)
        enableIRQ(i);
}


extern "C" void exceptionHandler(){
    asm("mov $0xb8000, %edi\n\t"
    "mov $0x1f201f201f201f20, %rax\n\t"
    "mov $500, %ecx\n\t"
    "rep stosq");

    cout("Unhandled Exception! Core Dumped");
    outw(0x8A00,0x8A00); outw(0x8A00,0x08AE0);
    __CLI;
    __HLT;
}