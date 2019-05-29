#include <stdio.h>
#include <stdlib.h>

/**
 * Funcao que recebe um numero inteiro (base) e outro inteiro (expoente)
 * e retorna a potencial da base elevada ao expoente
 */
long int potencia(int base, int expoente) {
	int i = 1;
	int resultado = base;
	while (i < expoente) {
	  resultado = resultado * base;
	  i++;
  }
	return resultado;
}

/**
 * Funcao RECURSIVA que recebe um numero inteiro (base) e outro inteiro (expoente)
 * e retorna a potencial da base elevada ao expoente
 */
long int potencia(int base, int expoente) {

  return 1;
}

int main(){
  int valorBase, valorExpoente;
  
  printf("Digite um valor inteiro para base: ");
  scanf("%d", &valorBase);
  printf("Digite um valor inteiro como expoente: ");
  scanf("%d", &valorExpoente);  
  printf("\n\n%d elevado a %d eh %ld\n", valorBase, valorExpoente, potencia(valorBase, valorExpoente));
  
  return 1;
}
