/*
    Arquivo texto (plain text)

    TIPOS específicos:
        - FILE * nomeVariavel;
        . variável que aponta para um endereço de um arquivo em disco
        . conceito de procuração

    Aberturas:
        - fopen
        . abrir no modo leitura "r" (read)
        . abrir no modo apendar "a" (append)
        . abrir no modo criar/escrever "w" (write)
        . abrir significa fazer o ponteiro procurador apontar para o
          endereço do arquivo no disco

    Fechamento:
        - fclose
        . é neste momento que todo o conteúdo colocado no procurador
          vai para o disco

    Gravação em disco
        - fflush

    Leitura
        - fscanf
        - fgets
        - fgetc

    Escrever/Gravar
        - fprintf
        - fputs
        - fputc

    CURIOSIDADES:
        . EOF diferente da função feof()
        . EOF é um símbolo de caracter para final de arquivo,
          usado nas leitura caracter a caracter
        . feof() é uma função que retorna se um procurador
          chegou ao final do arquivo

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    //programa que le um nome de arquivo e se existe exibe seu conteudo
    //na tela. OBS.: arquivos text
    FILE *procurador;
    char nomeArquivo[200];

    printf("Digite o nome do arquivo com particulas: ");
    scanf("%s", nomeArquivo);

    procurador = fopen(nomeArquivo,"r");

    if (!procurador) {
        printf("Arquivo nao encontrado, vai ser criado!\n");
        procurador = fopen(nomeArquivo,"w");
    } else {
        printf("Arquivo localizado e pronto para gravacao...\n");
        fclose(procurador);
        procurador = fopen(nomeArquivo,"a");
    }

    float x,y;
    int massa;
    do {
        printf("Valor de x: ");
        scanf("%f", &x);

        printf("Valor de y: ");
        scanf("%f", &y);

        printf("Valor de massa: ");
        scanf("%d", &massa);

        fprintf(procurador,"%.2f\t%.2f\t%d\n", x,y,massa);

        fflush(procurador);
    } while(1);

    fclose(procurador);
    return 1;
}
