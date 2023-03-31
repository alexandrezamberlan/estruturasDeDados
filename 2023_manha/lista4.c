/*
Lista é uma Estrutura de Dados Abstrata com todas as operações: percurso, pesquisa, inserção ordenada, remoção

Lista utiliza struct e ponteiro

Há 3 tipos de listas:
    - simples: um ponteiro (prox) apontando para a próxima célula - a estrutura básica é igual a da pilha
    - circular: um ponteiro (prox) apontando para a próxima célula, contudo o último elemento, o seu prox
                aponta para o primeiro elemento da lista
    - duplas: são dois ponteiros, um prox, apontando para o próximo elemento e um ant, apontando para o
              elemento anterior


Lista simples possui:
    - a mesma estrutura que pilha
    - percurso: necessidade de p (ponteiro vigente) e pR (ponteiro de retaguarda, ou seja, que vai atrás do p)

    for (pR = NULL, p = lista; p ; pR = p, p = p->prox)

    - inserir ordenado (no início, no fim, ou em qualquer posição do meio)
    - remover deve garantir o encadeamento, pois é escolhido quem remover
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista.h"

Celula *popularListaAleatoria(Celula *lista, int qtd) {
    srand(time(NULL));
    for (int i = 0; i < qtd; i++) {
        lista = inserir(rand() % 100, lista);
    }
    return lista;
}

int main(int qtdArgumentos, char **vetorArgumentos) {
    if (qtdArgumentos != 2) {
        printf("Problemas com os parametros...\n");
        exit(0);
    }

    int qtdNumeros = atoi(vetorArgumentos[1]);

    Celula *lista = NULL;

    lista = popularListaAleatoria(lista,qtdNumeros);

    // exibir(lista);

    // codigo de manipulação da lista

    // lista = destruir(lista);
    
    // exibir(lista);
    printf("Insercao ordenada terminada\n");

    return 1;
}