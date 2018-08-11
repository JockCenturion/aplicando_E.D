#include <stdio.h>
#include "quadrado.c"

int main() {
	
	Quadrado *q = criar(2);
	calcularArea(q);
	calcularPerimetro(q);
	imprimir(q);
	liberar(q);
	
	
	return 0;
}
