#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"


int main() {
	
	Pilha p1, p2;
	
	criar(&p1, 5);
	criar(&p2, 5);
	
	inserir(&p1, 1);
	inserir(&p1, 2);
	inserir(&p1, 3);
	inserir(&p1, 4);
	inserir(&p1, 5);
	
	inserir(&p2, 1);
	inserir(&p2, 2);
	inserir(&p2, 3);
	inserir(&p2, 4);
	//inserir(&p2, 5);
	
	short flag = 1;
	
	while (1) {
		if (vazia(&p1) && vazia(&p2)) 
			break;
		else if (vazia(&p1) || vazia(&p2)) {
			flag = 0;
			break;
		} else if (remover(&p1) != remover(&p2))
			flag = 0;
	}
	
	if (flag) {
		printf("Sao iguais.");
	} else {
		printf("Nao sao iguas.");
	}
	
	return 0;
}
