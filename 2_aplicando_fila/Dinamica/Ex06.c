#include <stdio.h>
#include <stdlib.h>
#include "Queue.c"


int main() {
	
	Queue filaDecolagem, filaDeEspera;
	int resp, qtdAvioes;
	Data *dt;
	

	newQueue(&filaDecolagem, 0);
	newQueue(&filaDeEspera, 0);
	
	
	do {
		printf("1 - Adicionar Avisao.\n"
			   "2 - Lista Avioes na fila de decolagem.\n" 
			   "3 - Adicionar Aviao na fila de espera.\n"
			   "4 - Listar todos os aviões na fila de espera.\n"
			   "5 - lista as caracteristicas do primeiro avião da fila\n\n");
		
		scanf("%d", &resp);
		
		switch(resp) {
			case 1:
				dt = malloc(sizeof(Data));
				
				printf("ID: ");
				scanf("%d", &dt->value);
				printf("Company: ");
				fflush(stdin);
				gets(dt->company);
				
				addInQueue(&filaDecolagem, dt);
				
				break;
			case 2:
				viewQueueProx(&filaDecolagem);
				break;
			case 3:
				dt = malloc(sizeof(Data));
				
				printf("ID: ");
				scanf("%d", &dt->value);
				printf("Company: ");
				fflush(stdin);
				gets(dt->company);
				
				addInQueue(&filaDeEspera, dt);
				break;
			case 4:
				viewQueueProx(&filaDeEspera);
				break;
			case 5:
				impress(getHead(&filaDecolagem));
				printf("\n\n");
				impress(getHead(&filaDeEspera));
				break;	
		}
	} while (resp != 6);
	
	return 0;
}
