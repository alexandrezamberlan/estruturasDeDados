typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} Arvore;

Arvore *inserir(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor < raiz->valor) { //avançar ou empilhar para a esquerda
            raiz->esq = inserir(valor, raiz->esq);
        } else { //avançar ou empilhar para a direita
            raiz->dir = inserir(valor, raiz->dir);
        }
        return raiz;
    } else {
        //se estamos aqui, pq chegamos em um folha e estamos prontos para adicionar o nodo na árvore
        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->esq = NULL;
        novo->dir = NULL;
        novo->valor = valor;
        return novo;
    }
}


//RED -> visita Raiz; vai para Esquerda; vai para Direita
void exibirRED(Arvore *raiz) {
    if (raiz) {
        printf("%d\n", raiz->valor); //antes do primeiro empilhamento
        exibirRED(raiz->esq);
        exibirRED(raiz->dir);
    }
}

//ERD -> vai para Esquerda; visita Raiz; vai para Direita
void exibirERD(Arvore *raiz) {
    if (raiz) {
        exibirERD(raiz->esq);
        printf("%d\n", raiz->valor); //depois do primeiro empilhamento
        exibirERD(raiz->dir);
    }
}

//EDR -> vai para Esquerda; vai para Direita; visita Raiz
void exibirEDR(Arvore *raiz) {
    if (raiz) {
        exibirEDR(raiz->esq);
        exibirEDR(raiz->dir);
        printf("%d\n", raiz->valor); //depois de todos os empilhamentos
    }
}