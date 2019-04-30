#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct noD {
	int dado;
	struct noD *ant;
	struct noD *prox;
} CelulaD;

void exibirD(CelulaD *l) {
	if (!l) {
		printf("Lista dupla vazia\n");
		return;
	}
	for (;l->ant; l = l->ant); //ter certeza que o controle da lista l esteja na primeira posicao
	
	for (;l; l = l->prox) {
		printf("%d\t", l->dado);
	}
	printf("\n");
}

int contarElementosD(CelulaD *l) {
	int qtd = 0;
	if (!l) {
		return qtd;
	}
	for (;l->ant; l = l->ant); //ter certeza que o controle da lista l esteja na primeira posicao
	
	for (;l;l = l->prox) {
		qtd++;
	}
	return qtd;
}

CelulaD *excluirD(int valor, CelulaD *l) {
	CelulaD *p, *pR;
	
	if (!l) return l;
	
	for (;l->ant;l = l->prox);
	
	for (pR = NULL, p = l; p; pR = p, p = p->prox) {
		if (valor == p->dado) break; //achei dado para exclusao
	}
	if (!p) {
		printf("%d nao foi localizado na lista dupla!!\n", valor);
		return l;
	}
	if (p == l) { //primeiro
		l = l->prox;
		if (l) l->ant = NULL; //caso seja o unico elemento a ser excluido
		free(p);
		return l;
	}
	if (!p->prox) { //ultimo
		pR->prox = NULL;		
	} else { //meio
		pR->prox = p->prox;
		p->prox->ant = pR;
	}
	free(p);
	return l;
}

CelulaD *inserirD(int valor, CelulaD *l) {
	CelulaD *p, *pR, *novo = (CelulaD *)malloc(sizeof(CelulaD));
	
	novo->dado = valor;
	novo->ant = NULL;
	novo->prox = NULL;
	
	if (!l) return novo;
	
	for (;l->ant;l = l->prox);
	
	for (pR = NULL, p = l; p; pR = p, p = p->prox) {
		if (valor < p->dado) break;
	}
	if (p == l) { //primeiro
		novo->prox = l;
		l->ant = novo;
		return novo;
	}
	if (!p) { //ultimo
		novo->ant = pR;
		pR->prox = novo;
	} else { //meio
		pR->prox = novo;
		novo->ant = pR;
		novo->prox = p;
		p->ant = novo;
	}
	return l;
}

int main() {
	CelulaD *listaD = NULL;
	srand(time(NULL));
	
	int qtd = (rand() % 20) + 2;
	for (; qtd > 0; qtd--) {
		listaD = inserirD(rand() % 100, listaD);
	}
	exibirD(listaD);
	printf("Total de elementos na lista dupla: %d\n", contarElementosD(listaD));
	
	int numero;
	printf("Informe numero para excluir: ");
	scanf("%d", &numero);
	listaD = excluirD(numero, listaD);
	
	exibirD(listaD);
	printf("Total de elementos na lista dupla apos exclusao: %d\n", contarElementosD(listaD));
	return 1;
}
