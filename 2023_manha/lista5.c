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

int main() {
    
    Celula *lista1 = NULL;
    Celula *lista2 = NULL;

    lista1 = popularListaAleatoria(lista1,10);
    lista2 = popularListaAleatoria(lista2,20);

    exibir(lista1);
    exibir(lista2);

    //concatenar a lista1 com a lista2 -> ultimo elemento da lista1 deve apontar para o primeiro elemento da lista2
    //Celula *lista3 = concatenar(lista1,lista2);

    //mesclar a lista1 com a lista2 -> unificar as duas listas, mantendo a ordenação
    //Celula *lista4 = mesclar(lista1,lista2)

    //mesclar a lista1 com a lista2 -> unificar as duas listas, sem repetir valores
    //Celula *lista5 = mesclarSemRepetidos(lista1,lista2)


    return 1;
}