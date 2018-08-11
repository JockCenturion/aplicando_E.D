/*
 *Autor: Jock
 *Diciplina: ED 
 *Conteudo: Filas
 *Data 18/08/2017 | 00:46 |
 */


#include <stdio.h>
#include <stdlib.h>

/* Fila de com Prioridade */
typedef struct info {
	short value, priority;
}Info;

typedef struct queue {
	Info **array;
	short head, tail, length;
}Queue;

short size(Queue *q) {
	return ( q->tail - q->head );
}

short isFull(Queue *q) {
	return ( size(q) == q->length );
}

short isEmpty(Queue *q) {
	return ( !q->tail );	
}

void newQueue(Queue *q, short length) {
	if ( !(q->array = malloc(length * sizeof(Info*))) ) {
		printf("Error in newQueue.");
		exit(1);
	} else {
		q->head = q->tail = 0;
		q->length = length;
	}
}

void addInQueue(Queue *q, short value, short priority) {
	if ( isFull(q) || !(q->array[q->tail % q->length] = malloc(sizeof(Info))) ) {
		printf("Erro in addInQueue [isFull].");
		exit(1);
	} 
	q->array[q->tail % q->length]->value = value;
	q->array[q->tail % q->length]->priority = priority;
	q->tail++;
}

Info* removeInQueue(Queue *q) {
	if ( isEmpty(q) ) {
		printf("Erro in removeInQueue [isEmpty].");
		exit(1);
	} else {
		return q->array[q->head++ % q->length];
	}
}

Queue* divisionByPriority(Queue *q, short priority) {
	/* Declaraçoes */
	Queue *queues;
	int length = size(q);
	
	/*Alocando o array de Queues*/
	if ( !(queues = malloc(2 * sizeof(Queue))) ) {
		printf("Error");
		exit(1);
	}
	
	/* Criando as Duas Filas */
	newQueue(&queues[0], length);
	newQueue(&queues[1], length);
	
	/* fila[0] (menor prioridade) && fila[1] (maior prioridade) */
	for (int i = 0; i < length; i++) {
		if (  q->array[i]->priority <= priority ) 
			addInQueue(&queues[0], q->array[i]->value, q->array[i]->priority);
		else 
			addInQueue(&queues[1], q->array[i]->value, q->array[i]->priority);
	}

	/* Retorna o array de fila */
	return queues;
}

void viewQueue(Queue *q) {
	for (int i = q->head; i < q->tail; i++) 
		printf("[%d, %d] -> ", q->array[i % q->length]->value, q->array[i % q->length]->priority);
	printf("NULL\n");
}

void freeQueue(Queue *q) {
	free(q->array);
}

 


int main() {
	/* Criacao e Inicializaca da fila q */
	Queue q;
	newQueue(&q, 6);
	addInQueue(&q, 2, 0);
	addInQueue(&q, 3, 1);
	addInQueue(&q, 4, 2);
	addInQueue(&q, 5, 0);
	addInQueue(&q, 6, 1);
	addInQueue(&q, 7, 2);
	

	/*Solucao da questao 5*/
	Queue *d = divisionByPriority(&q, 1);   // --> [ Alterar Aqui a Prioridade ] <---
 	viewQueue(&q);
	viewQueue(&d[0]);
	viewQueue(&d[1]);

	


	
	
	

	return 0;
}
