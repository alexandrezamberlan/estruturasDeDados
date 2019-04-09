#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int dado;
    struct no *prox;
}Celula;

void exibir(Celula *l) {
    Celula *p;
    int i = 0;
    for (p = l; p; p = p->prox, i++) {
        printf("%d -> %d\n", i, p->dado);
    }
}

Celula *inserir(int valor, Celula *l) {
    Celula *p, *pR, *novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prox = NULL;

    if (!l) return novo;

    for (pR = NULL, p = l; p; pR = p, p = p->prox) {
        if (valor < p->dado) break;
    }

    if (p == l) { //inicio
        novo->prox = l;
        return novo;
    }
    pR->prox = novo; //ultimo
    if (p) {
        novo->prox = p; //meio
    }
    return l;
}

Celula *excluir(int valor, Celula *l) {
    Celula *pR, *p;
    if (!l) return l;
    for (pR = NULL, p = l; p; pR = p, p = p->prox) {
        if (valor == p->dado) break;
    }
    if (!p) return l; //nao localizado
    if (p == l) { //localizado no inicio
        l = l->prox;
        free(p);
        return l;
    }
    if (!p->prox) { //encontrado na ultima posicao
        free(p);
        pR->prox = NULL;
        return l;
    }
    pR->prox = p->prox;
    free(p);

    return l;
}

Celula *excluirPares(Celula *l) {
	Celula *p;
	if (!l) return l;		
	
	for (p = l; p ; ) {			
		if (p->dado % 2 == 0) {
			l = excluir(p->dado,l);
			p = l;
		} else p = p->prox;
	}	
		
	return l;
}

Celula *destruir(Celula *l) {
	Celula *p, *pR;
	if (!l) return l;
	
	for (pR = l, p = l->prox; p; pR = p, p = p->prox) {
		free(pR);
	}
	free(pR);
	return NULL;
}

Celula *excluirFaixa(int ini, int fim, Celula *l) {
	Celula *p, *pR;
	int i;
	
	if (!l) return l;
	
	for (i = 0, pR = NULL, p = l; p && i <= fim; i++,
	                                             pR = p,
												 p = p->prox) {
		if (i >= ini && i <= fim) {
			printf("%d -> %d\n",i, p->dado);
			//aqui vai a exclusao
		}		
	}
	return l;
}

int main() {
    Celula *lista = NULL;
	 int ini, fim;

    srand(time(NULL));
    int i = rand() % 30;

    for (; i > 0; i--) {
        lista = inserir(rand() % 1000, lista);
    }
    exibir(lista);
/*
    int numero;
    printf("Informe um numero para exclusao: ");
    scanf("%d", &numero);
    lista = excluir(numero, lista);

    exibir(lista);
    
    printf("Excluindo os pares....\n");
    //faca metodo para excluir todos os pares da lista
    lista = excluirPares(lista);
    exibir(lista);
    
    //faca metodo para destruir a lista
    printf("Destruindo a lista, ou seja, liberando memoria....\n");
    lista = destruir(lista);
    exibir(lista);
    
    */
   
    printf("Escolha posicao logica inicial (indice): ");   
    scanf("%d", &ini);
	printf("Escolha posicao logica final (indice): ");   
	scanf("%d", &fim);
    lista = excluirFaixa(ini,fim,lista);
    
    //exibir(lista);
	
	return 1;
}
