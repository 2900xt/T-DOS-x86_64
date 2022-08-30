
CROSS = /usr/local/x86_64elfgcc/bin/x86_64-elf-g++
LD = /usr/local/x86_64elfgcc/bin/x86_64-elf-ld
CCFLAGS = -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -I headers


ASFLAGS = -felf32

INCLUDE = 2900-files/include

all: buildiso run

buildiso:
	nasm -o build/boot.bin -f bin T-DOS/boot/boot.asm
	nasm -o build/ext.elf -f elf64 src/ext.s

	${CROSS} ${CCFLAGS} -c "T-DOS/INIT.cpp" -o "build/kernel.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/Programs/serial.cpp" -o "build/serial.o"
	${LD} -T "link.ld"

	cat  build/boot.bin build/kernel.bin > build/os.img

	rm build/ext.elf build/boot.bin build/kernel.bin build/kernel.o

run:
	qemu-system-x86_64 --fda build/os.img