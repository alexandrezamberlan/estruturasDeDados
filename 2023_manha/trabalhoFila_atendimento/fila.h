//tipo para a celula, como em pilhas e listas simples
typedef struct nodo {
	int conteudo;
    struct tm dataHora;
	struct nodo *prox;
} Celula;

//tipo para armazenar os dois ponteiros da fila
typedef struct {
	Celula *cabeca; //operacao de remocao
	Celula *cauda;  //operacao de insercao
} Fila;

/*
metodo que incializa a fila
*/
void inicializacao(Fila *f) {
	f->cabeca = NULL;
	f->cauda = NULL;
}

/*
metodo que insere um elemento na cauda da fila
*/
void inserirFila(int valor, Fila *f) {
	Celula *novo;

	novo = (Celula *)malloc(sizeof(Celula));
	novo->conteudo = valor;
    time_t t = time(NULL);
    novo->dataHora = *localtime(&t);
	novo->prox = NULL;

	//eh a primeira vez?
	if (!f->cauda) {
		f->cauda = novo;
		f->cabeca = novo;
	} else {
		f->cauda->prox = novo;
		f->cauda = novo;
	}
}

/*
metodo que remove elemento da cabeca da fila
*/
Celula removerFila(Fila *f) {
	Celula *lixo;
    Celula ficha;
	//fila existe?
	if (f->cabeca) {
		ficha.conteudo = f->cabeca->conteudo;
        ficha.dataHora = f->cabeca->dataHora;
        ficha.prox = NULL; //garantir que nao tenha sujeira na ficha
		lixo = f->cabeca;
		f->cabeca = f->cabeca->prox;
		free(lixo);

		//caso apague o ultimo elemento
		if (!f->cabeca) {
			f->cauda = NULL;
		}
		return ficha;
	} 
    ficha.conteudo = -27;
	return ficha;
}

int contarFila(Fila f) {
	int quantidade = 0;
	if (!f.cabeca) return quantidade;

	Celula *p;
	for (p = f.cabeca; p ; p = p->prox) {
		quantidade++;
	}

	return quantidade;
}