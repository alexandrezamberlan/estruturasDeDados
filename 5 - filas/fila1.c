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

	Celula *lista = NULL;
	Celula *listaC = NULL;

	Fila fila1; //observe o tipo Fila utilizado
	Fila fila2;
	Fila fila3;

	inicializacao(&fila1); //observe que fila nao eh um ponteiro
	inicializacao(&fila2); //observe que fila nao eh um ponteiro
	inicializacao(&fila3); //observe que fila nao eh um ponteiro
	
	return 1;
}