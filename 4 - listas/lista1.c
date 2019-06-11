#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

void exibir(Celula *l);
Celula *inserirPilha(int valor, Celula *topo);
Celula *inserirLista(int valor, Celula *l);
Celula *popular(double qtd, Celula *topo);
Celula *copiar(Celula *topo, char tipo);
Celula *ordenar(Celula *l);

int main() {
    Celula *pilha = NULL;
    Celula *listaDesordenada = NULL;
    Celula *listaOrdenada = NULL;

    //inserindo 1000 numeros aleatorios na pilha
    pilha = popular(10, pilha);

    printf("\n\n----------------inserindo na lista como pilha e ordenando em metodo posterior---------------\n\n");
    //duplicar os numeros da pilha na lista desordenada
    listaDesordenada = copiar(pilha, 'd');

    //ordenar pelo metodo da bolha a lista desordenada
    listaDesordenada = ordenar(listaDesordenada);

    exibir(listaDesordenada);

    printf("\n\n----------------inserindo na lista e jah ordenando---------------\n");
    //duplicar os numeros da pilha na lista ordenada, entretanto, a insercao na lista jah deve ser ordenada
    listaOrdenada = copiar(pilha,'o');
    exibir(listaOrdenada);

    return 1;
}

void exibir(Celula *l) {
    Celula *p;

    for (p = l; p; p = p->prox) {
        printf("%d\n", p->dado);
    }
}

Celula *inserirPilha(int valor, Celula *topo) {
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prox = topo;
    return novo;
}

Celula *inserirLista(int valor, Celula *l) {
    Celula *p, *pR, *novo;
    novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prox = NULL;

    if (!l) return novo;

    for (pR = NULL, p = l; p; pR = p, p = p->prox) {
        if (valor < p->dado) break;
    }
    if (p ==l) { //inserir no inicio
        novo->prox = l;
        return novo;
    }
    pR->prox = novo;
    if (p) { //inserir no final da lista
        novo->prox = p;
    }
    return l;

}

Celula *popular(double qtd, Celula *topo) {
    srand(time(NULL));
    for (; qtd > 0; qtd--) {
        topo = inserirPilha(rand() % 1000, topo);
    }
    return topo;
}

Celula *copiar(Celula *topo, char tipo) {
    Celula *p, *l = NULL;

    for (p = topo; p ; p = p->prox) {
        if (tipo == 'd') l = inserirPilha(p->dado, l);
        else if (tipo == 'o') l = inserirLista(p->dado, l);
    }

    return l;
}

Celula *ordenar(Celula *l) { //metodo da bolha
    Celula *p;
    int aux, houveTroca;

    do {
        houveTroca = 0;
        for (p = l; p->prox; p = p->prox) {
            if (p->dado > p->prox->dado) {
                houveTroca = 1;
                aux = p->dado;
                p->dado = p->prox->dado;
                p->prox->dado = aux;
            }
        }
    } while (houveTroca);
    return l;
}
