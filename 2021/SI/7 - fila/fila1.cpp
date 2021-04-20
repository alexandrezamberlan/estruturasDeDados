#include <iostream>
using namespace std;

typedef struct no {
    int codigo;
    struct no *prox;
} Celula;

typedef struct {
    Celula *inicio; //ponteiro utilizado para fazer as remoções - indica o elemento mais antigo na estrutura
    Celula *fim;    //ponteiro utilizado para fazer as inserções - indica o elemento mais recente na estrutura
} Fila;

Fila inicializar(Fila f);

int main() {
    Fila filaNormal;
    Fila filaPrioritaria;

    filaNormal = inicializar(filaNormal);
    filaPrioritaria = inicializar(filaPrioritaria);

    return 1;
}

Fila inicializar(Fila f) {
    f.inicio = NULL;
    f.fim = NULL;

    return f;
}