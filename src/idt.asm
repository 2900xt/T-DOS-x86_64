
[extern _idt]
idtDescriptor:
  dw 4095
  dq _idt

  %macro PUSHALL 0
  	push rax
  	push rcx
  	push rdx
  	push r8
  	push r9
  	push r10
  	push r11
  %endmacro

  %macro POPALL 0
  	pop r11
  	pop r10
  	pop r9
  	pop r8
  	pop rdx
  	pop rcx
  	pop rax
  %endmacro

  %macro _ISR 2
  [extern %1]
  GLOBAL %2
  %2:
   PUSHALL
   call %1
   POPALL
   iretq
  %endmacro

_ISR isr1_handler,isr1

GLOBAL isr0
isr0:
	PUSHALL

	POPALL
	iretq

GLOBAL LoadIDT
LoadIDT:
  lidt [idtDescriptor]
  sti
  ret

