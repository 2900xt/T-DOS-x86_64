
CROSS = /usr/local/x86_64elfgcc/bin/x86_64-elf-g++
LD = /usr/local/x86_64elfgcc/bin/x86_64-elf-ld
CCFLAGS = -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -I T-DOS/include -I TFS


ASFLAGS = -felf32

INCLUDE = 2900-files/include

all: buildimg run

buildimg:
	clear
	nasm -o build/boot.bin -f bin T-DOS/boot/boot.asm
	nasm -o build/ext.elf -f elf64 T-DOS/src/asm/ext.s -w+zeroing

	${CROSS} ${CCFLAGS} -c "T-DOS/main.cpp" -o "build/kernel.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/src/cxx/gvfs.c" -o "build/gvfs.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/src/cxx/idt.c" -o "build/idt.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/src/cxx/io.cpp" -o "build/io.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/src/cxx/mem.c" -o "build/mem.o"
	${LD} -T "link.ld"

	cat  build/boot.bin build/kernel.bin > build/os.img

	rm build/ext.elf build/boot.bin build/kernel.bin build/kernel.o

run:
	@echo STARTING VM 
	qemu-system-x86_64 -drive file=build/os.img,index=0,if=floppy,format=raw