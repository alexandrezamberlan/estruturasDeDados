#include <iostream>
#include <string>

using namespace std;

typedef struct nodo {
    string senha;
    struct nodo *prox;
} CelulaS;

CelulaS *inserir(string senha, CelulaS *lista) {
    //alocar memória
    CelulaS *novo = (CelulaS *)malloc(sizeof(CelulaS));

    //depositar valores de parâmetro
    novo->senha = senha;
    novo->prox = NULL;

    if (!lista) return novo; //se a lista for vazia, o novo será o primeiro elemento nela

    //percorrer toda a lista e inserir na última posição
    CelulaS *p;
    for (p = lista; p->prox != NULL; p = p->prox);

    //engatar na última posição
    p->prox = novo; //ultimo elemento vai apontar agora para o novo elemento alocado

    //retornar o primeiro elemento
    return lista;
}

void exibir(CelulaS *lista) {
    CelulaS *p;

    if (!lista) {
        return;
    }
    for (p = lista; p != NULL; p = p->prox) { //percurso clássico em listas
        cout << p->senha << "\t";
    }
    cout << endl;
}
