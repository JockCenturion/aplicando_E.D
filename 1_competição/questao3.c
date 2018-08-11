#include <stdio.h>
#include <stdlib.h>

void criaString(char **caracter, int size) 
{
	*caracter = malloc(sizeof(char) * size);
}

/**
 *
 * @return 0 não encontrou o caracter
 * @return 1 encontrou o caracter
 *
 */
short primeiraOcorrenciaDoCaracter(char *caracter, int size, char ctr) 
{
	
	short count = 0;
	short ocorrencia = 0;
	
	while (count < size && !ocorrencia) 
	{
		ocorrencia = (caracter[count++] == ctr) ? 1 : 0;
	}
	
	return ocorrencia;
}

/**
 *
 * @return 0 para inválida
 * @return 1 para válida
 *
 */
short analisaAutencidadeDaString(char *caracter, int size) 
{
	short resultado, count;
	
	resultado = 1;
	count = 0;
	
	while ( resultado && count < size )
	{
		resultado = ( caracter[count] == 83 || caracter[count] == 69 || caracter[count] == 46 || 
					  caracter[count] == 35 ) ? 1 : 0;
					   
		count++;
	}
	
	return resultado;
}


short contaQuantidadeDeVazios(char *caracter, int size)
{
	short countVazios = 0;
	
	for (short count = 0; count < size; count++)
	{
		countVazios += (caracter[count] == 46) ? 1 : 0;
	}
	
	return countVazios;
}

int executaCalculoDoTimeEstaped(int niveis, int linhas, int colunas) 
{
	
	char *caracter;
	int timeEscaped = 0;

	criaString(&caracter, colunas);
	
	//Complexidade O(N^2)
	for (int count1 = 0; count1 < niveis; count1++) 
	{
		for (int count2 = 0; count2 < linhas; count2++) 
		{
			
			setbuf(stdin, NULL);
			scanf("%[^\n]", caracter);
			
			if (!primeiraOcorrenciaDoCaracter(caracter, colunas, 'S'))
			{
				timeEscaped += contaQuantidadeDeVazios(caracter, colunas);
			}
			
			if (analisaAutencidadeDaString(caracter, colunas) == 0) 
			{
				exit(1);
			}

			printf("\n");
		}
		
		printf("\n\n\n");
	}

	return timeEscaped;
}



int main() 
{
	

	int niveis;
	int linhas;
	int colunas;
	int timeEscaped;

	niveis = linhas = colunas = 0;
	
	scanf("%d %d %d", &niveis, &linhas, &colunas);
	
	printf("\n");
	
	timeEscaped = executaCalculoDoTimeEstaped(niveis, linhas, colunas);
	
	if (timeEscaped != 0) 
	{
		printf("Escaped in %d minute(s)", timeEscaped);
	} 
	else 
	{
		printf("Trapped!");
	}

	return 0;
}
