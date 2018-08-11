#include <stdio.h>
#include <stdlib.h>
#include "reserva.h"

Reserva* cria(void) {
	Reserva *r = (Reserva*) malloc(sizeof(Reserva));
	r->vazia = 1;
	return r;
}

void inserir(Reserva *r, Data *d, Hora *h, ModeloCarro *c) {
	r->date = d;
	r->hour = h;
	r->carro = c;
	r->vazia = 0;
}

void remover(Reserva *r) {
	free(r);
}

void mostrar(Reserva *r) {
	system("cls");

	if (!r->vazia) {
		printf("_____________Inf._Reserva________________\n\n");
		printf("Data: %d/%d/%d\n", r->date->dia, r->date->mes, r->date->ano);
		printf("Hora: %d:%d:%d\n", r->hour->hora, r->hour->minuto, r->hour->segundo);
		printf("Informacoes do Carro:\n\tModelo: %s\n\tCor: %s\n\tAno: %d\n", 
				r->carro->modelo, r->carro->cor, r->carro->ano);
		printf("_________________________________________\n\n");

	} else {
		printf("Sem informacoes cadastradas!\n");
	}
}

