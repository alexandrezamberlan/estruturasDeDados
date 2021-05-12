#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

void popularR(int *vetor, int n) {
    if (n > 0) {
        vetor[n - 1] = rand() % 20;
        popularR(vetor, n - 1);
        //no desempilhamento não faz nada
    }
}

void exibirR(int *vetor, int n) {
    if (n > 0) {
        printf("%d\n", vetor[n - 1]);
        exibirR(vetor, n - 1);
    }
}

int somarElementosR(int *vetor, int n) {
    if (n > 0) {
        int soma = vetor[n - 1] + somarElementosR(vetor, n - 1);
        return soma;
    } else {
        return 0;
    }
}

int contarParesR(int *vetor, int n) {
    if (n > 0) {
        int conta;
        if (vetor[n - 1] % 2 == 0) {
            conta = 1 + contarParesR(vetor, n - 1);
        } else {
            conta = 0 + contarParesR(vetor, n - 1);
        }
        return conta;
    } else {
        return 0;
    }
}

int main() {
    int vetor[TAM];
    srand(time(NULL));
    popularR(vetor, TAM);
    exibirR(vetor, TAM);
    printf("A soma dos elementos do vetor é: %d\n ", somarElementosR(vetor, TAM));
    printf("A quantidade de pares presente no vetor é: %d\n", contarParesR(vetor, TAM));

    return 1;
}