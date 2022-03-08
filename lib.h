struct cel {
	int conteudo;
	struct cel *prox;
};

typedef struct cel celula;

celula *ini;

celula *cria(void);
void insere(int x, celula *p);
void imprime(celula *ini);
void menu(void);
void zerarSSD(void);
void gravar(celula *ini);
void score(void);
void ajuda(void);
void misturar(int cartas[]);
void draw(int num);
int ReiRainhaValete(int a);
int play(void);