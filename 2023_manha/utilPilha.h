//criar ou definir artificialmente um struct
//exemplo uma estrutura ou tipo para dados cartesianos
typedef struct no {
    int x;
    int y;
    struct no *prox;
} PontoCartesiano;        

PontoCartesiano *inserir(int x, int y, PontoCartesiano *topo) {
    //alocar memoria
    PontoCartesiano *novo = (PontoCartesiano *)malloc(sizeof(PontoCartesiano));
    
    //depositar valores
    novo->x = x;
    novo->y = y;

    //encadear e retornar
    novo->prox = topo;

    return novo;
}

PontoCartesiano *remover(PontoCartesiano *topo) {
    if (!topo) return topo;
    
    //guardar o topo em lixo
    PontoCartesiano *lixo = topo;

    //avancar o topo para o proximo elemento
    topo = topo->prox;

    //liberar memoria
    free(lixo);

    //retornar o novo topo
    return topo;
}

int contarPilha(PontoCartesiano *topo) {
    int qtd = 0;
    for (PontoCartesiano *p = topo; p ; p = p->prox) {
        qtd++;
    }
    return qtd;
}

void exibir(PontoCartesiano *topo) {

    for (PontoCartesiano *p = topo; p ; p = p->prox) {
        printf("(%d,%d)\n", p->x, p->y);
    }
    
}