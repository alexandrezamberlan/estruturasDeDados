#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

void popular(int *v, int n) {
    
    for (; n > 0; n--) {
        v[n-1] = rand() % 100;
    }
}

void exibir(int *v, int n) {
    
    for (; n > 0; n--) {
        printf("%d\t", v[n-1]);
    }
    printf("\n");
}

void popularR(int *v, int n) { //inicialização da variável de controle n
    if (n > 0) {
        v[n-1] = rand() % 100;
        popularR(v, n - 1); //ponto de recursão com a transformação da variável de controle
    }
}

void exibirR(int *v, int n) {
    if (n > 0) {
        printf("%d\t", v[n-1]);
        exibirR(v, n - 1);
    }
}

int main() {
    int vetor[TAM];
    srand(time(NULL));
    //popular(vetor, TAM);
    //exibir(vetor, TAM);


    popularR(vetor, TAM);
    exibirR(vetor, TAM);
    printf("\n");

    return 1;
}