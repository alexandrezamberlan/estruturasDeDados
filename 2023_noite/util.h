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
    
    if (!lista) return false;

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

//listas duplas

typedef struct noD {
    int valor;
    struct noD *prox, *ant;
} CelulaD;

void exibirListaDupla(CelulaD *lista) {
    if (!lista) return;

    //garatir que o controle da lista esteja no primeiro elemento
    while (lista->ant) {
        lista = lista->ant;
    }

    CelulaD *p;
    for (p = lista; p; p = p->prox) {
        cout << p->valor << "\t";
    }
    cout << endl;
}

void exibirListaDuplaDecrescente(CelulaD *lista) {
    if (!lista) return;

    //garatir que o controle da lista esteja no ultimo elemento
    while (lista->prox) {
        lista = lista->prox;
    }

    CelulaD *p;
    for (p = lista; p; p = p->ant) {
        cout << p->valor << "\t";
    }
    cout << endl;
}

bool localizarListaDupla(int valor, CelulaD *lista) {
    CelulaD *p;

    if (!lista) return false;

    //garatir que o controle da lista esteja no primeiro elemento
    while (lista->ant) {
        lista = lista->ant;
    }

    for (p = lista; p; p=p->prox) {
        if (valor == p->valor) {
            return true;
        }
    }
    return false;
}

CelulaD *destruirListaDupla(CelulaD *lista) {
    CelulaD *pR, *p;

    if (!lista) return lista;

    //garatir que o controle da lista esteja no primeiro elemento
    while (lista->ant) {
        lista = lista->ant;
    }

    for (pR = lista, p = lista->prox; p ; pR = p, p = p->prox) {
        free(pR);    
    }
    free(pR);
    return NULL;
}

CelulaD *destruirListaDupla2(CelulaD *lista) {
    CelulaD *p;

    if (!lista) return lista;

    //garatir que o controle da lista esteja no primeiro elemento
    while (lista->ant) {
        lista = lista->ant;
    }

    if (!p->prox) {
        free(p);
        return NULL;
    }

    for (p = lista->prox; p->prox ; p = p->prox) {
        free(p->ant);    
    }
    free(p->ant);
    free(p);
    return NULL;
}

CelulaD *inserirListaDupla(int valor, CelulaD *lista) {
    //alocar memória
    CelulaD *novo = (CelulaD *)malloc(sizeof(CelulaD));
    CelulaD *p, *pR;

    //depositar valores
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    //para a primeira alocação
    if (!lista) return novo;


    //garantir que o controle da lista esteja no primeiro elemento
    while (lista->ant) {
        lista = lista->ant;
    }

    //definir a posicao do valor na lista, ou seja, percorrer a lista
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor < p->valor) {
            break;
        }
    }
    //no inicio
    if (p == lista) {
        novo->prox = lista;
        lista->ant = novo; //codigo da lista dupla
        return novo;
    }
    //no fim
    if (!p) {
        pR->prox = novo;
        novo->ant = pR; //codigo da lista dupla
        return lista;
    }
    //no meio
    pR->prox = novo;
    novo->ant = pR; //codigo da lista dupla
    novo->prox = p;
    p->ant = novo;  //codigo da lista dupla
    return lista;
}

CelulaD *removerListaDupla(int valor, CelulaD *lista) {
    CelulaD *lixo;
    CelulaD *p, *pR;

    if (!lista) return lista;

    while (lista->ant) {
        lista = lista->ant;
    }

    //definir a posicao do valor na lista, ou seja, percorrer a lista
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor == p->valor) {
            lixo = p;
            if (p == lista) { //primeira posicao
                lista = lista->prox;
                lista->ant = NULL;
            } else if (!p->prox) { //ultima posicao
                pR->prox = NULL;
            } else { //posicao intermediaria
                pR->prox = p->prox;
                p->prox->ant = pR;
            }
            free(lixo);    
            return lista;        
        }
    }
    return lista;
}

CelulaD *removerRepetidosListaDupla(int valor, CelulaD *lista) {
    CelulaD *p;

    if (!lista) return lista;

    while (lista->ant) {
        lista = lista->ant;
    }

    p = lista; 
    while (p) {
        
        if (valor == p->valor) {
            lista = removerListaDupla(valor, lista);   
            p = lista;        
        } else p = p->prox;
    }
    return lista;
}