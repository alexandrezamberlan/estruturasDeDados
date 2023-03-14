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

Celula *removerListaSimples(int valor, Celula *lista) {
    //alocar memória
    Celula *lixo;
    Celula *p, *pR;

    //definir a posicao do valor na lista, ou seja, percorrer a lista
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor == p->valor) {
            lixo = p;
            if (p == lista) { //primeira posicao
                lista = lista->prox;
            } else if (!p->prox) { //ultima posicao
                pR->prox = NULL;
            } else { //posicao intermediaria
                pR->prox = p->prox;
            }
            free(lixo);    
            return lista;        
        }
    }
    return lista;
}

Celula *removerRepetidosListaSimples(int valor, Celula *lista) {
    Celula *p;
    p = lista; 
    while (p) {
        
        if (valor == p->valor) {
            lista = removerListaSimples(valor, lista);   
            p = lista;        

        } else p = p->prox;
    }
    return lista;
}


Celula *destruirListaSimples(Celula *lista) {
    Celula *pR, *p;

    if (!lista) return lista;

    for (pR = lista, p = lista->prox; p ; pR = p, p = p->prox) {
        free(pR);    
    }
    free(pR);
    return NULL;
}

void exibirListaSimples(Celula *lista) {
    if (!lista) return;

    Celula *p;
    for (p = lista; p; p = p->prox) {
        cout << p->valor << "\t";
    }
    cout << endl;
}


bool localizarListaSimples(int valor, Celula *lista) {
    Celula *p;
    for (p = lista; p; p=p->prox) {
        if (valor == p->valor) {
            return true;
        }
    }
    return false;
}

Celula *atualizarListaSimples(int valorAntigo, int valorNovo, Celula *lista) {
    Celula *p;
    if (localizarListaSimples(valorAntigo,lista)) {
        lista = removerListaSimples(valorAntigo,lista);
        lista = inserirListaSimples(valorNovo, lista);
        cout << "valor atualizado com sucesso na lista\n";
    }
    return lista;
}