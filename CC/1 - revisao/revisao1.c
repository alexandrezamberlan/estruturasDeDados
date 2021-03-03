/**
 * MÉTODOS = procedimento (void) e função (return)
 */

#include <stdio.h> //printf, scanf, getc, gets, ...
#include <stdlib.h> //??
#include <time.h>

#define TAMANHOLINHA 5
#define TAMANHOCOLUNA 5

void inicializarMatriz(int m[TAMANHOLINHA][TAMANHOCOLUNA], int linha, int coluna) {
    int i, j;
    srand(time(NULL)); //usar a biblioteca time.h.... este método/comando sempre renova os números sorteados
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            //m[i][j] = 0; //inicializando com zeros
            m[i][j] = rand() % 20; //usar a biblioteca time.h
        }
    }
}

void exibirMatriz(int m[TAMANHOLINHA][TAMANHOCOLUNA], int linha, int coluna) {
    int i, j;
    for (i = 0; i < linha; i++) {
        for (j = 0; j < coluna; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void inicializarVetor(int v[TAMANHOCOLUNA], int coluna) {
    int i;
    srand(time(NULL)); //usar a biblioteca time.h.... este método/comando sempre renova os números sorteados
    for (i = 0; i < coluna; i++) {
        //v[i] = 0;
        v[i] = rand() % 20; //usar a biblioteca time.h
    }
}

void exibirVetor(int v[TAMANHOCOLUNA], int coluna) {
    int i;
    
    for (i = 0; i < coluna; i++) {
        printf("%d ", v[i]);
    }
}

int main() {
    int matriz1[TAMANHOLINHA][TAMANHOCOLUNA];
    int vetor1[TAMANHOCOLUNA];

    printf("MATRIZ\n");
    //prencher a matriz com 0
    inicializarMatriz(matriz1, TAMANHOLINHA, TAMANHOCOLUNA);

    //exibir a matriz
    exibirMatriz(matriz1, TAMANHOLINHA, TAMANHOCOLUNA);

    printf("VETOR\n");
    //preencher o vetor com 0
    inicializarVetor(vetor1, TAMANHOCOLUNA);

    //exibir o vetor
    exibirVetor(vetor1, TAMANHOCOLUNA);

    printf("\nFeito\n");
    return 1;
}

/*
MATRIZ1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0

VETOR1
0 0 0 0 0
*/