#include <stdio.h>
#include <stdlib.h>
//tipo para a celula, como em pilhas e listas simples
typedef struct nodo {
	int conteudo;
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
void inicializarFila(Fila *f) {
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
int removerFila(Fila *f) {
	Celula *lixo;
    int ficha;
	//fila existe?
	if (f->cabeca) {
		ficha = f->cabeca->conteudo;
		lixo = f->cabeca;
		f->cabeca = f->cabeca->prox;
		free(lixo);

		//caso apague o ultimo elemento
		if (!f->cabeca) {
			f->cauda = NULL;
		}
		return ficha;
	} 
	return -1; //indica que a fila está vazia
}
