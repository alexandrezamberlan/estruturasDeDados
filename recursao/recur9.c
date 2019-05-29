#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 8

/**
 * procedimento que recebe 4 parametros:
 * os enderecos das variaveis maior e menor;
 * o tamanho do vetor
 * e o vetor de inteiros.
 * De forma recursiva, armazena nos enderecos maior e menor o maior e o menor numero do vetor
 **/

void maiorMenor(int *maior, int *menor, int n, int v[]) {
  if (n != 1) {
    maiorMenor (maior, menor, n-1, v);
    if (*maior < v[n-1]) *maior = v[n-1];
    if (*menor > v[n-1]) *menor = v[n-1];
  } else {
    *maior = v[0];
    *menor = v[0];
  }
}

int main() {
  int ma, me;
  int v[TAMANHO] = { 4, 3, 2, 1, 14, 13, -3, 7 };

  maiorMenor(&ma , &me  , TAMANHO , v );
  printf("\nMaior: %d\nMenor: %d", ma, me);

  return 1;
}