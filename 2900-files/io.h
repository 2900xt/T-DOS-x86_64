#pragma once

void outb(unsigned short port, unsigned char val){
    asm volatile("outb %0 ,%1" :: "a"(val), "Nd"(port));
}
unsigned char inb(unsigned short port){
    unsigned char returnval = 0;
    asm volatile("outb %0 ,%1" :: "a"(returnval), "Nd"(port));
    return returnval;
}