#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "lista.h"

int main() {
    int quantidadeValores;
    Celula *lista = NULL;
    int valor;

    system("clear");
    printf("Quantos números quer gerar? ");
    scanf("%d", &quantidadeValores);

    srand(time(NULL));
    for (; quantidadeValores > 0; quantidadeValores--) {
        lista = inserirR(rand() % 100, lista);
    }
    exibirR(lista);
    printf("A lista possui %d elementos\n", contarElementosR(lista));
    printf("A soma dos elementos da lista é: %d\n", somarElementosR(lista));
    
    printf("Digite um valor para pesquisa: ");
    scanf("%d", &valor);
    printf("O %d está na lista no endereço %p\n", valor, localizarElementoR(valor, lista));
    printf("O %d está na lista na posição %d\n", valor, localizarPosicaoLogicaElementoR(valor, lista));
    lista = excluirR(valor, lista);

    exibirR(lista);
    int quantidadeElementos = contarElementosR(lista);
    printf("A lista possui %d elementos\n", quantidadeElementos);


    printf("Na lista há %d pares..... exibindo os pares restantes na lista\n", contarParesR(lista));
    exibirParesR(lista);


    return 1;
}