#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.c"

char validarExp(char *exp) {
	Pilha p;
	criar(&p, strlen(exp));
	char flag = 1;
	
	for (int i = 0; i < strlen(exp); i++) {
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
			inserir(&p, exp[i]);
		} else if (vazia(&p)) 
			flag = 0;
		//remover sabendo que ela não é vazia	
		else { 									
			if ( (exp[i] == ']' || exp[i] == '}') && (remover(&p) + 2 != exp[i]) )
				flag = 0;
			else if ( (exp[i] == ')') && (remover(&p) + 1 != exp[i]) )
				flag = 0;	
		} 			
	}
	
	if (!vazia(&p))
		flag = 0;
	
	return flag;
}


int main() {
	
	char *plvr = "(((A)))";
	
	if (validarExp(plvr))
		printf("Valido!\n");
	else 
		printf("Invalido!\n");
		
	return 0;
}
