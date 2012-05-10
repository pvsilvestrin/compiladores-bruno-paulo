
%{

#include <stdlib.h>
#include <stdio.h>
#include "hash.h"
#include "semantic.h"

FILE *yyin;

%}

%union {
	ASTREE *astree;
	HASH_ELEMENT *symbol;
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

%token<symbol> TK_IDENTIFIER
%token<symbol> LIT_INTEGER
%token<symbol> LIT_FLOATING
%token<symbol> LIT_FALSE
%token<symbol> LIT_TRUE
%token<symbol> LIT_CHARACTER
%token<symbol> LIT_STRING

%type <astree> 	expressao		lista_expressoes	lista_expr_nao_vazia	controle_fluxo 
				input			output				return					atribuicao
				comando 		seq_comando 		decl_var 				decl_vetor 
				bloco_comando 	parametro 			tipo_var 				lista_parametros 
				cabecalho 		def_funcao 			lista_param_nao_vazia 	decl_global
				programa 		p


%token TOKEN_ERROR


%left OPERATOR_OR OPERATOR_AND
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left '+' '-'
%left '*' '/'

%%

p : programa													{ $$ = $1; astPrintTree($$); astPrintTreeSrc($$); checkDeclarations($$); checkUndeclared(); checkUtilization($$); }

programa : decl_global programa									{ $$ = astCreate(AST_PROG, 0, $1, $2, 0, 0); }
	| def_funcao programa										{ $$ = astCreate(AST_PROG, 0, $1, $2, 0, 0); }
	| 															{ $$ = astCreate(AST_EMPTY, 0, 0, 0, 0, 0); }
	;

decl_global : decl_var ';'										{ $$ = astCreate(AST_DECL_GL, 0, $1, 0, 0, 0); }
	| decl_vetor ';'											{ $$ = astCreate(AST_DECL_GL, 0, $1, 0, 0, 0); }
	;

decl_var : KW_DECLARE TK_IDENTIFIER ':' tipo_var				{ $$ = astCreate(AST_DECL_VAR, $2, $4, 0, 0, 0); }
	;

decl_vetor : KW_DECLARE TK_IDENTIFIER ':' tipo_var '[' LIT_INTEGER ']' { $$ = astCreate(AST_DECL_VEC, $2, $4, astCreate(AST_VEC_SIZE, $6, 0, 0, 0, 0), 0, 0); }
	;

tipo_var : KW_INTEGER											{ $$ = astCreate(AST_T_INT, 0, 0, 0, 0, 0); }
	| KW_FLOATING												{ $$ = astCreate(AST_T_FLO, 0, 0, 0, 0, 0); }
	| KW_BOOLEAN												{ $$ = astCreate(AST_T_BOO, 0, 0, 0, 0, 0); }
	| KW_CHARACTER												{ $$ = astCreate(AST_T_CHA, 0, 0, 0, 0, 0); }
	;

def_funcao : cabecalho comando ';'								{ $$ = astCreate(AST_DEF_F, 0, $1, $2, 0, 0); }
	;

cabecalho : TK_IDENTIFIER ':' tipo_var '(' lista_parametros ')'	{ $$ = astCreate(AST_CAB, $1, $3, $5, 0, 0); }
	;

lista_parametros : lista_param_nao_vazia						{ $$ = $1; }
	|															{ $$ = astCreate(AST_EMPTY, 0, 0, 0, 0, 0); }
	;	

lista_param_nao_vazia : parametro ',' lista_param_nao_vazia		{ $$ = astCreate(AST_LIST_P, 0, $1, $3, 0, 0); }
	| parametro 												{ $$ = astCreate(AST_LIST_P, 0, $1, 0, 0, 0); }
	;

parametro : TK_IDENTIFIER ':' tipo_var							{ $$ = astCreate(AST_PARAM, $1, $3, 0, 0, 0); }
	;

comando : bloco_comando											{ $$ = astCreate(AST_COM, 0, $1, 0, 0, 0); }
	| controle_fluxo											{ $$ = astCreate(AST_COM, 0, $1, 0, 0, 0); }
	| atribuicao												{ $$ = astCreate(AST_COM, 0, $1, 0, 0, 0); }
	| input														{ $$ = astCreate(AST_COM, 0, $1, 0, 0, 0); }
	| output													{ $$ = astCreate(AST_COM, 0, $1, 0, 0, 0); }
	| return													{ $$ = astCreate(AST_COM, 0, $1, 0, 0, 0); }
	|															{ $$ = astCreate(AST_COM, 0, 0, 0, 0, 0); }
	;

bloco_comando : '{' seq_comando '}'								{ $$ = astCreate(AST_BLO_COM, 0, $2, 0, 0, 0); }
	;

seq_comando : comando											{ $$ = astCreate(AST_SEQ, 0, $1, 0, 0, 0); }
	| comando ';' seq_comando									{ $$ = astCreate(AST_SEQ, 0, $1, $3, 0, 0); }
	;

atribuicao : TK_IDENTIFIER '=' expressao						{ $$ = astCreate(AST_ATR, $1, $3, 0, 0, 0); }
	| TK_IDENTIFIER '[' expressao ']' '=' expressao				{ $$ = astCreate(AST_ATR, $1, $3, $6, 0, 0); }
	;

input : KW_INPUT TK_IDENTIFIER									{ $$ = astCreate(AST_INP, $2, 0, 0, 0, 0); }
	;

output : KW_OUTPUT lista_expr_nao_vazia							{ $$ = astCreate(AST_OUT, 0, $2, 0, 0, 0); }
	;

lista_expr_nao_vazia : expressao ',' lista_expr_nao_vazia		{ $$ = astCreate(AST_LIST_E, 0, $1, $3, 0, 0); }
	| expressao 												{ $$ = astCreate(AST_LIST_E, 0, $1, 0, 0, 0); }
	;

return : KW_RETURN expressao									{ $$ = astCreate(AST_RET, 0, $2, 0, 0, 0); }
	;

controle_fluxo : KW_IF '(' expressao ')' KW_THEN comando		{ $$ = astCreate(AST_IF, 0, $3, $6, 0, 0); }
	| KW_IF '(' expressao ')' KW_THEN comando KW_ELSE comando 	{ $$ = astCreate(AST_IF, 0, $3, $6, $8, 0); }
	| KW_WHILE '(' expressao ')' comando 						{ $$ = astCreate(AST_WHILE, 0, $3, $5, 0, 0); }
	| KW_DO comando KW_WHILE '(' expressao ')'					{ $$ = astCreate(AST_DO_WHILE, 0, $2, $5, 0, 0); }
	;

expressao : TK_IDENTIFIER						{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| TK_IDENTIFIER '[' expressao ']'			{ $$ = astCreate(AST_SYMBOL, $1, $3, 0, 0, 0); }
	| LIT_INTEGER 								{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_FLOATING								{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_FALSE									{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_TRUE									{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_CHARACTER								{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }	
	| LIT_STRING								{ $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| expressao '+' expressao 					{ $$ = astCreate(AST_OP_SUM, 0, $1, $3, 0, 0); }
	| expressao '-' expressao 					{ $$ = astCreate(AST_OP_SUB, 0, $1, $3, 0, 0); }
	| expressao '*' expressao 					{ $$ = astCreate(AST_OP_MUL, 0, $1, $3, 0, 0); }
	| expressao '/' expressao 					{ $$ = astCreate(AST_OP_DIV, 0, $1, $3, 0, 0); }
	| expressao '<' expressao 					{ $$ = astCreate(AST_OP_LES, 0, $1, $3, 0, 0); }
	| expressao '>' expressao 					{ $$ = astCreate(AST_OP_GRE, 0, $1, $3, 0, 0); }
	| '(' expressao ')' 						{ $$ = $2; }
	| expressao OPERATOR_LE expressao 			{ $$ = astCreate(AST_OP_LE, 0, $1, $3, 0, 0); }
	| expressao OPERATOR_GE expressao 			{ $$ = astCreate(AST_OP_GE, 0, $1, $3, 0, 0); }
	| expressao OPERATOR_EQ expressao 			{ $$ = astCreate(AST_OP_EQ, 0, $1, $3, 0, 0); }
	| expressao OPERATOR_NE expressao 			{ $$ = astCreate(AST_OP_NE, 0, $1, $3, 0, 0); }
	| expressao OPERATOR_AND expressao 			{ $$ = astCreate(AST_OP_AND, 0, $1, $3, 0, 0); }
	| expressao OPERATOR_OR expressao 			{ $$ = astCreate(AST_OP_OR, 0, $1, $3, 0, 0); }
	| TK_IDENTIFIER '(' lista_expressoes ')' 	{ $$ = astCreate(AST_CHAM_F, $1, $3, 0, 0, 0); }
	;

lista_expressoes : lista_expr_nao_vazia			{ $$ = $1; }
	|											{ $$ = astCreate(AST_EMPTY, 0, 0, 0, 0, 0); }
	;

%%

int yyerror(char *t) {
	printf("Syntax Error on line %d\n", getLineNumber());
	exit(3);
}
