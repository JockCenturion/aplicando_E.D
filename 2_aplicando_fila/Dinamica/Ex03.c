#include <stdio.h>
#include <stdlib.h>
#include "Queue.c"

void inverteFila(Queue *fila) {
	int tamanho = size(fila);
	Data **dt = malloc(tamanho * sizeof(Data*));
	
	for (int i = 0; i < tamanho; i++) 
		dt[i] = removeInQueue(fila);
		
	for (int i = tamanho - 1; i >= 0; i--) {
		addInQueue(fila, dt[i]);
	}
}

int main() {
	Queue fila;
	newQueue(&fila, 0);
	
	Data dt[5] = { {1}, {2}, {3}, {4}, {5} };
	
	for (int i = 0; i < 5; i++) {
		addInQueue(&fila, dt + i);
	}
	
	inverteFila(&fila);
	viewQueueProx(&fila);
	
	return 0;
}
