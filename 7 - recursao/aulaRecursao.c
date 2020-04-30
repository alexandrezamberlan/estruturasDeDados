//programas da aula....
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define TAM 5
/**
 * Revisão RECURSÃO
 * 
 * 
 * */

void popularR(int *vetor, int n) { //n é a variável de controle e é inicializada no parâmetro
    if (n > 0) { //teste de parada observando o n que é a variável de controle
        //código executado no empilhamento
        vetor[n - 1] = rand() % 100;
        
        popularR(vetor, n - 1); //ponto de recursão com a transformação da variável de controle
        
        //código executado no desempilhamento
        //printf("%d\t", vetor[n - 1]);
    }
}

void exibirR(int *vetor, int n) {
    if (n > 0) {
        exibirR(vetor, n - 1);
        printf("%d\t",vetor[n - 1]);
    }
}

int main() {
    srand(time(NULL));
    int vetor[TAM];

    popularR(vetor, TAM);
    exibirR(vetor, TAM);

    return 1;
}