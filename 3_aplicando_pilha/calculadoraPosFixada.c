#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

typedef struct {
	int top;
	int vet[MAX];
}Stack;

void new(Stack *c) {
	(*c).top = -1; 
}

void push(Stack *c, int value) {
	if (c->top == MAX -1) { printf("Error!\n"); exit(1); }
	else c->vet[++(c->top)] = value;
}

void impress(Stack *c) {
	for (char i = c->top; i >= 0; i--)
		printf("%2d", c->vet[i]);
}

char empty(Stack *c) {
	return (c->top == -1);
}

int pop(Stack *c) {
	if(empty(c)) { printf("Error!\n"); exit(1); }
	else return (c->vet[(c->top)--]);
}


int main() {

	//Declaracoes
	Stack p1;
	char *exp = "53+6*21+/";

	//Inicializa�ao
	new(&p1);


	//Calculadora Pos-fixada (Notacao polonesa)
	for (char i = 0; i < strlen(exp); i++) {
		if (exp[i] >= '0' && exp[i] <= '9') {
			push(&p1, exp[i] - 48);	//converte para inteiro
		} else {
			int aux1  = pop(&p1);
			int aux2  = pop(&p1);
			switch (exp[i]) {
				case '+':
					push(&p1, aux2 + aux1);
					break;
				case '-':
					push(&p1, aux2 - aux1);
					break;
				case '*':
					push(&p1, aux2 * aux1);
					break;
				case '/':
					push(&p1, aux2 / aux1);
					break;
			}
		}
	}

	//resultado
	impress(&p1); 

	return 0;
}


/*https://www.ime.usp.br/~pf/mac0122-2002/aulas/stacks.html
 *https://pt.wikipedia.org/wiki/Nota%C3%A7%C3%A3o_polonesa_inversa
 *boot camps de programação
 *https://www.youtube.com/watch?v=L7g1dPlzZ7c*/

 /*http://olimpiada.ic.unicamp.br/pratique/iniciacao/nivel2/ResultadoSubmissao*/
 /*https://pro.tecmundo.com.br/linkedin/117056-ceo-linkedin-habilidades-valem-do-diplomas.htm?utm_source=tecmundo.com.br&utm_medium=internas&utm_campaign=quenteshoje
  *https://pro.tecmundo.com.br/pro/117128-google-apple-facebook-curriculo-conseguir-emprego-sonhos.htm*/

/*https://www.ibm.com/developerworks/community/blogs/fd26864d-cb41-49cf-b719-d89c6b072893/entry/como_structs_realmente_funcionam_em_c?lang=en*/

/*Livro ->Compiladores Príncipio, Técnicas e Ferramenta*/
