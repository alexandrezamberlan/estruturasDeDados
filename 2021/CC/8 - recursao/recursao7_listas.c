#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "lista.h"

int main() {
    int quantidadeValores;
    Celula *lista = NULL;

    printf("Quantos números quer gerar? ");
    scanf("%d", &quantidadeValores);

    srand(time(NULL));
    for (; quantidadeValores > 0; quantidadeValores--) {
        lista = inserirR(rand() % 100, lista);
    }
    exibirR(lista);
    printf("A lista possui %d elementos\n", contarElementosR(lista));
    printf("A soma dos elementos da lista é: %d\n", somarElementosR(lista));
    return 1;
}