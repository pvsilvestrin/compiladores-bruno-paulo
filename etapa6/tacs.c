//Bruno Nunes e Paulo Silvestrin

#include "tacs.h"
#include <stdlib.h>

FILE *nasmData;
FILE *nasmBss;
FILE *nasmText;

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

		case TAC_MOVE: printf("TAC_MOVE");
			break;
		case TAC_MOVE_IND: printf("TAC_MOVE_IND");
			break;

		case TAC_PARAM: printf("TAC_PARAM");
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
		case TAC_ARG_OUT: printf("TAC_ARG_OUT");
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
	if(tac != 0) tacPrintNasm(tac->prev);
	tacPrintOneNasm(tac);
}

void tacPrintOneNasm(TAC *tac) {
	if(!tac) return;

	switch(tac->type) {
		case TAC_SYMBOL:
			break;
		case TAC_SYMBOL_VEC:
			symbolVecNasm(tac);
			break;
		case TAC_SYMBOL_LIT:
			symbolLitNasm(tac);
			break;
		case TAC_OP_SUM:
			opSumNasm(tac);
			break;
		case TAC_OP_SUB:
			opSubNasm(tac);
			break;
		case TAC_OP_MUL:
			opMulNasm(tac);
			break;
		case TAC_OP_DIV:
			opDivNasm(tac);
			break;
		case TAC_OP_LES:
			opLesNasm(tac);
			break;
		case TAC_OP_GRE:
			opGreNasm(tac);
			break;
		case TAC_OP_LE:
			opLENasm(tac); 
			break;
		case TAC_OP_GE:
			opGENasm(tac); 
			break;
		case TAC_OP_EQ:
			opEqNasm(tac);
			break;
		case TAC_OP_NE:
			opNeNasm(tac);
			break;
		case TAC_OP_AND:
			opAndNasm(tac);
			break;
		case TAC_OP_OR:
			opOrNasm(tac);
			break;

		case TAC_CALL:
			break;

		case TAC_RET:
			break;
		case TAC_INP:
			break;

		case TAC_MOVE:
			moveNasm(tac);
			break;
		case TAC_MOVE_IND:
			moveIndNasm(tac);
			break;

		case TAC_PARAM:
			break;

		case TAC_DECL_VEC:
			declVecNasm(tac);
			break;
		case TAC_DECL_VAR:
			declVarNasm(tac);
			break;

		case TAC_JFALSE:
			fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\n", tac->op1->text);
			fprintf(nasmText, "\t\tcmp\t\t\teax, 0\n");
			fprintf(nasmText, "\t\tje\t\t\t%s\n", tac->res->text);
			break;
		case TAC_JTRUE:
			fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\n", tac->op1->text);
			fprintf(nasmText, "\t\tcmp\t\t\teax, 0\n");
			fprintf(nasmText, "\t\tjne\t\t\t%s\n", tac->res->text);
			break;
		case TAC_JUMP:
			fprintf(nasmText, "\t\tjmp\t\t\t%s\n", tac->res->text);
			break;
		case TAC_JUMPIND:
			break;
		case TAC_LABEL:
			fprintf(nasmText, "%s:\n", tac->res->text);
			break;

		case TAC_BEGINF:
			fprintf(nasmText, "%s:\n", tac->res->text);
			break;
		case TAC_ENDF:
			break;

		case TAC_ARG: //colocar tac->res em tac->op1
			break;
		case TAC_ARG_OUT: 
			outputNasm(tac);
			break;
		default : printf("UNKNOWN");
	}
}

void opSumNasm(TAC* tac) {
	if(tac->op1->dataType != DATATYPE_FLOATING && tac->op2->dataType != DATATYPE_FLOATING) {
		tac->res->dataType = DATATYPE_INTEGER;

		fprintf(nasmBss, "%s:\tresd\t1\t; integer\n", tac->res->text);

		fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\n", tac->op1->text);
		fprintf(nasmText, "\t\tadd\t\t\teax, [%s]\n", tac->op2->text);
		fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n\n", tac->res->text);
	}
	else {
		tac->res->dataType = DATATYPE_FLOATING;
		fprintf(nasmBss, "%s:\tresq\t1\t; floating\n", tac->res->text);

		if(tac->op1->dataType == DATATYPE_FLOATING) {
			fprintf(nasmText, "\t\tfld\t\t\tqword [%s]\n", tac->op1->text);
		} else {
			fprintf(nasmText, "\t\tfild\t\t\tdword [%s]\n", tac->op1->text);
		}


		if(tac->op2->dataType == DATATYPE_FLOATING) {
			fprintf(nasmText, "\t\tfadd\t\tqword [%s]\n", tac->op2->text);
		} else {
			fprintf(nasmText, "\t\tfiadd\t\tdword [%s]\n", tac->op2->text);
		}

		fprintf(nasmText, "\t\tfstp\t\tqword [%s]\n\n", tac->res->text);
	}
}

void opSubNasm(TAC* tac) {
	if(tac->op1->dataType != DATATYPE_FLOATING && tac->op2->dataType != DATATYPE_FLOATING) {
		tac->res->dataType = DATATYPE_INTEGER;

		fprintf(nasmBss, "%s:\tresd\t1\t; integer\n", tac->res->text);

		fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\n", tac->op1->text);
		fprintf(nasmText, "\t\tsub\t\t\teax, [%s]\n", tac->op2->text);
		fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n\n", tac->res->text);
	}
	else {
		tac->res->dataType = DATATYPE_FLOATING;
		fprintf(nasmBss, "%s:\tresq\t1\t; floating\n", tac->res->text);

		if(tac->op1->dataType == DATATYPE_FLOATING) {
			fprintf(nasmText, "\t\tfld\t\t\tqword [%s]\n", tac->op1->text);
		} else {
			fprintf(nasmText, "\t\tfild\t\t\tdword [%s]\n", tac->op1->text);
		}


		if(tac->op2->dataType == DATATYPE_FLOATING) {
			fprintf(nasmText, "\t\tfsub\t\tqword [%s]\n", tac->op2->text);
		} else {
			fprintf(nasmText, "\t\tfisub\t\tdword [%s]\n", tac->op2->text);
		}

		fprintf(nasmText, "\t\tfstp\t\tqword [%s]\n\n", tac->res->text);
	}
}

void opMulNasm(TAC* tac) {
	if(tac->op1->dataType != DATATYPE_FLOATING && tac->op2->dataType != DATATYPE_FLOATING) {
		tac->res->dataType = DATATYPE_INTEGER;

		fprintf(nasmBss, "%s:\tresd\t1\t; integer\n", tac->res->text);

		fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\n", tac->op1->text);
		fprintf(nasmText, "\t\timul\t\t\teax, [%s]\n", tac->op2->text);
		fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n\n", tac->res->text);
	}
	else {
		tac->res->dataType = DATATYPE_FLOATING;
		fprintf(nasmBss, "%s:\tresq\t1\t; floating\n", tac->res->text);

		if(tac->op1->dataType == DATATYPE_FLOATING) {
			fprintf(nasmText, "\t\tfld\t\t\tqword [%s]\n", tac->op1->text);
		} else {
			fprintf(nasmText, "\t\tfild\t\t\tdword [%s]\n", tac->op1->text);
		}


		if(tac->op2->dataType == DATATYPE_FLOATING) {
			fprintf(nasmText, "\t\tfmul\t\tqword [%s]\n", tac->op2->text);
		} else {
			fprintf(nasmText, "\t\tfimul\t\tdword [%s]\n", tac->op2->text);
		}

		fprintf(nasmText, "\t\tfstp\t\tqword [%s]\n\n", tac->res->text);
	}
}

void opDivNasm(TAC* tac) {
	if(tac->op1->dataType != DATATYPE_FLOATING && tac->op2->dataType != DATATYPE_FLOATING) {
		tac->res->dataType = DATATYPE_INTEGER;

		fprintf(nasmBss, "%s:\tresd\t1\t; integer\n", tac->res->text);

		fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\n", tac->op1->text);
		fprintf(nasmText, "\t\tmov\t\t\tedx, 0\n", tac->op1->text);
		fprintf(nasmText, "\t\tidiv\t\t\tdword [%s]\n", tac->op2->text);
		fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n\n", tac->res->text);
	}
	else {
		tac->res->dataType = DATATYPE_FLOATING;
		fprintf(nasmBss, "%s:\tresq\t1\t; floating\n", tac->res->text);

		if(tac->op1->dataType == DATATYPE_FLOATING) {
			fprintf(nasmText, "\t\tfld\t\t\tqword [%s]\n", tac->op1->text);
		} else {
			fprintf(nasmText, "\t\tfild\t\t\tdword [%s]\n", tac->op1->text);
		}


		if(tac->op2->dataType == DATATYPE_FLOATING) {
			fprintf(nasmText, "\t\tfdiv\t\tqword [%s]\n", tac->op2->text);
		} else {
			fprintf(nasmText, "\t\tfidiv\t\tdword [%s]\n", tac->op2->text);
		}

		fprintf(nasmText, "\t\tfstp\t\tqword [%s]\n\n", tac->res->text);
	}
}

void initCompOpsNasm(TAC *tac){
	tac->res->dataType = DATATYPE_BOOLEAN;
	fprintf(nasmBss, "%s:\tresd\t1\t; boolean\n", tac->res->text);

	if(tac->op1->dataType != DATATYPE_FLOATING && tac->op2->dataType != DATATYPE_FLOATING) {
		fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\n", tac->op1->text);
		fprintf(nasmText, "\t\tmov\t\t\tebx, [%s]\n", tac->op2->text);
		fprintf(nasmText, "\t\tcmp\t\teax, ebx\n");
	}
	else {
		if(tac->op1->dataType == DATATYPE_FLOATING) {
			fprintf(nasmText, "\t\tfld\t\t\tqword [%s]\n", tac->op1->text);
		} else {
			fprintf(nasmText, "\t\tfild\t\tdword [%s]\n", tac->op1->text);
		}

		if(tac->op2->dataType == DATATYPE_FLOATING) {
			fprintf(nasmText, "\t\tfld\t\t\tqword [%s]\n", tac->op2->text);
		} else {
			fprintf(nasmText, "\t\tfild\t\tdword [%s]\n", tac->op2->text);
		}
		fprintf(nasmText, "\t\tfcomip\t\t\t\n");
		//fprintf(nasmText, "\t\tfstsw ah\t\t\t\n");
	}
}

void opLesNasm(TAC* tac) {
	initCompOpsNasm(tac);

	fprintf(nasmText, "\t\tjl\t\t\t%sless\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\teax, 0\n");
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n", tac->res->text);
	fprintf(nasmText, "\t\tjmp\t\t\t%send\n", tac->res->text);
	fprintf(nasmText, "%sless:\n\t\tmov\t\t\teax, 1\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n\n", tac->res->text);
	fprintf(nasmText, "%send:\n", tac->res->text);
}

void opLENasm(TAC* tac) {
	initCompOpsNasm(tac);

	fprintf(nasmText, "\t\tjle\t\t\t%sle\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\teax, 0\n");
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n", tac->res->text);
	fprintf(nasmText, "\t\tjmp\t\t\t%send\n", tac->res->text);
	fprintf(nasmText, "%sle:\n\t\tmov\t\t\teax, 1\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n\n", tac->res->text);
	fprintf(nasmText, "%send:\n", tac->res->text);
}

void opGreNasm(TAC* tac) {
	initCompOpsNasm(tac);

	fprintf(nasmText, "\t\tjg\t\t\t%sgreater\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\teax, 0\n");
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n", tac->res->text);
	fprintf(nasmText, "\t\tjmp\t\t\t%send\n", tac->res->text);
	fprintf(nasmText, "%sgreater:\n\t\tmov\t\t\teax, 1\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n\n", tac->res->text);
	fprintf(nasmText, "%send:\n", tac->res->text);
}

void opGENasm(TAC* tac) {
	initCompOpsNasm(tac);

	fprintf(nasmText, "\t\tjge\t\t\t%sge\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\teax, 0\n");
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n", tac->res->text);
	fprintf(nasmText, "\t\tjmp\t\t\t%send\n", tac->res->text);
	fprintf(nasmText, "%sge:\n\t\tmov\t\t\teax, 1\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n\n", tac->res->text);
	fprintf(nasmText, "%send:\n", tac->res->text);
}

void opEqNasm(TAC* tac) {
	initCompOpsNasm(tac);

	fprintf(nasmText, "\t\tje\t\t\t%seq\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\teax, 0\n");
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n", tac->res->text);
	fprintf(nasmText, "\t\tjmp\t\t\t%send\n", tac->res->text);
	fprintf(nasmText, "%seq:\n\t\tmov\t\t\teax, 1\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n\n", tac->res->text);
	fprintf(nasmText, "%send:\n", tac->res->text);
}

void opNeNasm(TAC* tac) {
	initCompOpsNasm(tac);

	fprintf(nasmText, "\t\tjne\t\t\t%seq\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\teax, 0\n");
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n", tac->res->text);
	fprintf(nasmText, "\t\tjmp\t\t\t%send\n", tac->res->text);
	fprintf(nasmText, "%seq:\n\t\tmov\t\t\teax, 1\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n\n", tac->res->text);
	fprintf(nasmText, "%send:\n", tac->res->text);
}

void opAndNasm(TAC* tac) {
	fprintf(nasmBss, "%s:\tresd\t1\t; boolean\n", tac->res->text);
	// se o primeiro é falso, o and é falso
	fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\n", tac->op1->text);
	fprintf(nasmText, "\t\tcmp\t\t\teax, 0\n");
	fprintf(nasmText, "\t\tje\t\t\t%sfalse\n", tac->res->text);
	// se o segundo é falso, o and é falso
	fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\n", tac->op2->text);
	fprintf(nasmText, "\t\tcmp\t\t\teax, 0\n");
	fprintf(nasmText, "\t\tje\t\t\t%sfalse\n", tac->res->text);
	// se chegou aqui o and é verdadeiro
	fprintf(nasmText, "\t\tmov\t\t\teax, 1\n");
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n", tac->res->text);
	fprintf(nasmText, "\t\tjmp\t\t\t%send\n", tac->res->text);
	// se o and é falso
	fprintf(nasmText, "%sfalse:\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\teax, 0\n");
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n", tac->res->text);
	// continua o código
	fprintf(nasmText, "%send:\n", tac->res->text);
}

void opOrNasm(TAC* tac) {
	fprintf(nasmBss, "%s:\tresd\t1\t; boolean\n", tac->res->text);
	// se o primeiro é verdadeiro, o or é verdadeiro
	fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\n", tac->op1->text);
	fprintf(nasmText, "\t\tcmp\t\t\teax, 1\n");
	fprintf(nasmText, "\t\tje\t\t\t%strue\n", tac->res->text);
	// se o segundo é verdadeiro, o or é verdadeiro
	fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\n", tac->op2->text);
	fprintf(nasmText, "\t\tcmp\t\t\teax, 1\n");
	fprintf(nasmText, "\t\tje\t\t\t%strue\n", tac->res->text);
	// se chegou aqui o or é falso
	fprintf(nasmText, "\t\tmov\t\t\teax, 0\n");
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n", tac->res->text);
	fprintf(nasmText, "\t\tjmp\t\t\t%send\n", tac->res->text);
	// se o or é verdadeiro
	fprintf(nasmText, "%strue:\n", tac->res->text);
	fprintf(nasmText, "\t\tmov\t\t\teax, 1\n");
	fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\n", tac->res->text);
	// continua o código
	fprintf(nasmText, "%send:\n", tac->res->text);
}

void declVarNasm(TAC* tac) {
	switch(tac->res->dataType) {
		case DATATYPE_INTEGER:
			fprintf(nasmBss, "%s:\t\tresd\t1\t; integer\n", tac->res->text);
			break;
		case DATATYPE_FLOATING:
			fprintf(nasmBss, "%s:\t\tresq\t1\t; floating\n", tac->res->text);
			break;
		case DATATYPE_CHARACTER:
			fprintf(nasmBss, "%s:\t\tresd\t1\t; character\n", tac->res->text);
			break;
		case DATATYPE_BOOLEAN:
			fprintf(nasmBss, "%s:\t\tresd\t1\t; character\n", tac->res->text);
			break;
		default: 
			break;
	}
}

void declVecNasm(TAC* tac) {
	switch(tac->res->dataType) {
		case DATATYPE_INTEGER:
			fprintf(nasmBss, "%s:\t\tresd\t%s\t; integer\n", tac->res->text, tac->op1->text);
			break;
		case DATATYPE_FLOATING:
			fprintf(nasmBss, "%s:\t\tresq\t%s\t; floating\n", tac->res->text, tac->op1->text);
			break;
		case DATATYPE_CHARACTER:
			fprintf(nasmBss, "%s:\t\tresd\t%s\t; character\n", tac->res->text, tac->op1->text);
			break;
		case DATATYPE_BOOLEAN:
			fprintf(nasmBss, "%s:\t\tresd\t%s\t; character\n", tac->res->text, tac->op1->text);
			break;
		default: 
			break;
	}
}

void moveNasm(TAC* tac) {
	switch(tac->res->dataType) {
		case DATATYPE_INTEGER:
			fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\t; integer\n", tac->op1->text);
			fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\t; integer\n\n", tac->res->text);
			break;
		case DATATYPE_FLOATING:
			if(tac->op1->dataType == DATATYPE_FLOATING) {
				fprintf(nasmText, "\t\tfld\t\t\tqword [%s]\t; floating\n", tac->op1->text);
				fprintf(nasmText, "\t\tfstp\t\tqword [%s]\t; floating\n\n", tac->res->text);
			} else {
				fprintf(nasmText, "\t\tfild\t\tdword [%s]\t; floating\n", tac->op1->text);
				fprintf(nasmText, "\t\tfstp\t\tqword [%s]\t; floating\n\n", tac->res->text);
			}
			break;
		case DATATYPE_CHARACTER:
			fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\t; character\n", tac->op1->text);
			fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\t; character\n\n", tac->res->text);
			break;
		case DATATYPE_BOOLEAN:
			fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\t; boolean\n", tac->op1->text);
			fprintf(nasmText, "\t\tmov\t\t\t[%s], eax\t; boolean\n\n", tac->res->text);
			break;
		default: 
			break;
	}
}

void moveIndNasm(TAC* tac) {
	switch(tac->res->dataType) {
		case DATATYPE_INTEGER:
			fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\t; integer\n", tac->op1->text);
			fprintf(nasmText, "\t\tmov\t\t\tebx, [%s]\t; integer\n", tac->op2->text);
			fprintf(nasmText, "\t\tmov\t\t\t[%s + 4 * eax], ebx\t; integer\n\n", tac->res->text);
			break;
		case DATATYPE_FLOATING:
			if(tac->op2->dataType == DATATYPE_FLOATING) {
				fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\t; floating\n", tac->op1->text);
				fprintf(nasmText, "\t\tfld\t\t\tqword [%s]\t; floating\n", tac->op2->text);
				fprintf(nasmText, "\t\tfstp\t\tqword [%s + 8 * eax]\t; floating\n\n", tac->res->text);
			} else {
				fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\t; floating\n", tac->op1->text);
				fprintf(nasmText, "\t\tfild\t\tdword [%s]\t; integer\n", tac->op2->text);
				fprintf(nasmText, "\t\tfstp\t\tqword [%s + 8 * eax]\t; floating\n\n", tac->res->text);
			}
			break;
		case DATATYPE_CHARACTER:
			fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\t; character\n", tac->op1->text);
			fprintf(nasmText, "\t\tmov\t\t\tebx, [%s]\t; character\n", tac->op2->text);
			fprintf(nasmText, "\t\tmov\t\t\t[%s + 4 * eax], ebx\t; character\n\n", tac->res->text);
			break;
		case DATATYPE_BOOLEAN:
			fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\t; boolean\n", tac->op1->text);
			fprintf(nasmText, "\t\tmov\t\t\tebx, [%s]\t; boolean\n", tac->op2->text);
			fprintf(nasmText, "\t\tmov\t\t\t[%s + 4 * eax], ebx\t; boolean\n\n", tac->res->text);
			break;
		default: 
			break;
	}
}
/*TAC* findSymbolLitTAC(char* resText, TAC *current) {
	TAC *tac = current;

	while(tac != 0) {
		if(tac->type == TAC_SYMBOL_LIT && strcmp(tac->res->text, resText) == 0) {
			return tac;
		}
		tac = tac->prev;
	}

	return 0;
}*/

void symbolLitNasm(TAC* tac) {
	switch(tac->op1->dataType) {
		case DATATYPE_INTEGER:
			fprintf(nasmData, "%s:\t\tdd\t%s\t\t; integer\n", tac->res->text, tac->op1->text);
			break;
		case DATATYPE_FLOATING:
			fprintf(nasmData, "%s:\t\tdq\t%s\t\t; floating\n", tac->res->text, tac->op1->text);
			break;
		case DATATYPE_CHARACTER:
			fprintf(nasmData, "%s:\t\tdd\t%s\t\t; character\n", tac->res->text, tac->op1->text);
			break;
		case DATATYPE_BOOLEAN:
			if(tac->op1->text[0] == 't') {	// true
				fprintf(nasmData, "%s:\t\tdd\t1\t\t; true\n", tac->res->text);
			} else {					// false
				fprintf(nasmData, "%s:\t\tdd\t0\t\t; false\n", tac->res->text);
			}
			break;
		default: 
			fprintf(nasmData, "%s:\t\tdb\t%s, 0\t\t; string\n", tac->res->text, tac->op1->text);
			break;
	}
}

void symbolVecNasm(TAC* tac) {
	switch(tac->op1->dataType) {
		case DATATYPE_INTEGER:
			fprintf(nasmData, "%s:\t\tdd\t1\t\t; integer\n", tac->res->text);
			fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\t; integer\n", tac->op2->text);
			fprintf(nasmText, "\t\tmov\t\t\tebx, [%s + 4 * eax]\t; integer\n", tac->op1->text);
			fprintf(nasmText, "\t\tmov\t\t\t[%s], ebx\t; integer\n\n", tac->res->text);
			break;
		case DATATYPE_FLOATING:
			fprintf(nasmData, "%s:\t\tdq\t1\t\t; floating\n", tac->res->text);

			fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\t; floating\n", tac->op2->text);
			fprintf(nasmText, "\t\tfld\t\t\tqword [%s + 8 * eax]\t; floating\n", tac->op1->text);
			fprintf(nasmText, "\t\tfstp\t\tqword [%s]\t; floating\n\n", tac->res->text);
			break;
		case DATATYPE_CHARACTER:
			fprintf(nasmData, "%s:\t\tdd\t1\t\t; character\n", tac->res->text);
			fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\t; character\n", tac->op2->text);
			fprintf(nasmText, "\t\tmov\t\t\tebx, [%s + 4 * eax]\t; character\n", tac->op1->text);
			fprintf(nasmText, "\t\tmov\t\t\t[%s], ebx\t; character\n\n", tac->res->text);
			break;
		case DATATYPE_BOOLEAN:
			fprintf(nasmData, "%s:\t\tdd\t1\t\t; boolean\n", tac->res->text);
			fprintf(nasmText, "\t\tmov\t\t\teax, [%s]\t; boolean\n", tac->op2->text);
			fprintf(nasmText, "\t\tmov\t\t\tebx, [%s + 4 * eax]\t; boolean\n", tac->op1->text);
			fprintf(nasmText, "\t\tmov\t\t\t[%s], ebx\t; boolean\n\n", tac->res->text);
			break;
		default: 
			//fprintf(nasmData, "%s:\t\tdb\t%s, 0\t\t; string\n", tac->res->text, tac->op1->text);
			break;
	}
}

void outputNasm(TAC* tac) {
	switch(tac->res->dataType) {
		case DATATYPE_INTEGER:
			fprintf(nasmText, "\t\tpush\t\tdword [%s]\n", tac->res->text);
			fprintf(nasmText, "\t\tpush\t\tdword fmtInt\n");
			fprintf(nasmText, "\t\tcall\t\tprintf\n");
			fprintf(nasmText, "\t\tadd\t\t\tesp, 8\n\n");
			break;
		case DATATYPE_FLOATING:
			fprintf(nasmText, "\t\tpush\t\tdword [%s + 4]\n", tac->res->text);
			fprintf(nasmText, "\t\tpush\t\tdword [%s]\n", tac->res->text);
			fprintf(nasmText, "\t\tpush\t\tdword fmtFlo\n");
			fprintf(nasmText, "\t\tcall\t\tprintf\n");
			fprintf(nasmText, "\t\tadd\t\t\tesp, 12\n\n");
			break;
		case DATATYPE_CHARACTER:
			fprintf(nasmText, "\t\tpush\t\tdword [%s]\n", tac->res->text);
			fprintf(nasmText, "\t\tpush\t\tdword fmtCha\n");
			fprintf(nasmText, "\t\tcall\t\tprintf\n");
			fprintf(nasmText, "\t\tadd\t\t\tesp, 8\n\n");
			break;
		case DATATYPE_BOOLEAN:
			fprintf(nasmText, "\t\tpush\t\tdword [%s]\n", tac->res->text);
			fprintf(nasmText, "\t\tpush\t\tdword fmtInt\n");
			fprintf(nasmText, "\t\tcall\t\tprintf\n");
			fprintf(nasmText, "\t\tadd\t\t\tesp, 8\n\n");	
			break;
		default: //string
			fprintf(nasmText, "\t\tpush\t\tdword %s\n", tac->res->text);
			fprintf(nasmText, "\t\tpush\t\tdword fmtStr\n");
			fprintf(nasmText, "\t\tcall\t\tprintf\n");
			fprintf(nasmText, "\t\tadd\t\t\tesp, 8\n\n");
			break;
	}
}
