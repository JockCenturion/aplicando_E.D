#include <stdio.h>
#include <stdlib.h>

/* 
 * Autor:  Jock
 * Data:   18/08/2017 | 00:46 |
 * Titulo: Fila Estatica
 *
 * Tanto o tail como o head crescem infinitamente
 * Lógica: : head ou tail % length = Indice[0,..., 4]
 * Funcionamento: [0 % 5 = 0, 1 % 5 = 1, ... , 15 % 5 = 0];
 *
 * Impressao: enquanto i < tail é porque existe elemento
 */
 
typedef struct queue {
	short *array, length, head, tail, size;
}Queue;
  
void newQueue(Queue *q, short length) {
	if ( !(q->array = malloc(length * sizeof(short))) ) {
 		printf("[Error::insufficient memory] function newQueue.");
 		exit(1);
 	}
	q->length = length;
	q->head = q->tail = q->size = 0;
}

short size(Queue *q) {
	return q->size;
}

short isFull(Queue *q) {
	return (q->size == q->length);
} 

short isEmpty(Queue *q) {
	return (!q->size);
} 

void addInQueue(Queue *q, short value) {
	if ( isFull(q) ) {
		printf("[Error queue isFull] function addInQueue.");
		exit(1);
	} 
	q->size++;													
	q->array[q->tail++ % q->length] = value;
}

short removeInQueue(Queue *q) {
	if ( isEmpty(q) ) {
		printf("[Error queue isEmpty] function removeInQueue.");
		exit(1);
	} 
	q->size--;
	return q->array[q->head++ % q->length];
}

void freeQueue(Queue *q) {
	free(q->array);
}

void viewQueue(Queue *q) {
	for (int i = q->head; i < q->tail; i++)
		printf("%3d -> ", q->array[i % q->length]);
	printf("NULL\n");
}

void sortedQueue(Queue *q) {
	for (int i = q->length - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (q->array[j] > q->array[j+1]) {
				int temp 		= q->array[j];
				q->array[j] 	= q->array[j+1];
				q->array[j+1] 	= temp;
			}
		}
	}
}


