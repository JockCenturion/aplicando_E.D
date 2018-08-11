#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//__________\\\______________///TAD Pizza\\\________________///_____________\\/
typedef struct {
	char *sabor, *end, *data, *nomeCliente;
	double valor;
	int cod;
}Pizza;

short constructorPz(Pizza *pz, int cod, char *nomeCliente, char *sabor, char *end, char *data, double valor) {
	if ( !(pz->sabor =  malloc(strlen(sabor))) || !(pz->end = malloc(strlen(end))) || 
		 !(pz->nomeCliente = malloc(strlen(nomeCliente))) || !(pz->data  =  malloc(strlen(data)))) {
		printf("Error!\n");
		return 0;	 	
	} else {
		strcpy(pz->sabor, sabor);
		strcpy(pz->end, end);
		strcpy(pz->data, data);
		strcpy(pz->nomeCliente, nomeCliente);
		pz->valor = valor;
		pz->cod   = cod;
		return 1;
	}
}

void impressPz(Pizza *pz) {
	printf("Codigo: %d\nNome do Cliente: %s\nSabor: %s\nEndereco: %s\nData: %s\nPreco: %f\n\n",
		   pz->cod, pz->nomeCliente, pz->sabor, pz->end, pz->data, pz->valor);
} 

void liberatePz(Pizza *pz) {
	free(pz->nomeCliente);
	free(pz->sabor);
	free(pz->end);
	free(pz->data);
	free(pz);
}



//__________\\\______________///TAD Pilha\\\________________///_____________\\/
typedef struct no {
	Pizza *pz;	
	struct no *prox;	
}No;

typedef struct {
	No *top;
	int index;
}Pilha; 

void create(Pilha **p) {
	if ( !( *p = (Pilha*) malloc(sizeof(Pilha))) ) { printf("Error!\n"); exit(1); } 
	else { (*p)->top = NULL; (*p)->index = -1; }
}

short push(Pilha **p, char *nomeCliente, char *sabor, char *end, char *data, double valor) {
	No *nodo;
	
	if ( !(nodo = (No*) malloc(sizeof(No))) || !(nodo->pz = (Pizza*) malloc(sizeof(Pizza))) || 
		 !constructorPz(nodo->pz, ++(*p)->index, nomeCliente, sabor, end, data, valor) ) {
		printf("Error!\n");
		exit(1);
	} else {
		nodo->prox  = (*p)->top; 
		(*p)->top   = nodo;
	}
}

void impress(Pilha **p) {
	for (No *i = (*p)->top; i != NULL; i = i->prox) 
		impressPz(i->pz);
}

char isEmpty(Pilha **p) {
	return ((*p)->top == NULL);
}

Pizza* pop(Pilha **p) {
	if(isEmpty(p)) {
		printf("Error!\n");
		exit(1);
	} else {
		No 		*aux1 = (*p)->top;
		Pizza 	*aux2 = (*p)->top->pz; 			//eliminar e guardar os valores
		(*p)->top     = (*p)->top->prox;
		(*p)->index--;
		
		free(aux1);
		return (aux2);
	}
}

char search(Pilha **p, int cod) {
	int aux1 = (*p)->index;
	No* aux2 = (*p)->top;
	
	while (aux2 != NULL && aux2->pz->cod != cod) {
		aux1--;
		aux2 = aux2->prox;
	}
	
	return aux1;
	return -1;
}

void liberate(Pilha **p) {
	No *aux1 = (*p)->top;
	
	while (aux1 != NULL) {
		No *temp = aux1->prox;
		liberatePz(aux1->pz);		//libera todo struct pizza e suas alocaçoes dinamicas
		free(aux1);
		aux1 = temp;
	}
	
	free(*p);
}

void reverse(Pilha **p) {
	Pizza **vet;
	int aux1 = (*p)->index;
	
	if ( !(vet = malloc( ++aux1 * sizeof(Pizza*))) ) {
		printf("Error!\n");
		exit(1);
	} else {
		for (No *i = (*p)->top; i != NULL; i = i->prox) 
			vet[--aux1] = i->pz;
		for (No *i = (*p)->top; i != NULL; i = i->prox) 
			i->pz = vet[aux1++];  
		free(vet);
	}
}


int main() {
	
	Pilha *p;
	
	create(&p);
	
	push(&p,"Jock", "Mussarela", "Rua40", "13.05", 50);
	push(&p,"Rock", "Mussarela", "Rua10", "13.05", 50);
	push(&p,"Debora", "Calabreza", "Rua4", "13.05", 100);
	push(&p,"Romeu", "Mussarela", "Rua5", "13.05", 20);
	
	printf("\n\n1 - Remove o topo e Imprime a pizza do topo, Romeu, somente ela.\n\n");
	impressPz(pop(&p));
	
	printf("\n\n2 - Imprime toda pilha.\n\n");
	impress(&p);
	
	printf("\n\n3 - Busca pela pizza 3, Romeu ja foi removido.\n\n");
	printf("%d\n", search(&p, 3) );
	
	printf("\n\n4 - Invertendo a Pilha...");
	reverse(&p);
	
	printf("\n\n5 - Inserindo a Pizza de Romeu com a pilha invertida...\n");
	push(&p,"Romeu", "Mussarela", "Rua5", "13.05", 20);
	
	printf("\n\n6 - Imprimindo toda a pilha com a pizza de Romeu inserida na pilha invertida.\n\n");
	impress(&p);
	
	
	return 0;
}
