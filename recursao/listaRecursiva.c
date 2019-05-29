//listaRecursiva.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8

typedef struct no {
	int dado;
	struct no *prox;
} Celula;

void exibirR(Celula *l) { //inicializou a variavel de controle
	if (l) { //teste de parada
		printf("%d\t", l->dado);			
		exibirR(l->prox); //PONTO DE RECURSAO: transformacao variavel de controle
	}
}

Celula *inserirR(int valor, Celula *l) {		
	if (l && valor > l->dado) {
		//percorria - empilhar
		l->prox = inserirR(valor, l->prox);
		return l;
	} else { //sai da lista
		//aloca
		Celula *novo = (Celula *)malloc(sizeof(Celula));
		//deposita
		novo->dado = valor;
		novo->prox = l;
		
		//retorna
		return novo;
	}
}

int contarR(Celula *l) {
	if (l) {
		return 1 + contarR(l->prox);
	}
	return 0;
}

int main() {
	Celula *lista = NULL;
	int i;
	int valor;
	srand(time(NULL));
	printf("Valores gerados aleatoriamente:\n");
	for (i = 0; i < TAM; i++) {
		valor = rand() % 100;
		printf("Valor sorteado: %d\n", valor);
		lista = inserirR(valor, lista);		
	}
	
	printf("Valores da lista jah ordenados:\n");
	exibirR(lista);
	
	printf("\n\nTotal de elementos: %d\n", contarR(lista));
	return 1;
}
