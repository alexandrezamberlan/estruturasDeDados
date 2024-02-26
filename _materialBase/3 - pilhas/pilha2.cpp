#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct nodo {
    string valor;
    struct nodo *prox;
} Pilha;

Pilha *inserir(string valor, Pilha *topo) {
    //alocar memoria
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    cout << "entrei no inserir\n";
    //depositar valores dos parametros na estrutura criada
    novo->valor = valor;
    
    //engatar
    novo->prox = topo;

    //retornar
    return novo;
}

void imprimir(Pilha *topo) {
    if (!topo) return;
    cout << "passei no imprimir\n";
    for (Pilha *i = topo; i != NULL; i = i->prox) {
        cout << i->valor << endl;
    }
}

int contarElementos(Pilha *topo) {
    if (!topo) return 0;
    int quantidade = 0;
    for (Pilha *i = topo; i != NULL; i = i->prox) {
        quantidade++;
    }
    return quantidade;
}

Pilha *remover(Pilha *topo) {
    //verificar se existe
    if (!topo) return topo;

    //isolar o topo
    Pilha *lixo = topo;

    //atualizar o novo topo
    topo = topo->prox;

    //liberar memoria
    free(lixo);

    //retornar o novo topo
    return topo;
}

int main() {
    Pilha *pilhaNomes = NULL;

    pilhaNomes = inserir("Matheus", pilhaNomes);
    pilhaNomes = inserir("Wendel", pilhaNomes);
    pilhaNomes = inserir("Jojo", pilhaNomes);

    //pilhaNomes = remover(pilhaNomes);

    imprimir(pilhaNomes);

    //cout << "O tamanho da pilha eh " << contarElementos(pilhaNomes) << endl;

    //cout << "O topo da pilha eh " << pilhaNomes->valor << endl;

    return 1;
}