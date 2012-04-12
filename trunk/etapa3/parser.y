
%{

#include <stdlib.h>
#include <stdio.h>

FILE *yyin;

%}

%union {
	HASH_ELEMENT* symbol;
}

%token KW_INTEGER
%token KW_FLOATING
%token KW_BOOLEAN
%token KW_CHARACTER
%token KW_DECLARE
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_DO
%token KW_INPUT
%token KW_RETURN
%token KW_OUTPUT

%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_NE
%token OPERATOR_AND
%token OPERATOR_OR

%token TK_IDENTIFIER
%token LIT_INTEGER
%token LIT_FLOATING
%token LIT_FALSE
%token LIT_TRUE
%token LIT_CHARACTER
%token LIT_STRING

%token TOKEN_ERROR


%left OPERATOR_OR OPERATOR_AND
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left '+' '-'
%left '*' '/'

%%

programa : decl_global programa
	| def_funcao programa
	| 
	;

decl_global : decl_var ';'
	| decl_vetor ';'
	;

	decl_var : KW_DECLARE TK_IDENTIFIER ':' tipo_var
		;

	decl_vetor : KW_DECLARE TK_IDENTIFIER ':' tipo_var '[' LIT_INTEGER ']'
		;

tipo_var : KW_INTEGER
	| KW_FLOATING
	| KW_BOOLEAN
	| KW_CHARACTER
	;

def_funcao : cabecalho comando ';'
	;

	cabecalho : TK_IDENTIFIER ':' tipo_var '(' lista_parametros ')'
		;

		lista_parametros : lista_parametros_nao_vazia
			|
			;

		lista_parametros_nao_vazia : parametro ',' lista_parametros_nao_vazia
			| parametro
			;

		parametro : TK_IDENTIFIER ':' tipo_var
			;

	comando : bloco_comando
		| controle_fluxo
		| atribuicao
		| input
		| output
		| return
		|
		;

		bloco_comando : '{' seq_comando '}'
			;

			seq_comando : comando
				| comando ';' seq_comando
				| decl_var
				| decl_var ';' seq_comando
				| decl_vetor
				| decl_vetor ';' seq_comando
				;

		atribuicao : TK_IDENTIFIER '=' expressao
			| TK_IDENTIFIER '[' expressao ']' '=' expressao
			;

		input : KW_INPUT TK_IDENTIFIER
			;

		output : KW_OUTPUT lista_expressoes_nao_vazia
			;

			lista_expressoes_nao_vazia : expressao ',' lista_expressoes_nao_vazia
				| expressao
				;

		return : KW_RETURN expressao
			;

		controle_fluxo : KW_IF '(' expressao ')' KW_THEN comando
			| KW_IF '(' expressao ')' KW_THEN comando KW_ELSE comando
			| KW_WHILE '(' expressao ')' comando
			| KW_DO comando KW_WHILE '(' expressao ')'
			;

		expressao : TK_IDENTIFIER
			| TK_IDENTIFIER '[' expressao ']'
			| LIT_INTEGER
			| LIT_FLOATING
			| LIT_FALSE
			| LIT_TRUE
			| LIT_CHARACTER
			| LIT_STRING
			| expressao '+' expressao
			| expressao '-' expressao
			| expressao '*' expressao
			| expressao '/' expressao
			| expressao '<' expressao
			| expressao '>' expressao
			| '(' expressao ')'
			| expressao OPERATOR_LE expressao
			| expressao OPERATOR_GE expressao
			| expressao OPERATOR_EQ expressao
			| expressao OPERATOR_NE expressao
			| expressao OPERATOR_AND expressao
			| expressao OPERATOR_OR expressao
			| TK_IDENTIFIER '(' lista_expressoes ')'
			;

			lista_expressoes : lista_expressoes_nao_vazia
				|
				;

%%

#include "main.c"

int yyerror(char *t) {
	printf("Syntax Error on line %d\n", getLineNumber());
	exit(3);
}
