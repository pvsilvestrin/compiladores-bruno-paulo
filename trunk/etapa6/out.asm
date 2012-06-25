		SECTION .data
fmtStr:	db	"%s", 0	; The printf format for string
fmtInt:	db	"%d", 0	; The printf format for integer
fmtCha:	db	"%c", 0	; The printf format for character
fmtFlo:	db	"%f", 0	; The printf format for floating
__L_aBeL1:		dd	5		; integer
__L_aBeL2:		dd	6		; integer
__L_aBeL3:		dd	1		; integer


		SECTION .bss
a:		resd	10	; integer
d:		resd	1	; integer
__T_eMp2:	resd	1	; integer


		SECTION .text
		global	main
		extern	printf
main:
		mov			eax, [__T_eMp1]	; integer
		mov			[d], eax	; integer

		push		dword [d]
		push		dword fmtInt
		call		printf
		add			esp, 8

fun:
		mov			eax, [numero]
		add			eax, [__L_aBeL3]
		mov			[__T_eMp2], eax



		mov			eax, 0
		ret
