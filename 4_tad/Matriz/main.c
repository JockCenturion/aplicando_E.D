#include "matriz.c"
#include <stdio.h>

int main() {
	
	Matriz *p = cria(2, 2);
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			insereElemento(p, i, j, i + j);	
	}
				
	printf("\n");
			
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			printf("%d", acessaElemento(p, i, j));
		printf("\n");	
	}
			
	liberaMat(p);
			
		

	
	return 0;
}
