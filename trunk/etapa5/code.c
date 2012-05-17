
#include <stdio.h>
#include "code.h"

TAC *codeGenerate(ASTREE *root) {
	// search tree bottom-up

	int i;
	TAC *result[MAX_CHILDREN];

	for(i = 0; i < MAX_CHILDREN; i++)
		result[i] = 0;


	if(root == 0) return;

	TAC *codeList;

	for(i = 0; i < MAX_CHILDREN; i++)
		codeGenerate(root->children[i]);

	// process this node

	if(root->type == AST_OP_SUM) {
		codeList = tacCreate(AST_OP_SUM, makeTemp(), 
			result[0]? result[0]->res : 0, 
			result[1]? result[1]->res : 0);
	}

	if(root->type = AST_SYMBOL) {
		return tacCreate(TAC_SYMBOL, root->symbol, 0, 0);
	}


	return codeList;
}