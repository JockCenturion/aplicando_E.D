/*
 *Autor: Jock
 *Diciplina: ED 
 *Conteudo: Filas
 *Data 18/08/2017 | 00:46 |
 */

#include <stdio.h>
#include "QueueStack.c"


/*Questao 4*/
int main() {
	
	Queue s;
	
	newQueue(&s, 3);
	addInQueue(&s, 1);
	addInQueue(&s, 2);
	addInQueue(&s, 3);
	removeInQueue(&s);
	removeInQueue(&s);
	viewQueue(&s);
	//printf("%d %d %d\n", isEmpty(&s), isFull(&s), size(&s));
	
	
	return 0;
}
