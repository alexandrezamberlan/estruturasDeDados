

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

typedef struct {
    Celula *inicio;
    Celula *fim;
} Fila;


void inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void inserir(int valor, Fila *f) {
    //alocar memoria
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valores
    novo->dado = valor;
    novo->prox = NULL;

    //engatar no fim
    if (!f->fim) { //testar se é primeira vez. se sim, a celula vai ser o primeiro e o ultimo ao mesmo tempo
        f->inicio = novo;
        f->fim = novo;
        return;
    }

    f->fim->prox = novo;

    //atualizar o fim
    f->fim = novo;
}

int remover(Fila *f){
    //testar se fila vazia
    if (!f->inicio) {
        return -27;
    }    

    //isolar o inicio em lixo
    Celula *lixo = f->inicio;

    int valor = f->inicio->dado;

    //avancar o inicio
    f->inicio = f->inicio->prox;

    //liberar lixo
    free(lixo);

    //quando fila completamente esvaziada
    if (!f->inicio) {
        f->fim= NULL;
    }

    return valor;
}























