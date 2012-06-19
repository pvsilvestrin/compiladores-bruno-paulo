; Test file for A2I

; Base address of the module
BASEADDR        equ     020000h


KERNEL_CODE     equ     08h
KERNEL_DATA     equ     010h
                                     
[BITS 16]
org 0

startup:
        jmp entry
                                   
real_stack times 1024 db 0
real_stack_end:

align 8
gdt:
        dw 0               ; Zero descriptor
        dw 0
        dw 0
        dw 0
                                
        dw 0ffffh          ; Kernel code descriptor
        dw 00000h
        dw 09a02h
        dw 000cfh
                               
        dw 0ffffh          ; Kernel data descriptor
        dw 00000h
        dw 09200h
        dw 000cfh

align 8
gdt_descr:
        dw 6*8-1
        dd (gdt+BASEADDR)

entry:
        cli
                               
        ;
        ; Setup the segment registers and the stack
        ;
        mov     ax, cs
        mov     ds, ax
        mov     ss, ax
        mov     sp, real_stack_end

        ;
        ; load gdt
        ;
        lgdt    [gdt_descr]
                      
        ;       
        ; Enter pmode and clear prefetch queue
        ;
        mov     eax, cr0
        or      eax, 0x00000001
        mov     cr0, eax
        jmp     next
next:

        mov     ax, KERNEL_DATA
        mov     ds, ax

        mov     byte [0xb8000],'$'
        mov     byte [0xb8001],07h

        ;
        ; Jump to start of 32 bit code
        ;
        db 0eah
        dw startup32
        dw KERNEL_CODE

[BITS 32]
                              
startup32:
        mov     ax, KERNEL_DATA
        mov     ds, ax

        mov     byte [0xb8002],'A'
        mov     byte [0xb8003],07h

        call    _main

        jmp     $


%include "main.asm"

end:


