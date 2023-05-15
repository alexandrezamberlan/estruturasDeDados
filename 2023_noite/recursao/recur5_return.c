/**
 * Recursão == repetição
 *  - void
 *  - return
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 500

typedef struct no {
    int dado;
    struct no *prox;
} Celula;


void exibirListaR(Celula *lista) {
    if (lista) {
        printf("%d\n", lista->dado);
        exibirListaR(lista->prox);
    }
}

Celula *inserirListaR(int valor, Celula *lista) {
    if (lista && valor > lista->dado) {
        lista->prox = inserirListaR(valor, lista->prox);
        return lista;
    } else { //cheguei no final da lista
        Celula *novo = (Celula *)malloc(sizeof(Celula));
        novo->dado = valor;
        if (!lista) {
            novo->prox = NULL;
        } else {
            novo->prox = lista;
        }
        return novo;
    }
}


int main() {
    Celula *lista = NULL;
  
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        lista = inserirListaR(rand() % 20, lista);
    }
    exibirListaR(lista);

    
    return 1;
}