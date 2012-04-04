%{
	
#include "lex.yy.c"

#include "tokens.h"

// no scanner "#include y.tab.h" tirar tokens.h
// compila primeiro parser.y "yacc -d parser.y"

}%


%%

programa : assinalamento resto
				;

resto : programa
		|
		;

assinalamento: IDENTIFIER '=' INTEGER
		;

%%


int yyerror(char *t) {
	printf("Syntax Error\n");
}

// yyparse() no lugar do while-switch