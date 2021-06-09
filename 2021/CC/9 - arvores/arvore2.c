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
    
    int valorPesquisa;
    printf("Digite valor para pesquisa: ");
    scanf("%d", &valorPesquisa);

    
    printf("O valor %d aparece na árvore %d vezes\n", valorPesquisa, contarVezes(valorPesquisa, raiz));
    
    printf("A quantidade de nós folhas é: %d\n", contarFolhas(raiz));

    raiz = podar(raiz);
    printf("Poda realizada.... exibindo a árvore pós poda com %d nós\n", contarNos(raiz));
    exibir(raiz, 0);
    

    return 1;
}