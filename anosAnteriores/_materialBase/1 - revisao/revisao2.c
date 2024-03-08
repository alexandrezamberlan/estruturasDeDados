//Entretanto, os números não podem repetir. Ao final, exibir o vetor.
#include <stdio.h>
#include <stdlib.h>

int main() {
   int *vetor;
   int tamanhoVetor;
   int contador;
   int numero;
   int existe; //booleano para verificar se numero jah inserido

   printf("Quantos numeros quer cadastrar: ");
   scanf("%d", &tamanhoVetor);

   vetor = malloc(sizeof(int) * tamanhoVetor);

   //inicializacao do vetor com -1
   for (int i = 0; i < tamanhoVetor; i++) {
      vetor[i] = -1;
   }

   contador = 0;
   do {
      do {
         existe = 0;
         printf("Informe um numero inteiro: ");
         scanf("%d", &numero);

         for (int i = 0; vetor[i] != -1; i++) {
            if (numero == vetor[i]) {
               existe = 1; //localizou
               break;
            }
         }
         if (existe) printf("Numero jah digitado. \n");
      } while (existe);


      vetor[contador] = numero;
      contador++;

   } while (contador < tamanhoVetor);


   //exibicao do vetor
   for (int i = 0; i < tamanhoVetor; i++) {
      printf("%d\t", vetor[i]);
   }

   free(vetor);

   return 1;
}
