/*
 *Autor: Jock
 *Diciplina: ED 
 *Conteudo: Filas
 *Data 18/08/2017 | 00:46 |
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct stack {
	short *vet, top, length;
}Stack;


short isEmpty(Stack *s) {
	return !s->top;
}

short isFull(Stack *s) {
	return s->top == s->length;
}

short size(Stack *s) {
	return s->top;
}

void newStack(Stack *s, short length) {
	if ( !(s->vet = malloc(length * sizeof(short))) ) {
		printf("Error in newStack.");
		exit(1);
	} else {
		s->length = length;
		s->top    = 0;
	}
}

void addInStack(Stack *s, int value) {
	if ( s->top == s->length ) {
		printf("Error in function addInStack[isFull].");
		exit(1);
	}
	s->vet[s->top++] = value;
} 

short removeInStack(Stack *s) {
	if ( !s->top ) {
		printf("Error in function removeInStack[isEmpty].");
		exit(1);
	}
	return s->vet[--s->top];
}

void viewStack(Stack *s) {
	for (short i = s->top - 1; i >= 0; i--) 
		printf("%3d -> ", s->vet[i]);
	printf("NULL");
}

void freeStack(Stack *s) {
	free(s->vet);
}

void inverterStack(Stack *s) {
	short *newVet;
	
	if ( !(newVet = malloc(s->length * sizeof(short))) ) {
		printf("Error in function inverterStack.");
		exit(1);
	} else {
		for (short i = s->top - 1; i >= 0; i--)
			newVet[(s->top - 1) - i] = s->vet[i];
		
		free(s->vet);
		s->vet = newVet;
	}
}



