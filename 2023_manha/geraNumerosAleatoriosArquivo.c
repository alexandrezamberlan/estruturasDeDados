//programa em linha de comando que gera arquivo com números aleatorios dentro de uma faix
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int qtdArgumentos, char **vetorArgumentos) {
    //argumento 1 - quantidade de numeros
    //argumento 2 - faixa dos numeros
    //argumento 3 - nome do arquivo com numeros gerados
    //Exemplo:  roda 1000 100 numeros1.txt

    int qtdNumeros = atoi(vetorArgumentos[1]);
    int faixa = atoi(vetorArgumentos[2]);
    char nomeArquivo[150];
    strcpy(nomeArquivo, vetorArgumentos[3]);

    if (qtdArgumentos != 4 || qtdNumeros == 0 || faixa == 0) {
        printf("Problemas com os parametros!\n");
        exit(0);
    }

    FILE *arquivo;
    arquivo = fopen(nomeArquivo,"w");
    srand(time(NULL));
    for (int i = 0; i < qtdNumeros; i++) {
        fprintf(arquivo,"%d\n",rand() % faixa);
        fflush(arquivo);
    }
    fclose(arquivo);
    return 1;

}