//Bruno Nunes e Paulo Silvestrin


int main(int argc, char *argv[]){
	if(argc < 2) {
		printf("Use etapa2 <file_name>\n");
		exit(1);
	}
	
	yyin = fopen(argv[1], "r");
	
	initMe();
	
	yyparse();
	/*int token = yylex();
	
	while(running) {
		printf("token\t%d - %s - linha %d\n", token, yytext, getLineNumber());
	
		token = yylex();
	}*/
	
	hash_print();
	fclose(yyin);
	
	return 0;
}

