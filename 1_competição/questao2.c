#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/****************************Lista Duplamente Encadeada***********************************************/
/**TIPOS ABSTRATOS DE DADOS(TDA)**/
struct aresta {
	char no1, no2;
	int indice;
	struct aresta *prox;
	struct aresta *prev;
};


struct lista {
	struct aresta *head;
	struct aresta *tail;
	int size;
};
	
typedef struct aresta Aresta;
typedef struct lista Lista;	

/**Funções auxiliares**/
void rotinaUm() 
{
	printf("Error fatal\n");
	exit(1);
}

/**Funçoes de acesso ao TDA**/
void criaLista(Lista **lista) 
{
	*lista = malloc(sizeof(struct lista));
	
	if ( !(lista) ) { rotinaUm(); }
	
	(*lista)->head = (*lista)->tail = NULL;
	(*lista)->size = 0;
}

char listaVazia(Lista **lista) 
{
	return !(*lista) ? 1 : 0;
}

void insereNaLista(Lista **lista, char no1, char no2)
{
	if (listaVazia(lista)) { rotinaUm(); }

	Aresta *aresta = malloc(sizeof(struct aresta));
	aresta->no1 = no1;
	aresta->no2 = no2;
	aresta->indice = (*lista)->size;
	aresta->prev = aresta->prox = NULL;
	
	if ( !(*lista)->tail && !(*lista)->head )
	{
		(*lista)->tail = (*lista)->head = aresta;
	} 
	else 
	{
		aresta->prev = (*lista)->tail;
		(*lista)->tail = (*lista)->tail->prox = aresta;
	}
	
	(*lista)->size++;
}

Aresta* buscaCelulaPor(Lista **lista, int indice) 
{
	for (struct aresta* celula = (*lista)->head; celula != NULL; celula = celula->prox) 
	{
		
		if (celula->indice == indice) 
		{
			return celula;
		}
	}
	
	return NULL;
}

void exibeListaEmOrdem(Lista **lista) 
{
	for (struct aresta* count = (*lista)->head; count != NULL; count = count->prox)
	{
		printf("| %c %c |", count->no1, count->no2);
	}
}

void exibeListaEmOrdemInversa(Lista **lista) 
{
	for (struct aresta* count = (*lista)->tail; count != NULL; count = count->prev)
		printf("%c %c ", count->no1, count->no2);
}

/*************************Algortimo*********************************************/
short existeVazio(int *array, int size) 
{
	int count = 0;

	while (array[count] != 0 && count < size) { count++; }

	return (count == size) ? 0 : 1;
}

short posicaoDoMenorVazio(int *array, int size) 
{
	int count = 0;

	while (array[count] != 0) { count++; }
	
	return count;
}

short maiorElementoDoMarcador(int *array, int size)
{
	int maior = array[0];
	
	for (int count = 1; count < size; count++) 
	{
		maior = (maior < array[count]) ? array[count] : maior;
	}
	
	return maior;
}

void comparaComNaoMarcadosEFazMarcacao(Lista **lista, Aresta *celula, int *marcadores, int marcador) 
{

	for (struct aresta* particula = (*lista)->head; particula != NULL; particula = particula->prox) 
	{

		if ( (marcadores[particula->indice] == 0) && (celula->no1 == particula->no1 || celula->no1 == particula->no2) 
			|| (celula->no2 == particula->no1 || celula->no2 == particula->no2) ) 
		{
	
			marcadores[particula->indice] = marcador;
		}
	}
}

short seLigaComMarcados(Lista **lista, Aresta *celula, int *marcadores) 
{

	for (struct aresta* particula = (*lista)->head; particula != NULL; particula = particula->prox) 
	{

		if ( (marcadores[particula->indice] >= 1) && (celula->no1 == particula->no1 || celula->no1 == particula->no2 || celula->no2 == particula->no1 || celula->no2 == particula->no2) ) 
		{
			return 1;
		}
	}
	
	return 0;
}

int realizaCalculo(Lista **lista) 
{

	int size = (*lista)->size;
	int *marcadores = malloc(size * sizeof(int));
	int marcador = 0;

	memset(marcadores, 0, sizeof(int) * size); 
	
	while ( existeVazio(marcadores, size) )
	{
		int posicao = posicaoDoMenorVazio(marcadores, size);

		Aresta *celula = buscaCelulaPor(lista, posicao);
		
		if ( !seLigaComMarcados(lista, celula, marcadores) ) 
		{
			marcador++;
		}
		
		comparaComNaoMarcadosEFazMarcacao(lista, celula, marcadores, marcador);
	}

	return maiorElementoDoMarcador(marcadores, size);
}


int main() 
{

	int inteiro;
	char letraTeste;
	char aresta[3];
	Lista* lista;
	
	criaLista(&lista);
	
	scanf("%d", &inteiro);
	
	printf("\n");
	
	setbuf(stdin, NULL);
	scanf("%c", &letraTeste);
	
	printf("\n");
	
	insereNaLista(&lista, tolower(letraTeste), '0');

	while (1) 
	{
		setbuf(stdin, NULL);
		scanf("%[^\n]", aresta);
		
		printf("\n");
		
		if (strlen(aresta) == 0) 
		{
			break;
		}
		
		insereNaLista(&lista, tolower(aresta[0]), tolower(aresta[1]));
		
		aresta[0] = '\0';
	}
	
	printf("\n%d", realizaCalculo(&lista));
	

	return 0;
}


 	//A inserção pode ser minusculas ou maiusculas, mas sempre defina um só tipo, minuscula ou maiuscula, nunca os dois.

	/**
	 * 
	 *  TESTES MANUAIS DE GRAFOS REALIZADOS NO ALGORITMO
	 *
	 *
	
	//2 grafos
	//insereNaLista(&lista, 'e', '0'); // Este caractere representa o maior nome de nó no grafo (na interação insira somente e)
	
	//insereNaLista(&lista, 'a', 'b');
	
	//insereNaLista(&lista, 'c', 'e');
	
	//insereNaLista(&lista, 'd', 'b');
	
	//insereNaLista(&lista, 'e', 'c');
	
	//4 grafos
	//insereNaLista(&lista, 'a', '0'); // Este caractere representa o maior nome de nó no grafo (na interação insira somente a)

	//insereNaLista(&lista, 'a', 'b');
	
	//insereNaLista(&lista, 'b', 'c');
	
	//insereNaLista(&lista, 'e', 'f');
	
	//insereNaLista(&lista, 'g', 'h');
	
	//insereNaLista(&lista, 'i', 'j');
	
	//insereNaLista(&lista, 'j', 'i');

	
	//1 Grafo
	//insereNaLista(&lista, 'a', '0'); // Este caractere representa o maior nome de nó no grafo (na interação insira somente a)

	//insereNaLista(&lista, 'a', 'b');
	
	//insereNaLista(&lista, 'b', 'd');
	
	//insereNaLista(&lista, 'd', 'c');
	
	//insereNaLista(&lista, 'a', 'c');
	
	
	
	//2 Grafos
	//insereNaLista(&lista, 'a', '0'); // Este caractere representa o maior nome de nó no grafo (na interação insira somente a)
	
	//insereNaLista(&lista, 'a', 'b');
	
	//insereNaLista(&lista, 'b', 'c');
	
	//insereNaLista(&lista, 'c', 'f');
	
	//insereNaLista(&lista, 'e', 'd');
	
	printf("Qunatidade de Grafos: %d", realizaCalculo(&lista));
	*/




