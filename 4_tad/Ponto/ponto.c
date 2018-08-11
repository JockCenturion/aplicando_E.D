#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include <math.h>


Ponto* criar(void) {
	Ponto *p;
	if ((p = (Ponto *) malloc(sizeof(Ponto))) == NULL) {
		printf("Impossivel!\n");
		exit(1);
	}	
	return p;		
}

void atribuir(Ponto *p, short x, short y) {
	p->x = x;
	p->y = y;
}

void acessar(Ponto *p, short *x, short *y) {
	*x = p->x;
	*y = p->y;	
}

void liberar(Ponto *p) {
	free(p);
}

void somar(Ponto *p1, Ponto *p2, short *x, short *y) {
	*x = p1->x + p2->x;
	*y = p1->y + p2->y;
} 

short produto(Ponto *p1, Ponto *p2) {
	return ((p1->x * p2->x) + (p1->y * p2->y));
}

float distancia(Ponto *p1, Ponto *p2) {
	
	 return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}



