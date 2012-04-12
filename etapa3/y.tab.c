#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20101229

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 3 "parser.y"

#include <stdlib.h>
#include <stdio.h>

FILE *yyin;

#line 11 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	HASH_ELEMENT* symbol;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 37 "y.tab.c"
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
    0,    0,    0,    1,    1,    3,    4,    5,    5,    5,
    5,    2,    6,    8,    8,    9,    9,   10,    7,    7,
    7,    7,    7,    7,    7,   11,   17,   17,   17,   17,
   17,   17,   13,   13,   14,   15,   19,   19,   16,   12,
   12,   12,   12,   18,   18,   18,   18,   18,   18,   18,
   18,   18,   18,   18,   18,   18,   18,   18,   18,   18,
   18,   18,   18,   18,   18,   20,   20,
};
static const short yylen[] = {                            2,
    2,    2,    0,    2,    2,    4,    7,    1,    1,    1,
    1,    3,    6,    1,    0,    3,    1,    3,    1,    1,
    1,    1,    1,    1,    0,    3,    1,    3,    1,    3,
    1,    3,    3,    6,    2,    2,    3,    1,    2,    6,
    8,    5,    6,    1,    4,    1,    1,    1,    1,    1,
    1,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    4,    1,    0,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1,    2,    4,    5,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   19,   20,   21,   22,   23,   24,    0,
    8,    9,   10,   11,    0,    0,    0,    0,   35,    0,
   46,   47,   48,   49,   50,   51,    0,    0,    0,   36,
    0,    0,    0,    0,    0,    0,   12,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   26,    0,    0,    0,   14,    0,    0,
    0,    0,    0,   66,    0,   58,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   54,   55,   37,    0,
   30,   32,   28,    0,    0,   13,    0,    0,   42,    0,
   45,   65,    0,    7,   18,   16,    0,   43,    0,    0,
   41,
};
static const short yydgoto[] = {                          3,
    4,    5,   53,   54,   35,    8,   55,   87,   88,   89,
   24,   25,   26,   27,   28,   29,   56,   49,   50,   95,
};
static const short yysindex[] = {                      -259,
 -264,  -28,    0, -259, -259,  -41,  -32,  209,  -18,   12,
    0,    0,    0,    0,   -3,    2,  209, -231,  -40,  -40,
  -48,  197,  -10,    0,    0,    0,    0,    0,    0,   12,
    0,    0,    0,    0,   14,  -40,  -40, -213,    0,  -31,
    0,    0,    0,    0,    0,    0,  -40,  173,  138,    0,
  -40,  -40,   -4,   -2,   -1,  -64,    0,  -27, -210,   88,
  100,   33,  -40,  -40,  112,  -40,  -40,  -40,  -40,  -40,
  -40,  -40,  -40,  -40,  -40,  -40,  -40,  -40,  152,  173,
  197,  197,  197,    0, -199,   21,   40,    0,   41, -175,
  209,  -40,  164,    0,   59,    0,  -14,  -14,  -14,  -14,
  358,  358,  -14,  -14,  -36,  -36,    0,    0,    0,   42,
    0,    0,    0,   22,   12,    0, -210,  209,    0,  124,
    0,    0,  -40,    0,    0,    0, -159,    0,  173,  209,
    0,
};
static const short yyrindex[] = {                       107,
    0,    0,    0,  107,  107,    0,    0,   55,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -58,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -21,
    0,    0,    0,    0,    0,    0,    0,  -43,  -34,    0,
    0,    0,   -8,   -6,    1,    0,    0,  -49,   81,    0,
    0,    0,    0,   82,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   31,
  -58,  -58,  -58,    0,    0,    0,    0,    0,   93,    0,
  -56,    0,    0,    0,    0,    0,   15,   27,   39,   51,
   53,  347,   65,   77,   -9,    3,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -56,    0,    0,
    0,    0,    0,    0,    0,    0,  -55,    0,   43,  -56,
    0,
};
static const short yygindex[] = {                        10,
    0,    0,  187,  364,  -22,    0,  215,    0,   32,    0,
    0,    0,    0,    0,    0,    0,  122,  432,  -59,    0,
};
#define YYTABLESIZE 631
static const short yytable[] = {                         47,
   25,    1,   25,   40,   94,   76,   38,   58,   64,    6,
   77,    9,   52,   11,   12,   39,    2,   13,  109,   44,
   44,   44,   44,   44,   38,   44,   14,   76,   74,   10,
   75,   52,   77,   52,   52,   52,   36,   44,   44,   30,
   44,   37,   51,   53,   39,   53,   53,   53,   57,   52,
   52,   62,   52,   59,   81,   59,   82,   83,   59,   63,
   84,   53,   53,   85,   53,   86,   25,   60,   25,   40,
   60,   44,   92,   59,   59,    6,   59,  114,  115,   61,
  116,   39,   61,   52,  117,   60,   60,  118,   60,   33,
   38,   62,  125,   63,   62,   53,   63,   61,   61,  122,
   61,   34,  123,   44,  130,   56,    3,   59,   56,   62,
   62,   63,   62,   25,  124,   52,   29,   57,   31,   60,
   57,   15,   67,   56,   56,   27,   56,   53,   90,   76,
   74,   61,   75,   17,   77,   57,   57,    0,   57,   59,
   91,   76,   74,   62,   75,   63,   77,   72,  126,   73,
    0,   60,   96,   76,   74,   33,   75,   56,   77,   72,
    0,   73,    0,   61,  128,   76,   74,   34,   75,   57,
   77,   72,    0,   73,    0,   62,    0,   63,    0,   76,
   74,   78,   75,   72,   77,   73,    6,    0,    0,   56,
    6,    6,    0,   76,   74,    0,   75,   72,   77,   73,
    0,   57,  111,  112,  113,   76,   74,   25,   75,   40,
   77,   72,    0,   73,   76,   74,    0,   75,    0,   77,
   39,   39,   23,   72,    0,   73,    0,    0,    0,   38,
   38,   38,   72,    0,   73,   40,   41,   42,   43,   44,
   45,   46,   44,   44,  110,    0,    0,    0,   44,   44,
   44,   44,   44,   44,   52,   52,  121,    0,    0,    0,
   52,   52,   52,   52,   52,   52,   53,   53,   31,   32,
   33,   34,   53,   53,   53,   53,   53,   53,   59,   59,
    0,    0,    0,    0,   59,   59,   59,   59,   59,   59,
   60,   60,    0,    0,   33,   33,   60,   60,   60,   60,
   60,   60,   61,   61,    0,  119,   34,   34,   61,   61,
   61,   61,   61,   61,   62,   62,   63,   63,    0,   22,
   62,   62,   62,   62,   62,   62,   63,   63,   56,   56,
    0,   22,  127,    0,   56,   56,   56,   56,   56,   56,
   57,   57,    0,    0,  131,    0,   57,   57,   57,   57,
   57,   57,    0,    0,    0,    0,    0,   66,   67,   68,
   69,   70,   71,    7,    0,    0,    0,    7,    7,   66,
   67,   68,   69,   70,   71,    0,    0,    0,    0,    0,
    0,   66,   67,   68,   69,   70,   71,   64,    0,    0,
   64,    0,    0,   66,   67,   68,   69,   70,   71,   76,
   74,    0,   75,    0,   77,   64,    0,   66,   67,   68,
   69,   70,   71,    0,    0,    0,    0,   72,    0,   73,
    0,   66,   67,   68,   69,   70,   71,    0,    0,    0,
    0,    0,    0,   66,   67,   68,   69,   70,   71,   64,
    0,    0,   66,   67,   68,   69,   70,   71,    0,    0,
   48,    0,    0,    0,    0,    0,    0,    1,   15,    0,
    0,   16,   17,   18,   19,   20,    0,   60,   61,    0,
   15,   64,   21,   16,   17,   18,   19,   20,   65,    0,
    0,    0,   79,   80,   21,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   93,    0,    0,   97,   98,   99,
  100,  101,  102,  103,  104,  105,  106,  107,  108,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  120,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  129,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   64,   64,    0,    0,    0,    0,    0,    0,    0,    0,
   64,   64,    0,    0,    0,    0,    0,   66,   67,   68,
   69,
};
static const short yycheck[] = {                         40,
   59,  261,   59,   59,   64,   42,   41,   30,   40,   59,
   47,  276,   61,    4,    5,   59,  276,   59,   78,   41,
   42,   43,   44,   45,   59,   47,   59,   42,   43,   58,
   45,   41,   47,   43,   44,   45,   40,   59,   60,   58,
   62,   40,   91,   41,  276,   43,   44,   45,   59,   59,
   60,  265,   62,   40,   59,   41,   59,   59,   44,   91,
  125,   59,   60,   91,   62,  276,  125,   41,  125,  125,
   44,   93,   40,   59,   60,  125,   62,  277,   58,   41,
   41,  125,   44,   93,   44,   59,   60,  263,   62,   59,
  125,   41,  115,   41,   44,   93,   44,   59,   60,   41,
   62,   59,   61,  125,  264,   41,    0,   93,   44,   59,
   60,   59,   62,   59,   93,  125,  125,   41,  125,   93,
   44,   41,   41,   59,   60,  125,   62,  125,   41,   42,
   43,   93,   45,   41,   47,   59,   60,   -1,   62,  125,
   41,   42,   43,   93,   45,   93,   47,   60,  117,   62,
   -1,  125,   41,   42,   43,  125,   45,   93,   47,   60,
   -1,   62,   -1,  125,   41,   42,   43,  125,   45,   93,
   47,   60,   -1,   62,   -1,  125,   -1,  125,   -1,   42,
   43,   44,   45,   60,   47,   62,    0,   -1,   -1,  125,
    4,    5,   -1,   42,   43,   -1,   45,   60,   47,   62,
   -1,  125,   81,   82,   83,   42,   43,  264,   45,  265,
   47,   60,   -1,   62,   42,   43,   -1,   45,   -1,   47,
  264,  265,    8,   60,   -1,   62,   -1,   -1,   -1,  264,
  265,   17,   60,   -1,   62,  276,  277,  278,  279,  280,
  281,  282,  264,  265,   93,   -1,   -1,   -1,  270,  271,
  272,  273,  274,  275,  264,  265,   93,   -1,   -1,   -1,
  270,  271,  272,  273,  274,  275,  264,  265,  257,  258,
  259,  260,  270,  271,  272,  273,  274,  275,  264,  265,
   -1,   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,
  264,  265,   -1,   -1,  264,  265,  270,  271,  272,  273,
  274,  275,  264,  265,   -1,   91,  264,  265,  270,  271,
  272,  273,  274,  275,  264,  265,  264,  265,   -1,  123,
  270,  271,  272,  273,  274,  275,  274,  275,  264,  265,
   -1,  123,  118,   -1,  270,  271,  272,  273,  274,  275,
  264,  265,   -1,   -1,  130,   -1,  270,  271,  272,  273,
  274,  275,   -1,   -1,   -1,   -1,   -1,  270,  271,  272,
  273,  274,  275,    0,   -1,   -1,   -1,    4,    5,  270,
  271,  272,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,
   -1,  270,  271,  272,  273,  274,  275,   41,   -1,   -1,
   44,   -1,   -1,  270,  271,  272,  273,  274,  275,   42,
   43,   -1,   45,   -1,   47,   59,   -1,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   -1,   60,   -1,   62,
   -1,  270,  271,  272,  273,  274,  275,   -1,   -1,   -1,
   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,   93,
   -1,   -1,  270,  271,  272,  273,  274,  275,   -1,   -1,
   19,   -1,   -1,   -1,   -1,   -1,   -1,  261,  262,   -1,
   -1,  265,  266,  267,  268,  269,   -1,   36,   37,   -1,
  262,  125,  276,  265,  266,  267,  268,  269,   47,   -1,
   -1,   -1,   51,   52,  276,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   63,   -1,   -1,   66,   67,   68,
   69,   70,   71,   72,   73,   74,   75,   76,   77,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   92,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  123,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
"$accept : programa",
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
"lista_parametros : lista_parametros_nao_vazia",
"lista_parametros :",
"lista_parametros_nao_vazia : parametro ',' lista_parametros_nao_vazia",
"lista_parametros_nao_vazia : parametro",
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
"output : KW_OUTPUT lista_expressoes_nao_vazia",
"lista_expressoes_nao_vazia : expressao ',' lista_expressoes_nao_vazia",
"lista_expressoes_nao_vazia : expressao",
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
"lista_expressoes : lista_expressoes_nao_vazia",
"lista_expressoes :",

};
#endif
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

int      yydebug;
int      yynerrs;

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 164 "parser.y"

#include "main.c"

int yyerror(char *t) {
	printf("Syntax Error on line %d\n", getLineNumber());
	exit(3);
}
#line 435 "y.tab.c"

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
