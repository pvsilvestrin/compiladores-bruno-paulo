		SECTION .data
fmtStr:	db	"%s", 0	; The printf format for string
fmtInt:	db	"%d", 0	; The printf format for integer
fmtCha:	db	"%c", 0	; The printf format for character
__L_aBeL1:	dd	5	; integer
__L_aBeL2:	dd	0	; false
__L_aBeL3:	db	"hello, ", 0	; string
__L_aBeL5:	db	"world!", 0	; string
__L_aBeL6:	db	"\n", 0	; string
__L_aBeL7:	dd	4	; integer
__L_aBeL8:	dd	44	; integer
__L_aBeL9:	dd	666	; integer
__L_aBeL10:	db	'B'	; character
__L_aBeL11:	db	'r'	; character
__L_aBeL12:	dd	5	; integer
__L_aBeL13:	db	'u'	; character
__L_aBeL14:	dd	1	; true
__L_aBeL15:	db	'E'	; character
__L_aBeL16:	dd	0	; false
__L_aBeL17:	dd	1	; integer
__L_aBeL18:	dd	2	; integer


		SECTION .text
		global main
		extern printf
main:
		push		dword [__L_aBeL2]
		push		dword fmtInt
		call		printf
		add		esp, 8

		push		dword __L_aBeL3
		push		dword fmtStr
		call		printf
		add		esp, 8

		push		dword __L_aBeL5
		push		dword fmtStr
		call		printf
		add		esp, 8

		push		dword __L_aBeL6
		push		dword fmtStr
		call		printf
		add		esp, 8

		push		dword [__L_aBeL7]
		push		dword fmtInt
		call		printf
		add		esp, 8

		push		dword [__L_aBeL8]
		push		dword fmtInt
		call		printf
		add		esp, 8

		push		dword [__L_aBeL9]
		push		dword fmtInt
		call		printf
		add		esp, 8

		push		dword [__L_aBeL10]
		push		dword fmtCha
		call		printf
		add		esp, 8

		push		dword [__L_aBeL11]
		push		dword fmtCha
		call		printf
		add		esp, 8

		push		dword [__L_aBeL12]
		push		dword fmtInt
		call		printf
		add		esp, 8

		push		dword [__L_aBeL13]
		push		dword fmtCha
		call		printf
		add		esp, 8

		push		dword [__L_aBeL14]
		push		dword fmtInt
		call		printf
		add		esp, 8

		push		dword [__L_aBeL15]
		push		dword fmtCha
		call		printf
		add		esp, 8

		push		dword [__L_aBeL16]
		push		dword fmtInt
		call		printf
		add		esp, 8



		mov		eax, 0
		ret
