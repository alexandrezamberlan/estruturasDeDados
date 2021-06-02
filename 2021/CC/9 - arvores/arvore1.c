#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"

int main () {
    Arvore *raiz = NULL;

    int quantidadeNumeros;
    printf("Quantos números quer gerar?");
    scanf("%d", &quantidadeNumeros);

    srand(time(NULL));
    for (int i = 0; i < quantidadeNumeros; i++) {
        raiz = inserir(rand() % 50, raiz);
    }
    
    exibir(raiz, 0);

    return 1;
}