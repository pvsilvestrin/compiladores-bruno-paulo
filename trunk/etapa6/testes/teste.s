	.file	"teste.c"
	.comm	a,4,4
	.comm	b,4,4
	.comm	c,4,4
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$8, a(%rip)
	movl	$6, b(%rip)
	movl	a(%rip), %edx
	movl	b(%rip), %eax
	addl	%edx, %eax
	movl	%eax, c(%rip)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
