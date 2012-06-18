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

//adiciona l2 depois do l1
TAC * tacJoin(TAC *l1, TAC *l2) {
	if(!l1) return l2;
	if(!l2) return l1;

	TAC *t = l2;

	while(t->prev) {
		t = t->prev;
	}

	t->prev = l1;
	l1->next = l2;
	return l2;
}

void tacPrintOne(TAC *tac) {
	if(!tac) return;
	printf("TAC(");

	switch(tac->type) {
		case TAC_SYMBOL: printf("TAC_SYMBOL");
			break;
		case TAC_SYMBOL_VEC: printf("TAC_SYMBOL_VEC");
			break;
		case TAC_SYMBOL_LIT: printf("TAC_SYMBOL_LIT");
			break;
		case TAC_OP_SUM: printf("TAC_OP_SUM");
			break;
		case TAC_OP_SUB: printf("TAC_OP_SUB");
			break;
		case TAC_OP_MUL: printf("TAC_OP_MUL");
			break;
		case TAC_OP_DIV: printf("TAC_OP_DIV");
			break;
		case TAC_OP_LES: printf("TAC_OP_LES");
			break;
		case TAC_OP_GRE: printf("TAC_OP_GRE");
			break;
		case TAC_OP_LE: printf("TAC_OP_LE");
			break;
		case TAC_OP_GE: printf("TAC_OP_GE");
			break;
		case TAC_OP_EQ: printf("TAC_OP_EQ");
			break;
		case TAC_OP_NE: printf("TAC_OP_NE");
			break;
		case TAC_OP_AND: printf("TAC_OP_AND");
			break;
		case TAC_OP_OR: printf("TAC_OP_OR");
			break;

		case TAC_CALL: printf("TAC_CALL");
			break;

		case TAC_RET: printf("TAC_RET");
			break;
		case TAC_INP: printf("TAC_INP");
			break;
		case TAC_OUT: printf("TAC_OUT");
			break;

		case TAC_MOVE: printf("TAC_MOVE");
			break;
		case TAC_MOVE_IND: printf("TAC_MOVE_IND");
			break;

		case TAC_PARAM: printf("TAC_PARAM");
			break;

		case TAC_T_INT: printf("TAC_T_INT");
			break;
		case TAC_T_FLO: printf("TAC_T_FLO");
			break;
		case TAC_T_BOO: printf("TAC_T_BOO");
			break;
		case TAC_T_CHA: printf("TAC_T_CHA");
			break;

		case TAC_DECL_VEC: printf("TAC_DECL_VEC");
			break;
		case TAC_DECL_VAR: printf("TAC_DECL_VAR");
			break;

		case TAC_JFALSE: printf("TAC_JFALSE");
			break;
		case TAC_JTRUE: printf("TAC_JTRUE");
			break;
		case TAC_JUMP: printf("TAC_JUMP");
			break;
		case TAC_JUMPIND: printf("TAC_JUMPIND");
			break;
		case TAC_LABEL: printf("TAC_LABEL");
			break;

		case TAC_BEGINF: printf("TAC_BEGINF");
			break;
		case TAC_ENDF: printf("TAC_ENDF");
			break;

		case TAC_ARG: printf("TAC_ARG");
			break;
		default : printf("UNKNOWN");
	}

	if (tac->res) printf(", %s", tac->res->text); else printf(", ");
	if (tac->op1) printf(", %s", tac->op1->text); else printf(", ");
	if (tac->op2) printf(", %s", tac->op2->text); else printf(", ");
	
	printf(")\n");
}

void tacPrintList(TAC *tac) {	//backwards
	if(tac != 0) tacPrintList(tac->prev);
	tacPrintOne(tac);
}

void tacPrintNasm(TAC *tac){
	//fprintf(NASM, ";INICIO");
	if(tac != 0) tacPrintNasm(tac->prev);
	tacPrintOneNasm(tac);
}

void tacPrintOneNasm(TAC *tac) {
	if(!tac) return;
	printf("TAC(");

	switch(tac->type) {
		case TAC_SYMBOL: printf("TAC_SYMBOL");
			break;
		case TAC_SYMBOL_VEC: printf("TAC_SYMBOL_VEC");
			break;
		case TAC_SYMBOL_LIT: printf("TAC_SYMBOL_LIT");
			break;
		case TAC_OP_SUM: printf("TAC_OP_SUM");
			break;
		case TAC_OP_SUB: printf("TAC_OP_SUB");
			break;
		case TAC_OP_MUL: printf("TAC_OP_MUL");
			break;
		case TAC_OP_DIV: printf("TAC_OP_DIV");
			break;
		case TAC_OP_LES: printf("TAC_OP_LES");
			break;
		case TAC_OP_GRE: printf("TAC_OP_GRE");
			break;
		case TAC_OP_LE: printf("TAC_OP_LE");
			break;
		case TAC_OP_GE: printf("TAC_OP_GE");
			break;
		case TAC_OP_EQ: printf("TAC_OP_EQ");
			break;
		case TAC_OP_NE: printf("TAC_OP_NE");
			break;
		case TAC_OP_AND: printf("TAC_OP_AND");
			break;
		case TAC_OP_OR: printf("TAC_OP_OR");
			break;

		case TAC_INP: printf("TAC_INP");
			break;
		case TAC_OUT: printf("TAC_OUT");
			break;

		case TAC_MOVE: printf("TAC_MOVE");
			break;

		case TAC_DECL_VEC: printf("TAC_DECL_VEC");
			break;
		case TAC_DECL_VAR: printf("TAC_DECL_VAR");

			break;

		case TAC_JFALSE: printf("TAC_JFALSE");
			break;
		case TAC_JTRUE: printf("TAC_JTRUE");
			break;
		case TAC_JUMP: printf("TAC_JUMP");
			break;
		case TAC_JUMPIND: printf("TAC_JUMPIND");
			break;
		case TAC_LABEL: printf("TAC_LABEL");
			break;
		default : printf("UNKNOWN");
	}
}
