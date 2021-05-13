#include <time.h>
using namespace std;

typedef struct no {
    int valor;
    struct no *prox;
} Celula;

Celula *inserirR(int valor, Celula *lista) {
    if (lista && valor > lista->valor) {
        //avançar no empilhamento, logo na lista, para achar a posição correta do valor
        lista->prox = inserirR(valor, lista->prox); //o retorno da recursão será dentro da variável prox da lista
        return lista;
    } else {
        //quando entramos aqui? 
        //1) quando a lista chegar no final (valor a ser inserido é o maior de todos);
        //2) quando o valor a ser inserido for o primeiro ou estiver em alguma posição do meio
        Celula *novo = (Celula *)malloc(sizeof(Celula));
        novo->valor = valor;
        novo->prox = lista;
        return novo;
    }
}

void exibirR(Celula *lista) {
    if (lista) {
        cout << lista->valor << "\t";
        exibirR(lista->prox);
        //aqui, teríamos os códigos que seriam executados no retorno do empilhamento, ou desempilhamento
    }
}

Celula *popular(Celula *lista, int n) {
    srand(time(NULL));
    for (; n > 0; n--) {
        lista = inserirR(rand() % 100, lista);
    }
    return lista;
}

int contarElementosR(Celula *lista) {
    if (lista) {
        return 1 + contarElementosR(lista->prox);
    } else {
        return 0;
    }
}

int somarElementosR(Celula *lista) {
    if (lista) {
        return lista->valor + somarElementosR(lista->prox);
    } else {
        return 0;
    }
}

int contarParesR(Celula *lista) {
    if (lista) {
        if (lista->valor % 2 == 0)
            return 1 + contarParesR(lista->prox);
        return 0 + contarParesR(lista->prox);
    } else {
        return 0;
    }
}