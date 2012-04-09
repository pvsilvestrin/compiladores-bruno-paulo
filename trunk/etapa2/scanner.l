%{
//Bruno Nunes e Paulo Silvestrin

#include "y.tab.h"
#include "hash.c"

int running = 1;
int numLines = 1;

%}

%x COMM

letter				[A-Za-z_]
digit				[0-9]


%%

"integer"			{printf("KW_INTEGER\n");return KW_INTEGER;}
"floating"			{printf("KW_FLOATING\n");return KW_FLOATING;}
"boolean"			{printf("KW_BOOLEAN\n");return KW_BOOLEAN;}
"character"			{printf("KW_CHARACTER\n");return KW_CHARACTER;}
"declare"			{printf("KW_DECLARE\n");return KW_DECLARE;}
"if"				{return KW_IF;}
"then"				{return KW_THEN;}
"else"				{return KW_ELSE;}
"while"				{printf("KW_WHILE\n");return KW_WHILE;}
"do"				{return KW_DO;}
"input"				{return KW_INPUT;}
"return"			{return KW_RETURN;}
"output"			{printf("KW_OUTPUT\n");return KW_OUTPUT;}

"true"				{hash_insert(LIT_TRUE, yytext);return LIT_TRUE;}
"false"				{hash_insert(LIT_FALSE, yytext);return LIT_FALSE;}

[-,;:()[\]{}+\*/<>=!&$]		{printf("%c\n", yytext[0]);return yytext[0];}

"<="				{return OPERATOR_LE;}
">="				{return OPERATOR_GE;}
"=="				{return OPERATOR_EQ;}
"!="				{return OPERATOR_NE;}
"&&"				{return OPERATOR_AND;}
"||"				{return OPERATOR_OR;}

{letter}({letter}|{digit})*		{
									hash_insert(TK_IDENTIFIER, yytext);
									printf("TK_IDENTIFIER\n");
									return TK_IDENTIFIER;
								}
-?{digit}+						{
									hash_insert(LIT_INTEGER, yytext);
									printf("LIT_INTEGER\n");
									return LIT_INTEGER;
								}
-?{digit}+"."{digit}+			{
									hash_insert(LIT_FLOATING, yytext);
									printf("LIT_FLOATING\n");
									return LIT_FLOATING;
								}
\'.\'							{
									hash_insert(LIT_CHARACTER, yytext);
									printf("LIT_CHARACTER\n");
									return LIT_CHARACTER;
								}
\"[^"]*\"						{
									hash_insert(LIT_STRING, yytext);
									printf("LIT_STRING\n");
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

