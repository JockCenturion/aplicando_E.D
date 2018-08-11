#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.c"

char* inverterPlvr(char *plvr) {
	Pilha p;
	criar(&p, strlen(plvr));
	char *newPlvr;
	int count = 0;
	
	if ( !(newPlvr = (char*) malloc(strlen(plvr))) ) exit(1);
	
	for (int i = 0; i <= strlen(plvr); i++)  {
		if (plvr[i] != 32 && plvr[i] != '\0' && plvr[i] != 46)
			inserir(&p, plvr[i]);
		else {
			while (!vazia(&p)) 
				newPlvr[count++] = remover(&p);
				
			newPlvr[count] = 32;
			newPlvr[++count] = '\0';
		}
	}
	
	liberar(&p);
	return newPlvr;
	
}

int main() {
	
	//char *plvr = "ESTE EXERCICIO E MUITO FACIL.";
	char *plvr = "AMANHA EH PROVA";
	printf("%s", inverterPlvr(plvr));
	

	
	
	
	return 0;
}
