nasm -felf32 src/ext.s -o build/boot.o
nasm -felf32 2900-files/bin/bin.asm -o build/bin.o
/home/uhc/opt/cross/bin/i686-elf-gcc -c 2900-files/kernel/kernel.c -o build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I 2900-files/include
/home/uhc/opt/cross/bin/i686-elf-gcc -T link.ld -o build/iso/boot/2900-os.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o build/bin.o -lgcc

if grub-file --is-x86-multiboot build/iso/boot/2900-os.bin; then
  echo multiboot confirmed
  grub-mkrescue -o 2900-os.iso build/iso
  qemu-system-x86_64 --cdrom 2900-os.iso
else
  echo the file is not multiboot
fi



rm build/boot.o build/kernel.o 