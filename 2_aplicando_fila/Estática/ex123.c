/*
 *Autor: Jock
 *Diciplina: ED 
 *Conteudo: Filas
 *Data 18/08/2017 | 00:46 |
 */


#include <stdio.h>
#include <stdlib.h>
#include "fila.c"

void ex01(Queue *f) {
	printf("Solucao da Questao 1\n");
	viewQueue(f);
	
	for (int i = 0; i < size(f); i++) {
		int value = removeInQueue(f);
		addInQueue(f, value < 0 ? 0 : value);
	}
	
	viewQueue(f);
}


void ex02(Queue *f1, Queue *f2, Queue *f3) {
	printf("Solucao da Questao 2\n");
	newQueue(f3, size(f1) + size(f2));
	
	/*Remove da Fila 1 e add in Fila 3*/
	while ( !isEmpty(f1) ) 
		addInQueue(f3, removeInQueue(f1));
		
	/*Remove da Fila 2 e add in Fila 3*/
	while ( !isEmpty(f2) ) 
		addInQueue(f3, removeInQueue(f2));
	
	/*Fila Pós operacões*/
	sortedQueue(f3);		//Ordenacao	
	viewQueue(f3);
}

void ex03(Queue *f) {
	int value = removeInQueue(f);
	
	if ( !isEmpty(f) ) 
		ex03(f);
	
	addInQueue(f, value);		//Insere a parti do ultimo elemento	
	
	if ( isFull(f) ) {
		printf("Solucao da Questao 3\n");
		viewQueue(f);
	}
}


int main() {
	
	/* Declaraçoes */
	Queue f, f2, f3, f4, f5;
	
	newQueue(&f, 5);
	newQueue(&f2, 5);
	newQueue(&f4, 5);
	newQueue(&f5, 5);
	
	/*Inicializacao da Fila f*/
	addInQueue(&f, -1);
	addInQueue(&f, 2);
	addInQueue(&f, -3);
	addInQueue(&f, -4);
	addInQueue(&f, 5);
	
	/*Inicializacao da Fila f2*/
	addInQueue(&f2, 6);
	addInQueue(&f2, 7);
	addInQueue(&f2, 8);
	addInQueue(&f2, 9);
	addInQueue(&f2, 10);
	
	/*Inicializacao da Fila f4*/
	addInQueue(&f4, 10);
	addInQueue(&f4, 11);
	addInQueue(&f4, 12);
	addInQueue(&f4, 13);
	addInQueue(&f4, 14);
	
	/*Inicializacao da Fila f5*/
	addInQueue(&f5, 1);
	addInQueue(&f5, 2);
	addInQueue(&f5, 3);
	addInQueue(&f5, 4);
	addInQueue(&f5, 5);
	
	
	
	/*Respostas das Questoes 1, 2, e 3*/
	ex01(&f);
	ex02(&f2, &f5, &f3);
	ex03(&f4);
	
	return 0;
}


