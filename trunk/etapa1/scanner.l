%{

#include "tokens.h"

int running = 1;
int numLines = 0;
%}

%%

\n    {numLines++;}
.     {printf("Alguma coisa");}

%%

int yywrap(void){
	running = 0;
	return 1;
}

int main(void){
	yylex();
	return 0;
}
