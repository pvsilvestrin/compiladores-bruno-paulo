	.file	"hw.c"
	.intel_syntax noprefix
	.section	.rodata
.LC0:
	.string	"Hello World"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	push	ebp
	mov	ebp, esp
	and	esp, -16
	sub	esp, 16
	mov	eax, OFFSET FLAT:.LC0
	mov	DWORD PTR [esp], eax
	call	printf
	leave
	ret
