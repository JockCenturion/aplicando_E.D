#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aresta {
	int value;
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
	
	if ( !(*lista) ) { rotinaUm(); }
	
	(*lista)->head = (*lista)->tail = NULL;
	(*lista)->size = 0;
}

char listaVazia(Lista **lista) 
{
	return !(*lista) ? 1 : 0;
}

void insereNaLista(Lista **lista, int value)
{
	if (listaVazia(lista)) { rotinaUm(); }

	Aresta *aresta = malloc(sizeof(struct aresta));
	aresta->value = value;
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

Aresta* buscaCelulaPor(Lista **lista, int value) 
{
	for (struct aresta* celula = (*lista)->head; celula != NULL; celula = celula->prox) 
	{
		
		if (celula->value == value) 
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
		printf("| %d |", count->value);
	}
}

void exibeListaEmOrdemInversa(Lista **lista) 
{
	for (struct aresta* count = (*lista)->tail; count != NULL; count = count->prev)
		printf("| %d |", count->value);
}

/***********************************************************************************/
int* listToArray(Lista **lista) 
{
	
	int *array = malloc(sizeof(int) * (*lista)->size);
	int count = 0;
	
	for (struct aresta* celula = (*lista)->head; celula != NULL; celula = celula->prox) 
	{
		array[count] = celula->value;
		count++;
	}
	
	return array;
} 

int countCaracter(char *string, int count) {

	int size = 0;
	
	while (string[count] != 32) {
		
		if (string[count] == '\0') break;

		size++;
		count++;
	}
	
	return size;
}

Lista* montaString(char *string) 
{
	Lista *lista;
	int tamStr = strlen(string);
	int count = 0;
	char *temp;
	
	criaLista(&lista);

	while (string[count] != '\0' && count < tamStr) 
	{

		int size = countCaracter(string, count);
		temp = malloc(sizeof(char) * size);
		int indice = 0;
		
	
	
		for (indice = 0; indice < size; indice++) {
			temp[indice] = string[count];
			count++;
		}
		
		temp[indice] = '\0';
		
		insereNaLista(&lista, atoi(temp));
		
		free(temp);	
		count++;
	}
	
	return lista;
}


struct aresta* buscaPrimeiroALigar(Lista **listas, int posPrimeiraLista, int posSegundaLista) 
{
	for (struct aresta *celula = listas[posPrimeiraLista]->head; celula != NULL; celula = celula->prox) 
	{
		for (struct aresta *celula1 = listas[posSegundaLista]->head; celula1 != NULL; celula1 = celula1->prox) 
		{
			if (celula->value == celula1->value && celula1->value != 0) 
			{
				return celula1;
			}
		}
	}
	
	return NULL;
}


struct aresta* buscaUltimoAligar(Lista **listas, int posPrimeiraLista, int posSegundaLista) 
{
	struct aresta *ultimoLigar = NULL;
	
	for (struct aresta* celula = listas[posPrimeiraLista]->head; celula != NULL; celula = celula->prox) 
	{
		
		for (struct aresta *celula1 = listas[posSegundaLista]->head; celula1 != NULL; celula1 = celula1->prox) 
		{
			if (celula->value == celula1->value && celula1->value != 0) 
			{
				ultimoLigar = celula1;
			}
		}
		
	}
	
	return ultimoLigar;
}



struct aresta* buscaObjetivo(Lista **listas, int k, int posicaoLista) {
	
	for (struct aresta *celula = listas[posicaoLista]->head; celula != NULL; celula = celula->prox) 
	{
		if (celula->value == k) 
		{
			return celula;
		}
	}
	
	return NULL;	
}


int realizaCalculo(int n, int k, int *ts) 
{
	
	Lista** listas; 
	char string[k];


	listas = malloc(sizeof(Lista*) * n);

	
	for (int count = 0; count < n; count++) 
	{
		criaLista(&listas[count]);
		
		setbuf(stdin, NULL);
		scanf("%[^\n]", &string);

		listas[count] = montaString(string);
	}
	

	//Variaveis para resolução do problema
	int count = 0;
	int controle = 0;
	int distancia = 0;
	
	struct aresta *celulaAnterior = NULL;
	struct aresta *celulaObjetivo = NULL;
	struct aresta *celulaMaior 	  = NULL;
	
	while (count < n) 
	{
		if (n == 1) {

			
			celulaObjetivo = buscaObjetivo(listas, k, count);
			distancia = celulaObjetivo != NULL ? (celulaObjetivo->value * ts[count]) : 0; 
			break;

		}
		
		if (controle == 0) 
		{
			celulaAnterior = buscaPrimeiroALigar(listas, 0, 1);
			distancia = celulaAnterior == NULL ? 0 : (celulaAnterior->value * ts[count]); 
			count++;
		} 
		else 
		{
			
			celulaObjetivo = buscaObjetivo(listas, k, count);
			
			if (celulaObjetivo != NULL) 
			{

				distancia += (celulaObjetivo->value - celulaAnterior->value) * ts[count];
				break;
			} 
			else 
			{
				if (celulaAnterior->prox == NULL)  
				{
					celulaMaior = buscaUltimoAligar(listas, count, count + 1); 
					distancia += (celulaAnterior->value - celulaMaior->value) * ts[count];
					count++;
				} 
				else 
				{
					celulaMaior = buscaUltimoAligar(listas, count, count - 1); 
					distancia += (celulaMaior->value - celulaAnterior->value) * ts[count];
					count--;
				}
				
				celulaAnterior = celulaMaior;

			}
			
		}
		
		distancia += 60;
		controle++;
	}
	
	return distancia;
}



int main() 
{


	int n, k;
	int *pesos;
	Lista *lista;
	
	scanf("%d %d", &n, &k);
	
	char string[n + (n - 1)];
	
	setbuf(stdin, NULL);
	scanf("%[^\n]", &string);
	lista = montaString(string);
	pesos = listToArray(&lista);
	
	int custo = realizaCalculo(n, k, pesos);
	
	if (custo == 0) 
	{
		printf("IMPOSSIBLE");
	} 
	else 
	{
		printf("%d", custo); 
	}
	
	
	


/*	// 0 1 3 5 7 9 11 13...
	// 4 13 15 19 20 25..
	// 10 5
	// 2 30
	int *pesos = malloc(sizeof(int) * 2);
	pesos[0] = 10;
	pesos[1] = 5;
	printf("%d", realizaCalculo(2, 30, pesos));
*/	

/*	// 0 5 10 12 14 20...
	// 2 4 6 8 10 12 14 22 25 28...
	// 10 1
	// 2 30
	int *pesos = malloc(sizeof(int) * 2);
	pesos[0] = 10;
	pesos[1] = 1;
	printf("%d", realizaCalculo(2, 30, pesos));
*/

	
/*	// 0 10 30 40
	// 0 20 30
	// 0 20 50
	// 10 50 100
	// 2 50
	int *pesos = malloc(sizeof(int) * 3);
	pesos[0] = 10;
	pesos[1] = 50;
	pesos[2] = 100;
	printf("%d", realizaCalculo(3, 50, pesos)); //será solicitado que digite a lista, dê espaços entre os numeros 2 3 4 5 ...
*/	
	
	/*// 0 2 4 6 8 10
	// 2
	// 1 1
	int *pesos = malloc(sizeof(int) * 1);
	pesos[0] = 2;
	printf("%d", realizaCalculo(1, 1, pesos));
	*/


	
	return 0;
}






















