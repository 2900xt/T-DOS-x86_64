#define PIT_DATA0 0x40
#define PIT_DATA1 0x41
#define PIT_DATA2 0x42
#define PIT_MODE 0x43

unsigned readPitCount(){
    unsigned count = 0;

    __CLI;

    outb(PIT_MODE,0b0000000);

    count = inb(PIT_DATA0);
    count |= inb(PIT_DATA0) << 8;

    __STI;
    return count;
}

void setPitCount(unsigned count){
    __CLI;

    outb(PIT_DATA0,count & 0xFF);
    outb(PIT_DATA0, (count & 0xFF00) >> 8);
    __STI;

    return;
}