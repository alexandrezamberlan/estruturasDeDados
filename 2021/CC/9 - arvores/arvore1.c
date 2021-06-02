#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"

int main () {
    Arvore *raiz = NULL;

    int quantidadeNumeros;
    // printf("Quantos números quer gerar?");
    // scanf("%d", &quantidadeNumeros);

    srand(time(NULL));
    quantidadeNumeros = rand() % 20 + 5;

    
    for (int i = 0; i < quantidadeNumeros; i++) {
        raiz = inserir(rand() % 50, raiz);
    }
    
    exibir(raiz, 0);
    printf("\nEsta árvore possui %d nós\n", contarNos(raiz));
    printf("A soma dos elementos da árvore é: %d\n", somarNos(raiz));
    printf("Esta árvore possui %d nós pares\n", contarNosPares(raiz));

    int valorPesquisa;
    printf("Digite valor para pesquisa: ");
    scanf("%d", &valorPesquisa);

    int nivel = localizarNivel(valorPesquisa, raiz);
    if (nivel != -1) {
        printf("Valor localizado na árvore no nível %d\n", nivel);
    } else {
        printf("Valor não localizado na árvore\n");
    }

    return 1;
}