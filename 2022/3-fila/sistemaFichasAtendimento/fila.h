#include <cstdlib>

typedef struct no {
    int ficha;
    struct no *prox;
} Celula;

typedef struct {
    Celula *inicio; //onde são realizadas as remoções
    Celula *fim;    //onde são realizadas as inserções
} Fila;

void inicializar(Fila *fila) {
    fila->inicio = NULL; //ponteiro que coordena o primeiro elemento inserido, logo o que vai ser removido
    fila->fim = NULL;    //ponteiro que coordena o ultimo elemento inserido
}

void inserir(int ficha, Fila *fila) {
    //alocar memoria
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores
    novo->ficha = ficha;
    novo->prox = NULL;

    //engatar no fim
    if (!fila->fim) { //testar se é primeira vez. se sim, a celula vai ser o primeiro e o ultimo ao mesmo tempo
        fila->inicio = novo;
        fila->fim = novo;
        return;
    }

    fila->fim->prox = novo; //o ultimo da fila conhece o novo

    //atualizar o fim
    fila->fim = novo; //o novo passa a ser o ultimo da fila
}

void exibir(Fila fila) {
    if (!fila.inicio) {
        cout << "Vazia!\n";
        return;
    }
    Celula *p;
    for (p = fila.inicio; p; p = p->prox) {
        cout << p->ficha << "\n";
    }
}

int excluir(Fila *fila){
    //testar se fila vazia
    if (!fila->inicio) {
        return -27;
    }    

    //isolar o inicio em lixo
    Celula *lixo = fila->inicio;

    int valor = fila->inicio->ficha;

    //avancar o inicio
    fila->inicio = fila->inicio->prox;

    //liberar lixo
    free(lixo);

    //quando fila completamente esvaziada
    if (!fila->inicio) {
        fila->fim= NULL;
    }

    return valor;
}