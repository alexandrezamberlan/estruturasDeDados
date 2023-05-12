#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3

void inicializarR(int *v, int n, int valor) {
    if (n > 0) {
        //codigo no empilhamento

        inicializarR(v, n - 1, valor);
        
        //codigo no desempilhamento
        v[n - 1] = valor;
    }
}

void exibirR(int *v, int n) {
    if (n > 0) {
        //codigo no empilhamento

        exibirR(v, n - 1);
        
        //codigo no desempilhamento
        printf("[%d]:%d\n",n - 1, v[n - 1]);
    }
}


void popularR(int *v, int n, int valor) {
    if (n > 0) {
        //codigo no empilhamento

        popularR(v, n - 1, valor);
        
        //codigo no desempilhamento
        v[n - 1] = rand() % valor;
    }
}

int main() {
    int vetor[TAM];

    srand(time(NULL));
    inicializarR(vetor, TAM, 0);
    popularR(vetor, TAM, 50);
    exibirR(vetor, TAM);

    return 1;
}