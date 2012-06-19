/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "a2i.y"

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



/* Line 268 of yacc.c  */
#line 189 "a2i.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     STRING = 259,
     SEGMENT = 260,
     REG = 261,
     ONEBYTE = 262,
     STR = 263,
     JMP = 264,
     SET = 265,
     ARITH = 266,
     LEA = 267,
     INC = 268,
     PUSH = 269,
     IMUL = 270,
     IDIV = 271,
     TRANSLAT = 272,
     NEG = 273,
     DIV = 274,
     LSEG = 275,
     LGDT = 276,
     MOV_SD = 277,
     _FILE = 278,
     ASCII = 279,
     GLOBAL = 280,
     _LONG = 281,
     _WORD = 282,
     _BYTE = 283,
     IDENT = 284,
     ALIGN = 285,
     P2ALIGN = 286,
     COMM = 287,
     LCOMM = 288,
     SPACE = 289,
     CALL = 290,
     INT = 291,
     _VERSION = 292,
     SECTION = 293,
     UNSUPPORTED = 294,
     UNSUP_2 = 295,
     LOCAL = 296,
     ST = 297,
     MATH = 298,
     NUMBER = 299
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 118 "a2i.y"

  char *str;
  long type;
  long num;



/* Line 293 of yacc.c  */
#line 277 "a2i.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 343 of yacc.c  */
#line 137 "a2i.y"


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



/* Line 343 of yacc.c  */
#line 717 "a2i.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    52,     2,     2,     2,
      50,    51,    48,    49,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,     9,    12,    15,    17,    20,
      25,    32,    35,    39,    42,    45,    48,    53,    60,    63,
      66,    69,    72,    75,    78,    81,    84,    87,    92,    97,
     102,   109,   114,   117,   120,   123,   126,   129,   134,   139,
     144,   149,   154,   159,   164,   169,   172,   175,   178,   183,
     188,   191,   195,   198,   201,   205,   209,   212,   217,   222,
     227,   230,   233,   236,   239,   242,   247,   250,   253,   256,
     259,   264,   267,   269,   271,   274,   277,   282,   284,   286,
     288,   290,   292,   294,   296,   300,   302,   306,   309,   311,
     315,   319,   325,   333,   338,   345,   354,   360,   368,   371,
     374,   378,   383,   385,   387,   389,   391,   394,   397,   399
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    -1,    54,    55,    45,    -1,    -1,    23,
       4,    -1,    29,     4,    -1,     5,    -1,    38,     3,    -1,
      38,     3,    46,     4,    -1,    38,     3,    46,     4,    46,
       3,    -1,     3,    47,    -1,     3,    47,     7,    -1,    24,
       4,    -1,    34,    44,    -1,    25,     3,    -1,    25,     3,
      46,     3,    -1,    25,     3,    46,     3,    46,     3,    -1,
      26,    57,    -1,    26,     3,    -1,    27,    57,    -1,    27,
       3,    -1,    28,    57,    -1,    28,     3,    -1,    37,     4,
      -1,    31,    44,    -1,    30,    44,    -1,    30,    44,    46,
      44,    -1,    30,    44,    46,     7,    -1,    32,     3,    46,
      44,    -1,    32,     3,    46,    44,    46,    44,    -1,    33,
       3,    46,    44,    -1,    41,     3,    -1,    14,     6,    -1,
      14,    61,    -1,    14,    59,    -1,    14,    58,    -1,    11,
       6,    46,     6,    -1,    11,     6,    46,    59,    -1,    11,
      59,    46,     6,    -1,    11,     6,    46,    58,    -1,    11,
      58,    46,     6,    -1,    11,    61,    46,     6,    -1,    11,
      61,    46,    59,    -1,    11,    61,    46,    58,    -1,    13,
       6,    -1,    13,    59,    -1,    13,    58,    -1,    12,    59,
      46,     6,    -1,    12,    58,    46,     6,    -1,    35,     3,
      -1,    35,    48,     6,    -1,     9,     3,    -1,     9,    59,
      -1,     9,    48,     6,    -1,     9,    48,     3,    -1,    15,
       6,    -1,    15,     6,    46,     6,    -1,    15,    59,    46,
       6,    -1,    15,    58,    46,     6,    -1,    16,    59,    -1,
      16,     6,    -1,    16,    58,    -1,    19,    59,    -1,    19,
       6,    -1,    22,    56,    46,    56,    -1,    18,     6,    -1,
      18,    59,    -1,    10,     6,    -1,    36,    44,    -1,    20,
       3,    46,     6,    -1,    21,     3,    -1,     7,    -1,    17,
      -1,    43,    56,    -1,    43,    64,    -1,    43,    64,    46,
      64,    -1,    39,    -1,     1,    -1,     6,    -1,    58,    -1,
      59,    -1,    61,    -1,    44,    -1,    57,    46,    44,    -1,
       3,    -1,     3,    49,    44,    -1,     3,    44,    -1,    60,
      -1,     6,    47,    60,    -1,    50,     6,    51,    -1,    50,
       6,    46,     6,    51,    -1,    50,     6,    46,     6,    46,
      62,    51,    -1,    63,    50,     6,    51,    -1,    63,    50,
       6,    46,     6,    51,    -1,    63,    50,     6,    46,     6,
      46,    62,    51,    -1,    63,    50,    46,     6,    51,    -1,
      63,    50,    46,     6,    46,    62,    51,    -1,    52,    44,
      -1,    52,     3,    -1,    52,     3,    44,    -1,    52,     3,
      49,    44,    -1,     6,    -1,    44,    -1,    44,    -1,     3,
      -1,     3,    44,    -1,    48,     3,    -1,    42,    -1,    42,
      50,    44,    51,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   568,   568,   570,   573,   574,   575,   576,   577,   578,
     581,   586,   587,   589,   590,   592,   593,   594,   597,   598,
     600,   601,   603,   604,   606,   608,   610,   611,   618,   621,
     623,   627,   629,   632,   633,   634,   635,   637,   638,   640,
     643,   644,   646,   647,   649,   652,   653,   654,   656,   658,
     660,   661,   663,   664,   665,   666,   668,   669,   670,   671,
     673,   674,   675,   677,   678,   680,   682,   683,   685,   687,
     689,   691,   693,   695,   697,   698,   699,   702,   704,   707,
     708,   709,   710,   713,   714,   717,   718,   719,   723,   724,
     727,   728,   729,   731,   732,   734,   736,   738,   742,   743,
     744,   746,   749,   750,   753,   754,   755,   756,   759,   760
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "SEGMENT", "REG",
  "ONEBYTE", "STR", "JMP", "SET", "ARITH", "LEA", "INC", "PUSH", "IMUL",
  "IDIV", "TRANSLAT", "NEG", "DIV", "LSEG", "LGDT", "MOV_SD", "_FILE",
  "ASCII", "GLOBAL", "_LONG", "_WORD", "_BYTE", "IDENT", "ALIGN",
  "P2ALIGN", "COMM", "LCOMM", "SPACE", "CALL", "INT", "_VERSION",
  "SECTION", "UNSUPPORTED", "UNSUP_2", "LOCAL", "ST", "MATH", "NUMBER",
  "'\\n'", "','", "':'", "'*'", "'+'", "'('", "')'", "'$'", "$accept",
  "lines", "line", "arg", "numlist", "memptr", "memref", "memref1",
  "varptr", "scale", "offset", "math_reg", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    10,    44,    58,    42,    43,
      40,    41,    36
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      56,    56,    56,    57,    57,    58,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    61,    62,    62,    63,    63,    63,    63,    64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     2,     2,     1,     2,     4,
       6,     2,     3,     2,     2,     2,     4,     6,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     4,     4,     4,
       6,     4,     2,     2,     2,     2,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     2,     2,     2,     4,     4,
       2,     3,     2,     2,     3,     3,     2,     4,     4,     4,
       2,     2,     2,     2,     2,     4,     2,     2,     2,     2,
       4,     2,     1,     1,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     2,     1,     3,
       3,     5,     7,     4,     6,     8,     5,     7,     2,     2,
       3,     4,     1,     1,     1,     1,     2,     2,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    78,     0,     7,    72,     0,     0,     0,
       0,     0,     0,     0,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,     0,
       0,    11,    52,     0,   104,     0,     0,    53,    88,     0,
      68,    85,     0,     0,     0,     0,     0,     0,     0,     0,
      45,    47,    46,    33,    36,    35,    34,    56,     0,     0,
      61,    62,    60,   105,    66,    67,    64,    63,     0,    71,
      79,     0,    80,    81,    82,     5,    13,    15,    19,    83,
      18,    21,    20,    23,    22,     6,    26,    25,     0,     0,
      14,    50,     0,    69,    24,     8,    32,   108,    74,    75,
       3,    12,   106,     0,    55,    54,     0,     0,    87,     0,
       0,   107,    99,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,     0,    89,     0,    90,     0,     0,    86,    37,
      40,    38,   100,     0,    41,    39,    42,    44,    43,    49,
      48,    57,    59,    58,    70,    65,    16,    84,    28,    27,
      29,    31,     9,     0,    76,     0,     0,    93,     0,   101,
       0,     0,     0,   109,     0,    91,     0,     0,    96,    17,
      30,    10,   102,   103,     0,     0,    94,     0,    92,     0,
      97,    95
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    40,    81,    90,    82,    83,    48,    84,   194,
      49,   109
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -164
static const yytype_int16 yypact[] =
{
    -164,   158,  -164,  -164,   -14,  -164,  -164,    34,    16,    15,
      35,    42,    24,    43,    54,  -164,    91,   100,    39,    41,
      25,    50,    95,   113,    26,    44,    52,   116,    73,    79,
     123,   131,    96,     5,   101,   142,   144,  -164,   148,    14,
     107,   147,   -25,   110,  -164,    20,   160,  -164,  -164,   114,
    -164,    80,   -11,   195,    68,   154,   156,   159,   161,   162,
     110,  -164,  -164,   110,  -164,  -164,  -164,     4,   163,   164,
     110,  -164,  -164,   167,   110,  -164,   110,  -164,   166,  -164,
     110,   168,  -164,  -164,  -164,  -164,  -164,   169,  -164,  -164,
     170,  -164,   170,  -164,   170,  -164,   171,  -164,   172,   173,
    -164,  -164,   198,  -164,  -164,   174,  -164,   175,  -164,   176,
    -164,  -164,  -164,    77,   177,  -164,   -12,    55,   178,   179,
     105,  -164,    56,  -164,   200,   207,   112,   215,   218,   220,
     223,   224,   225,    25,   229,   189,    45,   190,   191,  -164,
     232,   193,   196,  -164,   233,  -164,    63,   234,  -164,   110,
    -164,  -164,  -164,   197,  -164,  -164,   110,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,   199,  -164,  -164,  -164,
     201,  -164,   202,   192,  -164,    85,   236,  -164,    86,  -164,
     241,   205,   243,  -164,    37,  -164,    87,    37,  -164,  -164,
    -164,  -164,  -164,  -164,   203,    37,  -164,   204,  -164,   206,
    -164,  -164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,   -38,   117,     2,    -7,   137,    98,  -163,
    -164,   109
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
      47,   108,    56,    59,    62,    65,    69,    72,   101,    75,
      77,    55,    58,    61,    64,    68,    71,    51,    51,   112,
      80,    52,    50,   114,   197,  -105,   115,    51,    51,    88,
      63,    80,   199,    41,   144,   120,   113,    42,    51,   145,
      43,    43,    78,   192,    79,    51,    51,    91,    60,    67,
     129,   113,   168,   102,    85,    93,   107,    51,    44,    44,
      70,   146,    53,    53,    46,    46,    54,    54,    44,    44,
      89,   122,    53,    53,    46,    46,    54,    54,    44,    44,
      73,   193,    45,    53,    46,    46,    44,    44,    89,   169,
      53,    53,    46,    46,    73,   165,    89,    74,    44,    86,
     152,   147,    53,    73,    46,   153,    76,    57,    51,   176,
      66,   149,   123,   151,   177,    51,    87,    96,   156,   158,
      95,    44,   150,    97,   118,    53,    98,    46,   157,   119,
    -105,   184,   187,   195,    99,    44,   185,   188,   196,    53,
     100,    46,    92,    94,    44,   103,   104,   105,    53,    44,
      46,   106,   110,    53,   111,    46,    44,   113,     2,     3,
      53,     4,    46,     5,   117,     6,   116,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,   121,    38,
     124,    39,   125,    -4,   139,   126,   154,   127,   128,   130,
     131,   112,   132,   155,   133,   134,   135,   136,   137,   138,
     140,   159,   142,   148,   160,   141,   161,  -107,  -106,   162,
     163,   164,   166,   167,   170,   171,   172,   173,   107,   175,
     178,   179,   186,   183,   189,   180,   191,   181,   182,   190,
     143,   174,     0,     0,   198,   200,     0,   201
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-164))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       7,    39,     9,    10,    11,    12,    13,    14,     3,    16,
      17,     9,    10,    11,    12,    13,    14,     3,     3,    44,
       6,     6,     6,     3,   187,    50,     6,     3,     3,     3,
       6,     6,   195,    47,    46,    46,    47,     3,     3,    51,
       6,     6,     3,     6,     3,     3,     3,     3,     6,     6,
      46,    47,     7,    48,     4,     3,    42,     3,    44,    44,
       6,     6,    48,    48,    50,    50,    52,    52,    44,    44,
      44,     3,    48,    48,    50,    50,    52,    52,    44,    44,
       3,    44,    48,    48,    50,    50,    44,    44,    44,    44,
      48,    48,    50,    50,     3,   133,    44,     6,    44,     4,
      44,    46,    48,     3,    50,    49,     6,     9,     3,    46,
      12,     6,    44,   120,    51,     3,     3,    44,     6,   126,
       4,    44,   120,    44,    44,    48,     3,    50,   126,    49,
      50,    46,    46,    46,     3,    44,    51,    51,    51,    48,
      44,    50,    25,    26,    44,    44,     4,     3,    48,    44,
      50,     3,    45,    48,     7,    50,    44,    47,     0,     1,
      48,     3,    50,     5,    50,     7,     6,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     3,    41,
      46,    43,    46,    45,     6,    46,     6,    46,    46,    46,
      46,    44,    46,     6,    46,    46,    46,    46,    46,    46,
      46,     6,    46,    44,     6,    50,     6,    50,    50,     6,
       6,     6,     3,    44,    44,    44,     4,    44,    42,     6,
       6,    44,     6,    51,     3,    46,     3,    46,    46,    44,
     113,   142,    -1,    -1,    51,    51,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,     1,     3,     5,     7,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    41,    43,
      55,    47,     3,     6,    44,    48,    50,    59,    60,    63,
       6,     3,     6,    48,    52,    58,    59,    61,    58,    59,
       6,    58,    59,     6,    58,    59,    61,     6,    58,    59,
       6,    58,    59,     3,     6,    59,     6,    59,     3,     3,
       6,    56,    58,    59,    61,     4,     4,     3,     3,    44,
      57,     3,    57,     3,    57,     4,    44,    44,     3,     3,
      44,     3,    48,    44,     4,     3,     3,    42,    56,    64,
      45,     7,    44,    47,     3,     6,     6,    50,    44,    49,
      46,     3,     3,    44,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,     6,
      46,    50,    46,    60,    46,    51,     6,    46,    44,     6,
      58,    59,    44,    49,     6,     6,     6,    58,    59,     6,
       6,     6,     6,     6,     6,    56,     3,    44,     7,    44,
      44,    44,     4,    44,    64,     6,    46,    51,     6,    44,
      46,    46,    46,    51,    46,    51,     6,    46,    51,     3,
      44,     3,     6,    44,    62,    46,    51,    62,    51,    62,
      51,    51
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:

/* Line 1806 of yacc.c  */
#line 570 "a2i.y"
    { line++; }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 574 "a2i.y"
    { D( fprintf(outfile, "; .file %s\n", (yyvsp[(2) - (2)].str)) ); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 575 "a2i.y"
    { D( fputs("; ident\n", outfile) ); dump_bytes((yyvsp[(2) - (2)].str), strbuflen); }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 576 "a2i.y"
    { fprintf(outfile, "[section %s]\n[BITS 32]\n", (yyvsp[(1) - (1)].str)); section = (yyvsp[(1) - (1)].str); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 577 "a2i.y"
    { if ((yyvsp[(2) - (2)].str)[0] == '$') (yyvsp[(2) - (2)].str)[0] = '.'; fprintf(outfile, "[section %s]\n[BITS 32]\n", (yyvsp[(2) - (2)].str)); section = (yyvsp[(2) - (2)].str); if ((yyvsp[(2) - (2)].str)[0] == '.') (yyvsp[(2) - (2)].str)[0] = '$'; killexternal((yyvsp[(2) - (2)].str)); }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 578 "a2i.y"
    { if ((yyvsp[(2) - (4)].str)[0] == '$') (yyvsp[(2) - (4)].str)[0] = '.';
        			 if (!warn_sect_attr) { warning("section attributs are ignored"); warning("(only appears one time)"); warn_sect_attr = 1; }
        				fprintf(outfile, "[section %s]\n[BITS 32]\n", (yyvsp[(2) - (4)].str)); section = (yyvsp[(2) - (4)].str); if ((yyvsp[(2) - (4)].str)[0] == '.') (yyvsp[(2) - (4)].str)[0] = '$'; killexternal((yyvsp[(2) - (4)].str)); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 582 "a2i.y"
    { if ((yyvsp[(2) - (6)].str)[0] == '$') (yyvsp[(2) - (6)].str)[0] = '.';
	                         if (!warn_sect_attr) { warning("section attributs are ignored"); warning("(only appears one time)"); warn_sect_attr = 1; }
        				fprintf(outfile, "[section %s]\n[BITS 32]\n", (yyvsp[(2) - (6)].str)); section = (yyvsp[(2) - (6)].str); if ((yyvsp[(2) - (6)].str)[0] == '.') (yyvsp[(2) - (6)].str)[0] = '$'; killexternal((yyvsp[(2) - (6)].str)); }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 586 "a2i.y"
    { output_label((yyvsp[(1) - (2)].str)); }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 587 "a2i.y"
    { output_label((yyvsp[(1) - (3)].str)); fprintf(outfile, "\t%s\n", (yyvsp[(3) - (3)].str));  }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 589 "a2i.y"
    { dump_bytes((yyvsp[(2) - (2)].str), strbuflen); }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 590 "a2i.y"
    { fprintf(outfile, "\tresb %ld\n", (yyvsp[(2) - (2)].num)); }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 592 "a2i.y"
    { fprintf(outfile, "\nGLOBAL %s\n", (yyvsp[(2) - (2)].str)); }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 593 "a2i.y"
    { fprintf(outfile, "\nGLOBAL %s\nGLOBAL %s\n", (yyvsp[(2) - (4)].str), (yyvsp[(4) - (4)].str)); }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 595 "a2i.y"
    { fprintf(outfile, "\nGLOBAL %s\nGLOBAL %s\nGLOBAL %s\n", (yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].str), (yyvsp[(6) - (6)].str)); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 597 "a2i.y"
    { fprintf(outfile, "\tdd %s\n", (yyvsp[(2) - (2)].str)); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 598 "a2i.y"
    { fprintf(outfile, "\tdd %s+0x%lx\n", (yyvsp[(2) - (2)].str), baseaddr); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 600 "a2i.y"
    { fprintf(outfile, "\tdw %s\n", (yyvsp[(2) - (2)].str)); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 601 "a2i.y"
    { fprintf(outfile, "\tdw %s+0x%lx\n", (yyvsp[(2) - (2)].str), baseaddr); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 603 "a2i.y"
    { fprintf(outfile, "\tdb %s\n", (yyvsp[(2) - (2)].str)); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 604 "a2i.y"
    { fprintf(outfile, "\tdb %s+0x%lx\n", (yyvsp[(2) - (2)].str), baseaddr); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 606 "a2i.y"
    { D( fprintf(outfile, "; version %s\n", (yyvsp[(2) - (2)].str)) ); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 608 "a2i.y"
    { D( fprintf(outfile, "; p2align %ld\n", (yyvsp[(2) - (2)].num)) );
        				fprintf(outfile, "\talign %ld\n", pow2((yyvsp[(2) - (2)].num))); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 610 "a2i.y"
    { fprintf(outfile, "\talign %ld\n", (yyvsp[(2) - (2)].num)); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 612 "a2i.y"
    { fprintf(outfile, "\talign %ld, nop\n", (yyvsp[(2) - (4)].num));
                                	if ((yyvsp[(4) - (4)].num) != 0x90) {
                                		warning("strange opcode after align (only NOPs are supported)");
                                		fprintf(outfile, "\talign %ld, nop\n", (yyvsp[(2) - (4)].num));
                                        }
                                }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 619 "a2i.y"
    { fprintf(outfile, "\talign %ld, %s\n", (yyvsp[(2) - (4)].num), (yyvsp[(4) - (4)].str)); warning("this align instruction might not be supported by nasm"); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 621 "a2i.y"
    { struct symbol* s = sym_lookup((yyvsp[(2) - (4)].str));
				  output_comm((yyvsp[(2) - (4)].str), (yyvsp[(4) - (4)].num), 0, ( (s!=NULL) && (s->islocal) ) ); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 624 "a2i.y"
    { struct symbol* s = sym_lookup((yyvsp[(2) - (6)].str));
                                  output_comm((yyvsp[(2) - (6)].str), (yyvsp[(4) - (6)].num), (yyvsp[(6) - (6)].num), ( (s!=NULL) && (s->islocal) ) ); }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 627 "a2i.y"
    { output_comm((yyvsp[(2) - (4)].str), (yyvsp[(4) - (4)].num), 0, 1); }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 629 "a2i.y"
    { struct symbol*s = addexternal((yyvsp[(2) - (2)].str));
				  s->isextern = 0; s->islocal = 1; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 632 "a2i.y"
    { fprintf(outfile, "\t%s %s %s\n", op((yyvsp[(1) - (2)].str)), op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 633 "a2i.y"
    { fprintf(outfile, "\t%s %s %s\n", op((yyvsp[(1) - (2)].str)), op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 634 "a2i.y"
    { fprintf(outfile, "\t%s %s %s\n", op((yyvsp[(1) - (2)].str)), op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 635 "a2i.y"
    { fprintf(outfile, "\t%s %s %s\n", op((yyvsp[(1) - (2)].str)), op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 637 "a2i.y"
    { fprintf(outfile, "\t%s %s %s, %s\n", op((yyvsp[(1) - (4)].str)), op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 639 "a2i.y"
    { fprintf(outfile, "\t%s %s %s, %s\n", op((yyvsp[(1) - (4)].str)), op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 641 "a2i.y"
    { fprintf(outfile, "\t%s %s %s, %s\n", op((yyvsp[(1) - (4)].str)), op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 643 "a2i.y"
    { fprintf(outfile, "\t%s %s %s, %s\n", op((yyvsp[(1) - (4)].str)), op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 644 "a2i.y"
    { fprintf(outfile, "\t%s %s %s, %s\n", op((yyvsp[(1) - (4)].str)), op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 646 "a2i.y"
    { fprintf(outfile, "\t%s %s %s, %s\n", op((yyvsp[(1) - (4)].str)), op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 648 "a2i.y"
    { fprintf(outfile, "\t%s %s %s, %s\n", op((yyvsp[(1) - (4)].str)), op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 650 "a2i.y"
    { fprintf(outfile, "\t%s %s %s, %s\n", op((yyvsp[(1) - (4)].str)), op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 652 "a2i.y"
    { fprintf(outfile, "\t%s %s %s\n", op((yyvsp[(1) - (2)].str)), op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 653 "a2i.y"
    { fprintf(outfile, "\t%s %s %s\n", op((yyvsp[(1) - (2)].str)), op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 654 "a2i.y"
    { fprintf(outfile, "\t%s %s %s\n", op((yyvsp[(1) - (2)].str)), op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 657 "a2i.y"
    { fprintf(outfile, "\tlea %s %s, %s\n", op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 658 "a2i.y"
    { fprintf(outfile, "\tlea %s %s, %s\n", op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 660 "a2i.y"
    { fprintf(outfile, "\tcall %s\n", (yyvsp[(2) - (2)].str)); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 661 "a2i.y"
    { fprintf(outfile, "\tcall %s\n", (yyvsp[(3) - (3)].str)); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 663 "a2i.y"
    { fprintf(outfile, "\t%s%s %s\n", (yyvsp[(1) - (2)].str), is_near((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 664 "a2i.y"
    { fprintf(outfile, "\t%s%s %s\n", (yyvsp[(1) - (2)].str), is_near((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 665 "a2i.y"
    { fprintf(outfile, "\t%s%s %s\n", (yyvsp[(1) - (3)].str), is_near((yyvsp[(1) - (3)].str)), (yyvsp[(3) - (3)].str)); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 666 "a2i.y"
    { fprintf(outfile, "\t%s%s %s\n", (yyvsp[(1) - (3)].str), is_near((yyvsp[(1) - (3)].str)), (yyvsp[(3) - (3)].str)); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 668 "a2i.y"
    { fprintf(outfile, "\timul %s %s\n", op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 669 "a2i.y"
    { fprintf(outfile, "\timul %s %s, %s\n", op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 670 "a2i.y"
    { fprintf(outfile, "\timul %s %s, %s\n", op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 671 "a2i.y"
    { fprintf(outfile, "\timul %s %s, %s\n", op_size((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 673 "a2i.y"
    { fprintf(outfile, "\tidiv %s %s\n", op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 674 "a2i.y"
    { fprintf(outfile, "\tidiv %s %s\n", op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 675 "a2i.y"
    { fprintf(outfile, "\tidiv %s %s\n", op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 677 "a2i.y"
    { fprintf(outfile, "\t%s %s %s\n", op((yyvsp[(1) - (2)].str)), op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 678 "a2i.y"
    { fprintf(outfile, "\t%s %s %s\n", op((yyvsp[(1) - (2)].str)), op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 680 "a2i.y"
    { mov_sd((yyvsp[(1) - (4)].str), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 682 "a2i.y"
    { fprintf(outfile, "\t%s %s %s\n", op((yyvsp[(1) - (2)].str)), op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 683 "a2i.y"
    { fprintf(outfile, "\t%s %s %s\n", op((yyvsp[(1) - (2)].str)), op_size((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 685 "a2i.y"
    { fprintf(outfile, "\t%s %s\n", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str)); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 687 "a2i.y"
    { fprintf(outfile, "\tint 0x%lx\n", (yyvsp[(2) - (2)].num)); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 689 "a2i.y"
    { fprintf(outfile, "\t%s %s, %s\n", (yyvsp[(1) - (4)].str), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 691 "a2i.y"
    { fprintf(outfile, "\t%s [%s]\n", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str)); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 693 "a2i.y"
    { fprintf(outfile, "\t%s\n", (yyvsp[(1) - (1)].str)); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 695 "a2i.y"
    { fprintf(outfile, "\t%s\n", translate_instr((yyvsp[(1) - (1)].str))); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 697 "a2i.y"
    { fprintf(outfile, "\t%s %s\n", translate_math((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 698 "a2i.y"
    { fprintf(outfile, "\t%s %s\n", translate_math((yyvsp[(1) - (2)].str)), (yyvsp[(2) - (2)].str)); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 700 "a2i.y"
    { fprintf(outfile, "\t%s %s, %s\n", translate_math((yyvsp[(1) - (4)].str)), (yyvsp[(4) - (4)].str), (yyvsp[(2) - (4)].str)); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 702 "a2i.y"
    { ; }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 707 "a2i.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 708 "a2i.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 709 "a2i.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 710 "a2i.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 713 "a2i.y"
    { (yyval.str) = signed_num((yyvsp[(1) - (1)].num)); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 714 "a2i.y"
    { sprintf(tmpstr5, "%s, 0x%lx", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].num)); (yyval.str) = tmpstr5; }
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 717 "a2i.y"
    { sprintf(tmpstr1, "[%s+0x%lx]", (yyvsp[(1) - (1)].str), baseaddr); (yyval.str) = tmpstr1; }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 718 "a2i.y"
    { sprintf(tmpstr1, "[%s+%ld+0x%lx]", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].num), baseaddr); (yyval.str) = tmpstr1; }
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 719 "a2i.y"
    { sprintf(tmpstr1, "[%s%ld+0x%lx]", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].num), baseaddr); (yyval.str) = tmpstr1;
        				if ((yyvsp[(2) - (2)].num)>0) yyerror("expression error"); }
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 723 "a2i.y"
    { sprintf(tmpstr6, "[%s]", (yyvsp[(1) - (1)].str)); (yyval.str) = tmpstr6; }
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 724 "a2i.y"
    { sprintf(tmpstr6, "[%s:%s]", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str)); (yyval.str) = tmpstr6; }
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 727 "a2i.y"
    { sprintf(tmpstr2, "%s", (yyvsp[(2) - (3)].str)); (yyval.str) = tmpstr2;}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 728 "a2i.y"
    { sprintf(tmpstr2, "%s + %s", (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].str)); (yyval.str) = tmpstr2; }
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 730 "a2i.y"
    { sprintf(tmpstr2, "%s + %s*%s", (yyvsp[(2) - (7)].str), (yyvsp[(4) - (7)].str), (yyvsp[(6) - (7)].str)); (yyval.str) = tmpstr2; }
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 731 "a2i.y"
    { sprintf(tmpstr2, "%s%s", (yyvsp[(3) - (4)].str), (yyvsp[(1) - (4)].str)); (yyval.str) = tmpstr2; }
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 733 "a2i.y"
    { sprintf(tmpstr2, "%s + %s %s", (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str), (yyvsp[(1) - (6)].str)); (yyval.str) = tmpstr2; }
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 735 "a2i.y"
    { sprintf(tmpstr2, "%s + %s*%s %s", (yyvsp[(3) - (8)].str), (yyvsp[(5) - (8)].str), (yyvsp[(7) - (8)].str), (yyvsp[(1) - (8)].str)); (yyval.str) = tmpstr2; }
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 737 "a2i.y"
    { sprintf(tmpstr2, "%s %s", (yyvsp[(4) - (5)].str), (yyvsp[(1) - (5)].str)); (yyval.str) = tmpstr2; }
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 739 "a2i.y"
    { sprintf(tmpstr2, "%s*%s %s", (yyvsp[(4) - (7)].str), (yyvsp[(6) - (7)].str), (yyvsp[(1) - (7)].str)); (yyval.str) = tmpstr2; }
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 742 "a2i.y"
    { (yyval.str) = signed_num((yyvsp[(2) - (2)].num)); }
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 743 "a2i.y"
    { sprintf(tmpstr3, "%s+0x%lx", (yyvsp[(2) - (2)].str), baseaddr); (yyval.str) = tmpstr3; }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 744 "a2i.y"
    { sprintf(tmpstr3, "%s%ld+0x%lx", (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].num), baseaddr); (yyval.str) = tmpstr3;
        				if ((yyvsp[(3) - (3)].num)>0) yyerror("expression error"); }
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 746 "a2i.y"
    { sprintf(tmpstr3, "%s+%ld+0x%lx", (yyvsp[(2) - (4)].str), (yyvsp[(4) - (4)].num), baseaddr); (yyval.str) = tmpstr3; }
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 749 "a2i.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); }
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 750 "a2i.y"
    { (yyval.str) = signed_num((yyvsp[(1) - (1)].num)); }
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 753 "a2i.y"
    { (yyval.str) = signed_num((yyvsp[(1) - (1)].num)); }
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 754 "a2i.y"
    { strcpy(tmpstr4, "+ "); strcat(tmpstr4, (yyvsp[(1) - (1)].str)); (yyval.str) = tmpstr4;}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 755 "a2i.y"
    { strcpy(tmpstr4, "+ "); strcat(tmpstr4, (yyvsp[(1) - (2)].str)); strcat(tmpstr4, signed_num((yyvsp[(2) - (2)].num))); (yyval.str) = tmpstr4; }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 756 "a2i.y"
    { strcpy(tmpstr4, "+ "); strcat(tmpstr4, (yyvsp[(2) - (2)].str)); (yyval.str) = tmpstr4; }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 759 "a2i.y"
    { (yyval.str) = "st"; }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 760 "a2i.y"
    { sprintf(tmpstr4, "st%d", (yyvsp[(3) - (4)].num)); (yyval.str) = tmpstr4; }
    break;



/* Line 1806 of yacc.c  */
#line 2884 "a2i.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 762 "a2i.y"


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


