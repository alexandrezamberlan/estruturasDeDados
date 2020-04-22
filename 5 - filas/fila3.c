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
	return -27;
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

int main() {

	Fila fila; //observe o tipo Fila utilizado

	inicializacao(&fila); //observe que fila nao eh um ponteiro

	inserirFila(10, &fila);
	inserirFila(45, &fila);
	inserirFila(13, &fila);
	inserirFila(66, &fila);

	printf("Na cabeca: %d\nNa cauda: %d\n", fila.cabeca->conteudo, fila.cauda->conteudo);

	int ficha;
	ficha = removerFila(&fila);
	printf("Ficha atendida: %d\n", ficha);
	ficha = removerFila(&fila);
	printf("Ficha atendida: %d\n", ficha);

	printf("Situacao da fila apos remocoes!\n");
	printf("Na cabeca: %d\nNa cauda: %d\n", fila.cabeca->conteudo, fila.cauda->conteudo);

	printf("Tamanho da fila: %d\n", contarFila(fila)); //nao passo o endereco, pq nao vai se alterar a fila
	
	return 1;
}