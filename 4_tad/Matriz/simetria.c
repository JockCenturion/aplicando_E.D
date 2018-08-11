#include <stdio.h>
#include "matriz.c"


int main() {
	
	int mat[2][2] = {1, 4, 1, 4};
	Matriz *p = cria(2, 2);
	short flag = 1;
	
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			insereElemento(p, i, j, mat[j][i]);
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (acessaElemento(p, i, j) != mat[i][j]) {
				flag = 0;
				break;
			}
		}
	}
	
	if (flag) 
		printf("\nEh simetrica!\n");
	else	
		printf("\nNao eh simetrica!\n");
	
	return 0;
}
