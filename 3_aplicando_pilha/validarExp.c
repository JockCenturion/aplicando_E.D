#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.c"

char validaExp(char *plvr) {
	Pilha p;
	criar(&p, strlen(plvr));
	
	/*Validaçao da Expressao*/
	for (int i = 0; i < strlen(plvr); i++) {
		if (plvr[i] == '(' || plvr[i] == '[' || plvr[i] == '{')
			inserir(&p, plvr[i]);
		else if (vazia(&p))
			return 0;	
		else {
			char remocao = remover(&p);
			if (plvr[i] == ')' && remocao + 1 != plvr[i])
				return 0;
			if ((plvr[i] == ']' || plvr[i] == '}') && remocao + 2 != plvr[i])
				return 0;	
		} 	
	}
	
	if (!vazia(&p)) return 0;
	return 1;

	
}

int main() {
	
	char *plvr = "{[()]}";
	
	if (validaExp(plvr) ) {
		printf("Expressao valida.");
	} else {
		printf("Expressao invalida.");
	}
	
	//printf("%d", validaExp(plvr));	

	
	return 0;
}
