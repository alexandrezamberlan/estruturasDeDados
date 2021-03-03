/***
 * Fazer um programa em C++, subdividido em métodos (funções ou procedimentos), que:
 * 1) peça para o usuário o tamanho da dimensão da matriz NxN
 * 2) valide se a dimensão é ímpar
 * 3) inicialize a matriz com zeros
 * 4) exiba a matriz na tela
 */ 
#include <iostream>
#include <stdlib.h>
using namespace std;

//protótipos dos métodos
void defineMatriz(int **matriz, int *dimensao); //
void inicializaMatriz(int **matriz, int dimensao);
void exibeMatriz(int **matriz, int dimensao);

int main() {
    int **matriz;
    int dimensao;

    //1) peça para o usuário o tamanho da dimensão da matriz NxN
    defineMatriz(matriz, &dimensao);

    //3) inicialize a matriz com zeros
    inicializaMatriz(matriz, dimensao);
    
    //4) exiba a matriz na tela
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