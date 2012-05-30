// AST 2012
#ifndef AST_H
#define AST_H

#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

#define AST_SYMBOL		1
#define AST_SYMBOL_VEC	2
#define AST_SYMBOL_LIT	3

#define AST_OP_SUM		4
#define AST_OP_SUB		5
#define AST_OP_MUL		6
#define AST_OP_DIV		7
#define AST_OP_LES		8
#define AST_OP_GRE		9
#define AST_OP_LE		10
#define AST_OP_GE		11
#define AST_OP_EQ		12
#define AST_OP_NE		13
#define AST_OP_AND		14
#define AST_OP_OR		15

#define AST_LIST_E		16
#define AST_CHAM_F		17

#define AST_IF			18
#define AST_WHILE		19
#define AST_DO_WHILE	20

#define AST_RET			21
#define AST_INP			22
#define AST_OUT			23

#define AST_ATR_VAR		24
#define AST_ATR_VEC		25

#define AST_SEQ			26
#define AST_PARAM		27

#define AST_T_INT		28
#define AST_T_FLO		29
#define AST_T_BOO		30
#define AST_T_CHA		31

#define AST_LIST_P		32

#define AST_DEF_F		33
#define AST_DECL_VEC	34
#define AST_VEC_SIZE	35
#define AST_DECL_VAR	36
#define AST_DECL_GL		37

#define AST_PROG		38

#define AST_COM 		39

#define AST_BLO_COM		40

#define AST_EMPTY		41


typedef struct astreenode
{
	int type;
	int lineNumber;
	HASH_ELEMENT *symbol;
	struct astreenode *children[MAX_CHILDREN];
} ASTREE;

ASTREE *astCreate(int type, HASH_ELEMENT *symbol, ASTREE *s0, ASTREE *s1, ASTREE *s2, ASTREE *s3);
void astPrintTree(ASTREE *root);
void astPrintTree_aux(ASTREE *root, int level);
void astPrintNode(ASTREE *node);
void astPrintTreeSrc(ASTREE *node);
int dataTypeMap(int type);
void printDataType(int dataType);

#endif