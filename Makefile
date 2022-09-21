
CROSS = /usr/local/x86_64elfgcc/bin/x86_64-elf-g++
LD = /usr/local/x86_64elfgcc/bin/x86_64-elf-ld
CCFLAGS = -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -I T-DOS/include -I TFS


ASFLAGS = -felf32

INCLUDE = 2900-files/include

test: buildimg clean run

buildimg:
	clear
	nasm -o build/boot.bin -f bin T-DOS/boot/boot.asm
	nasm -o build/ext.elf -f elf64 T-DOS/src/asm/ext.s -w+zeroing

	${CROSS} ${CCFLAGS} -c "T-DOS/main.cpp" -o "build/kernel.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/src/cxx/gvfs.c" -o "build/gvfs.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/src/cxx/idt.c" -o "build/idt.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/src/cxx/io.cpp" -o "build/io.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/src/cxx/mem.c" -o "build/mem.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/src/cxx/rtc.c" -o "build/rtc.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/src/cxx/math.c" -o "build/math.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/src/cxx/vga/vga.c" -o "build/vga.o"
	${CROSS} ${CCFLAGS} -c "T-DOS/src/cxx/vga/display.c" -o "build/display.o"
	${LD} -T "link.ld"

	@echo Formatting Image
	cat  build/boot.bin build/kernel.bin > build/os.bin
	dd if=/dev/null of=build/os.bin bs=1 count=1 seek=1474559 
	dd if=build/os.bin of=build/t-dos.flp bs=512 count=2880

run:
	@echo
	@echo
	@echo STARTING VM 
	qemu-system-x86_64 -drive file=build/t-dos.flp,index=0,if=floppy,format=raw -vga cirrus 

clean:
	@echo CLEANING UP
	rm build/ext.elf build/boot.bin build/kernel.bin build/kernel.o build/os.bin build/gvfs.o build/idt.o build/io.o build/math.o build/mem.o build/rtc.o