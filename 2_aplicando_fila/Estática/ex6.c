/*
 *Autor: Jock
 *Diciplina: ED 
 *Conteudo: Filas
 *Data 18/08/2017 | 00:46 |
 */

#include <stdio.h> 
#include <stdlib.h>

typedef struct nodo {
	int id, indice;
	struct nodo *prox;
}Nodo;

typedef struct queue {
	Nodo *head, *tail;
	int size;
}Queue;

int size(Queue **q) {
	return (*q)->size;
}

short isEmpty(Queue **q) {
	return ( !(*q)->head );
}

void newQueue(Queue **q) {
	if ( !( *q = malloc(sizeof(Queue))) ) {
		printf("Error.");
		exit(1);
	} else {
		(*q)->head = (*q)->tail = NULL;
		(*q)->size = 0;	
	}
}

void addInQueue(Queue **q, int id) {
	Nodo *no;
	
	if ( !(no = malloc(sizeof(Nodo))) ) {
		printf("Error.");
		exit(1);
	} else {
		no->id  	= id;
		no->indice 	= (*q)->size++;
		no->prox 	= NULL;
	}
	
	if ( !(*q)->head ) 
		(*q)->tail = (*q)->head = no;
	else 
		(*q)->tail = (*q)->tail->prox = no;
} 

int removeInQueue(Queue **q) {
	if ( !(*q)->head ) {
		printf("Error.");
		exit(1);
	} else {
		int id = (*q)->head->id;
		Nodo *oldHead = (*q)->head;
		
		(*q)->head = oldHead->prox;
		free(oldHead);
		
		return id;
	}
}

Nodo* getHead(Queue **q) {
	return (*q)->head;
}

void viewQueue(Queue **q) {
	for (Nodo *i = (*q)->head; i != NULL; i = i->prox) 
		printf("|%d|%3d| -> ", i->indice, i->id);
	printf("NULL\n");
	
} 


int main() {
	
	/* Declaracoes */
	Queue *filaDeDecolagem, *filaDeEspera;
	int resp, id;
	
	/* Criando as filas */
	newQueue(&filaDeDecolagem);
	newQueue(&filaDeEspera);
	
	/* Questao 6 */
	do {
		
		printf("\n\t\tMenu\t\t\n"
			   "\n\t1) Adicionar avioes na fila de Decolagem."
			   "\n\t2) Lista Numero de Avioes na fila de Decolagem."
			   "\n\t3) Autorizar a decolagem do primeiro avião da fila."
			   "\n\t4) Adicionar um avião à fila de espera." 
			   "\n\t5) Listar todos os aviões na fila de espera."
			   "\n\t6) Listar as características do primeiro avião da fila."
			   "\n\t7) Sair.\n\n");
			   
		scanf("%d", &resp);
		
		switch (resp) {
			case 1: 
				printf("ID do Aviao: ");
				scanf("%d", &id);
				addInQueue(&filaDeDecolagem, id);
				break;
			case 2: 
				viewQueue(&filaDeDecolagem);
				break;
			case 3:
				removeInQueue(&filaDeDecolagem);
				break;
			case 4: 
				printf("ID do Aviao: ");
				scanf("%d", &id);
				addInQueue(&filaDeEspera, id);
				break;
			case 5:
				viewQueue(&filaDeEspera); 
				break;
			case 6: 
				if ( !isEmpty(&filaDeDecolagem) ) 
					printf("Primeiro da fila de Decolagem: |%d|%3d|\n", getHead(&filaDeDecolagem)->indice, getHead(&filaDeDecolagem)->id);
				if ( !isEmpty(&filaDeEspera) ) 
					printf("Primeiro da fila de Espera: |%d|%3d|\n", getHead(&filaDeEspera)->indice, getHead(&filaDeEspera)->id);
				break;
			case 7:
				printf("Saindo...\n"); 
				break;
			default: 
				printf("Opcao Invalida.\n");
		}	
	} while (resp != 7);
	
	
	return 0;
}
