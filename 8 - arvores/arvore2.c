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

int localizarNivel(int valor, Arvore *r) {
	if (r) {
		if (valor == r->dado) return 0;

		if (valor < r->dado) { //lado esquerdo
			int resposta = localizarNivel(valor, r->esq);
			if (resposta == -1) return -1;
			return resposta + 1;
		} else { //lado direito
			int resposta = localizarNivel(valor, r->dir);
			if (resposta == -1) return -1;
			return resposta + 1;
		}
	}
	return -1;
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
	
	printf("\n\nExibe tipo arvore deitada a partir do nivel 0\n");
	exibir(raiz, 0);
	
	printf("Informe um inteiro para pesquisa na arvore: ");
	scanf("%d", &valor);
	
	printf("Endereco de %d na arvore: %p\n", valor, localizar(valor, raiz));
	
	printf("Nivel em que se encontra o %d na arvore: %d\n", valor, localizarNivel(valor,raiz));
	
	printf("Total de elementos na arvore: %d\n", contarNos(raiz));
	
	return 1;
}
