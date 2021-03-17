#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int dado;
    struct no *prox; //endereço do próximo elemento
} Celula;

Celula *inserir(int valor, Celula *topo) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valor
    novo->dado = valor; //(*novo).dado = valor;

    //encadear o novo elemento na pilha
    novo->prox = topo;

    //retornar o novo topo
    return novo;
}

Celula *remover(Celula *topo) {
    Celula *lixo;
    //verifica se a pilha existe
    if (topo == NULL) {
        printf("Pilha esta vazia!\n");
    } else {
        //isola o topo a ser removido
        lixo = topo;
        //avança o topo um endereço
        topo = topo->prox; 
        //libera memoria
        printf("Valor a ser removido: %d\n", lixo->dado);
        free(lixo);
    }
    //novo topo é retornado
    return topo;
}

int main() {
    Celula *pilha = NULL;

    pilha = inserir(4,pilha);
    pilha = inserir(2,pilha);
    pilha = inserir(10,pilha);
    pilha = inserir(3,pilha);

    printf("Valor no topo: %d\n", pilha->dado);

    pilha = remover(pilha);
    pilha = remover(pilha);
    printf("Valor no topo: %d\n", pilha->dado);

    return 1;
}