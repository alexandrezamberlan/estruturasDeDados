typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *lista) {
    //alocar
    Celula *novo = (Celula *)malloc(sizeof(Celula)); //casting ou coersão

    //depositar
    novo->dado = valor;
    novo->prox = NULL;

    //encadear
    if (!lista) return novo;

    Celula *p, *pR;
    for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
        if (valor < p->dado) {
            break;
        }
    }
    if (p == lista) { //inserir no inicio
        novo->prox = lista;
        return novo;
    } else if (!p) { //inserir no fim
        pR->prox = novo;
    } else { //inserir no meio
        pR->prox = novo;
        novo->prox = p;
    }

    //retornar
    return lista;
}

void exibir(Celula *lista) {
    Celula *p;
    printf("Exibindo.....\n");
    for (p = lista; p; p = p->prox) {
        printf("%d\t", p->dado);
    }
    printf("\n");
}