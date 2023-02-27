typedef struct no {
    int valor;
    struct no *prox;
} Celula;

Celula *inserirListaSimples(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    Celula *p, *pR;

    //depositar valores
    novo->valor = valor;
    novo->prox = NULL;

    //para a primeira alocação
    if (!lista) return novo;

    //definir a posicao do valor na lista, ou seja, percorrer a lista
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor < p->valor) {
            break;
        }
    }
    //no inicio
    if (p == lista) {
        novo->prox = lista;
        return novo;
    }
    //no fim
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //no meio
    pR->prox = novo;
    novo->prox = p;
    return lista;
}

void exibirListaSimples(Celula *lista) {
    if (!lista) return;

    Celula *p;
    for (p = lista; p; p = p->prox) {
        cout << p->valor << "\t";
    }
    cout << endl;
}