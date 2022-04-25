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

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *procuradorArquivo;
    char nomeArquivo[200];

    system("clear");
    printf("Digite o nome do arquivo que deseja abrir: ");
    scanf("%s", nomeArquivo);

    procuradorArquivo = fopen(nomeArquivo, "r");

    if (procuradorArquivo == NULL) {
        printf("Arquivo nao localizado\n");
    } else {
        printf("Arquivo localizado com sucesso\n");
        fclose(procuradorArquivo);
    }
    return 1;
}