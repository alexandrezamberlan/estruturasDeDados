typedef struct nodo 
{
    int dado;
    struct nodo *prox;
} Pilha;

Pilha *inserir(int valor, Pilha *topo) 
{
    //alocar memoria
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));

    //depositar valores
    novo->dado = valor;

    //empilhar com encadeamento
    novo->prox = topo;

    //retornar o novo topo
    return novo;
}

void exibir(Pilha *topo) 
{
    Pilha *p;
    for (p = topo; p; p = p->prox) 
    {
        cout << p->dado << endl;
    }
}

int topo(Pilha *topo) 
{
    if (!topo) return -27;

    return topo->dado;
}

bool localizado(int valor, Pilha *topo) 
{
    Pilha *p;
    for (p = topo; p ; p = p->prox) 
    {
        if (valor == p->dado)
        {
            return true;
        }
    }
    return false;
}

Pilha *remover(Pilha* topo) 
{
    if (!topo) return topo;

    Pilha *lixo;
    //reservar o topo que sera excluido
    lixo = topo;
    //avancar para o novo topo
    topo = topo->prox;
    //apagar o elemento reservado
    free(lixo);
    //retornar o novo topo
    return topo;
}
