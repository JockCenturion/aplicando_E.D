/*
 * Author: Jock
 * Date: 11/28/17
 * Hour: 1:19 PM
 *
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct funcionario {
	char nome[81];
	float salario;
}Funcionario;


void visualizaFuncionarios(Funcionario *array, int size) {
	for (int count = 0; count < size; count++) {
		printf("Nome: %s\nSalario: R$ %.2f\n\n", array[count].nome, 
			   array[count].salario);
	}	
}

void swap(Funcionario *var1, Funcionario *var2) {
	Funcionario aux = *var1;
	*var1			= *var2;
	*var2 			=  aux;
}

//Ordena por ordem Crescente 
void qSort(Funcionario *array, int start, int end, short upDown) {
	int left  			= start;
	int right 		 	= end;
	Funcionario pivot 	= array[(start + end) / 2];

	
	while (left <= right) {
		
		//Crescente
		while (array[left].salario  < pivot.salario && upDown == 1) left++;
		while (array[right].salario > pivot.salario && upDown == 1) right--;
		
		//Decrescente
		while (array[left].salario  > pivot.salario && upDown == 0) left++;
		while (array[right].salario < pivot.salario && upDown == 0) right--;
	
	
		if (left <= right) {
			swap(&array[left], &array[right]);
			left++;
			right--;
		}
	}
	
	if (left < end) {
		qSort(array, left, end, upDown);
	}
	
	if (right > start) {
		qSort(array, start, right, upDown);
	}
}

void qSortAlfabet(Funcionario *array, int start, int end) {
	int left 			= start;
	int right 			= end;
	Funcionario pivot 	= array[(left + right) / 2];
	
	while (left <= right) {
		while (stricmp(array[left].nome, pivot.nome)  < 0) left++;
		while (stricmp(array[right].nome, pivot.nome) > 0) right--;
		
		if (left <= right) {
			swap(&array[left], &array[right]);
			left++;
			right--;
		}
	}
	
	if (left < end) {
		qSortAlfabet(array, left, end);
	}
	
	if (right > start) {
		qSortAlfabet(array, start, right);
	}
}


int main() {
	Funcionario f[5] = {{"Bbas", 25}, {"Acas", 21}, {"Cacsa", 30}, {"Bacas", 26}, {"Ecas", 33}};
	//qSort(f, 0, 5-1, 1);
	qSortAlfabet(f, 0, 5-1);
	visualizaFuncionarios(f, 5);
	
	return 0;
}
