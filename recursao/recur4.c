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
 * Funcao iterativa que recebe um vetor de inteiros e o seu respectivo tamanho
 * e retorna o maior elemento desse vetor
 **/
int maior(int v[], int tamanho) {
	int i = 1, max = v[0];
	
	while (i < tamanho) {
	  if (max < v[i])
	    max = v[i];
	  i++;
  }
	return max;
}

/**
 * Funcao RECURSIVA que recebe um vetor de inteiros e o seu respectivo tamanho
 * e retorna o maior elemento desse vetor
 **/
int maiorR(int v[], int tamanho) {
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
  mostra(v, TAM);
  printf("\n\nMaior valor: %d", maior(v, TAM));
  printf("\n\nMaior valor (recursao): %d", maiorR(v, TAM));
  
  return 1;
}
