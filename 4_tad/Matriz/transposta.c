#include <stdio.h>
#include <stdlib.h>
#include "matriz.c"


int main() {
	
	
	int mat[2][2] = {5, 6, 7, 8};
	
	Matriz *p1 = cria(2, 2);
	
	/*Fazendo a transpostra*/
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			insereElemento(p1, i, j, mat[j][i]);
		}
	}
	
	/*Exibindo a nova transposta*/
	for (char i = 0; i < 2; i++) {
		for (char j = 0; j < 2; j++) 
			printf("%3d", acessaElemento(p1, i, j));
		printf("\n");
	}
	
	
	return 0;
}
