#include <stdio.h>
#include <stdlib.h>

/**
 * Funcao iterativa que recebe um numero inteiro
 * e retorna a quantidade de digitos desse inteiro
 **/
int numeroDeDigitos( int n ) {
  int cont = 1 ;
  while ( abs ( n ) > 9 ) {
    n = n / 10;
    cont++;
  }
  return cont;
}

/**
 * Funcao recursiva que recebe um numero inteiro
 * e retorna a quantidade de digitos desse inteiro
 **/
int numeroDeDigitosR( int n ) {
  if ( abs( n ) <= 9 )
    return 1;
  else return 1 + numeroDeDigitos( n / 10 );
}

int main() {
  int val1;
  
  printf("Digite um numero inteiro: ");
  scanf("%d", &val1);
  printf( "A quantidade de digitos de %d eh: %d\n", val1, numeroDeDigitos( val1 ) );
  printf( "A quantidade de digitos de %d eh: %d\n", val1, numeroDeDigitosR( val1 ) );
  return 1;
}

