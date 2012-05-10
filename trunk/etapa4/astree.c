// AST 2012

#include "astree.h"

FILE *yyout;

ASTREE *astCreate(int type, HASH_ELEMENT *symbol, ASTREE *s0, ASTREE *s1, ASTREE *s2, ASTREE *s3) {
	ASTREE *newNode;
	newNode = (ASTREE*) calloc(1, sizeof(ASTREE));
	newNode->type = type;
	newNode->symbol = symbol;
	newNode->children[0] = s0;
	newNode->children[1] = s1;
	newNode->children[2] = s2;
	newNode->children[3] = s3;
	newNode->lineNumber = getLineNumber();
	return newNode;
}

void astPrintTree(ASTREE *root) {
	astPrintTree_aux(root, 1);
}

void astPrintTree_aux(ASTREE *root, int level) {
	if (root == 0)
		return;
	
	int i;
	for (i = 0; i < level; ++i)	{
		printf("  ");
	}

	astPrintNode(root);
	
	for(i = 0; i < MAX_CHILDREN; i++){
		astPrintTree_aux(root->children[i], level+1);
	}
}

void astPrintTreeSrc (ASTREE *node) {
	if (node == 0)
		return;

	int i;

	switch(node->type) {
		case AST_SYMBOL: fprintf(yyout, "%s", node->symbol->text);
			break;
		case AST_OP_SUM: fprintf(yyout, "(");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, " + ");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_OP_SUB: fprintf(yyout, "(");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, " - ");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_OP_MUL: fprintf(yyout, "(");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, " * ");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_OP_DIV: fprintf(yyout, "(");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, " / ");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_OP_LES: fprintf(yyout, "(");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, " < ");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_OP_GRE: fprintf(yyout, "(");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, " > ");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_OP_LE: fprintf(yyout, "(");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, " <= ");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_OP_GE: fprintf(yyout, "(");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, " >= ");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_OP_EQ: fprintf(yyout, "(");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, " == ");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_OP_NE: fprintf(yyout, "(");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, " != ");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_OP_AND: fprintf(yyout, "(");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, " && ");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_OP_OR: fprintf(yyout, "(");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, " || ");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_LIST_E: fprintf(yyout, " ");
			astPrintTreeSrc(node->children[0]);
			if(node->children[1] != 0) {
				fprintf(yyout, ",");
				astPrintTreeSrc(node->children[1]);
			}
			break;
		case AST_IF: fprintf(yyout, "if (");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, ")\nthen ");
			astPrintTreeSrc(node->children[1]);
			if(node->children[2] != 0) {
				fprintf(yyout, "\nelse ");
				astPrintTreeSrc(node->children[2]);
			}
			break;
		case AST_WHILE:fprintf(yyout, "while (");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, ")\n");
			astPrintTreeSrc(node->children[1]);
			break;
		case AST_DO_WHILE: fprintf(yyout, "do");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, "\nwhile (");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")");
			break;
		case AST_RET: fprintf(yyout, "return ");
			astPrintTreeSrc(node->children[0]);
			break;
		case AST_INP: fprintf(yyout, "input %s", node->symbol->text);
			break;
		case AST_OUT: fprintf(yyout, "output");
			astPrintTreeSrc(node->children[0]);
			break;
		case AST_ATR: fprintf(yyout, "%s = ", node->symbol->text);
			astPrintTreeSrc(node->children[0]);
			break;
		case AST_CHAM_F: fprintf(yyout, "%s (", node->symbol->text);
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, ")");
			break;
		case AST_SEQ: fprintf(yyout, "\n");
			astPrintTreeSrc(node->children[0]);
			if(node->children[1] != 0) {
				fprintf(yyout, ";");
				astPrintTreeSrc(node->children[1]);
			}
			break;
		case AST_PARAM: fprintf(yyout, "%s: ", node->symbol->text);
			astPrintTreeSrc(node->children[0]);
			break;
		case AST_T_INT: fprintf(yyout, "integer");
			break;
		case AST_T_FLO: fprintf(yyout, "floating");
			break;
		case AST_T_BOO: fprintf(yyout, "boolean");
			break;
		case AST_T_CHA: fprintf(yyout, "character");
			break;
		case AST_LIST_P: astPrintTreeSrc(node->children[0]);
			if(node->children[1] != 0) {
				fprintf(yyout, ", ");
				astPrintTreeSrc(node->children[1]);
			}
			break;
		case AST_CAB: fprintf(yyout, "%s: ", node->symbol->text);
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, "(");
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ")\n");
			break;
		case AST_DEF_F: fprintf(yyout, "\n");
			astPrintTreeSrc(node->children[0]);
			astPrintTreeSrc(node->children[1]);
			fprintf(yyout, ";");
			break;
		case AST_DECL_VEC: fprintf(yyout, "declare %s: ", node->symbol->text);
			astPrintTreeSrc(node->children[0]);
			astPrintTreeSrc(node->children[1]);
			break;
		case AST_VEC_SIZE: fprintf(yyout, " [%s]", node->symbol->text);
			break;
		case AST_DECL_VAR: fprintf(yyout, "declare %s: ", node->symbol->text);
			astPrintTreeSrc(node->children[0]);
			break;
		case AST_DECL_GL: astPrintTreeSrc(node->children[0]);
			fprintf(yyout, ";");
			break;
		case AST_PROG: fprintf(yyout, "\n");
			for(i = 0; i < MAX_CHILDREN; i++)
				astPrintTreeSrc(node->children[i]);
			break;
		case AST_BLO_COM: fprintf(yyout, "{");
			astPrintTreeSrc(node->children[0]);
			fprintf(yyout, "\n}");
			break;
		case AST_COM: astPrintTreeSrc(node->children[0]);
			break;
		case AST_EMPTY: fprintf(yyout, "");
			break;
		default: break;
	}
}


void astPrintNode(ASTREE *node) {
	if (node == 0)
		return;
	
	printf("ASTREE(");
	
	switch(node->type) {
		case AST_SYMBOL: printf("Simbolo na hash");
			break;
		case AST_OP_SUM: printf("Operacao +");
			break;
		case AST_OP_SUB: printf("Operacao -");
			break;
		case AST_OP_MUL: printf("Operacao *");
			break;
		case AST_OP_DIV: printf("Operacao /");
			break;
		case AST_OP_LES: printf("Operacao <");
			break;
		case AST_OP_GRE: printf("Operacao >");
			break;
		case AST_OP_LE: printf("Operacao LE");
			break;
		case AST_OP_GE: printf("Operacao GE");
			break;
		case AST_OP_EQ: printf("Operacao EQ");
			break;
		case AST_OP_NE: printf("Operacao NE");
			break;
		case AST_OP_AND: printf("Operacao AND");
			break;
		case AST_OP_OR: printf("Operacao OR");
			break;
		case AST_LIST_E: printf("Lista de expressoes");
			break;
		case AST_IF: printf("If");
			break;
		case AST_WHILE: printf("While");
			break;
		case AST_DO_WHILE: printf("Do While");
			break;
		case AST_RET: printf("Return");
			break;
		case AST_INP: printf("Input");
			break;
		case AST_OUT: printf("Output");
			break;
		case AST_ATR: printf("Atribuicao");
			break;
		case AST_CHAM_F: printf("Chamada de funcao");
			break;
		case AST_SEQ: printf("Sequencia de comandos");
			break;
		case AST_PARAM: printf("Parametro");
			break;
		case AST_T_INT: printf("Tipo integer");
			break;
		case AST_T_FLO: printf("Tipo float");
			break;
		case AST_T_BOO: printf("Tipo boolean");
			break;
		case AST_T_CHA: printf("Tipo character");
			break;
		case AST_LIST_P: printf("Lista de parametros");
			break;
		case AST_CAB: printf("Cabecalho");
			break;
		case AST_DEF_F: printf("Definicao de funcao");
			break;
		case AST_DECL_VEC: printf("Declaracao de vetor");
			break;
		case AST_VEC_SIZE: printf("Tamanho do vetor");
			break;
		case AST_DECL_VAR: printf("Declaracao de variavel");
			break;
		case AST_DECL_GL: printf("Declaracao global");
			break;
		case AST_PROG: printf("Programa");
			break;
		case AST_BLO_COM: printf("Bloco de comandos");
			break;
		case AST_COM: printf("Comando");
			break;
		case AST_EMPTY: printf("Empty");
			break;
		default: printf("UNKNOWN");
			break;
	}
	
	if (node->symbol != 0)
		printf(", %s", node->symbol->text);
		
	printf(");\n");
}


int dataTypeMap(int type) {
	switch(type) {
		case AST_T_INT: return DATATYPE_INTEGER;
		case AST_T_FLO: return DATATYPE_FLOATING;
		case AST_T_CHA: return DATATYPE_CHARACTER;
		case AST_T_BOO: return DATATYPE_BOOLEAN;
		default: return 0;
	}
}