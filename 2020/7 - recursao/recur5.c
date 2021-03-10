#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

/**
 * Procedimento que recebe um vetor de inteiros e o seu respectivo tamanho
 * e preenche aletoriamente o vetor com numeros de 0 a 29
 **/
void preenche(int v[], int tamanho) {
	int i = 0;
	
	srand(time(NULL));
	
	while (i < tamanho)
		v[i++] = rand() % 30;
}

/**
 * Procedimento que recebe um vetor de inteiros e o seu respectivo tamanho
 * e mostra cada elemento desse vetor
 **/
void mostra(int v[], int tamanho) {
	int i = 0;
	
	while (i < tamanho)
		printf("%d\t",v[i++]);
	printf("\n");
}

/**
 * Funcao RECURSIVA que recebe um vetor de inteiros e o seu respectivo tamanho.
 * Para cada chamada recursiva, mostra o vetor atual
 * ao final, retorna o maior elemento desse vetor
 **/
int maiorR(int v[], int tamanho) {
  mostra(v, tamanho); getch();
	if (tamanho == 1)
	  return v[0];
	else {
		int max = maiorR(v, tamanho - 1);
	  if (max < v[tamanho - 1])
	    return v[tamanho - 1];
	  else return max;
  }
}

int main(){
  int v[TAM];
  
  preenche(v, TAM);
  printf("");
  mostra(v, TAM);
  printf("\n\nMaior valor (recursao): %d", maiorR(v, TAM));
  
  return 1;
}
