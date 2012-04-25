// AST 2012

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILDREN 4

#define AST_SYMBOL		1

#define AST_OP_SUM		2
#define AST_OP_SUB		3
#define AST_OP_MUL		4
#define AST_OP_DIV		5
#define AST_OP_LES		6
#define AST_OP_GRE		7
#define AST_OP_LE		8
#define AST_OP_GE		9
#define AST_OP_EQ		10
#define AST_OP_NE		11
#define AST_OP_AND		12
#define AST_OP_OR		13

#define AST_LIST_E		14
#define AST_EXPR		15

#define AST_IF			16
#define AST_WHILE		17
#define AST_DO_WHILE	18

#define AST_RET			19
#define AST_INP			20
#define AST_OUT			21

#define AST_ATR			22

#define AST_SEQ			23
#define AST_PARAM		24

#define AST_T_INT		25
#define AST_T_FLO		26
#define AST_T_BOO		27
#define AST_T_CHA		28

#define AST_LIST_P		29

#define AST_CAB			30
#define AST_DEF_F		31
#define AST_DECL_VEC	32
#define AST_VEC_SIZE	33
#define AST_DECL_VAR	34

#define AST_PROG		35


#define AST_EMPTY		50


typedef struct astreenode
{
	int type;
	HASH_ELEMENT *symbol;
	struct astreenode *children[MAX_CHILDREN];
} ASTREE;

ASTREE *astCreate(int type, HASH_ELEMENT *symbol, ASTREE *s0, ASTREE *s1, ASTREE *s2, ASTREE *s3);
void *astPrintTree(ASTREE *root);
void *astPrintTree_aux(ASTREE *root, int level);
void *astPrintNode(ASTREE *node);
void *astPrintNode2(ASTREE *node);

/*
parser:
#include "hash.h"
#include "astree.h"

%union {
	ASTREE *astree;
	HASH *symbol;
};


%token<symbol> LIT_INTEGER 281

expr:
'(' expr ')'	{ astPrintTree($2); $$ = $2; }
expr '+' expr	{ $$ = astCreate(AST_ADD, 0, $1, $3, 0, 0); }
LIT_INTEGER		{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
 
 
scanner:
#include stdlib.h
		hash.h
		astree.h
		y.tab.h
			
{DIGIT}+ {yylval.symbol=hashInsert(yytext)}
*/