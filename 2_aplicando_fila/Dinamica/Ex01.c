#include <stdio.h>
#include <stdlib.h>
#include "Queue.c"


int main() {
	Data dt[5] = {{1}, {-2}, {3}, {-5}, {6}};
	Queue fila;
	newQueue(&fila, 0);
	
	for (int i = 0; i < 5; i++) {
		addInQueue(&fila, &dt[i]);
	}
	
	for (int i = 0; i < size(&fila); i++) {
		Data *exc = removeInQueue(&fila);
		exc->value = (exc->value < 0 ? 0 : exc->value);
		addInQueue(&fila, exc);
	}
		
	viewQueueProx(&fila);
	
	return 0;
}
