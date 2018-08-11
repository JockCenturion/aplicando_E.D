#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

Pilha mesclaPilha(Pilha *p1, Pilha *p2) {
	Pilha p3;
	criar(&p3, qtdNo(p1) + qtdNo(p2));
	inverter(p1);
	inverter(p2);
	
	while (1) {
		if (!vazia(p1))
			inserir(&p3, remover(p1));
		if (!vazia(p2))
			inserir(&p3, remover(p2));
		if (vazia(p1) && vazia(p2))
			break;
	}
	
	return p3;	
}

int main() {
	
	Pilha p1, p2, p3;
	
	criar(&p1, 5);
	criar(&p2, 2);
	
	inserir(&p1, 123);
	inserir(&p1, 78);
	inserir(&p1, 875);
	inserir(&p1, 611);
	inserir(&p1, 7);
	
	printf("\n  Topo ------------------------ Base\n");
	printf("\n    | ------------------------   |\n");
	printf("\n   \\ / ------------------------ \\ /\n\n");
	
	printf("\n\n1a - Pilha\n\n");
	imprimir(&p1);
	
	inserir(&p2, 98);
	inserir(&p2, 101);
	
	printf("\n\n2a - Pilha\n\n");
	imprimir(&p2);
	
	p3 = mesclaPilha(&p1, &p2);
	
	printf("\n\n3a - Pilha (Mesclada)\n\n");
	imprimir(&p3);
	
	

	
	
	return 0;
}
