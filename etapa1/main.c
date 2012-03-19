


int main(int argc, char *argv[]){
	if(argc < 2) {
		printf("Use etapa1 <file_name>\n");
		exit(1);
	}
	
	yyin = fopen(argv[1], "r");
	
	initMe();
	
	int token = yylex();
	
	while(running) {
		printf("token\t%d - %s - linha %d\n", token, yytext, getLineNumber());
	
		/*switch(token) {
			case LIT_FLOATING:
				hash_insert(LIT_FLOATING, yytext);
				break;
			case LIT_FALSE:
				hash_insert(LIT_FALSE, yytext);
				break;
			case LIT_TRUE:
				hash_insert(LIT_TRUE, yytext);
				break;
			case LIT_CHARACTER:
				// tirar aspas
				hash_insert(LIT_CHARACTER, yytext);
				break;
			case LIT_STRING:
				// tirar aspas
				hash_insert(LIT_STRING, yytext);
				break;
			case TOKEN_ERROR:
				printf("Erro na linha %d: %s\n", numLines, yytext);
				break;
			default:
				break;
		}*/
	
		token = yylex();
	}
	
	hash_print();
	
	return 0;
}
