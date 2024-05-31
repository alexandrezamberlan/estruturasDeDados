#include <stdio.h>
#include <stdlib.h>

/**
 * Funcao que recebe um numero inteiro e retorna seu fatorial
 */
long int fatorial(int numero) {
	int i = numero;
	int resultado = 1;
	while (i > 1) {
	  resultado = resultado * i; //resultado *= i;
	  i--;
  }
	return resultado;
}

/**
 * Funcao RECURSIVA que recebe um numero inteiro e retorna seu fatorial
 */
long int fatorialR(int numero) {
  if (numero == 1)
    return numero;
  else {
		return numero * fatorialR(numero - 1);
	}
}

int main(){
  int valor;  
  
  printf("Digite um valor inteiro: ");
  scanf("%d", &valor);
  
  printf("\n\nO fatorial (versao iterativa) de %d eh %ld\n", valor, fatorial(valor));
  printf("\n\nO fatorial (versao recursiva) de %d eh %ld\n", valor, fatorialR(valor));
  
  return 1;
}
