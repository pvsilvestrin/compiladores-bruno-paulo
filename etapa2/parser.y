
%{

#include <stdlib.h>
#include <stdio.h>

FILE *yyin;

%}

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


%%

programa : conj_var_global conj_funcao programa
			|
			;

conj_var_global : decl_global conj_var_global
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

conj_funcao : funcao conj_funcao
			|
			;

funcao : cabecalho corpo
			;

	cabecalho : TK_IDENTIFIER ':' tipo_var '(' lista_parametros ')'
			;

		lista_parametros : lista_parametros_nao_vazia
			|
			;

		lista_parametros_nao_vazia : parametro, lista_parametros_nao_vazia
			| parametro
			;

		parametro : TK_IDENTIFIER ':' tipo_var
			;

	corpo : comando
			;

		comando : bloco_comando
			| atribuicao
			| input
			| output
			|
			;

			bloco_comando : '{' seq_comando '}'
			;

			seq_comando : comando
				| comando ';' seq_comando
				;

		atribuicao : TK_IDENTIFIER '=' expressao
			| TK_IDENTIFIER '[' expressao ']' '=' expressao
			;

		input : KW_INPUT TK_IDENTIFIER
			;

		output : KW_OUTPUT lista_saida
			;

			// assumindo que a lista do output nao pode ser vazia
		lista_saida : elemento_lista_saida, lista_saida
			| elemento_lista_saida
			;

			elementos_lista_saida : LIT_STRING
				| expressao
				;


		expressao :
			;

%%

#include "main.c"

int yyerror(char *t) {
	printf("Syntax Error\n");
	exit(1);
}