typedef struct no {
    int dado;
    struct no *esq;
    struct no *dir;
} Arvore;

//inserir
Arvore *add(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->dado) return raiz;
        if (valor < raiz->dado) { //ir para esquerda
            raiz->esq = add(valor, raiz->esq);
        } else { //ir para direita
            raiz->dir = add(valor, raiz->dir);
        }
        return raiz;
    } else { //chegou-se apos nós folhas.
        //alocar memoria
        Arvore *novo = (Arvore *)malloc(sizeof(Arvore));

        //depositar valores
        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;

        //refaz encadeamento
        return novo;
    }
}

//mostar
void showRED(Arvore *raiz) {
    if (raiz) {
        //visita raiz - R
        cout << raiz->dado << endl;
        //vai para esquerda - E
        showRED(raiz->esq);
        //vai para direita - D
        showRED(raiz->dir);
    }
}

void showERD(Arvore *raiz) {
    if (raiz) {
        //vai para esquerda - E
        showERD(raiz->esq);
        //visita raiz - R
        cout << raiz->dado << endl;
        //vai para direita - D
        showERD(raiz->dir);
    }
}

void showEDR(Arvore *raiz) {
    if (raiz) {
        //vai para esquerda - E
        showEDR(raiz->esq);
        //vai para direita - D
        showEDR(raiz->dir);
        //visita raiz - R
        cout << raiz->dado << endl;
    }
}

void mostrarArvore(Arvore *raiz, int nivel) {
    if (raiz) {
        //ir tudo para a direita
        mostrarArvore(raiz->dir, nivel + 1);

        //visitar o raiz
        for (int i = 0; i < nivel; i++) {
            cout << "  ";
        }
        cout << "(" << nivel << ")" << raiz->dado << endl;

        //ir tudo para a esquerda
        mostrarArvore(raiz->esq, nivel + 1);
    }
}

//contar

//estaContido

//qualONivel

//remover

//somar

//calcularAltura