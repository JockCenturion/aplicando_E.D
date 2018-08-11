#include <stdio.h>
#include <stdlib.h>


typedef struct funcionario {
	char nome[10];
	//char endereco[20];
	//char telefone[10];
	//char email[10];
	float salario;
}Funcionario;

void alocaFuncionarios(Funcionario **funcionarios, int max) 
{
	if ( !( *funcionarios = malloc( max * sizeof(Funcionario)) ) ) 
	{
		printf("Error ao alocar");
		exit(1);
	}
}

int encontraMaiorSalario(Funcionario *funcionarios, int size) 
{
	float maiorSalario = funcionarios[0].salario; 			//absurdo que o maior é primeiroSalario
	int indiceMaiorSalario;

	for (int count = 1; count < size; count++) {
		if (maiorSalario < funcionarios[count].salario) {
			maiorSalario = funcionarios[count].salario;		//guardo o novo maior salario para comparar na proxima interação
			indiceMaiorSalario = count;						//guardo o indice do maior salario
		}
	}
	
	return indiceMaiorSalario;
}



int main() 
{
	
	Funcionario *funcionarios;
	int quantidadeMaxima;
	
	printf("Informe a quantidade de Funcionarios: ");
	scanf("%d", &quantidadeMaxima);
	
	printf("\n");
	
	alocaFuncionarios(&funcionarios, quantidadeMaxima);

	for (int count = 0; count < quantidadeMaxima; count++) {
		
		printf("Nome: ");
		setbuf(stdin, NULL);
		scanf("%[^\n]", funcionarios[count].nome);
		
		printf("Salario: ");
		scanf("%f", &funcionarios[count].salario);
		
		printf("\n");
	}
	
	int indiceMaiorSalario = encontraMaiorSalario(funcionarios, quantidadeMaxima);
	
	printf("Nome: %s\n", funcionarios[indiceMaiorSalario].nome);
	printf("Salario: %.2f\n", funcionarios[indiceMaiorSalario].salario);
	printf("\n");
	

	return 0;
}
