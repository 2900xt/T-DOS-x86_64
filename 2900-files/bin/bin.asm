
%macro IncBin 2
	SECTION .rodata
	GLOBAL %1
%1:
	IncBin %2
	db 0
	%1_size: dq %1_size - %1
%endmacro

IncBin Test, "2900-files/bin/display.txt"