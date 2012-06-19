//Bruno Nunes e Paulo Silvestrin
#include <stdlib.h>
#include <stdio.h>

FILE *yyin;
FILE *yyout;
FILE *nasmData;
FILE *nasmText;

int main(int argc, char *argv[]){
	if(argc < 3) {
		printf("Use etapa6 <input_file_name> <output_file_name>\n");
		exit(1);
	}
	
	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");
	nasmData = 	fopen("nasmData", "w");
	nasmText = 	fopen("nasmText", "w");

	fprintf(nasmData, "\t\tSECTION .data\n");
	fprintf(nasmData, "fmtStr:\tdb\t\"%%s\", 0\t; The printf format for string\n");
	fprintf(nasmData, "fmtInt:\tdb\t\"%%d\", 0\t; The printf format for integer\n");
	fprintf(nasmData, "fmtCha:\tdb\t\"%%c\", 0\t; The printf format for character\n");

	fprintf(nasmText, "\t\tSECTION .text\n");
	fprintf(nasmText, "\t\tglobal main\n");
	fprintf(nasmText, "\t\textern printf\n");

	initMe();
	
	yyparse();
	
	fclose(yyin);
	fclose(yyout);
	fprintf(nasmData, "\n\n");
	fclose(nasmData);

	fprintf(nasmText, "\n\n\t\tmov\t\teax, 0\n");
	fprintf(nasmText, "\t\tret\n");
	fclose(nasmText);

	system("cat nasmData nasmText > out.asm");
	
	exit(0);
}