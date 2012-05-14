//Bruno Nunes e Paulo Silvestrin
#ifndef HASH_H
#define HASH_H

#include <stdio.h>
//#include "astree.h"

//typedef ASTREE; 

#define MAX_CHILDREN	4

#define SYMBOL_UNDEFINED 0	//quando?

#define SYMBOL_LIT_INTEGER 1
#define SYMBOL_LIT_FLOATING 2
#define SYMBOL_LIT_TRUE 3
#define SYMBOL_LIT_FALSE 4
#define SYMBOL_LIT_CHAR 5
#define SYMBOL_LIT_STRING 6
#define SYMBOL_IDENTIFIER 7

#define SYMBOL_VARIABLE 8
#define SYMBOL_VECTOR 9
#define SYMBOL_FUNCTION 10

#define DATATYPE_INTEGER		1
#define DATATYPE_FLOATING		2
#define DATATYPE_CHARACTER		3
#define DATATYPE_BOOLEAN		4

typedef struct astreenode
{
	int type;
	int lineNumber;
	struct hash_t *symbol;
	struct astreenode *children[MAX_CHILDREN];
} ASTREE;

typedef struct hash_t {
	int type;
	int dataType;
	ASTREE *ast;
	char *text;
	struct hash_t *next;
} HASH_ELEMENT;

void hash_init();
HASH_ELEMENT* hash_insert(int type, char *text);
int hash_address(char *text);
HASH_ELEMENT* hash_find(char *text);
void hash_print();
void checkUndeclared();

#endif
