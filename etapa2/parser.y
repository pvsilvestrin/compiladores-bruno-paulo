
%{

#include <stdlib.h>
#include <stdio.h>
FILE *yyin;

// no scanner "#include y.tab.h" tirar tokens.h
// compila primeiro parser.y "yacc -d parser.y"

%}

%token SYMBOL_UNDEFINED 0
%token SYMBOL_LIT_INTEGER 1
%token SYMBOL_LIT_FLOATING 2
%token SYMBOL_LIT_TRUE 3
%token SYMBOL_LIT_FALSE 4
%token SYMBOL_LIT_CHAR 5
%token SYMBOL_LIT_STRING 6
%token SYMBOL_IDENTIFIER 7


%%

programa : assinalamento resto
				;

resto : programa
		|
		;

assinalamento: SYMBOL_IDENTIFIER '=' SYMBOL_LIT_INTEGER
		;

%%

#include "main.c"

int yyerror(char *t) {
	printf("Syntax Error\n");
}