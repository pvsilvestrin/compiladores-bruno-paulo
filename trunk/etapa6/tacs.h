//Bruno Nunes e Paulo Silvestrin
#ifndef TACS_HEADER
#define TACS_HEADER

#include "hash.h"
#include <stdio.h>


#define TAC_SYMBOL		1
#define TAC_SYMBOL_VEC	2
#define TAC_SYMBOL_LIT	3

#define TAC_OP_SUM		4
#define TAC_OP_SUB		5
#define TAC_OP_MUL		6
#define TAC_OP_DIV		7
#define TAC_OP_LES		8
#define TAC_OP_GRE		9
#define TAC_OP_LE		10
#define TAC_OP_GE		11
#define TAC_OP_EQ		12
#define TAC_OP_NE		13
#define TAC_OP_AND		14
#define TAC_OP_OR		15

#define TAC_CALL		17

#define TAC_RET			21
#define TAC_INP			22

#define TAC_MOVE		24
#define TAC_MOVE_IND	25

#define TAC_PARAM		27

#define TAC_T_INT		28
#define TAC_T_FLO		29
#define TAC_T_BOO		30
#define TAC_T_CHA		31

#define TAC_DECL_VEC	34
#define TAC_VEC_SIZE	35
#define TAC_DECL_VAR	36
#define TAC_DECL_GL		37

#define TAC_EMPTY		41

#define TAC_JFALSE		42
#define TAC_JTRUE		43
#define TAC_JUMP		44
#define TAC_JUMPIND		45

#define TAC_LABEL		46

#define TAC_BEGINF		47
#define TAC_ENDF		48

#define TAC_ARG			49
#define TAC_ARG_OUT		50

typedef struct tac_structure {
	int type;
	HASH_ELEMENT *res;
	HASH_ELEMENT *op1;
	HASH_ELEMENT *op2;
	struct tac_structure *prev;
	struct tac_structure *next;
} TAC;


TAC * tacCreate(int type, HASH_ELEMENT *res, HASH_ELEMENT *op1, HASH_ELEMENT *op2);
TAC * tacJoin(TAC *l1, TAC *l2);
void tacPrintOne(TAC *tac);
void tacPrintList(TAC *tac);
void tacPrintNasm(TAC *tac);
void tacPrintOneNasm(TAC *tac);

void opSumNasm(TAC* tac);
void opSubNasm(TAC* tac);
void opMulNasm(TAC* tac);
void opDivNasm(TAC* tac);

void initCompOpsNasm(TAC *tac);
void opGENasm(TAC* tac);
void opGreNasm(TAC* tac);
void opLENasm(TAC* tac);
void opLesNasm(TAC* tac);
void opEqNasm(TAC* tac);
void opNeNasm(TAC* tac);

void opAndNasm(TAC* tac);
void opOrNasm(TAC* tac);

void declVarNasm(TAC* tac);
void declVecNasm(TAC* tac);
void moveNasm(TAC* tac);
void moveIndNasm(TAC* tac);
//TAC* findSymbolLitTAC(char* resText, TAC *current);
void symbolLitNasm(TAC* tac);
void symbolVecNasm(TAC* tac);
void outputNasm(TAC* tac);
void printLItNasm(TAC* tac);


#endif