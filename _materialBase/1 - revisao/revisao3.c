//Entretanto, os números não podem repetir. Ao final, exibir o vetor.
#include <stdio.h>
#include <stdlib.h>

void exibirVetor(int vetor[], int tamanhoVetor) {
   //exibicao do vetor
   for (int i = 0; i < tamanhoVetor; i++) {
      printf("%d\t", vetor[i]);
   }
}

int *alocarVetor(int *tamanhoVetor) {
   int *vetor;
   printf("Quantos numeros quer cadastrar: ");
   scanf("%d", tamanhoVetor);

   vetor = malloc(sizeof(int) * (*tamanhoVetor));

   //inicializacao do vetor com -1
   for (int i = 0; i < *tamanhoVetor; i++) {
      vetor[i] = -1;
   }

   return vetor;
}

void ordenarVetor(int vetor[], int tamanhoVetor) {
   //bolha
   int houveTroca;
   int i;
   int tmp;
   do {
      houveTroca = 0;
      for (i = 0; i < tamanhoVetor - 1; i++) {
         if (vetor[i] > vetor[i + 1]) {
            houveTroca = 1;
            tmp = vetor[i];
            vetor[i] = vetor[i + 1];
            vetor[i + 1] = tmp;
         }
      }
   } while (houveTroca);
}

int main() {
   int *vetor;
   int tamanhoVetor;
   int contador;
   int numero;
   int existe; //booleano para verificar se numero jah inserido

   vetor = alocarVetor(&tamanhoVetor);

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

   ordenarVetor(vetor, tamanhoVetor);

   exibirVetor(vetor, tamanhoVetor);

   free(vetor);

   return 1;
}
