#include <stdio.h>
#include <stdlib.h>

void mostraConteudoArquivo(char *nomeArquivo) {
    FILE *procurador;
    procurador = fopen(nomeArquivo,"r");
    if (!procurador) return;

    printf("\n#############################\nExibindo o arquivo %s\n", nomeArquivo);
    char linha[100];
    do {
        fgets(linha, 100, procurador);
        printf("%s",linha);  

    } while (!feof(procurador));

    fclose(procurador);
}

int main(int qtdArgumentos, char **vetorArgumentos) {
    for (int i = 1; i < qtdArgumentos; i++) {
        mostraConteudoArquivo(vetorArgumentos[i]);
    }
    return 1;
}