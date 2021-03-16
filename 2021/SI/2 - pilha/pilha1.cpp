#include <iostream>
#include <time.h>
using namespace std;

typedef struct nodo {
    int valor; // um ou mais atributos ou variávies
    struct nodo *prox;
} Celula;

Celula *inserir(int valor, Celula *topo) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores dos parametros
    novo->valor = valor;

    //engatar
    novo->prox = topo;

    //retornar
    return novo;
}

Celula *excluir(Celula *topo) {
    //soh eh possivel excluir se a pilha nao estiver vazia
    if (!topo) {
        cout << "Pilha vazia. Remocao nao pode ser realizada" << endl;
        return topo;
    }

    Celula *lixo;
    lixo = topo;
    topo = topo->prox; //o ponteiro topo andou uma posição para frente

    free(lixo); //libera a memória ou seja, apaga o elemento

    return topo;
}

void exibir(Celula *topo) {
    if (!topo) {
        cout << "Pilha vazia." << endl;
        return;
    }
    for (Celula *p = topo; p != NULL; p = p->prox) { // for (int i = 0; i < chegarFim; i++)
        cout << p->valor << "\t";
    }
    cout << endl;
}


int main() {
    Celula *pilha = NULL;
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        pilha = inserir(rand() % 100, pilha);
    }
    cout << "Resultado da pilha após 5 insercoes " << endl;
    cout << "Topo da pilha eh: " << pilha->valor << endl;
    exibir(pilha); //método não natural de uma pilha

    pilha = excluir(pilha);
    pilha = excluir(pilha);
    cout << "Exibindo a pilha após 2 exclusões" << endl;
    cout << "Topo da pilha eh: " << pilha->valor << endl;
    exibir(pilha); //método não natural de uma pilha
    return 1;
}
