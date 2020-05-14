#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAM 5

typedef struct no { //arvore binaria
	int conteudo;
	struct no *esq, *dir;
}Arvore;

Arvore *inserir(int valor, Arvore *r) { //Arvore Binaria de Pesquisa ou Ordenada
	if (r) {
		if (valor < r->conteudo) r->esq = inserir(valor, r->esq); //vai para esquerda
		else r->dir = inserir(valor, r->dir); //vai para direita
		
		return r;
	} else {
		Arvore *novo = (Arvore *)malloc(sizeof(Arvore));
		novo->conteudo = valor;
		novo->esq = NULL;
		novo->dir = NULL;
		return novo;
	}
}

void exibirRED(Arvore *r) {
	if (r) {
		printf("%d\t", r->conteudo);
		exibirRED(r->esq);
		exibirRED(r->dir);
	}
}

void exibirERD(Arvore *r) {
	if (r) {		
		exibirERD(r->esq);
		printf("%d\t", r->conteudo);
		exibirERD(r->dir);
	}
}

void exibirEDR(Arvore *r) {
	if (r) {		
		exibirEDR(r->esq);
		exibirEDR(r->dir);
		printf("%d\t", r->conteudo);		
	}
}

void exibir(Arvore *r, int nivel) {
	if (r) {
		exibir(r->dir, nivel + 1);//vai para direita
		
		int i;
		for (i = 0; i < nivel; i++) {
			printf("   ");
		}
		printf("(%d)%d\n", nivel, r->conteudo);
		
		exibir(r->esq, nivel + 1);//vai para esquerda
	}
}

Arvore *localizar(int valor, Arvore *r){
	if (r) {
		if (valor == r->conteudo) return r; //conteudo localizado
		if (valor < r->conteudo) return localizar(valor, r->esq); //procurar na esquerda
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
		//printf("%d\t", valor);
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
