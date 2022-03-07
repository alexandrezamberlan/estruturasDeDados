#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *procuradorArquivo;
    char nomeArquivo[200];
    char linha[200];

    system("clear");
    printf("Digite o nome do arquivo que deseja abrir: ");
    scanf("%s", nomeArquivo);

    procuradorArquivo = fopen(nomeArquivo, "r");

    if (procuradorArquivo == NULL) {
        printf("Arquivo nao localizado\n");
    } else {
        printf("Arquivo localizado com sucesso\n");
        //percorrer o arquivo para exibir seu conteudo
        while (!feof(procuradorArquivo)) {
            fgets(linha,200,procuradorArquivo);
            printf("%s",linha);
        }
        fclose(procuradorArquivo);
    }
    return 1;
}