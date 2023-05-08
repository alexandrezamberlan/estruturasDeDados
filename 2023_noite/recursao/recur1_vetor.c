#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100000

void popular(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 50;
    }
}

void exibir(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d]:%d\t",i, v[i]);
    }
    printf("\n");
}


void popularR(int *v, int n) {
    if (n > 0) {
        v[n - 1] = rand() % 50;
        popularR(v, n - 1);
    }
}

void exibirR(int *v, int n) {
    if (n > 0) {
        exibirR(v, n - 1);
        printf("[%d]:%d\t",n - 1, v[n - 1]);
    }
}

int main() {
    int vetor[TAM];
    srand(time(NULL));
    popularR(vetor, TAM);
    exibirR(vetor, TAM);
    return 1;
}