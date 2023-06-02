#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} Arvore;

Arvore *inserir(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->valor) return raiz;
        if (valor < raiz->valor) { //ir para esquerda
            raiz->esq = inserir(valor, raiz->esq);
        } else { //ir para direita
            raiz->dir = inserir(valor, raiz->dir);
        }
        return raiz;
    } else {
        Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
}

void exibirRED(Arvore *raiz) {
    if (raiz) {
        //R
        printf("%d\t", raiz->valor);
        //E
        exibirRED(raiz->esq);
        //D
        exibirRED(raiz->dir);
    }
}

void exibirERD(Arvore *raiz) {
    if (raiz) {
        //E
        exibirERD(raiz->esq);
        //R
        printf("%d\t", raiz->valor);
        //D
        exibirERD(raiz->dir);
    }
}

void exibirEDR(Arvore *raiz) {
    if (raiz) {
        //E
        exibirEDR(raiz->esq);
        //D
        exibirEDR(raiz->dir);
        //R
        printf("%d\t", raiz->valor);
    }
}

void exibir(Arvore *raiz, int nivel) {
    if (raiz) {
        //avançar para a direita
        exibir(raiz->dir, nivel + 1);

        for (int i = 0; i < nivel; i++) {
            printf("    ");
        }
        printf("(%d):%d\n", nivel, raiz->valor);

        //avançar para a esquerda
        exibir(raiz->esq, nivel + 1);
    }
}

int contar(Arvore *raiz) {
    if (raiz) {
        return 1 + contar(raiz->esq) + contar(raiz->dir);
    } 
    return 0;
}

Arvore *destruir(Arvore *raiz) {
    if (raiz) {
        raiz->esq = destruir(raiz->esq);
        raiz->dir = destruir(raiz->dir);
        free(raiz); 
    } 
    return NULL;
}

Arvore *localizar(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->valor) {
            return raiz;
        }
        if (valor < raiz->valor) { //ir para esquerda
            return localizar(valor, raiz->esq);
        } else { //ir para direita
            return localizar(valor, raiz->dir);
        }
    } 
    return NULL;
}

int localizarNivel(int valor, Arvore *raiz) {
    if (raiz) {
        if (valor == raiz->valor)
            return 0; //encontrei o valor e soma no desempilhamento
        if (valor < raiz->valor) { //ir para esquerda
            int respostaEmpilhamento = localizarNivel(valor, raiz->esq);
            if (respostaEmpilhamento == -1) return -1;
            return respostaEmpilhamento + 1;
        } else { //ir para direita
             int respostaEmpilhamento = localizarNivel(valor, raiz->dir);
            if (respostaEmpilhamento == -1) return -1;
            return respostaEmpilhamento + 1;
        }
    }
    return -1;
}

int main() {
    Arvore *raiz = NULL;
    // srand(time(NULL));
    // for (int i = 0; i < 5000; i++) {
    //     raiz = inserir(rand() % 5, raiz);
    // }
    raiz = inserir(15, raiz);
    raiz = inserir(5, raiz);
    raiz = inserir(50, raiz);
    raiz = inserir(1, raiz);
    raiz = inserir(10, raiz);
    raiz = inserir(20, raiz);
    raiz = inserir(100, raiz);
    printf("Total de nodos: %d\n\n", contar(raiz));
    exibir(raiz, 0);

    int pesquisar;
    printf("Valor de pesquisa: ");
    scanf("%d", &pesquisar);

    Arvore *posicao = localizar(pesquisar, raiz);
    printf("%d localizado na posicao %p\n", pesquisar, posicao);    

    int nivel = localizarNivel(pesquisar, raiz);
    printf("%d localizado no nivel %d\n", pesquisar, nivel);    

    // printf("Exibindo RED\n");
    // exibirRED(raiz);

    // printf("\n\nExibindo ERD\n");
    // exibirERD(raiz);

    // printf("\n\nExibindo EDR\n");
    // exibirEDR(raiz);

    // raiz = destruir(raiz);
    // printf("Total de nodos: %d\n\n", contar(raiz));
    // exibir(raiz, 0);

    return 1;
}
