#include <stdio.h>
#include <stdlib.h>
#define TAM 45

typedef struct {
    float x;
    float y;
    float z;
    float massa;
} Particula;

int main() {
    FILE *procuradorArquivo;
    char nomeArquivo[200];
    int i;
    Particula vetor[TAM];


    system("clear");
    printf("Digite o nome do arquivo com dados de particulas: ");
    scanf("%s", nomeArquivo);

    procuradorArquivo = fopen(nomeArquivo, "r");

    if (!procuradorArquivo) {
        printf("Arquivo nao localizado\n");
    } else {
        printf("Arquivo localizado com sucesso\n");
        //percorrer o arquivo para popular o vetor
        for (i = 0; !feof(procuradorArquivo); i++) {
            fscanf(procuradorArquivo,"%f %f %f %f", &vetor[i].x, &vetor[i].y, &vetor[i].z, &vetor[i].massa);  
        }

        //percorrer o vetor para exibir massas
        for (i = 0; i < 4; i++) {
            printf("%.1f\t", vetor[i].massa);
        }
        fclose(procuradorArquivo);
    }
    return 1;
}