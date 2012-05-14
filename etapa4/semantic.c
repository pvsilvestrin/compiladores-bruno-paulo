//SEMANTIC ANALISYS 2012

#include <stdlib.h>
#include "astree.h"

void checkDeclarations(ASTREE *root){
	if(root == 0) return;
	
	int i;

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

	// Make sure only declared scalars are being used as scalars
	if(root->type == AST_SYMBOL || root->type == AST_ATR){
		if (root->symbol->type == SYMBOL_VECTOR) {
			printf("Line %d: Declared vector %s being used as scalar type.\n", root->lineNumber, root->symbol->text);
		} else if(root->symbol->type == SYMBOL_FUNCTION) {
			printf("Line %d: Declared function %s being used as scalar type.\n", root->lineNumber, root->symbol->text);
		} else if (root->symbol->type != SYMBOL_VARIABLE){
			printf("Line %d: Variable %s not declared.\n", root->lineNumber, root->symbol->text);
		}
	}

	// Make sure only declared vectors are being used as vectors
	if(root->type == AST_SYMBOL_VEC || root->type == AST_ATR_VEC){
		if (root->symbol->type == SYMBOL_VARIABLE) {
			printf("Line %d: Declared variable %s being used as vector type.\n", root->lineNumber, root->symbol->text);
		} else if (root->symbol->type == SYMBOL_FUNCTION) {
			printf("Line %d: Declared function %s being used as vector type.\n", root->lineNumber, root->symbol->text);
		} else if (root->symbol->type != SYMBOL_VECTOR){
			printf("Line %d: Vector %s not declared.\n", root->lineNumber, root->symbol->text);
		}
	}

	// Make sure only declared functions are being used as functions
	if(root->type == AST_CHAM_F){
		if (root->symbol->type == SYMBOL_VARIABLE) {
			printf("Line %d: Declared variable %s being used as function type.\n", root->lineNumber, root->symbol->text);
		} else if (root->symbol->type == SYMBOL_VECTOR) {
			printf("Line %d: Declared variable %s being used as function type.\n", root->lineNumber, root->symbol->text);
		} else if (root->symbol->type != SYMBOL_FUNCTION){
			printf("Line %d: Function %s not declared.\n", root->lineNumber, root->symbol->text);
		}
	}


	for (i = 0; i < MAX_CHILDREN; ++i) {
		checkUtilization(root->children[i]);
	}
}

void checkDataTypes(ASTREE *root) {
	if(root == 0) return;
	
	int i;

	// Make sure the arithmetic expressions have the correct operators types
	if(root->type == AST_OP_SUM || root->type == AST_OP_SUB || root->type == AST_OP_MUL || root->type == AST_OP_DIV) {
		if(root->children[0]->type != AST_OP_SUM &&
			root->children[0]->type != AST_OP_SUB &&
			root->children[0]->type != AST_OP_MUL &&
			root->children[0]->type != AST_OP_DIV) {
			if(root->children[0]->type == AST_SYMBOL ||
				root->children[0]->type == AST_SYMBOL_VEC ||
				root->children[0]->type == AST_SYMBOL_LIT) {
				if(root->children[0]->symbol->dataType != DATATYPE_INTEGER &&
					root->children[0]->symbol->dataType != DATATYPE_FLOATING &&
					root->children[0]->symbol->dataType != DATATYPE_CHARACTER) {
					printf("Line %d: Operator %s is of an invalid type for arithmetic expression.\n", root->lineNumber, root->children[0]->symbol->text);
				}
			}
			else printf("Line %d: Operator is of an invalid type for arithmetic expression.\n", root->lineNumber);
		}

		if(root->children[1]->type != AST_OP_SUM &&
			root->children[1]->type != AST_OP_SUB &&
			root->children[1]->type != AST_OP_MUL &&
			root->children[1]->type != AST_OP_DIV) {
			if(root->children[1]->type == AST_SYMBOL ||
				root->children[1]->type == AST_SYMBOL_VEC ||
				root->children[1]->type == AST_SYMBOL_LIT) {
				if(root->children[1]->symbol->dataType != DATATYPE_INTEGER &&
					root->children[1]->symbol->dataType != DATATYPE_FLOATING &&
					root->children[1]->symbol->dataType != DATATYPE_CHARACTER) {
					printf("Line %d: Operator %s is of an invalid type for arithmetic expression.\n", root->lineNumber, root->children[1]->symbol->text);
				}
			}
			else printf("Line %d: Operator is of an invalid type for arithmetic expression.\n", root->lineNumber);
		}
	}

	// Make sure the relational expressions have the correct operators types
	if(root->type == AST_OP_LES || root->type == AST_OP_GRE || root->type == AST_OP_LE || root->type == AST_OP_GE
		 || root->type == AST_OP_EQ || root->type == AST_OP_NE) {

	}




	for (i = 0; i < MAX_CHILDREN; ++i) {
		checkDataTypes(root->children[i]);
	}
}

int arithmeticExpressionError(ASTREE *root) {
	if(root->type == AST_OP_SUM || root->type == AST_OP_SUB || root->type == AST_OP_MUL || root->type == AST_OP_DIV) {
		return(arithmeticExpressionError(root->children[0]) || arithmeticExpressionError(root->children[1]));
	}

	if(root->type == AST_SYMBOL || root->type == AST_SYMBOL_VEC || root->type == AST_SYMBOL_LIT) {
		if(root->symbol->dataType == DATATYPE_INTEGER || root->symbol->dataType == DATATYPE_FLOATING || root->symbol->dataType == DATATYPE_CHARACTER)
			return 0;
		return 1;
	}

	return 1;
}