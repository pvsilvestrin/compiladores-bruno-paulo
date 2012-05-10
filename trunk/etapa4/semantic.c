//SEMANTIC ANALISYS 2012

#include <stdlib.h>
#include "astree.h"

void checkDeclarations(ASTREE *root){
	int i;

	if(root == 0) return;

	// do some work

	if(root->type == AST_DECL_VAR ||
		root->type == AST_DECL_VEC ||
		root->type == AST_DEF_F){

		if(root->symbol == 0) {
			printf("Line %d: Declaration is missing the identifier name.\n", root->lineNumber);
		} else {
			if (root->symbol->type != SYMBOL_IDENTIFIER)
				printf("Line %d: Symbol %s already defined.\n", root->lineNumber, root->symbol->text);
			if (root->type == AST_DECL_VAR) root->symbol->type = SYMBOL_VARIABLE;
			if (root->type == AST_DECL_VEC) root->symbol->type = SYMBOL_VECTOR;
			if (root->type == AST_DEF_F) root->symbol->type = SYMBOL_FUNCTION;
		}
	}

	for (i = 0; i < MAX_CHILDREN; ++i) {
		checkDeclarations(root->children[i]);
	}
}

void checkUtilization(ASTREE *root){
	if(root == 0) return;
	
	int i;

	// Make sure variables are not being used as scalars
	if(root->type == AST_SYMBOL ||
		root->type == AST_ATR){
		if(root->symbol == 0) {
			printf("Line %d: Declaration is missing the identifier name.\n", root->lineNumber);
		} else if (root->symbol->type == SYMBOL_VECTOR ||
					root->symbol->type == SYMBOL_FUNCTION)
				printf("Line %d: Declared function or vector %s being used as scalar type.\n", root->lineNumber, root->symbol->text);
		
	}

	// Make sure only declared functions are being called
	if(root->type == AST_CHAM_F){
		if(root->symbol == 0) {
			printf("Line %d: Declaration is missing the identifier name.\n", root->lineNumber);
		} else {
			if (root->symbol->type != SYMBOL_FUNCTION)
				printf("Line %d: Trying to call function %s declared as variable or vector.\n", root->lineNumber, root->symbol->text);
		}
	}


	for (i = 0; i < MAX_CHILDREN; ++i) {
		checkDeclarations(root->children[i]);
	}
}