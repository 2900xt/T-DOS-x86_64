#include <globl.h>
#include <gsl/io.h>
#include <mem.h>


//DMA -> Direct Memory Access 
//We write the output of write operations and input of read operations at 0x1000

void DMAInitialize(){
    outb(0x0A, 0x06); //Mask DMA channel 2
    outb(0xD8, 0xFF); //Reset Master Flip-Flop
    outb(0x04, 0x00); //Adress = 0x1000
    outb(0x04, 0x10); 
    outb(0xD8, 0xFF); //Reset Master Flip-Flop

    outb(0x05, 0xFF); 
    outb(0x05, 0x23); //Count to 0x23FF (number of sectors in a floppy disk)

    outb(0x80, 0x00); //External Page REG = 0x00
    outb(0x0A, 0x02); //Unmask DMA channel 2
}

void DMARead(){
    outb(0x0A, 0x06); //Mask DMA channel 2
    outb(0x0B, 0x56); //Single transfer, address increment, autoinit, read, channel 2
    outb(0x0A, 0x02); //Unmask DMA channel 2
}

void DMAWrite(){
    outb(0x0A, 0x06); //Mask DMA channel 2
    outb(0x0B, 0x5A); //Single transfer, address increment, autoinit, write, channel 2
    outb(0x0A, 0x02); //Unmask DMA channel 2
}


#define DISK_PARAMETER_ADRESS   0x000fefc7

//FDC registers

#define FLOPPY_PRIMARY_BASE     0x03F0
#define STATUS_A                0x0000
#define STATUS_B                0x0001


/*
DOR: 
Bits 0 & 1:     Drive # (Binary)
Bit 2:          Contoller Enable
Bit 3:          Enable for DMA
Bits 4 - 7:     Motor Control (Drives 0 to 3)
*/

#define DIGITAL_OUTPUT          0x0002     

/*
MSR:
Bit 0 - 3:      Set if drives 0 to 3 respectively are busy in seek mode
Bit 4:          Set if the FDC is busy with a read/write command
Bit 5:          Set if the FDC isn't in a DMA mode
Bit 6:          Set if the FDC wants the CPU to read data, and unset if the FDC wants the CPU to write data
Bit 7:          Set if data is ready for transfer
*/

#define MAIN_STATUS             0x0004
#define DISK1_BUSY      1
#define DISK2_BUSY      2
#define DISK3_BUSY      4
#define DISK4_BUSY      8
#define FDC_BUSY        16
#define FDC_DMA         32
#define FDC_READ        64
#define FDC_READY       128

#define CONFIG_CONTROL          0x0007      //CCR

/*
CCR:

Bits 0-1 ->
Used to determine what time of floppy you have (3.25 inch is 00)
*/



#define DATA_FIFO               0x0005      //COMMAND and IO
//FIFO: Used for I/O operation and sending commands
//FIFO commands ->

enum FLPYDSK_CMD {
	
	FDC_CMD_READ_TRACK	=	2,
	FDC_CMD_SPECIFY		=	3,
	FDC_CMD_CHECK_STAT	=	4,
	FDC_CMD_WRITE_SECT	=	5,
	FDC_CMD_READ_SECT	=	6,
	FDC_CMD_CALIBRATE	=	7,
	FDC_CMD_CHECK_INT	=	8,
	FDC_CMD_WRITE_DEL_S	=	9,
	FDC_CMD_READ_ID_S	=	0xa,
	FDC_CMD_READ_DEL_S	=	0xc,
	FDC_CMD_FORMAT_TRACK	=	0xd,
	FDC_CMD_SEEK		=	0xf
};

enum FLPYDSK_CMD_EXT {
 
	FDC_CMD_EXT_SKIP	=	0x20,	//00100000
	FDC_CMD_EXT_DENSITY	=	0x40,	//01000000
	FDC_CMD_EXT_MULTITRACK	=	0x80	//10000000
};

enum FLPYDSK_GAP3_LENGTH {
 
	FLPYDSK_GAP3_LENGTH_STD = 42,
	FLPYDSK_GAP3_LENGTH_5_14= 32,
	FLPYDSK_GAP3_LENGTH_3_5= 27
};

enum FLPYDSK_SECTOR_DTL {
 
	FLPYDSK_SECTOR_DTL_128	=	0,
	FLPYDSK_SECTOR_DTL_256	=	1,
	FLPYDSK_SECTOR_DTL_512	=	2,
	FLPYDSK_SECTOR_DTL_1024	=	4
};


db readFDC(db REG){
    return inb(FLOPPY_PRIMARY_BASE + REG);
}

void writeFDC(db REG , db DATA){
    outb(FLOPPY_PRIMARY_BASE + REG, DATA);
}

void waitForInt(){
    while(FLOPPYINT == false);
    FLOPPYINT = false;
}

void motorControl(db drive, db enable){
    db DOR = (readFDC(DIGITAL_OUTPUT) | ((enable%2) << ((drive%4) + 4))) | 0b00000100;    //Resets and enables a motor
    writeFDC(DIGITAL_OUTPUT, DOR);
}

db FDSendCommand(db CMD){
    for(int i = 0;i<1000;i++){
        if(!(readFDC(MAIN_STATUS) & FDC_READ))
            return 0;                                             //FDC wants a read instead ...
        else if(readFDC(MAIN_STATUS) & FDC_READY){
            writeFDC(DATA_FIFO, CMD);
            return 1;
        }
    }
    return 0xFF;                                                    //Timeout!
}

db FDReadData(){
    for(int i = 0;i<1000;i++){
        if(readFDC(MAIN_STATUS) & FDC_READ)
            return 0;                                             //FDC wants a write instead ...
        else if(readFDC(MAIN_STATUS) & FDC_READY){
            return readFDC(DATA_FIFO);
        }
    }
    return 0xFF;                                                    //Timeout!
}

void checkIntStatus(dd* st0, dd* cyl){
    FDSendCommand(0x8);

    *st0 = FDReadData();
    *cyl = FDReadData();
    
    return;
}

int FDCCalibrate(dd drive){
    dd st0, cyl;

    if(drive >= 4)
        return -2;

    motorControl(drive,1);
    
    for(int i = 0 ; i < 10 ; i++){
        FDSendCommand(FDC_CMD_CALIBRATE);
        FDSendCommand(drive);
        waitForInt();
        checkIntStatus(&st0 , &cyl);

        if(!cyl){
            motorControl(drive,0);
            return 0;
        }
    }
bp(0);
    motorControl(drive,0);
	return -1;
}

void FDCSpecify(dd stepRate, dd loadTime, dd unloadTime, bool DMAEnable){
    dd data = 0;

    FDSendCommand(FDC_CMD_SPECIFY);

    data = ((stepRate & 0xF) << 4) | (unloadTime & 0xF);
    FDSendCommand(data);

    data = (loadTime) << 1 | (DMAEnable ? 1 : 0);
    FDSendCommand(data);

    return;
}

/*
Read Sector:

    Format: M F S 0 0 1 1 0
    Paramaters:
        x x x x x HD DR1 DR0 = HD=head DR0/DR1=Disk
        Cylinder
        Head
        Sector Number
        Sector Size
        Track Length
        Length of GAP3
        Data Length
    Return:
        Return byte 0: ST0
        Return byte 1: ST1
        Return byte 2: ST2
        Return byte 3: Current cylinder
        Return byte 4: Current head
        Return byte 5: Sector number
        Return byte 6: Sector size

*/


uint16_t FDCReadSector(db head, db track, db sector){
    dd st0, cyl;

    DMARead();

    FDSendCommand(FDC_CMD_READ_SECT | FDC_CMD_EXT_DENSITY | FDC_CMD_EXT_MULTITRACK | FDC_CMD_EXT_SKIP);     //Send Read Command
    FDSendCommand(head << 2 | 0b00000001);                                                                  //Parameter 1 : Drive 0
    FDSendCommand(track);                                                                                   //Parameter 2 : Cylinder
    FDSendCommand(head);                                                                                    //Parameter 3 : Head
    FDSendCommand(sector);                                                                                  //Parameter 4 : Sector #
    FDSendCommand(FLPYDSK_SECTOR_DTL_512);                                                                  //Parameter 5 : 512 bytes per sector
    FDSendCommand(18);                                                                                      //Parameter 6 : 18 sectors per track
    FDSendCommand(FLPYDSK_GAP3_LENGTH_3_5);                                                                 //Parameter 7 : 3.5 inch floppy
    FDSendCommand(0xFF);                                                                                    //Parameter 8 : Read 1 sector (512 bytes)

    waitForInt();

    for(int i = 0 ; i < 7 ; i++){
        FDReadData();
    }

    checkIntStatus(&st0, &cyl);

    //OUR SECTOR IS AT THE CURRENT DMA ADDRESS (0x1000)
    return 0x1000;
}

//WRITE 512 BYTES FROM ADRESS 0x1000

void FDCWriteSector(db head, db track, db sector){
    dd st0, cyl;

    DMAWrite();

    FDSendCommand(FDC_CMD_WRITE_SECT | FDC_CMD_EXT_DENSITY | FDC_CMD_EXT_MULTITRACK | FDC_CMD_EXT_SKIP);    //Send Read Command
    FDSendCommand(head << 2 | 0b00000001);                                                                  //Parameter 1 : Drive 0
    FDSendCommand(track);                                                                                   //Parameter 2 : Cylinder
    FDSendCommand(head);                                                                                    //Parameter 3 : Head
    FDSendCommand(sector);                                                                                  //Parameter 4 : Sector #
    FDSendCommand(FLPYDSK_SECTOR_DTL_512);                                                                  //Parameter 5 : 512 bytes per sector
    FDSendCommand(18);                                                                                      //Parameter 6 : 18 sectors per track
    FDSendCommand(FLPYDSK_GAP3_LENGTH_3_5);                                                                 //Parameter 7 : 3.5 inch floppy
    FDSendCommand(0xFF);                                                                                    //Parameter 8 : Read 1 sector (512 bytes)

    waitForInt();

    for(int i = 0 ; i < 7 ; i++){
        FDReadData();
    }

    checkIntStatus(&st0, &cyl);

    return;
}

void FDCINIT(){

    __STI;

    outb(0x70,0x10);

    switch (inb(0x71)){
        default:
            cout("\nCMOS: 0x%x",inb(0x71));
    }
    DMAInitialize();

    dd st0, cyl;

    writeFDC(DIGITAL_OUTPUT, 0);                    //Reset
    writeFDC(DIGITAL_OUTPUT, 0b00011100);           //DMA on and enable
    waitForInt();
    cout("\nDOR:%x",readFDC(DIGITAL_OUTPUT));


    writeFDC(CONFIG_CONTROL , 0);                   //1.44 MB
    cout("\nCCR:%x",readFDC(CONFIG_CONTROL));
    FDCSpecify(3 , 16 , 240 , true);

    FDCCalibrate(0);

    return;
}