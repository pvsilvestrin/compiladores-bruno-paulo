//Bruno Nunes e Paulo Silvestrin
#ifndef TACS_HEADER
#define TACS_HEADER

#include "hash.h"
#include <stdio.h>


#define TAC_SYMBOL		1

#define TAC_ADD			2


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


#endif