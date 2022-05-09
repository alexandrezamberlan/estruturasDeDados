#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

void popularR(int *v, int n) { //inicialização da variável de controle n
    if (n > 0) {
        v[n-1] = rand() % 10;
        popularR(v, n - 1); //ponto de recursão com a transformação da variável de controle
    }
}

void exibirR(int *v, int n) {
    if (n > 0) {
        printf("%d\t", v[n-1]);
        exibirR(v, n - 1);
    }
}

void trocar(int *v, int n, int valorOrigem, int valorDestino) {
    for (; n > 0; n--) {
        if (v[n-1] == valorOrigem) {
            v[n-1] = valorDestino;
        }
    }
}

void trocarR(int *v, int n, int valorOrigem, int valorDestino) {
    if (n > 0) {
        if (v[n-1] == valorOrigem) {
            v[n-1] = valorDestino;
            return; //cancelar o empilhamento
        } 
        trocarR(v, n - 1, valorOrigem, valorDestino);
        //printf("estou desempilhando\n");
    }
}

int main() {
    int vetor[TAM];
    srand(time(NULL));

    popularR(vetor, TAM);
    exibirR(vetor, TAM);
    printf("\n");
    int valor;
    printf("Digite um valor para troca: ");
    scanf("%d", &valor);
    
    //trocar(vetor, TAM, valor, 0);
    trocarR(vetor, TAM, valor, 0);
    
    exibirR(vetor, TAM);
    printf("\n");

    return 1;
}