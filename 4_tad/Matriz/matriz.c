#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz{
	int linha, coluna;
	int **p;	
};

Matriz* cria(int m, int n) {
	Matriz *mat = (Matriz*) malloc(sizeof(Matriz));
	mat->linha  = m;
	mat->coluna = n;
	mat->p = (int**) malloc(sizeof(int*));
		for (int i = 0; i < m; i++) 
			mat->p[i] = (int*) malloc(sizeof(int));
	return mat;	 
}
void insereElemento(Matriz *mat, int m, int n, int valor) {
	if (m < 0 || m >= mat->linha || n < 0 || n >= mat->coluna) {
		exit(1);
	} 
	mat->p[m][n] = valor;
}
	

int acessaElemento(Matriz *mat, int m, int n) {
	if (m < 0 || m >= mat->linha || n < 0 || n >= mat->coluna) {
		exit(1);
	}
	return mat->p[m][n];
}

void liberaMat(Matriz *mat) {
	free(mat);
}

int somaMat(Matriz *mat1, Matriz *mat2, int m, int n) {
	if (( mat1->linha != mat2->linha || mat1->coluna != mat2->coluna) ||
	(m < 0 || n < 0 || m >= mat1->linha || m >= mat1->linha || n >= mat1->coluna)) {
		 	printf("Error!\n");
		 	exit(1);
	}
	
	return mat1->p[m][n] + mat2->p[m][n];
}


