
%{

#include <stdlib.h>
#include <stdio.h>

FILE *yyin;

// no scanner "#include y.tab.h" tirar tokens.h
// compila primeiro parser.y "yacc -d parser.y"

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

%token SYMBOL_UNDEFINED 
%token SYMBOL_LIT_INTEGER 
%token SYMBOL_LIT_FLOATING 
%token SYMBOL_LIT_TRUE 
%token SYMBOL_LIT_FALSE 
%token SYMBOL_LIT_CHAR 
%token SYMBOL_LIT_STRING 
%token SYMBOL_IDENTIFIER 


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