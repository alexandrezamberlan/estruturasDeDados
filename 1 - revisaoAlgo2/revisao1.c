//Faça um programa que recebe e armazene números inteiros em vetor de tamanho TAM.
//Entretanto, os números não podem repetir. Ao final, exibir o vetor.
#include <stdio.h>
#include <stdlib.h>
#define TAM 10
int main() {
   int vetor[TAM];
   int contador;
   int numero;
   int existe; //booleano para verificar se numero jah inserido
   
   //inicializacao do vetor com -1
   for (int i = 0; i < TAM; i++) {
      vetor[i] = -1;
   }
   
   contador = 0;
   do {
      do {
         existe = 0;
         printf("Informe um numero inteiro: ");
         scanf("%d", &numero);
         
         for (int i = 0; i < contador && vetor[i] != -1; i++) {
            if (numero == vetor[i]) {
               existe = 1; //localizou
               break;
            }
         }
         if (existe) print("Numero jah digitado. \n");
      } while (existe);
      
      contador++;
      vetor[contador] = numero;
      
   } while (contador < TAM);
   

   //exibicao do vetor
   for (int i = 0; i < TAM; i++) {
      printf("%d\t", vetor[i]);
   }
   
   
   return 1;
}
