#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct no {
	int dado;
	struct no *esq, *dir;
}Arvore;

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
} 
 

Arvore *inserir(int valor, Arvore *r) {
	if (r) {
		if (valor == r->dado) return r;//controle duplicidade
		if (valor < r->dado) {
			r->esq = inserir(valor, r->esq);
		} else {
			r->dir = inserir(valor, r->dir);
		}
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
		exibir(r->dir, nivel + 1);
		
		int i;
		for (i = 0; i < nivel; i++) {
			printf("   ");
		}
		
		printf("(%d)%d\n", nivel, r->dado);
		
		exibir(r->esq, nivel + 1);
	}
}

int contaNosFolhas(Arvore *r) {
	if (r) {
		if (!r->esq && !r->dir) {
			return 1;
		}
		return contaNosFolhas(r->esq) + contaNosFolhas(r->dir);
	}
	return 0;
}

Arvore *podar(Arvore *r) {
	if (r) {
		if (!r->esq && !r->dir) {
			free(r);
			return NULL;
		}
		r->esq = podar(r->esq);
		r->dir = podar(r->dir);
		return r;
	}
	return NULL;
}

int altura(Arvore *r) {
	if (r) {
		int altE = altura(r->esq);
		int altD = altura(r->dir);
		if (altE > altD) return altE + 1;
		return altD + 1;
	}
	return 0;
}

Arvore *excluir(int valor, Arvore *r) {
	if (r) {
		if (valor == r->dado) { //achei
		    Arvore *novoPai, *tmp, *rTmp;
			//eh folha
			if (!r->esq && !r->dir) {
				free(r);
				return NULL;
			}
			//verificar se tem filho na esq
			if (r->esq) {
				novoPai = r->esq;
				tmp = r->dir;
				for (rTmp = novoPai; rTmp->dir; rTmp = rTmp->dir);
				
				rTmp->dir = tmp;
			} else novoPai = r->dir;
			
			free(r);//apagar o r pai
			return novoPai;
		} 
		if (valor < r->dado) {
			r->esq = excluir(valor, r->esq);
		} else {
			r->dir = excluir(valor, r->dir);
		}
		return r;
	}
	return NULL;
}

Arvore *destruir(Arvore *r) {
	if (r) {
		r->esq = destruir(r->esq);
		r->dir = destruir(r->dir);
		printf("Excluindo.... %d\n", r->dado);
		delay(1);
		free(r);	
	}
	return NULL;
}

int main() {
	Arvore *raiz = NULL;	
	srand(time(NULL));
	int quantidadeNos = 12;
	int valor;
	
	for (;quantidadeNos > 0; quantidadeNos--) {
		raiz = inserir(rand()% 50, raiz);
	}
	exibir(raiz, 0);	
	printf("A altura final da arvore eh: %d\n", altura(raiz));
		
	printf("Destruindo a arvore... ou liberando memoria\n");
	raiz = destruir(raiz);
	exibir(raiz, 0);
	
	return 1;
}
