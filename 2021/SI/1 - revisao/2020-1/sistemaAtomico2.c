#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
    int massa;
} Ponto;

int alocarVetor(char nomeArquivo[], FILE *procurador, Ponto **vetor) {
    procurador = fopen(nomeArquivo, "r");
    
    if (!procurador) {
        printf("Arquivo nao encontrado!\n");
        exit(0);
    }

    //percorrer o arquivo contando as linhas
    int totalPontos = 0;
    char linha[200];
    while (!feof(procurador)) {
        fgets(linha,200,procurador);
        totalPontos++;
    }

    //alocar um vetor de Pontos a partir da quantidade
    //de particulas existentes no arquivo
    *vetor = (Ponto *)malloc(sizeof(Ponto) * totalPontos);

    fclose(procurador);

    return totalPontos;
}

Ponto *popularVetor(char nomeArquivo[], Ponto *vetor) {
    
    //percorrer o arquivo e popular o vetor com os
    //pontos existentes no arquivo
    FILE *procurador = fopen(nomeArquivo, "r");
    int i = 0;
    do {
        fscanf(procurador,"%f %f %d", &vetor[i].x, &vetor[i].y, &vetor[i].massa);
        i++;
    } while(!feof(procurador));
    fclose(procurador);
    return vetor;
}

void exibirVetor(Ponto *vetor, int n) {
    //mostrar o vetor
    for (int i = 0; i < n; i++) {
        printf("%.2f,%.2f,%d\n", vetor[i].x, vetor[i].y, vetor[i].massa);
    }
}


int main() {
    
    //receber nome do arquivo e le-lo para contar
    //quantas linhas hah, ou seja, quantas particulas
    char nomeArquivo[200];
    FILE *procurador;
    int totalPontos;
    Ponto *vetor;

    printf("Digite nome arquivo com pontos no plano 2D: ");
    scanf("%s", nomeArquivo);
    totalPontos = alocarVetor(nomeArquivo, procurador, &vetor);
    printf("O arquivo possui %d pontos\n", totalPontos);

    vetor = popularVetor(nomeArquivo, vetor);

    exibirVetor(vetor, totalPontos);
    
    return 1;
}