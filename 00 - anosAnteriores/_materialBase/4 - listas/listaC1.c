#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//Celula serve tanto para lista simples quanto para lista circular
typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

void exibir(Celula *lista) {
    Celula *p;
    if (!lista) {
        printf("Lista vazia.\n");
        return;
    }
    for (p = lista; p->prox != lista; p = p->prox) {
        printf("%d\t", p->conteudo);
    }
    printf("%d\n", p->conteudo);
}

int contar(Celula *lista) {
    Celula *p;
    int total = 0;
    if (!lista) {
        printf("Lista vazia.\n");
        return 0;
    }
    for (p = lista; p->prox != lista; p = p->prox){
        total++;
    }
    total++;

    return total;
}

Celula *localizar(int valor, Celula *lista) {
    Celula *p;
    if (!lista) {
        printf("Lista vazia.\n");
        return NULL;
    }
    for (p = lista; p->prox != lista ; p = p->prox) {
        if (valor == p->conteudo) {
            return p;
        }
    }
    if (valor == p->conteudo) {
        return p;
    }
    return NULL;
}

//inserindo na lista sem ordenacao, sempre na última posição
Celula *inserir(int valor, Celula *lista) {
    Celula *p, *pR, *novo;
    novo = (Celula *)malloc(sizeof(Celula));
    novo->conteudo = valor;
    novo->prox = novo;

    if (!lista) return novo; //se for o único, já retorno o novo

    for (pR = NULL, p = lista; p->prox != lista ; pR = p, p = p->prox) {
        if (valor < p->conteudo) {
            break;
        }
    }
    
    if (p->prox == lista && valor > p->conteudo) { //é o ultimo elemento
        p->prox = novo;
        novo->prox = lista;
    } else if (!pR) { //if (p == lista) ou seja, é o primeiro elemento
        novo->prox = lista; //novo->prox = p;
        
        for (; p->prox != lista; p = p->prox);

        p->prox = novo;
        return novo;
    } else { //é um elemento de meio
        pR->prox = novo;
        novo->prox = p;
    }
	return lista;
}

Celula *popular(Celula *lista, int quantidade) {
    srand(time(NULL));
    int i;
    int numero;
    printf("Números sorteados:\n");
    for (i = 0; i < quantidade; i++ ) {
        numero = rand() % 100;
        printf("%d\t", numero);
        lista = inserir(numero, lista);
    }
    printf("\n");

    return lista;
}

int ehListaSimples(Celula *lista) {
    Celula *p;

    if (!lista) return -27; //nao é simples, não é circular

    for (p = lista; p ; p = p->prox) {
        if (p->prox == lista) return 0; //não é simples, é circular
    }
    return 1; //é simples
}

int main() {
    setlocale(LC_ALL,"Portuguese");
	Celula *listaC = NULL;
    
    listaC = popular(listaC,8);
    printf("Lista circular com %d elementos\n", contar(listaC));
    exibir(listaC);
    return 1;
}
