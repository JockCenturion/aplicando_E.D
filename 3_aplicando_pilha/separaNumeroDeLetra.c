#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.c"

char* inverteNum(char *plvr) {
	Pilha p;
	char *newPlvr;
	short count = 0;
	
	criar(&p, strlen(plvr));
	if ( !(newPlvr = malloc(strlen(plvr))) ) exit(1);
	
	for (int i = 0; i < strlen(plvr); i++) {
		if (plvr[i] >= '0' && plvr[i] <= '9')
			inserir(&p, plvr[i]);
		else 
			newPlvr[count++] = plvr[i];
	}
	
	for (int i = count; i < strlen(plvr); i++) {
		newPlvr[count++] = remover(&p);
		newPlvr[count] = '\0';
	}
	
	liberar(&p);
	return newPlvr;
} 

int main() {
	char *plvr = "3C9H4Q6";
	
	printf("%s", inverteNum(plvr));
	

	
	return 0;
}
