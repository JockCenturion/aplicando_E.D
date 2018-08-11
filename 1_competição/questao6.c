/*
 * 
 * Author: Jock
 * Date: 11/28/17
 * Hour: 8:34 AM
 *
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct aluno {
	int matricula;
	char nome[81];
} Aluno;

void imprimeAlunos(Aluno *array, int size) {
	for (int count = 0; count < size; count++) {
		printf("\tMatricula: %d\n\tNome: %s\n\n", array[count].matricula, array[count].nome);
	}
}

void quickSort(Aluno *array, int start, int end) {
	int left  = start;
	int right = end;
	int pivot = array[(left + right) / 2].matricula;

	while (left <= right) {
		while (array[left].matricula < pivot) {
			left++;
		}

		while (array[right].matricula > pivot) {
			right--;
		}

		if (left <= right) {
			Aluno aux		= 	array[left];
			array[left] 	= 	array[right];
			array[right]	= 	aux;
			left++;
			right--;
		}

	}

	if (right > start) {
		quickSort(array, start, right);
	}

	if (left < end) {
		quickSort(array, left, end);
	}

}

int buscaBinaria(Aluno *array, int numeroAluno, int matricula) {
	int inicio = 0;
	int fim    = numeroAluno - 1;

	while (inicio <= fim) {
		int meio = (inicio + fim) / 2;

		if (array[meio].matricula == matricula) {
			return meio;
		} else if (matricula < array[meio].matricula) {
			fim = meio - 1;
		} else {
			inicio = meio + 1; 
		}
	}

	return -1;
}


int main() {
	Aluno alunos[4] = {{4, "Jock"}, {2, "Carlos"}, {3, "Pedro"}, {1, "Lucas"}};
	quickSort(alunos, 0, 4-1);
	imprimeAlunos(alunos, 4);
	printf("\n\nBusca Bin: %d\n", buscaBinaria(alunos, 4, 4));

	return 0;
}