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

int main() {
    Arvore *raiz = NULL;
    srand(time(NULL));
    for (int i = 0; i < 50 + 2; i++) {
        raiz = inserir(rand() % 50, raiz);
    }
    printf("Total de nodos: %d\n\n", contar(raiz));
    exibir(raiz, 0);

    // printf("Exibindo RED\n");
    // exibirRED(raiz);

    // printf("\n\nExibindo ERD\n");
    // exibirERD(raiz);

    // printf("\n\nExibindo EDR\n");
    // exibirEDR(raiz);

    return 1;
}