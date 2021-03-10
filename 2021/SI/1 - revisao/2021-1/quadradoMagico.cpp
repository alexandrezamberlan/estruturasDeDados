#include <iostream>
#include <stdlib.h>
using namespace std;

//protótipos dos métodos
void defineMatriz(int **matriz, int *dimensao); //
void inicializaMatriz(int **matriz, int dimensao);
void exibeMatriz(int **matriz, int dimensao);
void montarQuadradoMagico(int **matriz, int dimensao);

int main() {
    int **matriz;
    int dimensao;

    defineMatriz(matriz, &dimensao);

    inicializaMatriz(matriz, dimensao);
    
    montarQuadradoMagico(matriz, dimensao);

    exibeMatriz(matriz, dimensao);

    return 1;
}

void defineMatriz(int **matriz, int *dimensao) {    
    //2) valide se a dimensão é ímpar
    do {
        cout << "Informe uma dimensão ímpar para a matriz: ";
        cin >> *dimensao;
        if (*dimensao % 2 == 1) {
            break;
        } else {
            cout << "Lembre que a dimensão deve ser ímpar " << endl;
        }
    } while (true);

    //alocando as linhas da matriz
    *matriz = (int *)malloc(*dimensao * sizeof(int));
    //alocando as colunas para cada linha da matriz
    for (int i = 0; i < *dimensao; i++) {
        matriz[i] = (int *)malloc(sizeof(int) * *dimensao);
    }

    cout << "A dimensão escolhida foi " << *dimensao << " e matriz foi alocada com sucesso" << endl;
}

void inicializaMatriz(int **matriz, int dimensao) {
    for (int i = 0; i < dimensao; i++) {
        for (int j = 0; j < dimensao; j++) {
            matriz[i][j] = 0;
        }
    }
}

void exibeMatriz(int **matriz, int dimensao) {
    for (int i = 0; i < dimensao; i++) {
        for (int j = 0; j < dimensao; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

void montarQuadradoMagico(int **matriz, int dimensao) {
    int linha = dimensao - 1;
    int coluna = (int)dimensao / 2;
    int lin, col;
    
    matriz[linha][coluna] = 1;

    for (int a = 2; a <= dimensao*dimensao; a++) {
        lin = linha;
        linha++;
        if (linha == dimensao) linha = 0;

        col = coluna;
        coluna++;
        if (coluna == dimensao) coluna = 0;

        if (matriz[linha][coluna] == 0) {
            matriz[linha][coluna] = a;
        } else {
            linha = lin - 1;
            coluna = col;
            matriz[linha][coluna] = a;
        }
    }

}