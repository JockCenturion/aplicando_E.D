#include "matriz.c"
#include <stdio.h>


int main() {
	
	typedef Matriz *Mat;
	
	
	Mat p1, p2;
	
	p1 = cria(2, 2);
	p2 = cria(2, 2);
	
	insereElemento(p1, 1, 1, 5);
	insereElemento(p2, 1, 1, 2);
	printf("%d", acessaElemento(p1, 1, 1));
	
	printf("%d", somaMat(p1, p2, 1, 1));
	
	
	
	
	return 0;
}
