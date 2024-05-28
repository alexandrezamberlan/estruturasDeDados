#include<iostream>
using namespace std;

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula *add(int valor, Celula *lista) {
    if (lista && valor > lista->dado) {
        //avançar na lista a procura do lugar ideal para valor
        lista->prox = add(valor, lista->prox);
        return lista;
    } else {
        //alocar memoria
        Celula *novo = (Celula *)malloc(sizeof(Celula));
        //depositar valores
        novo->dado = valor;
        
        novo->prox = lista;
        //retornar o elemento criado
        return novo;
    }
}

void print(Celula *lista) {
    if (lista) {
        cout << lista->dado << endl;
        print(lista->prox);
        //
    }
    //
}

bool contains(int valor, Celula *lista) {
    if (lista) {
        if (valor == lista->dado) {
            return true;
        }
        return contains(valor, lista->prox);
    }
    return false;
}

int count(Celula *lista) {
    if (lista) {
        return 1 + count(lista->prox);
    }
    return 0;
}

int countPair(Celula *lista) {
    if (lista) {
        if (lista->dado % 2 == 0)
            return 1 + countPair(lista->prox);
        return countPair(lista->prox);
    }
    return 0;
}

Celula *remove(int valor, Celula *lista) {
    if (lista) {
        if (valor == lista->dado) {
            //codigo de remocao
            Celula *paraRetorno = lista->prox;
            free(lista);
            return paraRetorno;
        }
        lista->prox = remove(valor, lista->prox);
        return lista;
    }
    return NULL;
}

int indexOf(int valor, Celula *lista) {
    if (lista) {
        if (valor == lista->dado) {
            return 0;
        }
        int resposta = indexOf(valor, lista->prox);
        if (resposta == -27) {
            return -27;
        }
        return resposta + 1;
    } else {
        //valor nao localizado
        return -27;
    }
}