//Estruturas

typedef struct {
	short dia, mes, ano;
} Data;

typedef struct {
	short hora, minuto, segundo;
} Hora;

typedef struct {
	char modelo[15], cor[10];
	short ano;
} ModeloCarro;

typedef struct {					//Estrutura Principal
	Data *date;
	Hora *hour;
	ModeloCarro *carro;
	short vazia;
} Reserva;


//Prototipos
Reserva* cria(void);
void inserir(Reserva *r, Data *d, Hora *h, ModeloCarro *c);
//void alterar(Reserva *r);   									//Desenvolver
void remover(Reserva *r);
void mostrar(Reserva *r);