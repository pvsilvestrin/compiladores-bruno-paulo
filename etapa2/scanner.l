%{
//Bruno Nunes e Paulo Silvestrin

#include "y.tab.h"
#include "hash.c"

int running = 1;
int numLines = 1;


#define SYMBOL_UNDEFINED 0	//quando?
#define SYMBOL_LIT_INTEGER 1
#define SYMBOL_LIT_FLOATING 2
#define SYMBOL_LIT_TRUE 3
#define SYMBOL_LIT_FALSE 4
#define SYMBOL_LIT_CHAR 5
#define SYMBOL_LIT_STRING 6
#define SYMBOL_IDENTIFIER 7

%}

%x COMM

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

"true"				{
						hash_insert(SYMBOL_LIT_TRUE, yytext);
						return LIT_TRUE;
					}
"false"				{
						hash_insert(SYMBOL_LIT_FALSE, yytext);
						return LIT_FALSE;
					}

[-,;:()[\]{}+\*/<>=!&$]		{printf("%c\n", yytext[0]); return yytext[0];}

"<="				{return OPERATOR_LE;}
">="				{return OPERATOR_GE;}
"=="				{return OPERATOR_EQ;}
"!="				{return OPERATOR_NE;}
"&&"				{return OPERATOR_AND;}
"||"				{return OPERATOR_OR;}

{letter}({letter}|{digit})*		{
									hash_insert(SYMBOL_IDENTIFIER, yytext);
									return TK_IDENTIFIER;
								}
-?{digit}+						{
									hash_insert(SYMBOL_LIT_INTEGER, yytext);
									return LIT_INTEGER;
								}
-?{digit}+"."{digit}+			{
									hash_insert(SYMBOL_LIT_FLOATING, yytext);
									return LIT_FLOATING;
								}
\'.\'							{
									hash_insert(SYMBOL_LIT_CHAR, yytext);
									return LIT_CHARACTER;
								}
\"[^"]*\"						{
									hash_insert(SYMBOL_LIT_STRING, yytext);
									return LIT_STRING;
								}

"//".*							{printf("Comment\n");}

"/*"							{BEGIN(COMM);}
<COMM>"*/"						{BEGIN(INITIAL);}
<COMM>"\n"						{numLines++;}
<COMM>.							

\n								{numLines++;}
[ \t]							{}
.								{printf("Erro na linha %d: %s\n", numLines, yytext); return TOKEN_ERROR;}

%%

void initMe(void) {
	hash_init();
}

int yywrap(void){
	running = 0;
	return 1;
}

int getLineNumber(void) {
	return numLines;
}

