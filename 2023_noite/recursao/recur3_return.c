/**
 * Recursão == repetição
 *  - void
 *  - return
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

void popularVetorR(int *v, int n, int faixa) {
    if (n > 0) {

        popularVetorR(v, n-1, faixa); //ponto de recursao
        
        v[n-1] = rand() % faixa;
    }
}

void exibirVetorR(int *v, int n) {
    if (n > 0) {

        exibirVetorR(v, n-1); //ponto de recursao
        
        printf("[%d]:%d\n", n-1, v[n-1]);
    }
}


int main() {
    int vetor[TAM];
    Celula *lista = NULL;
    srand(time(NULL));
    popularVetorR(vetor, TAM, 100);
    exibirVetorR(vetor, TAM);


    return 1;
}