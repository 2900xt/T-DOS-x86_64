nasm -o os.o -f bin boot/boot.asm
nasm -o ext.o -f bin run/ext.s

cat  os.o ext.o > os.flp

qemu-system-x86_64 --fda os.flp
rm os.flp ext.o os.o