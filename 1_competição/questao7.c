/*
 * Author: Jock
 * Date: 11/28/17
 * Hour: 9:27 PM
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*____________ Uma forma de Resolver o Problema __________________ */
void quickSort(char *array, int start, int end) {
	int left = start;
	int right = end;
	char pivot = array[(start + end) / 2];

	while (left <= right) {
		while (array[left] < pivot) left++;
		while (array[right] > pivot) right--;

		if (left <= right) {
			char aux     = array[left];
			array[left]  = array[right];
			array[right] = aux;
			left++;
			right--;
		}
	}

	if (left < end) {
		quickSort(array, left, end);
	}

	if (right > start) {
		quickSort(array, start, right);
	}
}

char* juntaStrings(char *s1, char *s2) {
	int start1, start2, size;
	char *novaString;

	size 		= strlen(s1) + strlen(s2);
	start1 		= start2 = 0;
	novaString  = malloc(size);

	for (int count = 0; count <= size; count++) {
		novaString[count] = (s1[start1] != '\0') ? s1[start1++] : s2[start2++];
	}

	quickSort(novaString, 0, size - 1);
	return novaString;
}



int main() {
	char s1[] = "abelk";
	char s2[] = "acil";
	//char s1[] = "bacd";
	//char s2[] = "acil";
	printf("%s\n", juntaStrings(s1, s2));


	return 0;
}
