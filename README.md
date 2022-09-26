# T-DOS

Operating system written in x86 assembly and cxx

# How to compile??

Prebuilt.flp file can be found in the "build" folder

Alternatively, build the OS by running "make buildimg"
GCC-Directory in the makefile is :
/usr/local/x86_64elfgcc/bin/x86_64-elf-g++

# How do I run/try this?? 

Currently, the .flp precompiles image only works with qemu x86_64 and maybe bochs
Virtualbox doesn't work becuase there is no filesytem at the time on the floppy

Run "make run" after "make builimg" to try out the OS in qemu

# Programs

There are some custom programs that come with the OS :
Tcalc, Tedit and more to be added.