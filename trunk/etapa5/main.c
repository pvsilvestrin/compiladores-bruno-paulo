//Bruno Nunes e Paulo Silvestrin
#include <stdlib.h>
#include <stdio.h>

FILE *yyin;
FILE *yyout;

int main(int argc, char *argv[]){
	if(argc < 3) {
		printf("Use etapa5 <input_file_name> <output_file_name>\n");
		exit(1);
	}
	
	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");
	
	initMe();
	
	yyparse();
	
	fclose(yyin);
	fclose(yyout);
	
	exit(0);
}