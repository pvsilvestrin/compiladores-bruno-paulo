//Bruno Nunes e Paulo Silvestrin
#include <stdlib.h>
#include <stdio.h>

FILE *yyin;
FILE *yyout;
FILE *NASM;

int main(int argc, char *argv[]){
	if(argc < 3) {
		printf("Use etapa6 <input_file_name> <output_file_name>\n");
		exit(1);
	}
	
	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");
	NASM = 	fopen("source.asm", "w");
	initMe();
	
	yyparse();
	
	fclose(yyin);
	fclose(yyout);
	fclose(NASM);
	
	exit(0);
}