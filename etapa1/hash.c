#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define SIZE 997

HASH_ELEMENT *hashTable[SIZE];

void hash_init()
{
	int i;
	for(i = 0; i < SIZE; ++i)
		hashTable[i] = 0;
}

HASH_ELEMENT* hash_insert(int token, char *text)
{
	int address;
	HASH_ELEMENT *element;

	element = (HASH_ELEMENT*)malloc(sizeof(HASH_ELEMENT));
	element->token = token;
	element->text = (char*)malloc(strlen(text)*sizeof(char));
	strcpy(element->text, text);
	element->next = 0;
	
	address = hash_address(text);
	printf("%d\n", address);
	element->next = hashTable[address];
	hashTable[address] = element;	
	
	return element; 
}

int hash_address(char *text)
{
	int i;
	int address=1;
	for(i = 0; text[i] != '\0'; ++i)
	{
		address = (address*text[i]) % SIZE;	
	} 
	return address;
}

HASH_ELEMENT* hash_find(char *text)
{
	int address;
	HASH_ELEMENT *ret;

	address = hash_address(text);

	ret = hashTable[address];
	while(ret && strcmp(ret->text, text) != 0) ret = ret->next;
	
	return ret;	
}

void hash_print()
{
	int i;
	HASH_ELEMENT *aux;
	for(i = 0; i < SIZE; ++i){
		aux = hashTable[i];
		while(aux != 0) {
			printf("%d %s\n", aux->token, aux->text);
			aux = aux->next;
		}
	}
}

int main(){
	
	hash_init();

	hash_insert(23, "lala");
	hash_insert(24, "sagfa");
	hash_insert(634, "ag43");

	hash_print();
	
	HASH_ELEMENT *aux = hash_find("lala");
	printf("%d %s\n", aux->token, aux->text);
	
	return 0;
}
