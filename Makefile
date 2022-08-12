
CROSS = /home/uhc/opt/cross/bin/i686-elf-g++
CCFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -std=c++20 -mgeneral-regs-only

LDFLAGS =	-T link.ld -o build/iso/boot/2900-os.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o build/bin.o build/idt.o build/gdt.o build/isr.o -lgcc

ASFLAGS = -felf32

INCLUDE = 2900-files/include

all: buildiso run

buildiso:
	nasm ${ASFLAGS} src/ext.s -o build/boot.o
	nasm ${ASFLAGS} 2900-files/bin/bin.asm -o build/bin.o
	nasm ${ASFLAGS} 2900-files/include/mem/gdt.asm -o build/gdt.o
	nasm ${ASFLAGS} 2900-files/include/mem/idt.asm  -o build/idt.o
	nasm ${ASFLAGS} 2900-files/include/mem/isr.asm -o build/isr.o
	${CROSS} -c 2900-files/kernel/kernel.cpp -o build/kernel.o ${CCFLAGS} -I ${INCLUDE}
	${CROSS} ${LDFLAGS}

	grub-mkrescue -o 2900-os.iso build/iso

	rm build/boot.o build/kernel.o 

run:
	qemu-system-x86_64 --cdrom 2900-os.iso