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
int main() {
    //programa que le um nome de arquivo e se existe exibe seu conteudo
    //na tela. OBS.: arquivos text
    FILE *procurador;
    char nomeArquivo[200];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    procurador = fopen(nomeArquivo,"r");

    if (!procurador) {
        printf("Arquivo nao encontrado!\n");
        exit(0);
    }
    printf("Arquivo localizado e sendo aberto...\n");

    float x,y;
    int massa;
    int contaLinhas = 0;
    int conseguiu;
    do {
        contaLinhas++;
        conseguiu = fscanf(procurador,"%f %f %d", &x, &y, &massa);
        if (!conseguiu) break;
        printf("%.2f %.2f %d\n", x, y, massa);
    } while(!feof(procurador));

    printf("Este arquivo tem %d linhas\n", contaLinhas);
    fclose(procurador);
    return 1;
}
