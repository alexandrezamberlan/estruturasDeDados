/**
 * Recursão == repetição
 *  - void
 *  - return
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

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


int somarListaR(Celula *lista) {
    if (lista) {
        return lista->dado + somarListaR(lista->prox);
    }
    return 0;
}

//10 -> 20 -> 30 
int contarListaR(Celula *lista) {
    if (lista) {
        return 1 + contarListaR(lista->prox);
    }
    return 0;
}

int main() {
    Celula *lista = NULL;
  
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        lista = inserirListaR(rand() % 10, lista);
    }
    exibirListaR(lista);

    printf("Total de elementos: %d\n", contarListaR(lista));
    printf("A soma dos elementos: %d\n", somarListaR(lista));

    int valorPesquisa;
    printf("Digite valor a pesquisar: ");
    scanf("%d", &valorPesquisa);

    printf("%d localizado na posicao %p\n", valorPesquisa, localizarR(valorPesquisa, lista));
    
    return 1;
}