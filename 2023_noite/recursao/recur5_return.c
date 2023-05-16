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

Celula *localizarR(int valor, Celula *lista) {
    if (lista) {
        if (valor == lista->dado)
            return lista; //valor encontrado na posicao de memória de lista
        return localizarR(valor, lista->prox);
    } 
    return NULL; //passamos por toda a lista e não encontramos o valor, logo retorna NULL
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

    Celula *posicao = localizarR(valorPesquisa, lista);
    printf("%d localizado na posicao %p->%d\n", valorPesquisa, posicao, posicao->dado);

    lista = excluirListaR(valorPesquisa, lista);
    exibirListaR(lista);
    
    return 1;
}