/*
 *Autor: Jock
 *Diciplina: ED 
 *Conteudo: Filas
 *Data 18/08/2017 | 00:46 |
 */


#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

typedef Stack Queue; 

void newQueue(Queue *q, int length) {
	newStack(q, length);
}

void addInQueue(Queue *q, int value) {
	addInStack(q, value);
}

short removeInQueue(Queue *q) {
	inverterStack(q);
	short value = removeInStack(q);
	inverterStack(q);
	return value;
}

void viewQueue(Queue *q) {
	inverterStack(q);
	viewStack(q);
	inverterStack(q);
}

void freeQueue(Queue *q) {
	freeStack(q);
}

/* Funções size, isFull e isEmpty são "herdados" */



