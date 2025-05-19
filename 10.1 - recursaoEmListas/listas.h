#include <cstdlib>
using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula *inserir(int dado, Celula *lista) {
    //alocar memoria
    Celula *novo = (Celula*)malloc(sizeof(Celula));
    
    //depositar valores
    novo->dado = dado;
    novo->prox = NULL;

    //percorrer se existir lista
    if (lista == NULL) { //if (!lista)
        return novo;
    }
    Celula *p;
    for (p = lista; p->prox != NULL; p = p->prox) {
        if (dado == p->dado) return lista; //controle de duplicados no método sem recursão
    }

    //encadear e retornar
    p->prox = novo;
    return lista;
}

Celula *inserirR(int dado, Celula *lista) {
    //testar a parada = há lista neste ponto
    if (lista && dado > lista->dado) {
        if (dado == lista->dado){
            return lista; //começa o desempilhamento sem a inserção
        }
        lista->prox = inserirR(dado, lista->prox); //ponto de recursão
        return lista;
    } else { //lista não existe mais, ou seja, empilhei até sair da lista
        //alocar memoria
        Celula *novo = (Celula*)malloc(sizeof(Celula));
    
        //depositar valores
        novo->dado = dado;

        if (lista && dado < lista->dado) {
            novo->prox = lista;
        }
        else {
            novo->prox = NULL;
        }
        return novo;
    }
}

void exibir(Celula *lista) {
    for (Celula *p = lista; p != NULL; p = p->prox) {
        cout << p->dado << "\n";
    }
    cout << endl;
}

void exibirR(Celula *lista) {
    if (lista) {
        cout << lista->dado << "\n";
        exibirR(lista->prox);        
    }
}