
CROSS = /home/uhc/opt/cross/bin/i686-elf-g++
CCFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -std=c++20

LDFLAGS =	-T link.ld -o build/iso/boot/2900-os.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o build/bin.o -lgcc

ASFLAGS = -felf32

INCLUDE = 2900-files/include

all: buildiso run

buildiso:
	nasm ${ASFLAGS} src/ext.s -o build/boot.o
	nasm ${ASFLAGS} 2900-files/bin/bin.asm -o build/bin.o
	${CROSS} -c 2900-files/kernel/kernel.cpp -o build/kernel.o ${CCFLAGS} -I ${INCLUDE}
	${CROSS} ${LDFLAGS}

	grub-mkrescue -o 2900-os.iso build/iso

	rm build/boot.o build/kernel.o 

run:
	qemu-system-x86_64 --cdrom 2900-os.iso