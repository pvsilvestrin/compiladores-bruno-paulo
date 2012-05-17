//Bruno Nunes e Paulo Silvestrin

#include "tacs.h"
#include <stdlib.h>


TAC * tacCreate(int type, HASH_ELEMENT *res, HASH_ELEMENT *op1, HASH_ELEMENT *op2) {
	TAC *newTac = 0;
	newTac = (TAC*) calloc(1, sizeof(TAC));
	newTac->type = type;
	newTac->res = res;
	newTac->op1 = op1;
	newTac->op2 = op2;
	newTac->prev = 0;
	newTac->next = 0;
	return newTac;
}

TAC * tacJoin(TAC *l1, TAC *l2) {
	if(!l1) return l2;
	if(!l2) return l1;

	TAC *t;

	for(t=l2; t->prev; t = t->prev)
		;

	t->prev = l1;
	return l2;
}

void tacPrintOne(TAC *tac) {
	if(!tac) return;
	printf("TAC(");

	switch(tac->type) {
		case TAC_ADD: printf("TAC_ADD ");
			break;
		default : printf("UNKNOWN");
	}

	if (tac->res) printf(", %s", tac->res->text); else printf(",");
	if (tac->op1) printf(", %s", tac->op1->text); else printf(",");
	if (tac->op2) printf(", %s", tac->op2->text); else printf(",");
	
	printf(")\n");
}

void tacPrintList(TAC *tac) {	//backwards
	for(; tac; tac = tac->prev)
		tacPrintOne(tac);
}
