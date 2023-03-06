#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *procurador;
    char nomeArquivo[200];

    //abrir o arquivo com os dados de glicemia
    printf("Qual o nome do arquivo fonte? ");
    scanf("%s", nomeArquivo);

    procurador = fopen(nomeArquivo,"r");
    if (procurador == NULL) {
        printf("Arquivo nao localizado");
        return 0;
    }        

    //alocar o vetor com a quantidade de dados glicemicos
    int *vetor;
    int contaLinhas = 0;
    char linha[250];
    do {
        fgets(linha,250,procurador);
        printf("%s", linha);
        contaLinhas++;
    } while(!feof(procurador));

    printf("\nTotal de linhas no arquivo: %d\n", contaLinhas);
    vetor = (int *)malloc(sizeof(int) * contaLinhas);
    
    //popular um vetor
    int i = 0;
    do {
        fgets(linha,250,procurador);
        vetor[i] = atoi(linha);
        i++;
    } while(!feof(procurador));

    //calcular as estatisticas
    //media

    //minimo

    //maximo

    //exibir resultados
}