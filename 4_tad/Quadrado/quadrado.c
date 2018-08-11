#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Quadrado.h"

struct quadrado{
	float lado, area, perimetro;	
};

Quadrado* criar(float lado) {
	Quadrado *q = (Quadrado *) malloc(sizeof(Quadrado));
	q->lado = lado;
	return q;
}

void calcularArea(Quadrado *q) {
	q->area = pow(q->lado, 2);
}

void calcularPerimetro(Quadrado *q) {
	q->perimetro = 4 * q->lado;
}

void imprimir(Quadrado *q) {
	printf("Lado: %.2f\n", q->lado);
	printf("Area: %.2f\n", q->area);
	printf("Perimetro: %.2f\n", q->perimetro);
}

void liberar(Quadrado *q) {
	free(q);
}

