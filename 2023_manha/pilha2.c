#include <stdio.h>
#include <stdlib.h>

#include "utilPilha.h"

PontoCartesiano *popularPilhaDoArquivo(PontoCartesiano *pilha) {
    FILE *procurador;
    char nomeArquivo[200];

    //pedir pelo arquivo
    printf("Caminho e nome do arquivo: ");
    scanf("%s", nomeArquivo);

    //abrir o arquivo e validar
    procurador = fopen(nomeArquivo,"r");
    if (!procurador) {
        return NULL;
    }

    //percorrer o arquivo e extrair pontos cartesianos e inserir na pilha
    int x, y;
    while (!feof(procurador)) {
        fscanf(procurador,"%d %d", &x, &y);
        pilha = inserir(x,y,pilha);
    }

    //fechar o arquivo
    fclose(procurador);

    //retornar a pilha
    return pilha;
}

int main() {
    PontoCartesiano *pilha = NULL;

    pilha = popularPilhaDoArquivo(pilha);

    printf("Esta estrutura tem %d elementos\n", contarPilha(pilha));
    exibir(pilha);
    return 1;
}

