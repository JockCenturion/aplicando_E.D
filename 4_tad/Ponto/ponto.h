typedef struct {
	short x, y;
} Ponto;

Ponto* criar(void);
void atribuir(Ponto *p, short x, short y);
void somar(Ponto *p1, Ponto *p2, short *x, short *y);
short produto(Ponto *p1, Ponto *p2);
void acessar(Ponto *p, short *x, short *y);
void liberar(Ponto *p);
float distancia(Ponto *p1, Ponto *p2);

