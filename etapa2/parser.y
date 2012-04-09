
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

conj_funcao : def_funcao ';' conj_funcao
			|
			;

def_funcao : cabecalho corpo {printf("cabecalho corpo\n");}
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

	corpo : comando {printf("corpo: comando\n");}
			;

		comando : bloco_comando {printf("bloco_comando\n");}
			| controle_fluxo {printf("controle_fluxo\n");}
			| atribuicao {printf("atribuicao\n");}
			| input
			| output
			| return
			| decl_var
			| decl_vetor
			|
			;

			bloco_comando : '{' seq_comando '}'	{printf("{ seq_comando }\n");}
			;

			seq_comando : comando 	{printf("comando\n");}
				| comando ';' seq_comando {printf("comando ; seq_comando\n");}
				;

		atribuicao : TK_IDENTIFIER '=' expressao {printf("TK_IDENTIFIER = expressao\n");}
			| TK_IDENTIFIER '[' expressao ']' '=' expressao
			;

		input : KW_INPUT TK_IDENTIFIER
			;

		output : KW_OUTPUT lista_saida
			;

		lista_saida : elemento_lista_saida ',' lista_saida
			| elemento_lista_saida
			;

			elemento_lista_saida : LIT_STRING
				| expressao
				;

		return : KW_RETURN expressao
			;

		controle_fluxo : KW_IF '(' expressao ')' KW_THEN comando
			| KW_IF '(' expressao ')' KW_THEN comando KW_ELSE comando
			| KW_WHILE '(' expressao ')' comando  		{printf("while\n");}
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
			| expressao '+' expressao 		{printf("expressao + expressao\n");}
			| expressao '-' expressao
			| expressao '*' expressao
			| expressao '/' expressao
			| expressao '<' expressao 		{printf("expressao < expressao\n");}
			| expressao '>' expressao
			| expressao '&' expressao
			| '!' expressao
			| '(' expressao ')'			   {printf("(expressao)\n");}
			| expressao OPERATOR_LE expressao
			| expressao OPERATOR_GE expressao
			| expressao OPERATOR_EQ expressao
			| expressao OPERATOR_NE expressao
			| expressao OPERATOR_AND expressao
			| expressao OPERATOR_OR expressao
			| TK_IDENTIFIER '(' lista_expressoes ')' {printf("funcao\n");}
			;

		lista_expressoes : lista_expressoes_nao_vazia
			|
			;

		lista_expressoes_nao_vazia : expressao ',' lista_expressoes_nao_vazia
			| expressao
			;

%%

			// assumindo que a lista do output nao pode ser vazia

#include "main.c"

int yyerror(char *t) {
	printf("Syntax Error\n");
	exit(1);
}