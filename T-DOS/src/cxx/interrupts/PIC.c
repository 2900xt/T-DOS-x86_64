#include <globl.h>

#define PIC_COMMAND     0x0020
#define PIC_DATA        0x0021
#define SLAVE_COMMAND   0x00A0
#define SLAVE_DATA      0x00A1

 
#define ICW1_ICW4	0x01		/* ICW4 (not) needed */
#define ICW1_SINGLE	0x02		/* Single (cascade) mode */
#define ICW1_INTERVAL4	0x04		/* Call address interval 4 (8) */
#define ICW1_LEVEL	0x08		/* Level triggered (edge) mode */
#define ICW1_INIT	0x10		/* Initialization - required! */
 
#define ICW4_8086	0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO	0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		/* Buffered mode/master */
#define ICW4_SFNM	0x10		/* Special fully nested (not) */



void sendEOI(uint8_t irq){
    if(irq>7)
        outb(SLAVE_COMMAND,0x20);
    outb(PIC_COMMAND,0x20);
}

void pic_Remap(int offseta, int offsetb){
    uint8_t a1, a2;

    a1 = inb(PIC_DATA);
    a2 = inb(PIC_DATA);

    outb(PIC_COMMAND, ICW1_INIT | ICW1_ICW4);   //Initialize master PIC
    outb(SLAVE_COMMAND, ICW1_INIT | ICW1_ICW4); //Initialize slave PIC
    
    outb(PIC_DATA,offseta);                     //Set master PIC vector offset
    outb(SLAVE_DATA,offsetb);                   //Set slave PIC vector offset
    
    outb(PIC_DATA,4);                           //tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
    outb(SLAVE_DATA,2);                         //tell Slave PIC its cascade identity (0000 0010)

    outb(PIC_DATA, ICW4_8086);
    outb(SLAVE_DATA, ICW4_8086);

    outb(PIC_DATA,a1);
    outb(SLAVE_DATA,a2);

}

void maskIRQ(uint8_t irq){
    uint16_t port;
    uint8_t value;

    if(irq < 8)
        port = PIC_DATA;
    else{
        port = SLAVE_DATA;
        irq -=8 ;
    }

    value = inb(port) | (1 << irq);

    outb(port,value);
    
}
void enableIRQ(uint8_t irq){
    uint16_t port;
    uint8_t value;

    if(irq < 8)
        port = PIC_DATA;
    else{
        port = SLAVE_DATA;
        irq -=8 ;
    }

    value = inb(port) & ~(1 << irq);
    outb(port, value);    

}