#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
	int dado;
	struct nodo *prox;
} Celula;

Celula *inserirC(int valor, Celula *l) {
	Celula *novo, *p, *pR;

	//alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));
	//depositar valores
	novo->dado = valor;
	novo->prox = novo;
	//eh o primeiro
	if (!l) return novo;

	//percorrer
	for(pR = NULL, p = l; p->prox != l; pR = p, p = p->prox) {
		if (valor < p->dado) break;
	}
	//descobrir por que parou o for
	if (valor > p->dado) {//ultimo
		p->prox = novo;
		novo->prox = l;
	} else if (p == l) { //inicio
		novo->prox = l;
		for (;p->prox != l; p = p->prox);
		p->prox = novo;
		return novo;
	} else if (p->prox != l || valor < p->dado) {
		pR->prox = novo;
		novo->prox = p;
	}
	return l;
}

void exibirR(Celula *l) {
	Celula *p;
	if (!l) {
		printf("Lista Circular Vazia\n");
		return;
	}
	for (p = l; p->prox != l; p = p->prox) {
		printf("%d\t", p->dado);
	}	
	printf("%d\n", p->dado);
}

Celula *removerC(int valor, Celula *l) {
	Celula *p, *pR;
	if (!l) return NULL;

	for(pR = NULL, p = l; p->prox != l; pR = p, p = p->prox) {
		if (valor == p->dado) break;
	}
	if (valor != p->dado) return l;

	if (p == l) { //inicio
		l = l->prox;
		if (!l) {
			return NULL;
		}
		pR = p;
		for (p = l;p->prox != pR; p = p->prox);
		p->prox = l;
		free(pR);
	} else if (p->prox != l) { //meio
		pR->prox = p->prox;
		free(p);
	} else { //fim
		pR->prox  = l;
		free(p);
	}
	return l;
}

int main() {
	Celula *listaC = NULL;
	int numero;
	int i;
	srand(time(NULL));
	for (i = 0; i < 10; i++) {
		numero = rand() % 100;
		printf("%d\n",numero);
		listaC = inserirC(numero, listaC);
	}
	exibirR(listaC);
	printf("Informe um numero para pesquisa: ");
	scanf("%d", &numero);

	listaC = removerC(numero, listaC);
	exibirR(listaC);
	return 1;
}
