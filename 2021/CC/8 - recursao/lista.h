
typedef struct no {
    int valor;
    struct no *prox;
} Celula;


Celula *inserirR(int valor, Celula *lista) {
    //if (lista && lista->valor == valor) return lista; //codigo para controlar duplicados

    if (lista && valor > lista->valor) {
        lista->prox = inserirR(valor, lista->prox);
        return lista;
    } 
    Celula *novo;
    //chegamos neste ponto, quando atingimos o final da lista ou a posição de inserção correta do valor
    novo = (Celula *)malloc(sizeof(Celula));
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

void exibirR(Celula *lista) {
    if (lista) {
        printf("%d\n", lista->valor);
        exibirR(lista->prox);
    }
}

int contarElementosR(Celula *lista) {
    if (lista) {
        return 1 + contarElementosR(lista->prox);
    } 
    return 0;
}

int somarElementosR(Celula *lista) {
    if (lista) {
        return lista->valor + somarElementosR(lista->prox);
    }
    return 0;
}