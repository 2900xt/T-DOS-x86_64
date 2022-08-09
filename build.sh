/home/uhc/opt/cross/bin/i686-elf-as src/ext.s -o build/boot.o
/home/uhc/opt/cross/bin/i686-elf-gcc -c 2900-files/kernel.c -o build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
/home/uhc/opt/cross/bin/i686-elf-gcc -T link.ld -o build/iso/boot/2900-os.bin -ffreestanding -O2 -nostdlib build/boot.o build/kernel.o -lgcc

if grub-file --is-x86-multiboot build/2900-os.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi


grub-mkrescue -o 2900-os.iso build/iso

#qemu-system-x86_64 -hda build/os.bin
rm build/boot.o build/kernel.o 