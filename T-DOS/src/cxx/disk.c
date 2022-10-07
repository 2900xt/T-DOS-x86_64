#include <globl.h>
#include <gsl/io.h>
#include <mem.h>

#define DISK_PARAMETER_ADRESS   0x000fefc7

//FDC registers

#define FLOPPY_PRIMARY_BASE     0x03F0
#define STATUS_A                0x0000
#define STATUS_B                0x0001
#define DIGITAL_OUTPUT          0x0002      //DOR
#define MAIN_STATUS             0x0004      //MSR
#define DATA_RATE_SELECT        0x0004
#define DATA_FIFO               0x0005
#define DIGITAL_INPUT           0x0007      //DIR
#define CONFIG_CONTROL          0x0007      //CCR
#define PRIMARY_RESULT_STATUS   0x0000
#define SECONDARY_RESULT_STATUS 0x0000

//FDC commands

#define FIX_DRIVE_DATA          0x03
#define CHECK_DRIVE_STATUS      0x04
#define CALIBRATE_DRIVE         0x07
#define CHECK_INTERRUPT_STATUS  0x08
#define FORMAT_TRACK            0x0D
#define READ_SECTOR             0x66
#define READ_DELETE_SECTOR      0xDD
#define READ_SECTOR_ID          0x4A
#define READ_TRACK              0x42
#define SEEK_TRACK              0x0F
#define WRITE_SECTOR            0xC5
#define WRITE_DELETE_SECTOR     0xC9


typedef uint8_t db;
typedef uint16_t dw;
typedef uint32_t dd;
typedef uint64_t dq;

db st0;
db cylinder;

typedef struct{
    db steprate_headunload;
    db headload_ndma;
    db motor_delay_off;         //specified in clock ticks
    db bytes_per_sector;
    db sectos_per_track;
    db gap_length;
    db data_length;             //used only if bytes_per_sector is 0
    db format_gap_length;
    db filler;
    db head_settle_time;
    db motor_start_time;
}__attribute__ ((packed)) floppy_parameters;

db readFDC(db REG){
    return inb(FLOPPY_PRIMARY_BASE + REG);
}

void writeFDC(db REG , db DATA){
    outb(FLOPPY_PRIMARY_BASE + REG, DATA);
}
void waitForData(){
    while(((inb(FLOPPY_PRIMARY_BASE + MAIN_STATUS))&0xd0)!=0xd0);
}

void waitForInt(){
    while(FLOPPYINT == false);
    FLOPPYINT = false;
}

void checkIntStaus(db* st0, db* cylinder){
    writeFDC(DATA_FIFO, CHECK_INTERRUPT_STATUS);
    waitForData();
    *st0 = readFDC(DATA_FIFO);
    waitForData();
    *cylinder = readFDC(DATA_FIFO);
    return;
}

void FDCCalibrate(){
    //Turn drive motor on
    writeFDC(DIGITAL_OUTPUT, inb(DIGITAL_OUTPUT) | 0b00010000);

    //Send callibrate command
    writeFDC(DATA_FIFO , CALIBRATE_DRIVE);
    writeFDC(DATA_FIFO , 0);                    //Drive 0
    
    waitForInt();

    checkIntStaus(&st0,&cylinder);

    return;

}

void FDCConfigure(){
    writeFDC(DATA_FIFO, FIX_DRIVE_DATA);
    writeFDC(DATA_FIFO, 0);
    writeFDC(DATA_FIFO, 0);
    return;
}


//Resets the FDC to put it in a desirable state.

void FDCReset(){
    writeFDC(DIGITAL_OUTPUT, 0x00);          //Disable FDC
    writeFDC(DIGITAL_OUTPUT, 0x0C);          //Enable FDC
    waitForInt();

    checkIntStaus(&st0,&cylinder);

    writeFDC(CONFIG_CONTROL, 0);

    FDCConfigure();
    FDCCalibrate();
    return;

}

