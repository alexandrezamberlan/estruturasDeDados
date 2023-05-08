#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAML 4
#define TAMC 4

void popular(int matriz[TAML][TAMC], int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            matriz[i][j] = rand() % 50;
        }
    }
}

void popularR(int matriz[TAML][TAMC], int lin, int col, int backLin, int backcol)
{
    if (col > 0) {
        matriz[lin - 1][col - 1] = rand() % 10;
        popularR(matriz, lin, col - 1, backLin, backcol);
    } else if (lin > 0) {
        popularR(matriz, lin - 1, backcol ,backLin, backcol);
    }
}

void inicializarR(int matriz[TAML][TAMC], int lin, int col, int backLin, int backcol)
{
    if (col > 0) {
        matriz[lin - 1][col - 1] = 0;
        inicializarR(matriz, lin, col - 1, backLin, backcol);
    } else if (lin > 0) {
        inicializarR(matriz, lin - 1, backcol ,backLin, backcol);
    }
}

void preencherR(int matriz[TAML][TAMC], int lin, int col, int backLin, int backcol)
{
    if (col > 0) {
        if (lin < col) {
            matriz[lin - 1][col - 1] = 1;
        }
        preencherR(matriz, lin, col - 1, backLin, backcol);
    } else if (lin > 0) {
        preencherR(matriz, lin - 1, backcol ,backLin, backcol);
    }
}

void exibirR(int matriz[TAML][TAMC], int lin, int col, int backLin, int backcol) {
    if (col > 0) {
        exibirR(matriz, lin, col - 1, backLin, backcol);
        printf("%d\t",matriz[lin - 1][col - 1]);
    } else if (lin - 1 > 0) {
        exibirR(matriz, lin - 1, backcol ,backLin, backcol);
        printf("\n");
    }
}

void exibir(int matriz[TAML][TAMC], int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[TAML][TAMC];
    srand(time(NULL));
    // popular(matriz, TAM, TAM);
    // exibir(matriz, TAM, TAM);
                    //qtdlin, qtdcol, backuli, backucol
    inicializarR(matriz, TAML, TAMC, TAML, TAMC);
    preencherR(matriz, TAML, TAMC, TAML, TAMC);
    exibirR(matriz, TAML, TAMC, TAML, TAMC);
    return 1;
}