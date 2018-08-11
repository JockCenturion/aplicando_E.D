#include <stdio.h>
#include <stdlib.h>
#include "Queue.c"

void concateQueue(Queue *fila1, Queue *fila2, Queue *fila3) {
	
	while (!isEmpty(fila1)) {
		addInQueue(fila3, removeInQueue(fila1));
	}
	
	while (!isEmpty(fila2)) {
		addInQueue(fila3, removeInQueue(fila2));
	}

}

int main() {
	Queue fila[3];
	
	Data d[2][4] = { {{1}, {2}, {3}, {4}}, {{6}, {7}, {8}, {9}} };
	
	for (int i = 0; i < 3; i++)
		newQueue(&fila[i], 0);
		
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 4; j++)
			addInQueue(&fila[i], &d[i][j]);
		
	
	concateQueue(&fila[0], &fila[1], &fila[2]);
	viewQueueProx(&fila[2]);
		
	
	
	
	
	
	
	return 0;
}
