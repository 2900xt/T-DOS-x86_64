nasm -o build/boot.bin -f bin boot/boot.asm
nasm -o build/ext.elf -f elf64 run/ext.s

/usr/local/x86_64elfgcc/bin/x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "2900-files/kernel.cpp" -o "build/kernel.o"
/usr/local/x86_64elfgcc/bin/x86_64-elf-ld -T "link.ld"

cat  build/boot.bin build/kernel.bin > build/os.img

qemu-system-x86_64  build/os.img
rm build/ext.elf build/boot.bin build/kernel.bin build/kernel.o