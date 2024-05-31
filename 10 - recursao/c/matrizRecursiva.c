//metodos recursivos sobre vetores
//popular recursivo
//exibir recursivo
//filtrar recursivo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 3

void popularR(int matriz[TAM][TAM], int lin, int col, int backup) {
    if (col > 0) {
        popularR(matriz, lin, col - 1, backup);        
        matriz[lin - 1][col - 1] = rand() % 20;
        printf("[%d][%d]: %d\n", lin-1, col-1, matriz[lin - 1][col - 1]);
    } else if (lin - 1 > 0) {
        popularR(matriz, lin - 1, backup, backup);
    }
}

void exibirR(int matriz[TAM][TAM], int lin, int col, int backup) {
    if (col > 0) {        
        exibirR(matriz, lin, col - 1, backup);        
        printf("%d\t", matriz[lin - 1][col - 1]);
    } else if (lin - 1 > 0) {
        exibirR(matriz, lin - 1, backup, backup);
        printf("\n");
    }
}

void exibir(int matriz[TAM][TAM], int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {    
    int n = TAM;
    int matriz[TAM][TAM];

    srand(time(NULL));
    popularR(matriz, n, n, n);
    printf("exibindo sem recursao... \n");
    exibir(matriz, n, n);
    printf("exibindo com recursao... \n");
    exibirR(matriz, n, n, n);
    
    

    return 1;
}
