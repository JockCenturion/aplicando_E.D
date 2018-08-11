#include <stdio.h>
#include <stdio.h>
#include "Queue.c"

Queue* divideFila(Queue *fila, int valor) {
	Queue *vet = malloc(2 * sizeof(Queue));
	
	newQueue(vet + 0, 0);
	newQueue(vet + 1, 0);
	
	for (int i = 0; i < 5; i++) {
		Data *dt = removeInQueue(fila);
		
		if (dt->priority <= valor) 
			addInQueue(vet, dt);
		else 
			addInQueue(vet + 1, dt);
	}
	return vet;
}

int main() {
	Queue fila;
	newQueue(&fila, 1);  									  //1 -> com prioridade 0 -> sem prioridade
	
	Data dt[5] = { {1, -1}, {2, 3}, {3, 2}, {4, 1}, {5, 4} }; // {valor, prioridade}
	
	for (int i = 0; i < 5; i++) 
		addInQueue(&fila, dt + i);
	
	//Rebendo o ArrayCom duas Filas
	Queue *vet = divideFila(&fila, 3);
	
	//Exibindo a fila com valores de prioridade <= valor
	viewQueueProx(vet++);
	printf("\n");
	//Exibindo a fila com valores de prioridade <= valor
	viewQueueProx(vet);

	

	
	
	return 0;
}
