%{
/*
 * A2I
 * Copyright (c) 1998 Lacroix Pascal <placr@hotmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:

 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)

 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

/* 
 * Please contact me if you find bugs or if you want to improve A2I.
 * Lacroix Pascal <placr@hotmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "0.4"

/* forward declarations */

void warning(char *);
void fatal();

void yyerror(char *);

void dump_bytes(char *s, int len);

void output_comm(char *id, long len, int align, int lcomm);
void output_label(char *id);

void mov_sd(const char*, const char*, const char*);

/* some variables */
long line = 1, errors = 0;
char *section;				/* current section name */

/* command line switches */
int no_info = 0, opt = 0;
long baseaddr = 0;

/* the file filename is converted to outname */
char filename[250], outname[250], *program_name;

/* contains the entire command line for the function open_file */
char cmdline[250];

FILE *infile, *outfile;

long warn_debug = 0, warn_sect_attr = 0;

/* buffer used for strings and IDs */
char strbuf[512];
long strbuflen;

/* symbol structure for externals */
struct symbol {
  char *name;
  char isextern;
  char islocal;  
  struct symbol *next;
};

#define HASH_BITS 32
#define HASH_SIZE 509

static struct symbol *hashtab[HASH_SIZE];

static unsigned int hash(char *name) {
       	unsigned int hash = 0;

       	while (*name) {
        	hash = hash << 3 | hash >> HASH_BITS - 3;
                hash += *name++;
       	}

        return hash % HASH_SIZE;
}

struct symbol *addexternal(char *);
void killexternal(char *s);
struct symbol *sym_lookup(char *);

void *xmalloc(int size)
{
  void *p = (void *) malloc(size);
  if (!p) {
    printf("error: not enough memory\n");
    _exit(0);
  }
}

%}

%union {
  char *str;
  long type;
  long num;
};

%token <str> ID STRING SEGMENT REG ONEBYTE STR JMP SET ARITH LEA INC
%token <str> PUSH IMUL IDIV TRANSLAT NEG DIV LSEG LGDT MOV_SD

%token _FILE ASCII GLOBAL _LONG _WORD _BYTE IDENT
%token ALIGN P2ALIGN COMM LCOMM SPACE CALL INT _VERSION
%token SECTION UNSUPPORTED UNSUP_2 LOCAL

%token <str> ST MATH

%token <num> NUMBER

%type <str> memref1 memref scale offset memptr varptr arg numlist math_reg

%{

#define tDWORD 1
#define tWORD 2
#define tBYTE 3

/* return the correct instruction without 'l', 'w' or 'b' at the end */
static inline char *op(const char *s) {
  static char tmp[50];
  strcpy(tmp, s);
  tmp[strlen(tmp)-1] = 0;
  return strdup(tmp);
}

/* get instruction size: dword, word or byte */
static inline char *op_size(const char *s) {
        int c;
        if (strlen(s)>1) c = s[strlen(s)-1];
        else c = 0;

	if (c == 'l')  return "dword";
        else
        if (c == 'w') return "word";
        else
        if (c == 'b') return "byte";
        else
        { fprintf(stderr, "Internal error: op_size=%c (in %s line %d)\n", c, __FILE__, __LINE__);
          yyerror("unknown instruction");
          return "[error]";
        }
}

/* convert a number to a string but always with a sign (+ or -) */
static inline char *signed_num(const long x) {
	static char s[16];
        sprintf(s, "%s%ld", (x>=0 ? "+" : ""), x);
        return strdup(s);
}

/* useful for jumps */
static inline char *is_near(const char *s) {
	if (strcmp(s, "jmp") == 0) return ""; else return " near";
}


static char *translate_instr(char *instr) {
    char s[20];
    strcpy(s, instr);
    if (s[strlen(s)-1] == 'l') {
        s[strlen(s)-1] = 'd';
    }
    else {
        char buf[100];
        sprintf(buf, "translating %s to %s", instr, s);
        warning(buf);
    }

    return strdup(s);
}

static char *translate_math(char *instr) {
    char s[30], c;
    strcpy(s, instr);
    c = s[strlen(s)-1];
    if (c=='s') {
        s[strlen(s)-1] = 0;
        strcat(s, " dword");
        return strdup(s);
    }
    else
    if (c=='l') {
        s[strlen(s)-1] = 0;
        strcat(s, " qword");
        return strdup(s);
    }
    else
    if (c=='p') {
        return strdup(s);
    }
    else warning("unknown math instruction");

    return instr;
}

struct tok {
	char *name;
        long token;
};

struct tok tokens[] = {
    ".file", _FILE,
    ".text", SEGMENT,
    ".data", SEGMENT,
    ".bss", SEGMENT,
    ".section", SECTION,
    ".ascii", ASCII,
    ".string", ASCII,
    ".globl", GLOBAL,
    ".version", _VERSION,
    ".local", LOCAL,

    ".long", _LONG,
    ".word", _WORD,
    ".byte", _BYTE,

    ".p2align", P2ALIGN,
    ".align", ALIGN,
    ".space", SPACE,
    ".zero", SPACE,

    "pushl", PUSH,
    "pushw", PUSH,

    "popl", PUSH,
    "popw", PUSH,

    "movl", ARITH,
    "movw", ARITH,
    "movb", ARITH,

    "xorl", ARITH,
    "xorw", ARITH,
    "xorb", ARITH,

    "call", CALL,

    "addl", ARITH,
    "addw", ARITH,
    "addb", ARITH,

    "subl", ARITH,
    "subw", ARITH,
    "subb", ARITH,

    "cmpl", ARITH,
    "cmpw", ARITH,
    "cmpb", ARITH,

    "leal", LEA,
    "leaw", LEA,

    "incl", INC,
    "incw", INC,
    "incb", INC,

    "decl", INC,
    "decw", INC,
    "decb", INC,

    "ja", JMP,
    "jae", JMP,
    "jb", JMP,
    "jbe", JMP,
    "jc", JMP,
    "jcxz", JMP,
    "je", JMP,
    "jg", JMP,
    "jge", JMP,
    "jl", JMP,
    "jle", JMP,
    "jmp", JMP,
    "jna", JMP,
    "jnae", JMP,
    "jnb", JMP,
    "jnbe", JMP,
    "jnc", JMP,
    "jne", JMP,
    "jng", JMP,
    "jnge", JMP,
    "jnl", JMP,
    "jnle", JMP,
    "jno", JMP,
    "jnp", JMP,
    "jns", JMP,
    "jnz", JMP,
    "jo", JMP,
    "jp", JMP,
    "jpe", JMP,
    "jpo", JMP,
    "js", JMP,
    "jz", JMP,
    "jcxz", JMP,
    "jecxz", JMP,
    "loop", JMP,
    "loopz", JMP,
    "loope", JMP,
    "loopnz", JMP,
    "loopne", JMP,


    "sarl", ARITH,
    "sarw", ARITH,

    "sall", ARITH,
    "salw", ARITH,

    "movswl", MOV_SD,
    "movslw", MOV_SD,
    "movsbl", MOV_SD,
    "movsbw", MOV_SD,

    "movzwl", MOV_SD,
    "movzlw", MOV_SD,
    "movzbl", MOV_SD,
    "movzbw", MOV_SD,

    "testl", ARITH,
    "testw", ARITH,
    "testb", ARITH,

    "negl", NEG,
    "negw", NEG,
    "negb", NEG,

    "notl", NEG,
    "notw", NEG,
    "notb", NEG,

    "setne", SET,
    "sete", SET,
    "setg", SET,

    "andl", ARITH,
    "andw", ARITH,
    "andb", ARITH,

    ".comm", COMM,
    ".lcomm", LCOMM,

    "shrl", ARITH,
    "shrw", ARITH,
    "shrb", ARITH,

    "shll", ARITH,
    "shlw", ARITH,
    "shlb", ARITH,

    "imull", IMUL,
    "imulw", IMUL,

    "idivl", IDIV,
    "idivw", IDIV,
    "idivb", IDIV,

    "divl", DIV,
    "divw", DIV,

    "orl", ARITH,
    "orw", ARITH,
    "orb", ARITH,

    "sbbl", ARITH,
    "sbbw", ARITH,
    "sbbb", ARITH,

    "eax", REG,
    "ebx", REG,
    "ecx", REG,
    "edx", REG,
    "esi", REG,
    "edi", REG,
    "ebp", REG,
    "esp", REG,

    "cr0", REG,
    "cr2", REG,
    "cr3", REG,
    "cr4", REG,

    "ax", REG,
    "bx", REG,
    "cx", REG,
    "dx", REG,
    "si", REG,
    "di", REG,
    "bp", REG,
    "sp", REG,

    "ah", REG,
    "al", REG,
    "bh", REG,
    "bl", REG,
    "ch", REG,
    "cl", REG,
    "dh", REG,
    "dl", REG,

    "cs", REG,
    "ds", REG,
    "es", REG,
    "fs", REG,
    "gs", REG,
    "ss", REG,

    "cld", ONEBYTE,
    "cmc", ONEBYTE,
    "std", ONEBYTE,
    "stc", ONEBYTE,
    "ret", ONEBYTE,
    "nop", ONEBYTE,

    "rep", ONEBYTE,
    "repe", ONEBYTE,
    "repne", ONEBYTE,
    "repnz", ONEBYTE,
    "repz", ONEBYTE,

    "cmpsb", ONEBYTE,
    "leave", ONEBYTE,

    "movs", ONEBYTE,
    "movsw", ONEBYTE,
    "movsb", ONEBYTE,
    "aaa", ONEBYTE,
    "aad", ONEBYTE,

    "lods", ONEBYTE,
    "lodsb", ONEBYTE,
    "lodsw", ONEBYTE,
    "lodsl", TRANSLAT,

    "movsl", TRANSLAT,
    "pushal", TRANSLAT,
    "popal", TRANSLAT,

    "outl", ARITH,
    "outw", ARITH,
    "outb", ARITH,
    "inl", ARITH,
    "inb", ARITH,
    "inw", ARITH,

    "btrl", ARITH,
    "btrw", ARITH,
    "btrb", ARITH,

    "cmps", ONEBYTE,
    "cmpsb", ONEBYTE,
    "cmpsw", ONEBYTE,
    "cmpsl", TRANSLAT,

    "scasb", ONEBYTE,
    "scasw", ONEBYTE,
    "scasl", TRANSLAT,

    "adcl", ARITH,
    "adcw", ARITH,
    "adcb", ARITH,

    "btl", ARITH,
    "btw", ARITH,
    "btb", ARITH,

    "cli", ONEBYTE,
    "sti", ONEBYTE,
    "daa", ONEBYTE,
    "clc", ONEBYTE,
    "das", ONEBYTE,

    "int", INT,

    "lds", LSEG,
    "les", LSEG,
    "lfs", LSEG,
    "lgs", LSEG,
    "lss", LSEG,

    "lgdt", LGDT,
    "sgdt", LGDT,
    "lidt", LGDT,
    "sidt", LGDT,
    ".type", UNSUPPORTED,
    ".size", UNSUPPORTED,
    ".weak", UNSUPPORTED,
    ".set", UNSUPPORTED,
    ".4byte", UNSUPPORTED,
    ".ident", IDENT,

    "roll", ARITH,
    "rolw", ARITH,
    "rolb", ARITH,

    "mull", DIV,
    "mulw", DIV,
    "mulb", DIV,

    "st", ST,
    "flds", MATH,
    "fldl", MATH,
    "fdivs", MATH,
    "fdivl", MATH,
    "fstps", MATH,
    "fstpl", MATH,
    "fadds", MATH,
    "faddl", MATH,
    "faddp", MATH,
    "faddrp", MATH,
    "fsubs", MATH,
    "fsubl", MATH,
    "fsubp", MATH,
    "fsubrp", MATH,
    "fmuls", MATH,
    "fmull", MATH,
    "fdivrp", MATH,
    "fstp", MATH,
    "filds", MATH,
    "fildl", MATH
};

/* slower than in math.h but without math instructions */
long pow2(long to)
{
  long i, j;
  j = 1;
  for (i = 0; i < to; i++) j *= 2;
  return j;
}

/* used by the parser */
char tmpstr1[100], tmpstr2[100], tmpstr3[100], tmpstr4[100], tmpstr5[100],
	tmpstr6[100];

/* execute something if there is no `--no-info' switch */
#define D(x) { if (no_info == 0) (x); }

%}

%start lines

%%

lines
	:
        | lines line '\n'	{ line++; }
        ;

line	:
	| _FILE STRING		{ D( fprintf(outfile, "; .file %s\n", $2) ); }
        | IDENT STRING		{ D( fputs("; ident\n", outfile) ); dump_bytes($2, strbuflen); }
        | SEGMENT		{ fprintf(outfile, "[section %s]\n[BITS 32]\n", $1); section = $1; }
        | SECTION ID		{ if ($2[0] == '$') $2[0] = '.'; fprintf(outfile, "[section %s]\n[BITS 32]\n", $2); section = $2; if ($2[0] == '.') $2[0] = '$'; killexternal($2); }
        | SECTION ID ',' STRING	{ if ($2[0] == '$') $2[0] = '.';
        			 if (!warn_sect_attr) { warning("section attributs are ignored"); warning("(only appears one time)"); warn_sect_attr = 1; }
        				fprintf(outfile, "[section %s]\n[BITS 32]\n", $2); section = $2; if ($2[0] == '.') $2[0] = '$'; killexternal($2); }
        | SECTION ID ',' STRING ',' ID
	                        { if ($2[0] == '$') $2[0] = '.';
	                         if (!warn_sect_attr) { warning("section attributs are ignored"); warning("(only appears one time)"); warn_sect_attr = 1; }
        				fprintf(outfile, "[section %s]\n[BITS 32]\n", $2); section = $2; if ($2[0] == '.') $2[0] = '$'; killexternal($2); }

        | ID ':'		{ output_label($1); }
        | ID ':' ONEBYTE	{ output_label($1); fprintf(outfile, "\t%s\n", $3);  }

        | ASCII STRING		{ dump_bytes($2, strbuflen); }
        | SPACE NUMBER		{ fprintf(outfile, "\tresb %ld\n", $2); }

        | GLOBAL ID		{ fprintf(outfile, "\nGLOBAL %s\n", $2); }
        | GLOBAL ID ',' ID	{ fprintf(outfile, "\nGLOBAL %s\nGLOBAL %s\n", $2, $4); }
	| GLOBAL ID ',' ID ',' ID
        			{ fprintf(outfile, "\nGLOBAL %s\nGLOBAL %s\nGLOBAL %s\n", $2, $4, $6); }

        | _LONG numlist		{ fprintf(outfile, "\tdd %s\n", $2); }
        | _LONG ID		{ fprintf(outfile, "\tdd %s+0x%lx\n", $2, baseaddr); }

        | _WORD numlist		{ fprintf(outfile, "\tdw %s\n", $2); }
        | _WORD ID		{ fprintf(outfile, "\tdw %s+0x%lx\n", $2, baseaddr); }

        | _BYTE numlist		{ fprintf(outfile, "\tdb %s\n", $2); }
        | _BYTE ID		{ fprintf(outfile, "\tdb %s+0x%lx\n", $2, baseaddr); }

        | _VERSION STRING	{ D( fprintf(outfile, "; version %s\n", $2) ); }

        | P2ALIGN NUMBER	{ D( fprintf(outfile, "; p2align %ld\n", $2) );
        				fprintf(outfile, "\talign %ld\n", pow2($2)); }
        | ALIGN NUMBER		{ fprintf(outfile, "\talign %ld\n", $2); }
        | ALIGN NUMBER ',' NUMBER
        			{ fprintf(outfile, "\talign %ld, nop\n", $2);
                                	if ($4 != 0x90) {
                                		warning("strange opcode after align (only NOPs are supported)");
                                		fprintf(outfile, "\talign %ld, nop\n", $2);
                                        }
                                }
	| ALIGN NUMBER ',' ONEBYTE
        			{ fprintf(outfile, "\talign %ld, %s\n", $2, $4); warning("this align instruction might not be supported by nasm"); }

        | COMM ID ',' NUMBER	{ struct symbol* s = sym_lookup($2);
				  output_comm($2, $4, 0, ( (s!=NULL) && (s->islocal) ) ); }
        | COMM ID ',' NUMBER ',' NUMBER
        			{ struct symbol* s = sym_lookup($2);
                                  output_comm($2, $4, $6, ( (s!=NULL) && (s->islocal) ) ); }

        | LCOMM ID ',' NUMBER	{ output_comm($2, $4, 0, 1); }

	| LOCAL ID		{ struct symbol*s = addexternal($2);
				  s->isextern = 0; s->islocal = 1; }

        | PUSH REG		{ fprintf(outfile, "\t%s %s %s\n", op($1), op_size($1), $2); }
        | PUSH varptr		{ fprintf(outfile, "\t%s %s %s\n", op($1), op_size($1), $2); }
        | PUSH memref		{ fprintf(outfile, "\t%s %s %s\n", op($1), op_size($1), $2); }
        | PUSH memptr		{ fprintf(outfile, "\t%s %s %s\n", op($1), op_size($1), $2); }

        | ARITH REG ',' REG	{ fprintf(outfile, "\t%s %s %s, %s\n", op($1), op_size($1), $4, $2); }
        | ARITH REG ',' memref
        			{ fprintf(outfile, "\t%s %s %s, %s\n", op($1), op_size($1), $4, $2); }
        | ARITH memref ',' REG
	       			{ fprintf(outfile, "\t%s %s %s, %s\n", op($1), op_size($1), $4, $2); }

        | ARITH REG ',' memptr	{ fprintf(outfile, "\t%s %s %s, %s\n", op($1), op_size($1), $4, $2); }
        | ARITH memptr ',' REG	{ fprintf(outfile, "\t%s %s %s, %s\n", op($1), op_size($1), $4, $2); }

        | ARITH varptr ',' REG	{ fprintf(outfile, "\t%s %s %s, %s\n", op($1), op_size($1), $4, $2); }
        | ARITH varptr ',' memref
        			{ fprintf(outfile, "\t%s %s %s, %s\n", op($1), op_size($1), $4, $2); }
        | ARITH varptr ',' memptr
				{ fprintf(outfile, "\t%s %s %s, %s\n", op($1), op_size($1), $4, $2); }

        | INC REG		{ fprintf(outfile, "\t%s %s %s\n", op($1), op_size($1), $2); }
        | INC memref		{ fprintf(outfile, "\t%s %s %s\n", op($1), op_size($1), $2); }
        | INC memptr		{ fprintf(outfile, "\t%s %s %s\n", op($1), op_size($1), $2); }

        | LEA memref ',' REG
        			{ fprintf(outfile, "\tlea %s %s, %s\n", op_size($1), $4, $2); }
        | LEA memptr ',' REG	{ fprintf(outfile, "\tlea %s %s, %s\n", op_size($1), $4, $2); }

        | CALL ID		{ fprintf(outfile, "\tcall %s\n", $2); }
        | CALL '*' REG		{ fprintf(outfile, "\tcall %s\n", $3); }

	| JMP ID		{ fprintf(outfile, "\t%s%s %s\n", $1, is_near($1), $2); }
        | JMP memref		{ fprintf(outfile, "\t%s%s %s\n", $1, is_near($1), $2); }
        | JMP '*' REG		{ fprintf(outfile, "\t%s%s %s\n", $1, is_near($1), $3); }
        | JMP '*' ID		{ fprintf(outfile, "\t%s%s %s\n", $1, is_near($1), $3); }

        | IMUL REG		{ fprintf(outfile, "\timul %s %s\n", op_size($1), $2); }
        | IMUL REG ',' REG	{ fprintf(outfile, "\timul %s %s, %s\n", op_size($1), $4, $2); }
        | IMUL memref ',' REG	{ fprintf(outfile, "\timul %s %s, %s\n", op_size($1), $4, $2); }
        | IMUL memptr ',' REG	{ fprintf(outfile, "\timul %s %s, %s\n", op_size($1), $4, $2); }

        | IDIV memref		{ fprintf(outfile, "\tidiv %s %s\n", op_size($1), $2); }
        | IDIV REG		{ fprintf(outfile, "\tidiv %s %s\n", op_size($1), $2); }
        | IDIV memptr		{ fprintf(outfile, "\tidiv %s %s\n", op_size($1), $2); }

        | DIV memref		{ fprintf(outfile, "\t%s %s %s\n", op($1), op_size($1), $2); }
        | DIV REG		{ fprintf(outfile, "\t%s %s %s\n", op($1), op_size($1), $2); }

        | MOV_SD arg ',' arg	{ mov_sd($1, $4, $2); }

        | NEG REG		{ fprintf(outfile, "\t%s %s %s\n", op($1), op_size($1), $2); }
        | NEG memref		{ fprintf(outfile, "\t%s %s %s\n", op($1), op_size($1), $2); }

        | SET REG		{ fprintf(outfile, "\t%s %s\n", $1, $2); }

        | INT NUMBER		{ fprintf(outfile, "\tint 0x%lx\n", $2); }

        | LSEG ID ',' REG	{ fprintf(outfile, "\t%s %s, %s\n", $1, $4, $2); }

        | LGDT ID		{ fprintf(outfile, "\t%s [%s]\n", $1, $2); }

        | ONEBYTE		{ fprintf(outfile, "\t%s\n", $1); }

        | TRANSLAT		{ fprintf(outfile, "\t%s\n", translate_instr($1)); }

        | MATH arg              { fprintf(outfile, "\t%s %s\n", translate_math($1), $2); }
	| MATH math_reg		{ fprintf(outfile, "\t%s %s\n", translate_math($1), $2); }
        | MATH math_reg ',' math_reg
                                { fprintf(outfile, "\t%s %s, %s\n", translate_math($1), $4, $2); }

        | UNSUPPORTED		{ ; }

	| error
        ;

arg	: REG			{ $$ = $1; }
	| memptr		{ $$ = $1; }
        | memref		{ $$ = $1; }
        | varptr		{ $$ = $1; }
        ;

numlist	: NUMBER		{ $$ = signed_num($1); }
	| numlist ',' NUMBER	{ sprintf(tmpstr5, "%s, 0x%lx", $1, $3); $$ = tmpstr5; }
        ;

memptr	: ID			{ sprintf(tmpstr1, "[%s+0x%lx]", $1, baseaddr); $$ = tmpstr1; }
	| ID '+' NUMBER		{ sprintf(tmpstr1, "[%s+%ld+0x%lx]", $1, $3, baseaddr); $$ = tmpstr1; }
        | ID NUMBER		{ sprintf(tmpstr1, "[%s%ld+0x%lx]", $1, $2, baseaddr); $$ = tmpstr1;
        				if ($2>0) yyerror("expression error"); }
        ;

memref	: memref1               { sprintf(tmpstr6, "[%s]", $1); $$ = tmpstr6; }
	| REG ':' memref1	{ sprintf(tmpstr6, "[%s:%s]", $1, $3); $$ = tmpstr6; }
        ;

memref1	: '(' REG ')'		{ sprintf(tmpstr2, "%s", $2); $$ = tmpstr2;}
        | '(' REG ',' REG ')'	{ sprintf(tmpstr2, "%s + %s", $2, $4); $$ = tmpstr2; }
        | '(' REG ',' REG ',' scale ')'
        			{ sprintf(tmpstr2, "%s + %s*%s", $2, $4, $6); $$ = tmpstr2; }
	| offset '(' REG ')'	{ sprintf(tmpstr2, "%s%s", $3, $1); $$ = tmpstr2; }
        | offset '(' REG ',' REG ')'
        			{ sprintf(tmpstr2, "%s + %s %s", $3, $5, $1); $$ = tmpstr2; }
        | offset '(' REG ',' REG ',' scale ')'
        			{ sprintf(tmpstr2, "%s + %s*%s %s", $3, $5, $7, $1); $$ = tmpstr2; }
        | offset '(' ',' REG ')'
        			{ sprintf(tmpstr2, "%s %s", $4, $1); $$ = tmpstr2; }
        | offset '(' ',' REG ',' scale ')'
        			{ sprintf(tmpstr2, "%s*%s %s", $4, $6, $1); $$ = tmpstr2; }
        ;

varptr	: '$' NUMBER		{ $$ = signed_num($2); }
	| '$' ID		{ sprintf(tmpstr3, "%s+0x%lx", $2, baseaddr); $$ = tmpstr3; }
	| '$' ID NUMBER		{ sprintf(tmpstr3, "%s%ld+0x%lx", $2, $3, baseaddr); $$ = tmpstr3;
        				if ($3>0) yyerror("expression error"); }
        | '$' ID '+' NUMBER	{ sprintf(tmpstr3, "%s+%ld+0x%lx", $2, $4, baseaddr); $$ = tmpstr3; }
        ;

scale	: REG			{ $$ = $1; }
	| NUMBER		{ $$ = signed_num($1); }
        ;

offset	: NUMBER		{ $$ = signed_num($1); }
	| ID			{ strcpy(tmpstr4, "+ "); strcat(tmpstr4, $1); $$ = tmpstr4;}
        | ID NUMBER		{ strcpy(tmpstr4, "+ "); strcat(tmpstr4, $1); strcat(tmpstr4, signed_num($2)); $$ = tmpstr4; }
        | '*' ID		{ strcpy(tmpstr4, "+ "); strcat(tmpstr4, $2); $$ = tmpstr4; }
        ;

math_reg: ST                    { $$ = "st"; }
        | ST '(' NUMBER ')'     { sprintf(tmpstr4, "st%d", $3); $$ = tmpstr4; }
        ;
%%

/* output an error, exit if more than 15 errors */
void yyerror(char *s)
{
  fprintf(stderr, "%s:%ld: %s\n", filename, line, s);
  fprintf(outfile, ";* %s at line %ld *\n", s, line);
  errors++;
  if (errors>15) {
    fprintf(stderr, "Too many errors\n");
    fclose(infile);
    fclose(outfile);
    exit(1);
  }
}

/* output a warning */
void warning(char *s)
{
  fprintf(stderr, "%s:%ld: Warning: %s\n", filename, line, s);
}

/* function used for token sorting */
static inline int tok_cmp (const void *e1, const void *e2)
{
  return strcmp (((struct tok *)e1)->name, ((struct tok *)e2)->name);
}

/* THE lexer */
int yylex(void)
{
  static int was_percent = 0;
  int c, oldc, i;
  struct tok *token, t;

  do {
  	c = getc(infile);
  } while (c == ' ' || c == '\t');

  switch (c) {
  	case EOF: return 0;

        case 'a' ... 'z':
        case 'A' ... 'Z':
        case '.':
        case '@':
        case '_':
        case '%':
        	if (c != '%') { ungetc(c, infile); was_percent = 0; } else was_percent = 1;
                fscanf(infile, "%[a-zA-Z0-9_$.@]", strbuf);

                t.name = strbuf;

		/* bsearch is quicker */
                token = bsearch(&t, tokens, sizeof(tokens) / sizeof(tokens[0]),
                	sizeof(tokens[0]), tok_cmp);

                if (token) {
                        yylval.str = strdup(token->name);
                        if (token->token == UNSUPPORTED || token->token == UNSUP_2) {
                        	char tmp[100];
                                if (token->token == UNSUPPORTED) {
	                                sprintf(tmp, "unsupported keyword `%s'", token->name);
        	                	warning(tmp);
                	                warning("(only appears one time)");
	                                token->token = UNSUP_2;
                                }
				/* eat line */
                                while ((c = getc(infile)) != EOF && c != '\n') ;
                                ungetc(c, infile);
                                return UNSUPPORTED;
                        }
                        		/* not a real REG */
                        if ((token->token == REG || token->token == ST) && (was_percent == 0) ) {
                        	yylval.str = strdup (strbuf);
                                addexternal(strbuf);
				printf("%s\n", strbuf);
                                return ID;
			}

			return token->token;
                }
                if (strbuf[0] == '.') strbuf[0] = '$';
                yylval.str = strdup(strbuf);
                addexternal(strbuf);	/* add it to the symbol table */
                return ID;

	case '0' ... '9':
        	ungetc(c, infile);
                fscanf(infile, "%li", &yylval.num);
                return NUMBER;

        case '-':
        	ungetc(c, infile);
                fscanf(infile, "%ld", &yylval.num);
                return NUMBER;

        case '"':	/* a string */
        case '\'':
        	oldc = c;
                i = 0;
                while (1) {
                	c = getc(infile);
                        if (c == oldc) {
                                strbuflen = i;
                                strbuf[i] = 0;
                                yylval.str = strdup(strbuf);
                                return STRING;
                        }
                        switch (c) {
                        	case '\\':
                                	switch (c = getc(infile)) {
                                        	case '0': strbuf[i++] = 0; break;
                                                case 'n': strbuf[i++] = '\n'; break;
                                                case 't': strbuf[i++] = '\t'; break;
                                                default:
                                                	if (c >= '0' && c<= '9') {
	                                                	ungetc(c, infile);

        	                                                fscanf(infile, "%i", &c);
                	                                        if (c == 12) c = 10;
                        	                                else
                                	                        if (c == 11) c = 9;

                                        	                strbuf[i++] = c;
                                                	        break;
                                                        }
                                                        else strbuf[i++] = c;
                                        }
	                                break;
                                default: strbuf[i++] = c; break;
                        }
                }
                abort();
        case '/':
                c = ';';
        	while (c != '\n') {
                	if (no_info == 0) putc(c, outfile);
                        c = getc(infile);
                }
                c = '\n';
                if (no_info == 0) putc(c, outfile);
                return '\n';
	case ';':
        case '#':
        	while ((c = getc(infile))!= '\n') ;
                c = '\n';

	default:
        	return c;
  }
}

/* output a string to outfile */
void dump_bytes(char *s, int len)
{
#define LINE_LENGTH 60

	long i, j, counter, lines;
        int c, quoted;

        counter = 0;
        lines = len / LINE_LENGTH;
        if (len>0) {
                for (j = 0; j < lines; j++) {
                        fputs("\tdb ", outfile);
                        quoted = 0;
                        for (i = counter; i < counter + LINE_LENGTH; i++) {
                                c = (unsigned char) s[i];
                                if (c>31 && c<128 && c!= '"') {
                                	if (!quoted) {
                                                if (i>counter) fputc(',', outfile);
                                                fputc('"', outfile);
                                        }
                                        fputc(c, outfile);
                                        quoted = 1;
                                }
                                else {
                                        if (quoted) fputc('"', outfile);
                                        if (i>counter) fputc(',', outfile);
                                        quoted = 0;
                                        fprintf(outfile, "%d", c);
                                }
                        }
                        if (quoted) fputc('"', outfile);
                        fputc('\n', outfile);
                        counter += LINE_LENGTH;
                }
                fputs("\tdb ", outfile);
                quoted = 0;
                for (i = counter; i < len; i++) {
                        c = (unsigned char) s[i];
                        if (c > 31 && c<128 && c!= '"') {
                                if (!quoted) {
                                        if (i>counter) fputc(',', outfile);
                                        fputc('"', outfile);
                                }
                                fputc(c, outfile);
                                quoted = 1;
                        }
                        else {
                                if (quoted) fputc('"', outfile);
                                if (i>counter) fputc(',', outfile);
                                quoted = 0;
                                fprintf(outfile, "%d", c);
                        }
                }
                if (quoted) fputc('"', outfile);
                fputc('\n', outfile);
        }

#undef LINE_LENGTH
}

/* output a common symbol */
void output_comm(char *id, long len, int align, int lcomm)
{
        fprintf(outfile, "[section .bss]\n");
        if (lcomm == 0) fprintf(outfile, "GLOBAL %s\n", id);
        output_label(id);
        if (align!=0) fprintf(outfile, "\talign %d\n", align);
        fprintf(outfile, "\tresb %ld\n[section %s]\n", len, section);
}

int in_text(void)
{
	 if (section!=NULL && strstr(section, "text")!= NULL) return 1;
         	else return 0;
}

int in_data(void)
{
		/* can be ".rodata" or ".data" */
	if (section!=NULL && (strstr(section, "data")!= NULL || strstr(section, "bss")!= NULL)) return 1;
        	else return 0;
}

void output_label(char *id)
{
	int put_label = 1;
       	if ((strstr(id, "gcc2_compiled")!=NULL || strstr(id, "gnu_compiled")!=NULL) && no_info==1) put_label = 0;

	D( fprintf(outfile, "; (label at line %ld)\n", line) );
        if (put_label==1) {
               	if (opt==1) { /* -O1 switch */
               		if (in_data()) fprintf(outfile, "\talign 4\n");
                        else
                        if (in_text()) fprintf(outfile, "\talign 2, nop\n");
                }
                else
                if (opt==2) { /* -O2 switch */
                	if (in_data()) fprintf(outfile, "\talign 4\n");
                        else
                        if (in_text()) fprintf(outfile, "\talign 4, nop\n");
                }
              	fprintf(outfile, "%s:\n", id);
        }
	killexternal(id);
}

void mov_sd(const char *mov, const char *arg1, const char *arg2)
{
	int src, dst;
        char *s, *d;
       	src = mov[4]; dst = mov[5];
       	if (src == 'l') s = "dword";
        else
        if (src == 'w') s = "word";
        else
        if (src == 'b') s = "byte";
        else
        { yyerror("mov?? unknown"); s = "[error]"; }

        if (dst == 'l') d = "dword";
        else
        if (dst == 'w') d = "word";
        else
        if (dst == 'b') d = "byte";
        else
        { yyerror("mov?? unknown"); d = "[error]"; }

	if (strncmp(mov, "movs", 4) == 0)
                fprintf(outfile, "\tmovsx %s %s, %s %s\n",
                	d, arg1, s, arg2);
        else
        if (strncmp(mov, "movz", 4) == 0)
        	fprintf(outfile, "\tmovzx %s %s, %s %s\n",
                        d, arg1, s, arg2);
        else yyerror("mov?? unknown");
}

/* look for a symbol */
struct symbol *sym_lookup(char *name) {
	int i;
        struct symbol *s;

        i = hash(name);
        for (s = hashtab[i]; s; s = s->next) {
        	if (!strcmp(s->name, name))
                	return s;
        }
        return (struct symbol *)NULL;
}

/* add a symbol to the table */
struct symbol* addexternal(char *name)
{
	int i;
	struct symbol* s = sym_lookup(name);
        if (s == NULL) {	/* not found, add it */
        	i = hash(name);
                s = (struct symbol *) xmalloc(sizeof (struct symbol));
                s->name = (char *) xmalloc(strlen(name) + 1);
                strcpy(s->name, name);
                s->isextern = 1;
		s->islocal = 0; 
                s->next = hashtab[i];
                hashtab[i] = s;
                return s;
        }
}

/* set a symbol to defined state */
void killexternal(char *name)
{
        struct symbol *s = sym_lookup(name);
        if (s == NULL) s = addexternal(name);

        s->isextern = 0;
        /*free(s->name);*/
}

/* open the files, and write the header */
void open_file(char *inf, char *outf)
{
	char *tmp;

        strcpy(filename, inf);

        if (!outf) {
  	      	tmp = strrchr(inf, '.');
        	if (tmp) {
        		strcpy(tmp, ".asm");
                	strcpy(outname, inf);
        	}
        	else
        	{
       		 	strcpy(outname, inf);
                	strcat(outname, ".asm");
        	}
        } else strcpy(outname, outf);

        infile = fopen(filename, "r");
        if (!infile) fatal("unable to open file `%s'", filename);

        outfile = fopen(outname, "w+");
        if (!outfile) fatal("unable to create file `%s'", outname);

        fprintf(outfile, "; File generated with A2I "VERSION" (by Pascal Lacroix)\n");
        fprintf(outfile, "; %s\n", cmdline);
        fprintf(outfile, "; Warning: Use at your own risks, no warranties\n\n");
        fprintf(outfile, "[section .text USE32]\n");

        fprintf(outfile, "\n");
}

void usage(void)
{
	fputs("A2I version "VERSION" by Pascal Lacroix (placr@mygale.org)\n", stderr);
        fprintf(stderr, "%s [options...] filename.s\n", program_name);
	fputs("Options\n", stderr);
        fputs(" -B baseaddr     set base address of your program (experimental)\n", stderr);
        fputs(" -O1             align data to 4 and code to 2\n", stderr);
        fputs(" -O2             align all to 4\n", stderr);
        fputs(" -o name         set output file name\n", stderr);
        fputs(" --no-lines      suppress extra info in file\n", stderr);
}

int main(int argc, char **argv)
{
	long j, i;

        char *outf, *inf;

        outf = (char *)NULL;

        program_name = strdup(argv[0]);

  	if (argc == 1) {
    		fprintf(stderr, "Usage: %s [options...] filename.s\n", program_name);
                fprintf(stderr, "type `a2i --help' for more information\n");
                free(program_name);
                exit(1);
 	}
        else {
        	strcpy(cmdline, "a2i");
        	for (i = 1; i < argc; i++) strcat(cmdline, " "), strcat(cmdline, argv[i]);

        	if (!strcmp(argv[1], "--help")) { usage(); exit(1); }
                else
                {
                	for (i = 1; i < argc; i++) {
                                if (argv[i][0] != '-') {
                                	inf = argv[i];
                                }
                                else {
                                	switch (argv[i][1]) {
						case 'B':
                                                	if (i+1 == argc) fatal("adress missing after -B");
                                                        if (!strstr("0x", argv[i+1])) baseaddr = strtol(argv[i+1], NULL, 16);
                                                        	else baseaddr = atoi(argv[i+1]);
                                                        i++;
                                                        break;
                                                case 'o':
                                                	if (i+1 == argc) fatal("output name missing after -o");
                                                        outf = argv[i+1];
                                                        i++;
						case 'O':
                                                	if (argv[i][2]==0) fatal("you must specify -O1 or -O2");
                                                        opt = (unsigned char) atoi(argv[i]+2);
                                                        if (opt>2) fatal("you must specify -O1 or -O2");
							break;
                                                case '-':
                                                	if (!strcmp(argv[i], "--no-info")) no_info = 1;
                                                        break;
                                               default:
                                               		fatal("invalid options `%s'", argv[i]);
                                        }
                                }
	                }
                }
        }

        free(program_name);

        if (inf == 0 || strlen(inf) == 0) fatal("no input file given");

        if ((outf != 0) && !strcmp(inf, outf))
        	fatal("input file and output file are the same");

	qsort(tokens, sizeof(tokens) / sizeof(tokens[0]), sizeof(tokens[0]), tok_cmp);

        open_file(inf, outf);
  	yyparse();

  	fprintf(outfile, "\n\n;[-- Externals --]\n");

  	j = 0;
        for (i = 0; i < HASH_SIZE; i++) {
		struct symbol *s = hashtab[i];
               	while (s!= NULL) {
                       	if (s->isextern == 1)
                       		fprintf(outfile, "extern %s\n", s->name), j++;
		s = s->next;
                }
        }
	fprintf(outfile, "\n; %ld externals\n", j);

	printf("%s: %ld lines, %ld externals\n", outname, line, j);

  	fclose(infile);
  	fclose(outfile);

  	return errors;
}

void fatal (str, arg)
     char *str, *arg;
{
  usage();
  fputs("Fatal: ", stderr);
  fprintf (stderr, str, arg);
  fprintf (stderr, "\n");
  exit (1);
}

