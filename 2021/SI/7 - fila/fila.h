#include <iostream>
#include <string>

using namespace std;

typedef struct no {
    string senha;
    struct no *prox;
} Celula;

typedef struct {
    Celula *inicio; //ponteiro utilizado para fazer as remoções - indica o elemento mais antigo na estrutura
    Celula *fim;    //ponteiro utilizado para fazer as inserções - indica o elemento mais recente na estrutura
} Fila;

Fila inicializar(Fila f) {
    f.inicio = NULL;
    f.fim = NULL;

    return f;
}

Fila inserir(string senha, Fila f) {
    //alocar memória - como faziamos em pilha, listas 
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores dos parâmetros
    novo->senha = senha;
    novo->prox = NULL;

    //testa se é o primeiro
    if (!f.fim) { //fila está vazia, então o novo é o primeiro e o último ao mesmo tempo
        f.fim = novo;
        f.inicio = novo;
        return f;
    }

    //engata e atualiza onde está o último elemento
    f.fim->prox = novo;
    f.fim = novo;

    //retorna
    return f;
}

Fila remover(Fila f, string *resultado) {
    if (!f.inicio) {
        return f;
    }

    *resultado = f.inicio->senha; //guarda a senha a ser removida da lista
    Celula *lixo = f.inicio; //guardamos o elemento que será retirado da fila
    f.inicio = f.inicio->prox; //avança o início para o 2o elemento da fila
    free(lixo); //apagamos o primeiro elemento da fila

    if (!f.inicio) {
        f.fim = NULL;
    }

    return f;
}