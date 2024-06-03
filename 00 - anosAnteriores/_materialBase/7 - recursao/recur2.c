#include <stdio.h>
#include <stdlib.h>

/**
 * Funcao ITERATIVA que recebe um valor inteiro para o inicio da sequencia e 
 * um outro inteiro para o final da sequencia.
 * Ao final, retorna a soma dos numeros desse intervalo
 **/
int soma( int inicio, int fim ) {
  int resultado = 0 , i ;
  for ( i = inicio; i <= fim ; i++)
    resultado += i ;
  return ( resultado ) ;
}

/**
 * Funcao recursiva que recebe um valor inteiro para o inicio 
 * da sequencia e um outro inteiro para o final da sequencia.
 * Ao final, retorna a soma dos numeros desse intervalo
 **/
int somaA( int inicio, int fim ) {
  if ( inicio == fim )
    return inicio;
  else return somaA( inicio, fim - 1 ) + fim;  
}

/**
 * Versao B da funcao recursiva acima
 **/
int somaB( int inicio, int fim ) {
  if ( inicio == fim )
    return inicio;
  else return inicio + somaB( inicio + 1 , fim );
}

int main() {
  int val1, val2;
  //system( "cls" );
  val1 = 3;
  val2 = 6;
  printf( "Soma do intervalo (VERSAO ITERATIVA) (%d a %d): %d\n", val1, val2, soma( val1,val2 ) );
  printf( "Soma do intervalo (VERSAO RECURSIVA A) (%d a %d): %d\n", val1, val2, somaA( val1,val2 ) );
  printf( "Soma do intervalo (VERSAO RECURSIVA B) (%d a %d): %d\n", val1, val2, somaB( val1,val2 ) );
  return 1;
}

