#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *procurador, *procuradorEscrita;
    char nomeArquivo[200];
    int qtdParticulas = 0, conta1q = 0, conta2q = 0, conta3q = 0, conta4q = 0, contaOrigem = 0;
    int x, y;

    printf("Informe nome do arquivo de entrada com dados de particulas: ");
    scanf("%s",nomeArquivo);

    procurador = fopen(nomeArquivo,"r");
    if (!procurador) {
        printf("Arquivo digitado nao localizado!");
        exit(0);
    }

    do {
        fscanf(procurador,"%d,%d", &x, &y);
        qtdParticulas++;
        //if (feof(procurador)) break;

        if (x > 0 && y > 0) {
            conta1q++;
        } else if (x < 0 && y > 0) {
            conta2q++;
        } else if (x < 0 && y < 0) {
            conta3q++;
        } else if (x > 0 && y < 0) {
            conta4q++;
        } else {
            contaOrigem++;
        }
    } while (!feof(procurador));
    fclose(procurador);

    procuradorEscrita = fopen("log.txt","w");
    fprintf(procuradorEscrita,"Foram localizadas %d particulas\n", qtdParticulas);
    fprintf(procuradorEscrita,"1º Quadrante: %d\n", conta1q);
    fprintf(procuradorEscrita,"2º Quadrante: %d\n", conta2q);
    fprintf(procuradorEscrita,"3º Quadrante: %d\n", conta3q);
    fprintf(procuradorEscrita,"4º Quadrante: %d\n", conta4q);
    fprintf(procuradorEscrita,"Origwm: %d\n", contaOrigem);

    fclose(procuradorEscrita);
    return 1;
}

