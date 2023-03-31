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


Celula *inserirControleDuplicados(int valor, Celula *lista) {
    //alocar
    Celula *novo = (Celula *)malloc(sizeof(Celula)); //casting ou coersão

    //depositar
    novo->dado = valor;
    novo->prox = NULL;

    //encadear
    if (!lista) return novo;

    Celula *p, *pR;
    for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
        if (valor == p->dado) {
            free(novo);
            return lista;
        }
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

Celula *excluir(int valor, Celula *lista) {
    Celula *p, *pR;
    for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
        if (valor == p->dado) { //valor encontrado
            //testar se esta no inicio
            if (p == lista) {
                lista = lista->prox;
                free(p);
            } else if (!p->prox) { //testar se esta no fim
                free(p);
                pR->prox = NULL;
            } else { //esta no meio
                pR->prox = p->prox;
                free(p);                
            }
            break;
        }       
    }
    return lista;
}

Celula *excluirRepetidos(int valor, Celula *lista) {
    return NULL;
}

int contar(Celula *lista) {
    Celula *p;
    int conta = 0;
    
    for (p = lista; p; p = p->prox) {
        conta++;
    }
    return conta;
}

Celula *localizar(int valor, Celula *lista) {
    Celula *p;
    
    for (p = lista; p; p = p->prox) {
        if (valor == p->dado) {
            return p;
        }
    }
    return NULL;
}

Celula *destruir(Celula *lista) { //devolver memória ao SO

    Celula *pR, *p;
    if (!lista) return NULL;

    for (pR = lista, p = lista->prox; p; pR = p, p = p->prox) {
        free(pR);
    }
    free(pR); //para apagar o ultimo elemento

    return NULL;
}