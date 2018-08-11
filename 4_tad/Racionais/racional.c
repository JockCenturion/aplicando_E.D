#include <stdio.h>
#include <stdlib.h>

struct racional{
	float num;
};

typedef struct racional Racional;

Racional* cria(float m) {
	Racional *r = (Racional*) malloc(sizeof(Racional));
	r->num = m;
}

float somaRacional(Racional *r1, Racional *r2) {
	return r1->num + r2->num;
}

float multRacional(Racional *r1, Racional *r2) {
	return r1->num * r2->num;
}

char testaIgualdade(Racional *r1, Racional *r2) {
	if (r1->num == r2->num)
		return 1;
	else
		return 0;
}

void libera(Racional *r) {
	free(r);
}

int main() {
	
	Racional *p1, *p2;
	
	p1 = cria(2.5);
	p2 = cria(2.5);
	
	printf("Soma: %.2f\n", somaRacional(p1, p2));
	printf("Mult: %.2f\n", multRacional(p1, p2));
	if (testaIgualdade(p1, p2))
		printf("Sao Iguais!\n");
	else
		printf("Nao sao iguais!\n");
	
	libera(p1);
	libera(p2);
	
	return 0;
}
