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
int contarElementos(Arvore *raiz) {
    if (raiz) {
        return 1 + contarElementos(raiz->esq) + contarElementos(raiz->dir);
    }
    return 0;
}

int somarElementos(Arvore *raiz) {
    if (raiz) {
        return raiz->dado + somarElementos(raiz->esq) + somarElementos(raiz->dir);
    }
    return 0;
}

//estaContido
bool estaContido(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->dado) return true;
        if (valor < raiz->dado) { //ir para esquerda
            return estaContido(valor, raiz->esq);
        } else { //ir para direita
            return estaContido(valor, raiz->dir);
        }
    } 
    return false;
}

//qualONivel
int nivel(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->dado) return 0;
        if (valor < raiz->dado) { //ir para esquerda
            int respostaEmpilhamento = nivel(valor, raiz->esq);
            if (respostaEmpilhamento == -27)
                return respostaEmpilhamento;
            else return respostaEmpilhamento + 1;
        } else { //ir para direita
            int respostaEmpilhamento = nivel(valor, raiz->dir);
            if (respostaEmpilhamento == -27)
                return respostaEmpilhamento;
            else return respostaEmpilhamento + 1;
        }
    } 
    return -27;
}

//remover

//somar

//calcularAltura