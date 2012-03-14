%{

#include "tokens.h"

int running = 1;
int numLines = 1;
%}

letter				[A-Za-z_]
digit				[0-9]


%%

"integer"			{return KW_INTEGER;}
"floating"			{return KW_FLOATING;}
"boolean"			{return KW_BOOLEAN;}
"character"			{return KW_CHARACTER;}
"declare"			{return KW_DECLARE;}
"if"				{return KW_IF;}
"then"				{return KW_THEN;}
"else"				{return KW_ELSE;}
"while"				{return KW_WHILE;}
"do"				{return KW_DO;}
"input"				{return KW_INPUT;}
"return"			{return KW_RETURN;}
"output"			{return KW_OUTPUT;}

[,;:()[\]{}+\-*/<>=!&$]		{return yytext[0];}

"<="				{return OPERATOR_LE;}
">="				{return OPERATOR_GE;}
"=="				{return OPERATOR_EQ;}
"!="				{return OPERATOR_NE;}
"&&"				{return OPERATOR_AND;}
"||"				{return OPERATOR_OR;}

{letter}({letter}|{digit})*	{return TK_IDENTIFIER;}
-?{digit}+			{return LIT_INTEGER;}
-?{digit}+"."{digit}+		{return LIT_FLOATING;}
\'.\'				{return LIT_CHARACTER;}
\".*\"				{return LIT_STRING;}

\n				{numLines++;}
[ \t]				{}
.				{printf("Alguma coisa na linha %d - %s\n", numLines, yytext);}

%%

int yywrap(void){
	running = 0;
	return 1;
}

int getLineNumber(void) {
	return numLines;
}

int main(int argc, char *argv[]){
	if(argc < 2) {
		printf("Use etapa1 <file_name>\n");
		exit(1);
	}
	
	yyin = fopen(argv[1], "r");
	
	
	int token = yylex();
	
	while(running) {
		printf("token\t%d - %s - linha %d\n", token, yytext, getLineNumber());
	
		/*switch(token) {
			case 1: break;
		}*/
	
		token = yylex();
	}
	
	return 0;
}
