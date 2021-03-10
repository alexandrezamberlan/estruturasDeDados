#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    FILE *procuradorDoArquivo;
    char nomeArquivo[200];

    system("clear");
    //descobrir o nome do arquivo a ser lido
    printf("Informe caminho e nome do arquivo que deseja abrir: ");
    scanf("%s", nomeArquivo);

    //abrir o arquivo no modo leitura
    procuradorDoArquivo = fopen(nomeArquivo, "r");
    
    if (!procuradorDoArquivo) {
        printf("Arquivo nao localizado.\n");
        exit(0);
    }

    printf("Arquivo localizado com sucesso.\n");

    //percorrer o procurador para capturar os dados, neste exemplo a linha e exibir na tela
    char linha[200];
    do {
        fgets(linha,200,procuradorDoArquivo);
        printf("%s", linha);

    } while (!feof(procuradorDoArquivo));

    //fechar o arquivo
    printf("\n");
    fclose(procuradorDoArquivo);
    return 1;
}

/**
 * arquivo em disco precisa de uma variável em RAM que o represente, em geral um ponteiro para arquivo
 * Operações:
 *  - fopen - abrir (associar o arquivo ao procurador): read, append, write
 *  - fclose - fechar (gravar os dados que estão em RAM para o Disco)
 *  - fprintf: escrever no arquivo - gravar
 *  - fscanf: ler do arquivo - ler variavel por variavel  
 *  - fgets: ler do arquivo - ler uma linha inteira
 *  - fgetc: ler do arquivo - ler caracter por caracter
 *  - feof: função que verifica se o controlador do arquivo já chegou no final
 */