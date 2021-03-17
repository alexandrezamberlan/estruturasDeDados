#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popularMatriz(int **matriz, int tamanhoLinha, int tamanhoColuna) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < tamanhoLinha; i++) {
        for (j = 0; j < tamanhoColuna; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
}

void exibirMatriz(int **matriz, int tamanhoLinha, int tamanhoColuna) {
    
    int i, j;
    for (i = 0; i < tamanhoLinha; i++) {
        for (j = 0; j < tamanhoColuna; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
   
    int **matriz;

    int tamanhoLinha;
    int tamanhoColuna;

    printf("Quantas linhas para a matriz? ");
    scanf("%d", &tamanhoLinha);

    printf("Quantas colunas para a matriz? ");
    scanf("%d", &tamanhoColuna);

    //criando as linhas da matriz
    *matriz = (int *)malloc(sizeof(int) * tamanhoLinha); //alocação de memória em tempo de execução
    
    //criando as colunas da matriz
    for (int i = 0; i < tamanhoLinha; i++) {
        matriz[i] = malloc(sizeof(int) * tamanhoColuna);
    }
    
    popularMatriz(matriz, tamanhoLinha, tamanhoColuna);
    exibirMatriz(matriz, tamanhoLinha, tamanhoColuna);

    // free(matriz); //liberação de memória em tempo de execução
    
    return 1;
}