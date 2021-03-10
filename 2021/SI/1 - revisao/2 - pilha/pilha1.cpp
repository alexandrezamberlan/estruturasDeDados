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

void exibir(Celula *topo) {
    if (!topo) {
        cout << "Pilha vazia." << endl;
        return;
    }
    for (Celula *p = topo; p != NULL; p = p->prox) { // for (int i = 0; i < chegarFim; i++)
        cout << p->valor << "\t";
    }
}


int main() {
    Celula *pilha = NULL;
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        pilha = inserir(rand() % 100, pilha);
    }

    cout << pilha->valor;
    cout << endl;

    exibir(pilha);

    return 1;
}
