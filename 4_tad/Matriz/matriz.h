//Estrutura 
typedef struct matriz Matriz;

//Funçoes
Matriz* cria(int m, int n);
void insereElemento(Matriz *mat, int m, int n, int valor);
void liberaMat(Matriz *mat);
int acessaElemento(Matriz *mat, int m, int n);



