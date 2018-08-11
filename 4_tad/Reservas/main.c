#include <stdio.h>
#include "reserva.c"


int main() {

	Hora h = {3, 30, 59};
	Data d = {2, 5, 2017};
	ModeloCarro m = {"Gol", "verde", 2017};

	Reserva *r = cria();
	inserir(r, &d, &h, &m);
	mostrar(r);
	remover(r);
				 

	setbuf(stdin, NULL);
	getchar();

	return 0;
}
