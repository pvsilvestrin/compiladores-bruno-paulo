// AST 2012

#include "astree.h"

ASTREE *astCreate(int type, HASH_ELEMENT *symbol, ASTREE *s0, ASTREE *s1, ASTREE *s2, ASTREE *s3) {
	ASTREE *newNode;
	newNode = (ASTREE*) calloc(1, sizeof(ASTREE));
	newNode->type = type;
	newNode->symbol = symbol;
	newNode->children[0] = s0;
	newNode->children[1] = s1;
	newNode->children[2] = s2;
	newNode->children[3] = s3;
	return newNode;
}

void *astPrintTree(ASTREE *root) {
	if (root == 0)
		return;
	
	astPrintNode2(root);
	
	int i;

	for(i = 0; i < MAX_CHILDREN; i++)
		astPrintTree(root->children[i]);
}

void *astPrintTree_aux(ASTREE *root, int level) {
	if (root == 0)
		return;
	
	/*int i;
	for (i = 0; i < level; ++i)	{
		printf("  ");
	}*/
	astPrintNode2(root);
	
	int i;
	for(i = 0; i < MAX_CHILDREN; i++){
		astPrintTree_aux(root->children[i], level+1);
	}
}

void *astPrintNode2(ASTREE *node) {
	if (node == 0)
		return;
	int i;
	switch(node->type) {
		case AST_SYMBOL: printf("%s", node->symbol->text);
			break;
		case AST_OP_SUM: printf("+");
			break;
		case AST_OP_SUB: printf("-");
			break;
		case AST_OP_MUL: printf("*");
			break;
		case AST_OP_DIV: printf("/");
			break;
		case AST_OP_LES: printf("<");
			break;
		case AST_OP_GRE: printf(">");
			break;
		case AST_OP_LE: printf("<=");
			break;
		case AST_OP_GE: printf(">=");
			break;
		case AST_OP_EQ: printf("==");
			break;
		case AST_OP_NE: printf("!=");
			break;
		case AST_OP_AND: printf("&&");
			break;
		case AST_OP_OR: printf("||");
			break;
		case AST_LIST_E: printf(" ");
			break;
		case AST_EXPR: printf("Expressao");
			break;
		case AST_IF: printf("If");
			break;
		case AST_WHILE: printf("While");
			break;
		case AST_DO_WHILE: printf("Do While");
			break;
		case AST_RET: printf("return");
			break;
		case AST_INP: printf("input %s;", node->symbol->text);
			break;
		case AST_OUT: printf("output");
			break;
		case AST_ATR: printf("Atribuicao");
			break;
		case AST_SEQ: printf("\n");
			break;
		case AST_PARAM: printf("%s: ", node->symbol->text);
			break;
		case AST_T_INT: printf("integer");
			break;
		case AST_T_FLO: printf("floating");
			break;
		case AST_T_BOO: printf("boolean");
			break;
		case AST_T_CHA: printf("character");
			break;
		case AST_LIST_P: printf("");
			break;
		case AST_CAB: printf("%s: ", node->symbol->text);
			break;
		case AST_DEF_F: printf("");
			break;
		case AST_DECL_VEC: printf("declare %s: ", node->symbol->text);
			break;
		case AST_VEC_SIZE: printf(" [%s]", node->symbol->text);
			break;
		case AST_DECL_VAR: printf("declare %s: ", node->symbol->text);
			break;
		case AST_PROG: printf("\n");
			break;
		case AST_FIML: printf(";");
			break;
		case AST_INIPAR: printf("(");
			break;
		case AST_FIMPAR: printf(")");
			break;
		case AST_COMM: printf(", ");
			break;
		case AST_SEQ_COM: printf("");
			break;
		case AST_INICHA: printf("\n{");
			break;
		case AST_FIMCHA: printf("}\n");
			break;
		default: printf("UNKNOWN");
			break;
	}
	
	//if (node->symbol != 0)
	//	printf(", %s", node->symbol->text);
		
	//printf("\n");
}


void *astPrintNode(ASTREE *node) {
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
		case AST_EXPR: printf("Expressao");
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
		case AST_PROG: printf("Programa");
			break;
		default: printf("UNKNOWN");
			break;
	}
	
	if (node->symbol != 0)
		printf(", %s", node->symbol->text);
		
	printf(");\n");
}