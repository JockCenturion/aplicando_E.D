#include <stdio.h>
#include <stdlib.h>

typedef struct data {
	int value;
	char company[10];
	short priority;
}Data;


void impress(Data *data) {
	printf("%4d", data->value);
	//printf("%d - %s\n", data->value, data->company); //Somente para exercicio 6
}


	



