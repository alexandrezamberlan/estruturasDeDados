/**
 * MÉTODOS = procedimento (void) e função (return)
 */

#include <stdio.h> //printf, scanf, getc, gets, ...
#include <stdlib.h> //??
#include <time.h>

#define TAMANHOCOLUNA 20


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

void localizarDadoNoVetor(int v[], int n, int valor) {
    int i;
    for (i = 0; i < n; i++) {
        if (valor == v[i]) {
            printf("Valor localizado na posição %d\n", i);
        }
    }
}

int retornaPosicaoDadoNoVetor(int v[], int n, int valor) {
    int i;
    for (i = 0; i < n; i++) {
        if (valor == v[i]) {
            return i; //encontra a primeira ocorrencia do valor e já retorna
        }
    }
    return -1; //indica que o valor nao foi encontrado
}

int main() {
    int vetor1[TAMANHOCOLUNA];
    int valor;

    printf("VETOR\n");
    //preencher o vetor com 0
    inicializarVetor(vetor1, TAMANHOCOLUNA);

    //exibir o vetor
    exibirVetor(vetor1, TAMANHOCOLUNA);

    printf("\nDigite um valor inteiro para a busca: ");
    scanf("%d", &valor);
    
    //metodo que recebe um vetor e um valor e exibe a posição que o valor aparece no vetor
    int posicao = retornaPosicaoDadoNoVetor(vetor1, TAMANHOCOLUNA, valor);
    printf("Posicao: %d\n", posicao);

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