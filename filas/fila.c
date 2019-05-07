#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int dado;
	struct no *prox;
} Celula;

typedef struct {
	Celula *inicio;
	Celula *fim;
} Fila;

void inicializarFila(Fila *f) {
	f->inicio = NULL;
	f->fim = NULL;
}

void inserirFila(int valor, Fila *f) {
	Celula *novo = (Celula *)malloc(sizeof(Celula));
	novo->dado = valor;
	novo->prox = NULL;

	if (!f->fim) {
		f->inicio = novo;
		f->fim = novo;
	} else {
		f->fim->prox = novo;
		f->fim = novo;
	}
}

int removerFila(Fila *f) {
	Celula *lixo;
	int dadoRemovido = -1;

	if (!f->inicio) {
		printf("Fila vazia\n");
	} else {
		lixo = f->inicio;
		f->inicio = f->inicio->prox;
		dadoRemovido = lixo->dado;
		free(lixo);
		if (!f->inicio) f->fim = NULL;
	}
	return dadoRemovido;
}


int main() {
	Fila fila;

	Celula *lista = NULL;

	// fila.inicio = NULL;
	// fila.fim = NULL;
	inicializarFila(&fila);

	inserirFila(123,&fila);
	inserirFila(124,&fila);
	inserirFila(135,&fila);
	int dado;
	do {
		dado = removerFila(&fila);
		if (dado == -1) break;
		printf("%d\n", dado);
	} while (1);

	return 1;
}