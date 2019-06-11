#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

typedef struct no { //arvore binaria
	int dado;
	struct no *esq, *dir;
}Arvore;

Arvore *inserir(int valor, Arvore *r) { //Arvore Binaria de Pesquisa ou Ordenada
	if (r) {
		if (valor < r->dado) r->esq = inserir(valor, r->esq); //vai para esquerda
		else r->dir = inserir(valor, r->dir); //vai para direita
		
		return r;
	} else {
		Arvore *novo = (Arvore *)malloc(sizeof(Arvore));
		novo->dado = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		return novo;
	}
}

void exibirRED(Arvore *r) {
	if (r) {
		printf("%d\t", r->dado);
		exibirRED(r->esq);
		exibirRED(r->dir);
	}
}

void exibirERD(Arvore *r) {
	if (r) {		
		exibirERD(r->esq);
		printf("%d\t", r->dado);
		exibirERD(r->dir);
	}
}

void exibirEDR(Arvore *r) {
	if (r) {		
		exibirEDR(r->esq);
		exibirEDR(r->dir);
		printf("%d\t", r->dado);		
	}
}

void exibir(Arvore *r, int nivel) {
	if (r) {
		exibir(r->dir, nivel + 1);//vai para direita
		
		int i;
		for (i = 0; i < nivel; i++) {
			printf("   ");
		}
		printf("(%d)%d\n", nivel, r->dado);
		
		exibir(r->esq, nivel + 1);//vai para esquerda
	}
}

Arvore *localizar(int valor, Arvore *r){
	if (r) {
		if (valor == r->dado) return r; //dado localizado
		if (valor < r->dado) return localizar(valor, r->esq); //procurar na esquerda
		/*else*/ return localizar(valor, r->dir);
	}
	return NULL;
}

int contarNos(Arvore *r) {
	if (r) {
		return 1 + contarNos(r->esq) + contarNos(r->dir);
	}
	return 0;
}

int main() {
	Arvore *raiz = NULL;
	int i, valor;
	srand(time(NULL));
	
	printf("Gerando numeros aleatorios para a arvore\n");
	for (i = 0; i < TAM; i++){
		valor = rand() % 100;
		printf("%d\t", valor);
		raiz = inserir(valor, raiz);
	}
	
	printf("\n\nExibe pre-fixado: visita raiz; vai esq; vai dir\n");
	exibirRED(raiz);
	
	printf("\n\nExibe in-fixado: vai esq; visita raiz; vai dir\n");
	exibirERD(raiz);
	
	printf("\n\nExibe pos-fixado: vai esq; vai dir; visita raiz\n");
	exibirEDR(raiz);
	
	printf("\n\nExibe tipo arvore deitada a partir do nivel 0\n");
	exibir(raiz, 0);
	
	printf("Informe um inteiro para pesquisa na arvore: ");
	scanf("%d", &valor);
	
	printf("Endereco de %d na arvore: %p\n", valor, localizar(valor, raiz));
	
	printf("Total de elementos na arvore: %d\n", contarNos(raiz));
	
	return 1;
}
