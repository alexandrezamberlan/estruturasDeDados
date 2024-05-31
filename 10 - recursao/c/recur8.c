#include <stdio.h>
#include <stdlib.h>
#define TAM 7

/**
 * metodo que recebe 
 * @param v - representando um vetor de inteiros
 * @param n - o tamanho do vetor
 * @return o maior elemento do vetor
 */
int maiorR(int *v, int n) {
  if (n > 0) {
    int maior = maiorR(v, n-1);
    
    if (v[n-1] > maior) maior = v[n-1];
    printf("\nComparando v[%d]: %d e o maior %d", n-1, v[n-1], maior);
    return maior;
  }
  return v[n];
}

/**
 * metodo que recebe
 * @param valor para a pesquisa no vetor em v
 * @param v que representa um vetor de inteiros
 * @param n que eh o tamanho de v
 * @return a posicao em que se encontra valor no vetor. Caso ausente, retorn -1
 */
int buscaR(int valor, int *v, int n) {
  if (n > 0) {
    if (valor == v[n-1]) return n-1;
    return buscaR(valor, v, n-1);
  }
  return -1; //valor nao presente no vetor
}

/**
 * metodo que recebe
 * @param v representando um vetor de inteiros
 * @param n representando o tamanho de v
 * @return a quantidade de numeros pares de v
 */
int contaParesR(int *v, int n) {
  if (n > 0) {
    if (v[n-1] % 2 == 0) return 1 + contaParesR(v, n-1);
    return 0 + contaParesR(v, n-1);
  }
  return 0;
}

/**
 * metodo que recebe
 * @param v que eh um vetor de inteiros
 * @param n que eh o tamanho de v
 * @return 1 se v estiver ordenado crescente, ou 0 se desordenado
 */
int ordenadoR(int *v, int n) {
  if (n > 1) {
    if (v[n-1] < v[n-2])
      return 0;
    return ordenadoR(v, n-1);
  }
  return 1;
}

/**
 * metodo que imprime um vetor de inteiros. Recebe
 * @param v representando um vetor de inteiros
 * @param n o tamanho desse vetor v
 */
void imprimirR(int *v, int n) {
  if (n > 0) {
    imprimirR(v, n-1);
    printf("%d\t", v[n-1]);
  }
}

int main(int argc, char** argv) {
  int vetor[TAM] = {100, 2 , 3000, 4, 15, 5, 601};
  int vetor2[TAM] = {1,2,3,4,5,6,7};
  int i;


  imprimirR(vetor, TAM);

  printf("\n%d eh o maior do vetor\n\n", maiorR(vetor, TAM));
  printf("Procurando 4... resultado: posicao %d\n\n", buscaR(4,vetor, TAM));
  printf("Total de numeros pares: %d\n\n", contaParesR(vetor, TAM));
  if (ordenadoR(vetor, TAM)) printf("Vetor 1... ordenado\n\n");
  else printf("Vetor 1.... desordenado\n\n");


  imprimirR(vetor2, TAM);

  printf("\n%d eh o maior do vetor\n\n", maiorR(vetor2, TAM));
  printf("Procurando 4... resultado: posicao %d\n\n", buscaR(4,vetor2, TAM));
  printf("Total de numeros pares: %d\n\n", contaParesR(vetor2, TAM));
  if (ordenadoR(vetor2, TAM)) printf("Vetor 2... ordenado\n\n");
  else printf("Vetor 2.... desordenado\n\n");
  return 1;
}

