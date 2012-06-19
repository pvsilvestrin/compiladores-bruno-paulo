; File generated with A2I 0.4 (by Pascal Lacroix)
; a2i teste.s
; Warning: Use at your own risks, no warranties

[section .text USE32]

; .file teste.c
[section .rodata]
[BITS 32]
; (label at line 3)
$LC0:
	db "Hello World!"
[section .text]
[BITS 32]

GLOBAL main
; (label at line 8)
main:
; (label at line 9)
$LFB0:
;* syntax error at line 10 *
	push dword ebp
;* syntax error at line 12 *
	mov dword ebp, esp
;* syntax error at line 15 *
	and dword esp, -16
	sub dword esp, +16
	mov dword [esp], $LC0+0x0
	call puts
	leave
;* syntax error at line 21 *
	ret
;* syntax error at line 24 *
; (label at line 25)
$LFE0:
; ident
	db "GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
[section .note.GNU]
[BITS 32]
;* syntax error at line 28 *


;[-- Externals --]
extern stack
extern $cfi_def_cfa_register
extern $cfi_endproc
extern puts
extern $cfi_restore
extern $cfi_def_cfa_offset
extern $cfi_startproc
extern $cfi_offset
extern $cfi_def_cfa
extern @progbits

; 10 externals
