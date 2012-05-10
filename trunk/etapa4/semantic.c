//SEMANTIC ANALISYS 2012

#include <stdlib.h>
#include "astree.h"

void checkDeclarations(ASTREE *root){
	int i;

	if(root == 0) return;

	if(root->type == SYMBOL_VARIABLE ||
		root->type == SYMBOL_VECTOR ||
		root->type == SYMBOL_FUNCTION){

		if(root->symbol == 0) {
			printf("Declaration is missing the identifier name");
		} else {
			if (root->symbol->type != SYMBOL_IDENTIFIER)
				printf("symbol %s already defined", root->symbol->text);
			if (root->symbol->type == SYMBOL_IDENTIFIER)
				printf("symbol %s already defined", root->symbol->text);
			if (root->symbol->type != SYMBOL_IDENTIFIER)
				printf("symbol %s already defined", root->symbol->text);
			if (root->symbol->type != SYMBOL_IDENTIFIER)
				printf("symbol %s already defined", root->symbol->text);
		}
	}

	for (i = 0; i < MAX_CHILDREN; ++i) {
		checkDeclarations(root->children[i]);
	}
}

void checkUtilization(ASTREE *root){
	if(root == 0) return;
	
	int i;

	if(root->type == AST_SYMBOL){

		if(root->symbol == 0) {
			printf("Declaration is missing the identifier name");
		} else {
			if (root->symbol->type == SYMBOL_VECTOR ||
				root->symbol->type == SYMBOL_FUNCTION)
				printf("DECLARED FUNCTION OR VECTOR BEING USED AS SCALAR TYPE");
			//NÃO FUNCIONOU NA IMPLEMENTAÇÃO DELE
		}
	}

	for (i = 0; i < MAX_CHILDREN; ++i) {
		checkDeclarations(root->children[i]);
	}
}