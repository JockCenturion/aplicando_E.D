#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int cod;
	double saldo;
}ContaBancaria;

void construtor(ContaBancaria *contaPtr, int cod, double saldo) {
	contaPtr->cod 	= cod;
	contaPtr->saldo = saldo;
}

short depositar(ContaBancaria *contaPtr, double valor) {
	if (valor > 0) { contaPtr->saldo += valor; return 1; } 
	else return 0;		
}

short sacar(ContaBancaria *contaPtr, double valor) {
	if (valor > 0 && contaPtr->saldo - valor >= 0) { contaPtr->saldo -= valor; return 1;}
	else return 0;
}

void imprimir(ContaBancaria *contaPtr) {
	printf("Cod: %d\nSaldo: %.2f\n", contaPtr->cod, contaPtr->saldo);
}

int main() {
	
	ContaBancaria p;
	
	
	construtor(&p, 1, 1500);
	printf("%d\n", depositar(&p, 500));
	printf("%d\n", sacar(&p, 500));
	imprimir(&p);
	
	ContaBancaria p2;
	
	construtor(&p2, 2, 500);
	printf("\n\n%d\n", depositar(&p2, 500));
	printf("%d\n", sacar(&p2, 500));
	imprimir(&p2);
	
	
	return 0;
}
