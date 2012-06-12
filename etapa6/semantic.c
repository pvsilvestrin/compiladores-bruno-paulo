//SEMANTIC ANALISYS 2012

#include <stdlib.h>
#include "semantic.h"

void checkDeclarations(ASTREE *root){
	if(root == 0) return;
	
	int i;

	// do some work

	if(root->type == AST_DECL_VAR ||
		root->type == AST_DECL_VEC ||
		root->type == AST_DEF_F ||
		root->type == AST_PARAM){

		if(root->symbol == 0) {
			printf("Line %d: Declaration is missing the identifier name.\n", root->lineNumber);
		} else {
			if (root->symbol->type != SYMBOL_IDENTIFIER)
				printf("Line %d: Symbol %s already defined.\n", root->lineNumber, root->symbol->text);
			if (root->type == AST_DECL_VAR) root->symbol->type = SYMBOL_VARIABLE;
			if (root->type == AST_DECL_VEC) root->symbol->type = SYMBOL_VECTOR;
			if (root->type == AST_DEF_F) root->symbol->type = SYMBOL_FUNCTION;
			if (root->type == AST_PARAM) root->symbol->type = SYMBOL_PARAM;
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
	if(root->type == AST_SYMBOL || root->type == AST_ATR_VAR){
		if (root->symbol->type == SYMBOL_VECTOR) {
			printf("Line %d: Declared vector %s being used as scalar type.\n", root->lineNumber, root->symbol->text);
		} else if(root->symbol->type == SYMBOL_FUNCTION) {
			printf("Line %d: Declared function %s being used as scalar type.\n", root->lineNumber, root->symbol->text);
		} else if (root->symbol->type != SYMBOL_VARIABLE && root->symbol->type != SYMBOL_PARAM){
			printf("Line %d: Variable %s not declared.\n", root->lineNumber, root->symbol->text);
		}
	}

	// Make sure only declared vectors are being used as vectors
	else if(root->type == AST_SYMBOL_VEC || root->type == AST_ATR_VEC){
		if (root->symbol->type == SYMBOL_VARIABLE || root->symbol->type == SYMBOL_PARAM) {
			printf("Line %d: Declared variable %s being used as vector type.\n", root->lineNumber, root->symbol->text);
		} else if (root->symbol->type == SYMBOL_FUNCTION) {
			printf("Line %d: Declared function %s being used as vector type.\n", root->lineNumber, root->symbol->text);
		} else if (root->symbol->type != SYMBOL_VECTOR){
			printf("Line %d: Vector %s not declared.\n", root->lineNumber, root->symbol->text);
		}
	}

	// Make sure only declared functions are being used as functions
	else if(root->type == AST_CHAM_F){
		if (root->symbol->type == SYMBOL_VARIABLE || root->symbol->type == SYMBOL_PARAM) {
			printf("Line %d: Declared variable %s being used as function type.\n", root->lineNumber, root->symbol->text);
		} else if (root->symbol->type == SYMBOL_VECTOR) {
			printf("Line %d: Declared variable %s being used as function type.\n", root->lineNumber, root->symbol->text);
		} else if (root->symbol->type != SYMBOL_FUNCTION){
			printf("Line %d: Function %s not declared.\n", root->lineNumber, root->symbol->text);
		} else if (root->symbol->type == SYMBOL_FUNCTION) {
			checkFunctionCallParameters(root);
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
	else if(root->type == AST_OP_LES || root->type == AST_OP_GRE || root->type == AST_OP_LE || root->type == AST_OP_GE) {
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
					printf("Line %d: Operator %s is of an invalid type for relational expression.\n", root->lineNumber, root->children[0]->symbol->text);
				}
			}
			else printf("Line %d: Relational expression contains an invalid operator type.\n", root->lineNumber);
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
					printf("Line %d: Operator %s is of an invalid type for relational expression.\n", root->lineNumber, root->children[1]->symbol->text);
				}
			}
			else printf("Line %d: Relational expression contains an invalid operator type.\n", root->lineNumber);
		}
	}


	// Make sure the logical expressions have the correct operators types
	else if(root->type == AST_OP_AND || root->type == AST_OP_OR) {
		if(root->children[0]->type != AST_OP_LES &&
			root->children[0]->type != AST_OP_GRE &&
			root->children[0]->type != AST_OP_LE &&
			root->children[0]->type != AST_OP_GE &&
			root->children[0]->type != AST_OP_EQ &&
			root->children[0]->type != AST_OP_NE &&
			root->children[0]->type != AST_OP_AND &&
			root->children[0]->type != AST_OP_OR) {
			if(root->children[0]->type == AST_SYMBOL ||
				root->children[0]->type == AST_SYMBOL_VEC ||
				root->children[0]->type == AST_SYMBOL_LIT) {
				if(root->children[0]->symbol->dataType != DATATYPE_BOOLEAN) {
					printf("Line %d: Operator %s is of an invalid type for logical expression.\n", root->lineNumber, root->children[0]->symbol->text);
				}
			}
			else printf("Line %d: Logical expression contains an invalid operator type.\n", root->lineNumber);
		}

		if(root->children[1]->type != AST_OP_LES &&
			root->children[1]->type != AST_OP_GRE &&
			root->children[1]->type != AST_OP_LE &&
			root->children[1]->type != AST_OP_GE &&
			root->children[1]->type != AST_OP_EQ &&
			root->children[1]->type != AST_OP_NE &&
			root->children[1]->type != AST_OP_AND &&
			root->children[1]->type != AST_OP_OR) {
			if(root->children[1]->type == AST_SYMBOL ||
				root->children[1]->type == AST_SYMBOL_VEC ||
				root->children[1]->type == AST_SYMBOL_LIT) {
				if(root->children[1]->symbol->dataType != DATATYPE_BOOLEAN) {
					printf("Line %d: Operator %s is of an invalid type for logical expression.\n", root->lineNumber, root->children[1]->symbol->text);
				}
			}
			else printf("Line %d: Logical expression contains an invalid operator type.\n", root->lineNumber);
		}
	}



	// Make sure the vector index is of the correct type
	else if(root->type == AST_SYMBOL_VEC ||
		root->type == AST_ATR_VEC) {
		if(root->children[0]->type != AST_OP_SUM &&
			root->children[0]->type != AST_OP_SUB &&
			root->children[0]->type != AST_OP_MUL &&
			root->children[0]->type != AST_OP_DIV) {
			if(root->children[0]->type == AST_SYMBOL ||
				root->children[0]->type == AST_SYMBOL_VEC ||
				root->children[0]->type == AST_SYMBOL_LIT) {
				if(root->children[0]->symbol->dataType != DATATYPE_INTEGER &&
					root->children[0]->symbol->dataType != DATATYPE_CHARACTER) {
					printf("Line %d: Vector index %s is of an invalid type.\n", root->lineNumber, root->children[0]->symbol->text);
				}
			}
			else printf("Line %d: Vector index is of an invalid type.\n", root->lineNumber);
		}
	}

	for (i = 0; i < MAX_CHILDREN; ++i) {
		checkDataTypes(root->children[i]);
	}
}

void checkFunctionCallParameters(ASTREE *root) {
	if(root == 0) return;

	int i;

	if(root->type == AST_CHAM_F){
		ASTREE *params = root->symbol->ast;

		if(params->type == AST_EMPTY && root->children[0]->type != AST_EMPTY)
			printf("Line %d: Function call %s invalid number of parameters.\n", root->lineNumber, root->symbol->text);
		else checkListParams(params, root->children[0], root);

	}

}

void checkListParams(ASTREE *declParams, ASTREE *callParams, ASTREE *root){
	if(declParams == 0 && callParams == 0) return;
	if(declParams == 0 && callParams != 0 || declParams != 0 && callParams == 0){ 
		printf("Line %d: Function call %s invalid number of parameters.\n", root->lineNumber, root->symbol->text);
		return;
	}
	int parameterType = checkExpressionType(callParams->children[0]);

	if(declParams->children[0]->symbol->dataType == DATATYPE_BOOLEAN && parameterType != DATATYPE_BOOLEAN){
		printf("Line %d: Function call %s invalid parameter type.\n", root->lineNumber, root->symbol->text);
		return;
	}else if (declParams->children[0]->symbol->dataType == DATATYPE_CHARACTER 
		&& parameterType != DATATYPE_CHARACTER
		&& parameterType != DATATYPE_BOOLEAN){
		printf("Line %d: Function call %s invalid parameter type.\n", root->lineNumber, root->symbol->text);
		return;
	} else if(declParams->children[0]->symbol->dataType == DATATYPE_INTEGER && parameterType == DATATYPE_FLOATING){
		printf("Line %d: Function call %s invalid parameter type.\n", root->lineNumber, root->symbol->text);
		return;
	}
	
	checkListParams(declParams->children[1], callParams->children[1], root);
}

int checkExpressionType(ASTREE *expression){
	int dataType1, dataType2;
	if(expression == 0) return -1;
	else {
		if(expression->symbol != 0) return expression->symbol->dataType;
		else {
			if(expression->type == AST_OP_LES || expression->type == AST_OP_GRE || expression->type == AST_OP_LE ||
				expression->type == AST_OP_GE || expression->type == AST_OP_EQ || expression->type == AST_OP_NE ||
				expression->type == AST_OP_AND || expression->type == AST_OP_OR) 
				return DATATYPE_BOOLEAN;

			dataType1 = checkExpressionType(expression->children[0]);
			dataType2 = checkExpressionType(expression->children[1]);
			if(dataType1 == DATATYPE_FLOATING || dataType2 == DATATYPE_FLOATING) return DATATYPE_FLOATING;
			if(dataType1 == DATATYPE_INTEGER || dataType2 == DATATYPE_INTEGER) return DATATYPE_INTEGER;
			if(dataType1 == DATATYPE_CHARACTER || dataType2 == DATATYPE_CHARACTER) return DATATYPE_CHARACTER;
			else return DATATYPE_BOOLEAN;
		} 

	}

} 