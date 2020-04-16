#include <stdio.h>
#include <stdlib.h>

//tipo para a celula, como em pilhas e listas simples
typedef struct nodo {
	int dado;
	struct nodo *prox;
} Celula;

//tipo para armazenar os dois ponteiros da fila
typedef struct {
	Celula *cabeca; //operacao de remocao
	Celula *cauda;  //operacao de insercao
} Fila;

void inicializacao(Fila *f) {
	f->cabeca = NULL;
	f->cauda = NULL;
}

int main() {

	Fila fila; //observe o tipo Fila utilizado

	inicializacao(&fila); //observe que fila nao eh um ponteiro

	return 1;
}