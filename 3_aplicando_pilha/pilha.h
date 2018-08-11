
typedef struct pilha Pilha;
void criar(Pilha *p, int TAM);
void inserir(Pilha *p, int valor);
void imprimir(Pilha *p);
char vazia(Pilha *p);
int remover(Pilha *p);
int qtdNo(Pilha *p);
int topoEh(Pilha *p);
int buscar(Pilha *p, int valor);
void liberar(Pilha *p);
void inverter(Pilha *p); 
