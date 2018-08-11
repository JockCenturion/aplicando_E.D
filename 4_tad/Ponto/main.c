#include <stdio.h>
#include "ponto.c"

typedef struct {
	short x, y;
} Coordenadas;

int main() {
	
	Ponto *p1, *p2;
	Coordenadas c1, c2, soma;
	
	p1  = criar();
	p2 = criar();
	 
	atribuir(p1, 2, 3);
	atribuir(p2, 4, 5);
	acessar(p1, &c1.x, &c1.y);
	printf("P1 = (%d, %d)\n", c1.x, c1.y);
	acessar(p2, &c2.x, &c2.y);
	printf("P2 = (%d, %d)\n", c2.x, c2.y);
	printf("Distancia: %.2f\n", distancia(p1, p2));
	somar(p1, p2, &soma.x, &soma.y);
	printf("Soma: (%d, %d)\n", soma.x, soma.y);
	printf("Produto: %d\n", produto(p1, p2));
		
	return 0;
}
