#include <stdio.h>
#include <stdlib.h>
#include "Data.c"

typedef struct no {
	Data *data;
	struct no *prev, *prox;	
}No;

typedef struct queue {
	No *head, *tail;
	short size, priority;
}*Queue;

short isEmpty(Queue *q) {
	return !(*q)->head;
}

short size(Queue *q) {
	return (*q)->size;
}

Data* getHead(Queue *q) {
	return (isEmpty(q) ? NULL : (*q)->head->data);
} 

Data* getTail(Queue *q) {
	return (isEmpty(q) ? NULL : (*q)->tail->data);
}

void newQueue(Queue *q, int priority) {
	if ( !(*q = malloc (sizeof(struct queue))) ) {
		printf("[Error]\n");
		exit(1);
	} else {
		(*q)->head = (*q)->tail = NULL;
		(*q)->size = 0;
		(*q)->priority = priority;
	}
}

void addInQueue(Queue *q, Data *dt) {
	No *nodo = NULL, *prev = NULL, *current = (*q)->head;
	
	if ( !(nodo = malloc(sizeof(No))) ) {
		printf("[Error]\n");
		exit(1);
	} else {
		(*q)->size++;
		nodo->data = dt;
		nodo->prev = nodo->prox = NULL;
	}
	
	if ( (*q)->priority ) {

		while (current != NULL && dt->priority > current->data->priority) {
			prev 	= current;
			current = current->prox;
		}
		
		if ( !prev ) {
			(*q)->head = nodo;
			nodo->prox = current;
	 	} else {
			prev->prox = nodo;
			nodo->prev = prev;
			nodo->prox = current;
		}
		
		if ( current ) 
			current->prev = nodo;
		if ( !nodo->prox) 
			(*q)->tail = nodo;
			
	} else  {
		if ( !(*q)->head ) {
			(*q)->head = (*q)->tail = nodo;
		} else {
			nodo->prev = (*q)->tail;
			(*q)->tail = (*q)->tail->prox = nodo;
		}
	}
}

Data* removeInQueue(Queue *q) {
	if ( !(*q)->head ) {
		printf("Error\n");
		exit(1);
	} else {
		(*q)->size--;
		No   *aux = (*q)->head;
		Data *data = aux->data;
		
		(*q)->head = aux->prox;
		if ( (*q)->head ) (*q)->head->prev = NULL;
		else 			  (*q)->tail 	   = NULL;
		
		free(aux);
		return data;
	}
}

void freeQueue(Queue *q) {
	No *aux = NULL;
	
	while ((*q)->head != NULL) {
		aux = (*q)->head->prox;
		free( (*q)->head );
		(*q)->head = aux;
	}
	
	(*q)->head = (*q)->tail = NULL;
}

void reverseQueue(Queue *q) {
	Queue reverse;
	newQueue(&reverse, 0);
	
	for (No *i = (*q)->tail; i != NULL; i = i->prev) {
		addInQueue(&reverse, i->data);
	}
	
	freeQueue(q);
	*q = reverse;
} 

void viewQueueProx(Queue *q) {
	for (No *i = (*q)->head; i != NULL; i = i->prox)
		impress(i->data);
}

void viewQueuePrev(Queue *q) {
	for (No *i = (*q)->tail; i != NULL; i = i->prev) 
		impress(i->data);
	
}


