#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

//inserindo na lista com ordenacao. Na sua posição correta: no início, no fim, ou no meio
Celula *inserir(int valor, Celula *lista) {
	Celula *novo; //para alocar nova celula
    Celula *p, *pR;

	//alocar memoria
	novo = (Celula *)malloc(sizeof(Celula));
	//depositar valor
	novo->conteudo = valor;
    novo->prox = NULL; //nao sabemos onde o novo será inserido

    if (!lista) {
        return novo;
    }

    //percorrer a lista a procura da posicao correta
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor < p->conteudo) {
            //achamos a posicao
            break;
        }
    }
    //numero inserido como primeiro
    if (!pR) { // p == lista
        novo->prox = p; //ou novo->prox = lista;
        return novo;
    } else if (p == NULL) {//numero inserido na ultima posicao
        pR->prox = novo;
    } else {//numero inserido no meio
        pR->prox = novo;
        novo->prox = p;
    }	
	return lista; //retornamos o primeiro elemento
}

void exibir(Celula *lista) {
    Celula *p;
    if (!lista) {
        printf("Lista vazia.\n");
        return;
    }
    for (p = lista; p; p = p->prox) {
        printf("%d\t", p->conteudo);
    }
    printf("\n");
}

int contar(Celula *lista) {
    Celula *p;
    int total = 0;
    for (p = lista; p; p = p->prox, total++);

    return total;
}

Celula *popular(Celula *lista, int quantidade) {
    srand(time(NULL));
    int i;
    for (i = 0; i < quantidade; i++ ) {
        lista = inserir(rand() % 100, lista);
    }

    return lista;
}

int main() {
    setlocale(LC_ALL,"Portuguese");
	Celula *lista = NULL;
    
    lista = popular(lista,10);
    printf("A lista contém: %d números sorteados\n", contar(lista));
    exibir(lista);

	return 1;
}

