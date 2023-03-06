#include <iostream>
#include <stdlib.h>

using namespace std;

void exibirMatriz(int **quadrado, int dimensao) {
    for (int linha = 0; linha < dimensao; linha++) {
        for (int coluna = 0; coluna < dimensao; coluna++) {
            cout << quadrado[linha][coluna] << "\t";
        }
        cout << endl;
    }
}

int **alocarMatriz(int dimensao) {
    int **quadrado;

    for(int i=0; i< dimensao; i++){
        quadrado = (int**)malloc(sizeof(int) * dimensao);
    }

    for(int i=0; i< dimensao; i++){
        quadrado[i] = (int*)malloc(sizeof(int) * dimensao);
    }

    for (int linha = 0; linha < dimensao; linha++) {
        for (int coluna = 0; coluna < dimensao; coluna++) {
            quadrado[linha][coluna] = 0;
        }
    }
    return quadrado;
}

void posicionarNumerosMatriz(int **quadrado, int dimensao) {
    int lin, col;
    int linha = dimensao - 1;
    int coluna = (int)dimensao / 2;
    quadrado[linha][coluna] = 1;

    for (int a = 2; a <= dimensao*dimensao; a++) {
        lin = linha;
        linha++;
        if (linha == dimensao) linha = 0;

        col = coluna;
        coluna++;
        if (coluna == dimensao) coluna = 0;

        if (quadrado[linha][coluna] == 0) {
            quadrado[linha][coluna] = a;
        } else {
            linha = lin - 1;
            coluna = col;
            quadrado[linha][coluna] = a;
        }
    }
}

int main(){
    int dimensao;
    int **quadrado;

    cout << "Digite a dimensao de 3 a 21: ";
    cin >> dimensao;
    if(dimensao < 3 || dimensao > 21 || dimensao % 2 == 0){
        cout << "Dimensao invalida!\n";
        exit(0);
    }

    quadrado = alocarMatriz(dimensao);

    posicionarNumerosMatriz(quadrado, dimensao);

    exibirMatriz(quadrado, dimensao);

    free(quadrado);
    return 1;
}
