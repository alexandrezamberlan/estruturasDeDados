#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
    int massa;
} Ponto;

int main() {
    
    //receber nome do arquivo e le-lo para contar
    //quantas linhas hah, ou seja, quantas particulas
    char nomeArquivo[200];
    FILE *procurador;
    int totalPontos;

    printf("Digite nome arquivo com pontos no plano 2D: ");
    scanf("%s", nomeArquivo);

    procurador = fopen(nomeArquivo, "r");

    if (!procurador) {
        printf("Arquivo nao encontrado!\n");
        exit(0);
    }

    //percorrer o arquivo contando as linhas
    totalPontos = 0;
    char linha[200];
    while (!feof(procurador)) {
        fgets(linha,200,procurador);
        totalPontos++;
    }
    fclose(procurador);

    printf("O arquivo possui %d pontos\n", totalPontos);

    //alocar um vetor de Pontos a partir da quantidade
    //de particulas existentes no arquivo
    Ponto *vetor = (Ponto *)malloc(sizeof(Ponto) * totalPontos);

    //percorrer o arquivo e popular o vetor com os
    //pontos existentes no arquivo
    procurador = fopen(nomeArquivo, "r");
    int i = 0;
    do {
        fscanf(procurador,"%f %f %d", &vetor[i].x, &vetor[i].y, &vetor[i].massa);
        i++;
    } while(!feof(procurador));

    //mostrar o vetor
    for (i = 0; i < totalPontos; i++) {
        printf("%.2f,%.2f,%d\n", vetor[i].x, vetor[i].y, vetor[i].massa);
    }
    fclose(procurador);
    return 1;
}