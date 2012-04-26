#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20110908

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 3 "parser.y"

#include <stdlib.h>
#include <stdio.h>
#include "hash.h"
#include "astree.h"

FILE *yyin;

#line 13 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	ASTREE *astree;
	HASH_ELEMENT *symbol;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 40 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();

#define KW_INTEGER 257
#define KW_FLOATING 258
#define KW_BOOLEAN 259
#define KW_CHARACTER 260
#define KW_DECLARE 261
#define KW_IF 262
#define KW_THEN 263
#define KW_ELSE 264
#define KW_WHILE 265
#define KW_DO 266
#define KW_INPUT 267
#define KW_RETURN 268
#define KW_OUTPUT 269
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_NE 273
#define OPERATOR_AND 274
#define OPERATOR_OR 275
#define TK_IDENTIFIER 276
#define LIT_INTEGER 277
#define LIT_FLOATING 278
#define LIT_FALSE 279
#define LIT_TRUE 280
#define LIT_CHARACTER 281
#define LIT_STRING 282
#define TOKEN_ERROR 283
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   21,   21,   21,   20,   20,   11,   12,   15,   15,
   15,   15,   19,   18,   16,   16,   17,   17,   14,    9,
    9,    9,    9,    9,    9,    9,   13,   10,   10,   10,
   10,   10,   10,    8,    8,    5,    6,    3,    3,    7,
    4,    4,    4,    4,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    2,
};
static const short yylen[] = {                            2,
    1,    2,    2,    0,    2,    2,    4,    7,    1,    1,
    1,    1,    3,    6,    1,    0,    3,    1,    3,    1,
    1,    1,    1,    1,    1,    0,    3,    1,    3,    1,
    3,    1,    3,    3,    6,    2,    2,    3,    1,    2,
    6,    8,    5,    6,    1,    4,    1,    1,    1,    1,
    1,    1,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    4,    1,    0,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,
    0,    5,    6,    0,    0,    0,    0,    0,    0,    0,
    0,   21,   23,   24,   25,   22,    0,   20,    3,    2,
    0,    9,   10,   11,   12,    0,    0,    0,    0,   36,
    0,   47,   48,   49,   50,   51,   52,    0,    0,    0,
   37,    0,    0,    0,    0,    0,    0,   13,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   27,    0,    0,    0,    0,    0,    0,   15,
    0,    0,    0,    0,    0,   67,   59,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   55,   56,   38,
    0,   29,   31,   33,    0,    0,    0,   14,    0,   43,
    0,   46,   66,    0,    8,   19,   17,    0,   44,    0,
    0,   42,
};
static const short yydgoto[] = {                          3,
   50,   95,   51,   22,   23,   24,   25,   26,   54,   55,
   56,   57,   28,   88,   36,   89,   90,    6,    7,    8,
    9,
};
static const short yysindex[] = {                      -259,
 -258,  -28,    0,  -32,  -22,  209, -259, -259,    0,  -18,
   12,    0,    0,    2,    5,  209, -227,  -40,  -40,  -48,
  197,    0,    0,    0,    0,    0,   -7,    0,    0,    0,
   12,    0,    0,    0,    0,   17,  -40,  -40, -207,    0,
  -31,    0,    0,    0,    0,    0,    0,  -40,  173,  138,
    0,  -40,  -40,    7,  -64,   14,   19,    0,  -27, -197,
   88,  100,   41,  -40,  -40,  112,  -40,  -40,  -40,  -40,
  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  152,
  173,  197,    0,  197,  197, -192,   30,   56,   62,    0,
 -158,  209,  -40,  164,   76,    0,    0,  -14,  -14,  -14,
  -14,  358,  358,  -14,  -14,  -36,  -36,    0,    0,    0,
   58,    0,    0,    0,   29,   12, -197,    0,  209,    0,
  124,    0,    0,  -40,    0,    0,    0, -141,    0,  173,
  209,    0,
};
static const short yyrindex[] = {                       126,
    0,    0,    0,    0,    0,   75,  126,  126,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -58,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -21,    0,    0,    0,    0,    0,    0,    0,  -43,  -34,
    0,    0,    0,   13,    0,   24,   26,    0,  -49,  120,
    0,    0,    0,    0,  122,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   31,  -58,    0,  -58,  -58,    0,    0,  132,    0,    0,
    0,  -56,    0,    0,    0,    0,    0,   15,   27,   39,
   51,   53,  347,   65,   77,   -9,    3,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -56,    0,
    0,    0,    0,    0,    0,    0,    0,  -55,    0,   43,
  -56,    0,
};
static const short yygindex[] = {                         0,
  442,    0,  -60,    0,    0,    0,    0,    0,  337,  -70,
  107,  196,    0,    0,  -23,    0,   60,    0,    0,    0,
   47,
};
#define YYTABLESIZE 631
static const short yytable[] = {                         48,
   26,    1,   26,   41,   96,   77,   39,   59,   65,    7,
   78,  112,   53,  113,  114,   40,    2,   10,  110,   45,
   45,   45,   45,   45,   39,   45,   12,   77,   75,   11,
   76,   53,   78,   53,   53,   53,   13,   45,   45,   31,
   45,   37,   52,   54,   38,   54,   54,   54,   40,   53,
   53,   58,   53,   29,   30,   60,   60,   63,   60,   64,
   83,   54,   54,   86,   54,   82,   26,   61,   26,   41,
   61,   45,   84,   60,   60,    7,   60,   85,   87,   62,
   93,   40,   62,   53,  115,   61,   61,  116,   61,   34,
   39,   63,  126,   64,   63,   54,   64,   62,   62,  117,
   62,   35,  118,   45,  119,   57,    4,   60,   57,   63,
   63,   64,   63,    4,    4,   53,  123,   58,  124,   61,
   58,  125,  131,   57,   57,    4,   57,   54,   91,   77,
   75,   62,   76,   26,   78,   58,   58,   28,   58,   60,
   92,   77,   75,   63,   76,   64,   78,   73,   30,   74,
   32,   61,   97,   77,   75,   34,   76,   57,   78,   73,
   16,   74,   68,   62,  129,   77,   75,   35,   76,   58,
   78,   73,   18,   74,    0,   63,  127,   64,    0,   77,
   75,   79,   76,   73,   78,   74,    0,    0,    0,   57,
    0,    0,    0,   77,   75,    5,   76,   73,   78,   74,
    0,   58,    5,    5,    0,   77,   75,   26,   76,   41,
   78,   73,    0,   74,   77,   75,    0,   76,    0,   78,
   40,   40,    0,   73,    0,   74,    0,    0,    0,   39,
   39,    0,   73,    0,   74,   41,   42,   43,   44,   45,
   46,   47,   45,   45,  111,    0,    0,    0,   45,   45,
   45,   45,   45,   45,   53,   53,  122,    0,    0,    0,
   53,   53,   53,   53,   53,   53,   54,   54,   32,   33,
   34,   35,   54,   54,   54,   54,   54,   54,   60,   60,
    0,    0,    0,    0,   60,   60,   60,   60,   60,   60,
   61,   61,    0,    0,   34,   34,   61,   61,   61,   61,
   61,   61,   62,   62,    0,    0,   35,   35,   62,   62,
   62,   62,   62,   62,   63,   63,   64,   64,    0,   21,
   63,   63,   63,   63,   63,   63,   64,   64,   57,   57,
    0,   21,    0,    0,   57,   57,   57,   57,   57,   57,
   58,   58,   27,    0,    0,    0,   58,   58,   58,   58,
   58,   58,   39,    0,    0,    0,    0,   67,   68,   69,
   70,   71,   72,    0,    0,    0,    0,    0,    0,   67,
   68,   69,   70,   71,   72,    0,    0,    0,    0,    0,
    0,   67,   68,   69,   70,   71,   72,   65,    0,    0,
   65,    0,    0,   67,   68,   69,   70,   71,   72,   77,
   75,    0,   76,    0,   78,   65,    0,   67,   68,   69,
   70,   71,   72,    0,    0,    0,    0,   73,    0,   74,
    0,   67,   68,   69,   70,   71,   72,    0,  120,    0,
    0,    0,    0,   67,   68,   69,   70,   71,   72,   65,
    0,    0,   67,   68,   69,   70,   71,   72,    0,    0,
    0,    0,    0,    0,    0,  128,    0,    1,   14,   49,
    0,   15,   16,   17,   18,   19,    0,  132,    0,    0,
   14,   65,   20,   15,   16,   17,   18,   19,   61,   62,
    0,    0,    0,    0,   20,    0,    0,    0,    0,   66,
    0,    0,    0,   80,   81,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   94,    0,    0,   98,   99,
  100,  101,  102,  103,  104,  105,  106,  107,  108,  109,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  121,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  130,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   65,   65,    0,    0,    0,    0,    0,    0,    0,    0,
   65,   65,    0,    0,    0,    0,    0,   67,   68,   69,
   70,
};
static const short yycheck[] = {                         40,
   59,  261,   59,   59,   65,   42,   41,   31,   40,   59,
   47,   82,   61,   84,   85,   59,  276,  276,   79,   41,
   42,   43,   44,   45,   59,   47,   59,   42,   43,   58,
   45,   41,   47,   43,   44,   45,   59,   59,   60,   58,
   62,   40,   91,   41,   40,   43,   44,   45,  276,   59,
   60,   59,   62,    7,    8,   41,   40,  265,   44,   91,
  125,   59,   60,   91,   62,   59,  125,   41,  125,  125,
   44,   93,   59,   59,   60,  125,   62,   59,  276,   41,
   40,  125,   44,   93,  277,   59,   60,   58,   62,   59,
  125,   41,  116,   41,   44,   93,   44,   59,   60,   44,
   62,   59,   41,  125,  263,   41,    0,   93,   44,   59,
   60,   59,   62,    7,    8,  125,   41,   41,   61,   93,
   44,   93,  264,   59,   60,    0,   62,  125,   41,   42,
   43,   93,   45,   59,   47,   59,   60,  125,   62,  125,
   41,   42,   43,   93,   45,   93,   47,   60,  125,   62,
  125,  125,   41,   42,   43,  125,   45,   93,   47,   60,
   41,   62,   41,  125,   41,   42,   43,  125,   45,   93,
   47,   60,   41,   62,   -1,  125,  117,  125,   -1,   42,
   43,   44,   45,   60,   47,   62,   -1,   -1,   -1,  125,
   -1,   -1,   -1,   42,   43,    0,   45,   60,   47,   62,
   -1,  125,    7,    8,   -1,   42,   43,  264,   45,  265,
   47,   60,   -1,   62,   42,   43,   -1,   45,   -1,   47,
  264,  265,   -1,   60,   -1,   62,   -1,   -1,   -1,  264,
  265,   -1,   60,   -1,   62,  276,  277,  278,  279,  280,
  281,  282,  264,  265,   93,   -1,   -1,   -1,  270,  271,
  272,  273,  274,  275,  264,  265,   93,   -1,   -1,   -1,
  270,  271,  272,  273,  274,  275,  264,  265,  257,  258,
  259,  260,  270,  271,  272,  273,  274,  275,  264,  265,
   -1,   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,
  264,  265,   -1,   -1,  264,  265,  270,  271,  272,  273,
  274,  275,  264,  265,   -1,   -1,  264,  265,  270,  271,
  272,  273,  274,  275,  264,  265,  264,  265,   -1,  123,
  270,  271,  272,  273,  274,  275,  274,  275,  264,  265,
   -1,  123,   -1,   -1,  270,  271,  272,  273,  274,  275,
  264,  265,    6,   -1,   -1,   -1,  270,  271,  272,  273,
  274,  275,   16,   -1,   -1,   -1,   -1,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  270,
  271,  272,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,  274,  275,   41,   -1,   -1,
   44,   -1,   -1,  270,  271,  272,  273,  274,  275,   42,
   43,   -1,   45,   -1,   47,   59,   -1,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   -1,   60,   -1,   62,
   -1,  270,  271,  272,  273,  274,  275,   -1,   92,   -1,
   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,   93,
   -1,   -1,  270,  271,  272,  273,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  119,   -1,  261,  262,   18,
   -1,  265,  266,  267,  268,  269,   -1,  131,   -1,   -1,
  262,  125,  276,  265,  266,  267,  268,  269,   37,   38,
   -1,   -1,   -1,   -1,  276,   -1,   -1,   -1,   -1,   48,
   -1,   -1,   -1,   52,   53,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   64,   -1,   -1,   67,   68,
   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  274,  275,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,
  273,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 283
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_INTEGER","KW_FLOATING","KW_BOOLEAN",
"KW_CHARACTER","KW_DECLARE","KW_IF","KW_THEN","KW_ELSE","KW_WHILE","KW_DO",
"KW_INPUT","KW_RETURN","KW_OUTPUT","OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ",
"OPERATOR_NE","OPERATOR_AND","OPERATOR_OR","TK_IDENTIFIER","LIT_INTEGER",
"LIT_FLOATING","LIT_FALSE","LIT_TRUE","LIT_CHARACTER","LIT_STRING",
"TOKEN_ERROR",
};
static const char *yyrule[] = {
"$accept : p",
"p : programa",
"programa : decl_global programa",
"programa : def_funcao programa",
"programa :",
"decl_global : decl_var ';'",
"decl_global : decl_vetor ';'",
"decl_var : KW_DECLARE TK_IDENTIFIER ':' tipo_var",
"decl_vetor : KW_DECLARE TK_IDENTIFIER ':' tipo_var '[' LIT_INTEGER ']'",
"tipo_var : KW_INTEGER",
"tipo_var : KW_FLOATING",
"tipo_var : KW_BOOLEAN",
"tipo_var : KW_CHARACTER",
"def_funcao : cabecalho comando ';'",
"cabecalho : TK_IDENTIFIER ':' tipo_var '(' lista_parametros ')'",
"lista_parametros : lista_param_nao_vazia",
"lista_parametros :",
"lista_param_nao_vazia : parametro ',' lista_param_nao_vazia",
"lista_param_nao_vazia : parametro",
"parametro : TK_IDENTIFIER ':' tipo_var",
"comando : bloco_comando",
"comando : controle_fluxo",
"comando : atribuicao",
"comando : input",
"comando : output",
"comando : return",
"comando :",
"bloco_comando : '{' seq_comando '}'",
"seq_comando : comando",
"seq_comando : comando ';' seq_comando",
"seq_comando : decl_var",
"seq_comando : decl_var ';' seq_comando",
"seq_comando : decl_vetor",
"seq_comando : decl_vetor ';' seq_comando",
"atribuicao : TK_IDENTIFIER '=' expressao",
"atribuicao : TK_IDENTIFIER '[' expressao ']' '=' expressao",
"input : KW_INPUT TK_IDENTIFIER",
"output : KW_OUTPUT lista_expr_nao_vazia",
"lista_expr_nao_vazia : expressao ',' lista_expr_nao_vazia",
"lista_expr_nao_vazia : expressao",
"return : KW_RETURN expressao",
"controle_fluxo : KW_IF '(' expressao ')' KW_THEN comando",
"controle_fluxo : KW_IF '(' expressao ')' KW_THEN comando KW_ELSE comando",
"controle_fluxo : KW_WHILE '(' expressao ')' comando",
"controle_fluxo : KW_DO comando KW_WHILE '(' expressao ')'",
"expressao : TK_IDENTIFIER",
"expressao : TK_IDENTIFIER '[' expressao ']'",
"expressao : LIT_INTEGER",
"expressao : LIT_FLOATING",
"expressao : LIT_FALSE",
"expressao : LIT_TRUE",
"expressao : LIT_CHARACTER",
"expressao : LIT_STRING",
"expressao : expressao '+' expressao",
"expressao : expressao '-' expressao",
"expressao : expressao '*' expressao",
"expressao : expressao '/' expressao",
"expressao : expressao '<' expressao",
"expressao : expressao '>' expressao",
"expressao : '(' expressao ')'",
"expressao : expressao OPERATOR_LE expressao",
"expressao : expressao OPERATOR_GE expressao",
"expressao : expressao OPERATOR_EQ expressao",
"expressao : expressao OPERATOR_NE expressao",
"expressao : expressao OPERATOR_AND expressao",
"expressao : expressao OPERATOR_OR expressao",
"expressao : TK_IDENTIFIER '(' lista_expressoes ')'",
"lista_expressoes : lista_expr_nao_vazia",
"lista_expressoes :",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 178 "parser.y"

int yyerror(char *t) {
	printf("Syntax Error on line %d\n", getLineNumber());
	exit(3);
}
#line 441 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 66 "parser.y"
	{ yyval.astree = yystack.l_mark[0].astree; astPrintTree(yyval.astree); astPrintTreeSrc(yyval.astree); }
break;
case 2:
#line 68 "parser.y"
	{ yyval.astree = astCreate(AST_PROG, 0, yystack.l_mark[-1].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 3:
#line 69 "parser.y"
	{ yyval.astree = astCreate(AST_PROG, 0, yystack.l_mark[-1].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 4:
#line 70 "parser.y"
	{ yyval.astree = astCreate(AST_EMPTY, 0, 0, 0, 0, 0); }
break;
case 5:
#line 73 "parser.y"
	{ yyval.astree = astCreate(AST_DECL_GL, 0, yystack.l_mark[-1].astree, 0, 0, 0); }
break;
case 6:
#line 74 "parser.y"
	{ yyval.astree = astCreate(AST_DECL_GL, 0, yystack.l_mark[-1].astree, 0, 0, 0); }
break;
case 7:
#line 77 "parser.y"
	{ yyval.astree = astCreate(AST_DECL_VAR, yystack.l_mark[-2].symbol, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 8:
#line 80 "parser.y"
	{ yyval.astree = astCreate(AST_DECL_VEC, yystack.l_mark[-5].symbol, yystack.l_mark[-3].astree, astCreate(AST_VEC_SIZE, yystack.l_mark[-1].symbol, 0, 0, 0, 0), 0, 0); }
break;
case 9:
#line 83 "parser.y"
	{ yyval.astree = astCreate(AST_T_INT, 0, 0, 0, 0, 0); }
break;
case 10:
#line 84 "parser.y"
	{ yyval.astree = astCreate(AST_T_FLO, 0, 0, 0, 0, 0); }
break;
case 11:
#line 85 "parser.y"
	{ yyval.astree = astCreate(AST_T_BOO, 0, 0, 0, 0, 0); }
break;
case 12:
#line 86 "parser.y"
	{ yyval.astree = astCreate(AST_T_CHA, 0, 0, 0, 0, 0); }
break;
case 13:
#line 89 "parser.y"
	{ yyval.astree = astCreate(AST_DEF_F, 0, yystack.l_mark[-2].astree, yystack.l_mark[-1].astree, 0, 0); }
break;
case 14:
#line 92 "parser.y"
	{ yyval.astree = astCreate(AST_CAB, yystack.l_mark[-5].symbol, yystack.l_mark[-3].astree, yystack.l_mark[-1].astree, 0, 0); }
break;
case 15:
#line 95 "parser.y"
	{ yyval.astree = yystack.l_mark[0].astree; }
break;
case 16:
#line 96 "parser.y"
	{ yyval.astree = astCreate(AST_EMPTY, 0, 0, 0, 0, 0); }
break;
case 17:
#line 99 "parser.y"
	{ yyval.astree = astCreate(AST_LIST_P, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 18:
#line 100 "parser.y"
	{ yyval.astree = astCreate(AST_LIST_P, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 19:
#line 103 "parser.y"
	{ yyval.astree = astCreate(AST_PARAM, yystack.l_mark[-2].symbol, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 20:
#line 106 "parser.y"
	{ yyval.astree = astCreate(AST_COM, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 21:
#line 107 "parser.y"
	{ yyval.astree = astCreate(AST_COM, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 22:
#line 108 "parser.y"
	{ yyval.astree = astCreate(AST_COM, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 23:
#line 109 "parser.y"
	{ yyval.astree = astCreate(AST_COM, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 24:
#line 110 "parser.y"
	{ yyval.astree = astCreate(AST_COM, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 25:
#line 111 "parser.y"
	{ yyval.astree = astCreate(AST_COM, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 26:
#line 112 "parser.y"
	{ yyval.astree = astCreate(AST_COM, 0, 0, 0, 0, 0); }
break;
case 27:
#line 115 "parser.y"
	{ yyval.astree = astCreate(AST_BLO_COM, 0, yystack.l_mark[-1].astree, 0, 0, 0); }
break;
case 28:
#line 118 "parser.y"
	{ yyval.astree = astCreate(AST_SEQ, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 29:
#line 119 "parser.y"
	{ yyval.astree = astCreate(AST_SEQ, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 30:
#line 120 "parser.y"
	{ yyval.astree = astCreate(AST_SEQ, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 31:
#line 121 "parser.y"
	{ yyval.astree = astCreate(AST_SEQ, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 32:
#line 122 "parser.y"
	{ yyval.astree = astCreate(AST_SEQ, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 33:
#line 123 "parser.y"
	{ yyval.astree = astCreate(AST_SEQ, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 34:
#line 126 "parser.y"
	{ yyval.astree = astCreate(AST_ATR, yystack.l_mark[-2].symbol, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 35:
#line 127 "parser.y"
	{ yyval.astree = astCreate(AST_ATR, yystack.l_mark[-5].symbol, yystack.l_mark[-3].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 36:
#line 130 "parser.y"
	{ yyval.astree = astCreate(AST_INP, yystack.l_mark[0].symbol, 0, 0, 0, 0); }
break;
case 37:
#line 133 "parser.y"
	{ yyval.astree = astCreate(AST_OUT, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 38:
#line 136 "parser.y"
	{ yyval.astree = astCreate(AST_LIST_E, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 39:
#line 137 "parser.y"
	{ yyval.astree = astCreate(AST_LIST_E, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 40:
#line 140 "parser.y"
	{ yyval.astree = astCreate(AST_RET, 0, yystack.l_mark[0].astree, 0, 0, 0); }
break;
case 41:
#line 143 "parser.y"
	{ yyval.astree = astCreate(AST_IF, 0, yystack.l_mark[-3].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 42:
#line 144 "parser.y"
	{ yyval.astree = astCreate(AST_IF, 0, yystack.l_mark[-5].astree, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0); }
break;
case 43:
#line 145 "parser.y"
	{ yyval.astree = astCreate(AST_WHILE, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 44:
#line 146 "parser.y"
	{ yyval.astree = astCreate(AST_DO_WHILE, 0, yystack.l_mark[-4].astree, yystack.l_mark[-1].astree, 0, 0); }
break;
case 45:
#line 149 "parser.y"
	{ yyval.astree = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol, 0, 0, 0, 0); }
break;
case 46:
#line 150 "parser.y"
	{ yyval.astree = astCreate(AST_SYMBOL, yystack.l_mark[-3].symbol, yystack.l_mark[-1].astree, 0, 0, 0); }
break;
case 47:
#line 151 "parser.y"
	{ yyval.astree = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol, 0, 0, 0, 0); }
break;
case 48:
#line 152 "parser.y"
	{ yyval.astree = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol, 0, 0, 0, 0); }
break;
case 49:
#line 153 "parser.y"
	{ yyval.astree = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol, 0, 0, 0, 0); }
break;
case 50:
#line 154 "parser.y"
	{ yyval.astree = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol, 0, 0, 0, 0); }
break;
case 51:
#line 155 "parser.y"
	{ yyval.astree = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol, 0, 0, 0, 0); }
break;
case 52:
#line 156 "parser.y"
	{ yyval.astree = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol, 0, 0, 0, 0); }
break;
case 53:
#line 157 "parser.y"
	{ yyval.astree = astCreate(AST_OP_SUM, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 54:
#line 158 "parser.y"
	{ yyval.astree = astCreate(AST_OP_SUB, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 55:
#line 159 "parser.y"
	{ yyval.astree = astCreate(AST_OP_MUL, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 56:
#line 160 "parser.y"
	{ yyval.astree = astCreate(AST_OP_DIV, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 57:
#line 161 "parser.y"
	{ yyval.astree = astCreate(AST_OP_LES, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 58:
#line 162 "parser.y"
	{ yyval.astree = astCreate(AST_OP_GRE, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 59:
#line 163 "parser.y"
	{ yyval.astree = yystack.l_mark[-1].astree; }
break;
case 60:
#line 164 "parser.y"
	{ yyval.astree = astCreate(AST_OP_LE, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 61:
#line 165 "parser.y"
	{ yyval.astree = astCreate(AST_OP_GE, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 62:
#line 166 "parser.y"
	{ yyval.astree = astCreate(AST_OP_EQ, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 63:
#line 167 "parser.y"
	{ yyval.astree = astCreate(AST_OP_NE, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 64:
#line 168 "parser.y"
	{ yyval.astree = astCreate(AST_OP_AND, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 65:
#line 169 "parser.y"
	{ yyval.astree = astCreate(AST_OP_OR, 0, yystack.l_mark[-2].astree, yystack.l_mark[0].astree, 0, 0); }
break;
case 66:
#line 170 "parser.y"
	{ yyval.astree = astCreate(AST_CHAM_F, yystack.l_mark[-3].symbol, yystack.l_mark[-1].astree, 0, 0, 0); }
break;
case 67:
#line 173 "parser.y"
	{ yyval.astree = yystack.l_mark[0].astree; }
break;
case 68:
#line 174 "parser.y"
	{ yyval.astree = astCreate(AST_EMPTY, 0, 0, 0, 0, 0); }
break;
#line 919 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
