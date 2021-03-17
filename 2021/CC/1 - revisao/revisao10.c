#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popular(int *vetor, int tamanho) {
    
    int i;
    for (i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }
}

void exibir(int *vetor, int tamanho) {
    
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d\t", vetor[i]);
    }
}

int main() {
    srand(time(NULL));
    int *vetor;

    int tamanho;

    printf("Quantos numeros deseja gerar e armazenar?");
    scanf("%d", &tamanho);
    vetor = malloc(sizeof(int) * tamanho); //alocação de memória em tempo de execução

    popular(vetor, tamanho);
    exibir(vetor, tamanho);

    free(vetor); //liberação de memória em tempo de execução
    
    return 1;
}